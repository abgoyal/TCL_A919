

#include <linux/threads.h>
#include <asm/reg.h>
#include <asm/page.h>
#include <asm/mmu.h>
#include <asm/ppc_asm.h>
#include <asm/asm-offsets.h>
#include <asm/bug.h>
#include <asm/cputable.h>
#include <asm/setup.h>
#include <asm/hvcall.h>
#include <asm/iseries/lpar_map.h>
#include <asm/thread_info.h>
#include <asm/firmware.h>
#include <asm/page_64.h>
#include <asm/irqflags.h>
#include <asm/kvm_book3s_asm.h>



	.text
	.globl  _stext
_stext:
_GLOBAL(__start)
	/* NOP this out unconditionally */
BEGIN_FTR_SECTION
	b	.__start_initialization_multiplatform
END_FTR_SECTION(0, 1)

	/* Catch branch to 0 in real mode */
	trap

	/* Secondary processors spin on this value until it becomes nonzero.
	 * When it does it contains the real address of the descriptor
	 * of the function that the cpu should jump to to continue
	 * initialization.
	 */
	.globl  __secondary_hold_spinloop
__secondary_hold_spinloop:
	.llong	0x0

	/* Secondary processors write this value with their cpu # */
	/* after they enter the spin loop immediately below.	  */
	.globl	__secondary_hold_acknowledge
__secondary_hold_acknowledge:
	.llong	0x0

#ifdef CONFIG_PPC_ISERIES
	/*
	 * At offset 0x20, there is a pointer to iSeries LPAR data.
	 * This is required by the hypervisor
	 */
	. = 0x20
	.llong hvReleaseData-KERNELBASE
#endif /* CONFIG_PPC_ISERIES */

#ifdef CONFIG_CRASH_DUMP
	/* This flag is set to 1 by a loader if the kernel should run
	 * at the loaded address instead of the linked address.  This
	 * is used by kexec-tools to keep the the kdump kernel in the
	 * crash_kernel region.  The loader is responsible for
	 * observing the alignment requirement.
	 */
	/* Do not move this variable as kexec-tools knows about it. */
	. = 0x5c
	.globl	__run_at_load
__run_at_load:
	.long	0x72756e30	/* "run0" -- relocate to 0 by default */
#endif

	. = 0x60
	.globl	__secondary_hold
__secondary_hold:
#ifndef CONFIG_PPC_BOOK3E
	mfmsr	r24
	ori	r24,r24,MSR_RI
	mtmsrd	r24			/* RI on */
#endif
	/* Grab our physical cpu number */
	mr	r24,r3

	/* Tell the master cpu we're here */
	/* Relocation is off & we are located at an address less */
	/* than 0x100, so only need to grab low order offset.    */
	std	r24,__secondary_hold_acknowledge-_stext(0)
	sync

	/* All secondary cpus wait here until told to start. */
100:	ld	r4,__secondary_hold_spinloop-_stext(0)
	cmpdi	0,r4,0
	beq	100b

#if defined(CONFIG_SMP) || defined(CONFIG_KEXEC)
	ld	r4,0(r4)		/* deref function descriptor */
	mtctr	r4
	mr	r3,r24
	li	r4,0
	bctr
#else
	BUG_OPCODE
#endif

/* This value is used to mark exception frames on the stack. */
	.section ".toc","aw"
exception_marker:
	.tc	ID_72656773_68657265[TC],0x7265677368657265
	.text

#ifdef CONFIG_PPC_BOOK3S
#include "exceptions-64s.S"
#endif

/* KVM trampoline code needs to be close to the interrupt handlers */

#ifdef CONFIG_KVM_BOOK3S_64_HANDLER
#include "../kvm/book3s_rmhandlers.S"
#endif

_GLOBAL(generic_secondary_thread_init)
	mr	r24,r3

	/* turn on 64-bit mode */
	bl	.enable_64b_mode

	/* get a valid TOC pointer, wherever we're mapped at */
	bl	.relative_toc

#ifdef CONFIG_PPC_BOOK3E
	/* Book3E initialization */
	mr	r3,r24
	bl	.book3e_secondary_thread_init
#endif
	b	generic_secondary_common_init

_GLOBAL(generic_secondary_smp_init)
	mr	r24,r3
	mr	r25,r4

	/* turn on 64-bit mode */
	bl	.enable_64b_mode

	/* get a valid TOC pointer, wherever we're mapped at */
	bl	.relative_toc

#ifdef CONFIG_PPC_BOOK3E
	/* Book3E initialization */
	mr	r3,r24
	mr	r4,r25
	bl	.book3e_secondary_core_init
#endif

generic_secondary_common_init:
	/* Set up a paca value for this processor. Since we have the
	 * physical cpu id in r24, we need to search the pacas to find
	 * which logical id maps to our physical one.
	 */
	LOAD_REG_ADDR(r13, paca)	/* Load paca pointer		 */
	ld	r13,0(r13)		/* Get base vaddr of paca array	 */
	li	r5,0			/* logical cpu id                */
1:	lhz	r6,PACAHWCPUID(r13)	/* Load HW procid from paca      */
	cmpw	r6,r24			/* Compare to our id             */
	beq	2f
	addi	r13,r13,PACA_SIZE	/* Loop to next PACA on miss     */
	addi	r5,r5,1
	cmpwi	r5,NR_CPUS
	blt	1b

	mr	r3,r24			/* not found, copy phys to r3	 */
	b	.kexec_wait		/* next kernel might do better	 */

2:	mtspr	SPRN_SPRG_PACA,r13	/* Save vaddr of paca in an SPRG */
#ifdef CONFIG_PPC_BOOK3E
	addi	r12,r13,PACA_EXTLB	/* and TLB exc frame in another  */
	mtspr	SPRN_SPRG_TLB_EXFRAME,r12
#endif

	/* From now on, r24 is expected to be logical cpuid */
	mr	r24,r5
3:	HMT_LOW
	lbz	r23,PACAPROCSTART(r13)	/* Test if this processor should */
					/* start.			 */

#ifndef CONFIG_SMP
	b	3b			/* Never go on non-SMP		 */
#else
	cmpwi	0,r23,0
	beq	3b			/* Loop until told to go	 */

	sync				/* order paca.run and cur_cpu_spec */

	/* See if we need to call a cpu state restore handler */
	LOAD_REG_ADDR(r23, cur_cpu_spec)
	ld	r23,0(r23)
	ld	r23,CPU_SPEC_RESTORE(r23)
	cmpdi	0,r23,0
	beq	4f
	ld	r23,0(r23)
	mtctr	r23
	bctrl

4:	/* Create a temp kernel stack for use before relocation is on.	*/
	ld	r1,PACAEMERGSP(r13)
	subi	r1,r1,STACK_FRAME_OVERHEAD

	b	__secondary_start
#endif

#ifdef CONFIG_PPC_BOOK3S
_STATIC(__mmu_off)
	mfmsr	r3
	andi.	r0,r3,MSR_IR|MSR_DR
	beqlr
	mflr	r4
	andc	r3,r3,r0
	mtspr	SPRN_SRR0,r4
	mtspr	SPRN_SRR1,r3
	sync
	rfid
	b	.	/* prevent speculative execution */
#endif


_GLOBAL(__start_initialization_multiplatform)
	/* Make sure we are running in 64 bits mode */
	bl	.enable_64b_mode

	/* Get TOC pointer (current runtime address) */
	bl	.relative_toc

	/* find out where we are now */
	bcl	20,31,$+4
0:	mflr	r26			/* r26 = runtime addr here */
	addis	r26,r26,(_stext - 0b)@ha
	addi	r26,r26,(_stext - 0b)@l	/* current runtime base addr */

	/*
	 * Are we booted from a PROM Of-type client-interface ?
	 */
	cmpldi	cr0,r5,0
	beq	1f
	b	.__boot_from_prom		/* yes -> prom */
1:
	/* Save parameters */
	mr	r31,r3
	mr	r30,r4

#ifdef CONFIG_PPC_BOOK3E
	bl	.start_initialization_book3e
	b	.__after_prom_start
#else
	/* Setup some critical 970 SPRs before switching MMU off */
	mfspr	r0,SPRN_PVR
	srwi	r0,r0,16
	cmpwi	r0,0x39		/* 970 */
	beq	1f
	cmpwi	r0,0x3c		/* 970FX */
	beq	1f
	cmpwi	r0,0x44		/* 970MP */
	beq	1f
	cmpwi	r0,0x45		/* 970GX */
	bne	2f
1:	bl	.__cpu_preinit_ppc970
2:

	/* Switch off MMU if not already off */
	bl	.__mmu_off
	b	.__after_prom_start
#endif /* CONFIG_PPC_BOOK3E */

_INIT_STATIC(__boot_from_prom)
#ifdef CONFIG_PPC_OF_BOOT_TRAMPOLINE
	/* Save parameters */
	mr	r31,r3
	mr	r30,r4
	mr	r29,r5
	mr	r28,r6
	mr	r27,r7

	/*
	 * Align the stack to 16-byte boundary
	 * Depending on the size and layout of the ELF sections in the initial
	 * boot binary, the stack pointer may be unaligned on PowerMac
	 */
	rldicr	r1,r1,0,59

#ifdef CONFIG_RELOCATABLE
	/* Relocate code for where we are now */
	mr	r3,r26
	bl	.relocate
#endif

	/* Restore parameters */
	mr	r3,r31
	mr	r4,r30
	mr	r5,r29
	mr	r6,r28
	mr	r7,r27

	/* Do all of the interaction with OF client interface */
	mr	r8,r26
	bl	.prom_init
#endif /* #CONFIG_PPC_OF_BOOT_TRAMPOLINE */

	/* We never return. We also hit that trap if trying to boot
	 * from OF while CONFIG_PPC_OF_BOOT_TRAMPOLINE isn't selected */
	trap

_STATIC(__after_prom_start)
#ifdef CONFIG_RELOCATABLE
	/* process relocations for the final address of the kernel */
	lis	r25,PAGE_OFFSET@highest	/* compute virtual base of kernel */
	sldi	r25,r25,32
#ifdef CONFIG_CRASH_DUMP
	lwz	r7,__run_at_load-_stext(r26)
	cmplwi	cr0,r7,1	/* kdump kernel ? - stay where we are */
	bne	1f
	add	r25,r25,r26
#endif
1:	mr	r3,r25
	bl	.relocate
#endif

	li	r3,0			/* target addr */
#ifdef CONFIG_PPC_BOOK3E
	tovirt(r3,r3)			/* on booke, we already run at PAGE_OFFSET */
#endif
	mr.	r4,r26			/* In some cases the loader may  */
	beq	9f			/* have already put us at zero */
	li	r6,0x100		/* Start offset, the first 0x100 */
					/* bytes were copied earlier.	 */
#ifdef CONFIG_PPC_BOOK3E
	tovirt(r6,r6)			/* on booke, we already run at PAGE_OFFSET */
#endif

#ifdef CONFIG_CRASH_DUMP
	lwz	r7,__run_at_load-_stext(r26)
	cmplwi	cr0,r7,1
	bne	3f

	li	r5,__end_interrupts - _stext	/* just copy interrupts */
	b	5f
3:
#endif
	lis	r5,(copy_to_here - _stext)@ha
	addi	r5,r5,(copy_to_here - _stext)@l /* # bytes of memory to copy */

	bl	.copy_and_flush		/* copy the first n bytes	 */
					/* this includes the code being	 */
					/* executed here.		 */
	addis	r8,r3,(4f - _stext)@ha	/* Jump to the copy of this code */
	addi	r8,r8,(4f - _stext)@l	/* that we just made */
	mtctr	r8
	bctr

p_end:	.llong	_end - _stext

4:	/* Now copy the rest of the kernel up to _end */
	addis	r5,r26,(p_end - _stext)@ha
	ld	r5,(p_end - _stext)@l(r5)	/* get _end */
5:	bl	.copy_and_flush		/* copy the rest */

9:	b	.start_here_multiplatform

_GLOBAL(copy_and_flush)
	addi	r5,r5,-8
	addi	r6,r6,-8
4:	li	r0,8			/* Use the smallest common	*/
					/* denominator cache line	*/
					/* size.  This results in	*/
					/* extra cache line flushes	*/
					/* but operation is correct.	*/
					/* Can't get cache line size	*/
					/* from NACA as it is being	*/
					/* moved too.			*/

	mtctr	r0			/* put # words/line in ctr	*/
3:	addi	r6,r6,8			/* copy a cache line		*/
	ldx	r0,r6,r4
	stdx	r0,r6,r3
	bdnz	3b
	dcbst	r6,r3			/* write it to memory		*/
	sync
	icbi	r6,r3			/* flush the icache line	*/
	cmpld	0,r6,r5
	blt	4b
	sync
	addi	r5,r5,8
	addi	r6,r6,8
	blr

.align 8
copy_to_here:

#ifdef CONFIG_SMP
#ifdef CONFIG_PPC_PMAC
	.section ".text";
	.align 2 ;

	.globl	__secondary_start_pmac_0
__secondary_start_pmac_0:
	/* NB the entries for cpus 0, 1, 2 must each occupy 8 bytes. */
	li	r24,0
	b	1f
	li	r24,1
	b	1f
	li	r24,2
	b	1f
	li	r24,3
1:
	
_GLOBAL(pmac_secondary_start)
	/* turn on 64-bit mode */
	bl	.enable_64b_mode

	li	r0,0
	mfspr	r3,SPRN_HID4
	rldimi	r3,r0,40,23	/* clear bit 23 (rm_ci) */
	sync
	mtspr	SPRN_HID4,r3
	isync
	sync
	slbia

	/* get TOC pointer (real address) */
	bl	.relative_toc

	/* Copy some CPU settings from CPU 0 */
	bl	.__restore_cpu_ppc970

	/* pSeries do that early though I don't think we really need it */
	mfmsr	r3
	ori	r3,r3,MSR_RI
	mtmsrd	r3			/* RI on */

	/* Set up a paca value for this processor. */
	LOAD_REG_ADDR(r4,paca)		/* Load paca pointer		*/
	ld	r4,0(r4)		/* Get base vaddr of paca array	*/
	mulli	r13,r24,PACA_SIZE	/* Calculate vaddr of right paca */
	add	r13,r13,r4		/* for this processor.		*/
	mtspr	SPRN_SPRG_PACA,r13	/* Save vaddr of paca in an SPRG*/

	/* Create a temp kernel stack for use before relocation is on.	*/
	ld	r1,PACAEMERGSP(r13)
	subi	r1,r1,STACK_FRAME_OVERHEAD

	b	__secondary_start

#endif /* CONFIG_PPC_PMAC */

	.section ".text";
	.align 2 ;

	.globl	__secondary_start
__secondary_start:
	/* Set thread priority to MEDIUM */
	HMT_MEDIUM

	/* Do early setup for that CPU (stab, slb, hash table pointer) */
	bl	.early_setup_secondary

	/* Initialize the kernel stack.  Just a repeat for iSeries.	 */
	LOAD_REG_ADDR(r3, current_set)
	sldi	r28,r24,3		/* get current_set[cpu#]	 */
	ldx	r1,r3,r28
	addi	r1,r1,THREAD_SIZE-STACK_FRAME_OVERHEAD
	std	r1,PACAKSAVE(r13)

	/* Clear backchain so we get nice backtraces */
	li	r7,0
	mtlr	r7

	/* enable MMU and jump to start_secondary */
	LOAD_REG_ADDR(r3, .start_secondary_prolog)
	LOAD_REG_IMMEDIATE(r4, MSR_KERNEL)
#ifdef CONFIG_PPC_ISERIES
BEGIN_FW_FTR_SECTION
	ori	r4,r4,MSR_EE
	li	r8,1
	stb	r8,PACAHARDIRQEN(r13)
END_FW_FTR_SECTION_IFSET(FW_FEATURE_ISERIES)
#endif
BEGIN_FW_FTR_SECTION
	stb	r7,PACAHARDIRQEN(r13)
END_FW_FTR_SECTION_IFCLR(FW_FEATURE_ISERIES)
	stb	r7,PACASOFTIRQEN(r13)

	mtspr	SPRN_SRR0,r3
	mtspr	SPRN_SRR1,r4
	RFI
	b	.	/* prevent speculative execution */

_GLOBAL(start_secondary_prolog)
	ld	r2,PACATOC(r13)
	li	r3,0
	std	r3,0(r1)		/* Zero the stack frame pointer	*/
	bl	.start_secondary
	b	.
_GLOBAL(start_secondary_resume)
	ld	r1,PACAKSAVE(r13)	/* Reload kernel stack pointer */
	li	r3,0
	std	r3,0(r1)		/* Zero the stack frame pointer	*/
	bl	.start_secondary
	b	.
#endif

_GLOBAL(enable_64b_mode)
	mfmsr	r11			/* grab the current MSR */
#ifdef CONFIG_PPC_BOOK3E
	oris	r11,r11,0x8000		/* CM bit set, we'll set ICM later */
	mtmsr	r11
#else /* CONFIG_PPC_BOOK3E */
	li	r12,(MSR_SF | MSR_ISF)@highest
	sldi	r12,r12,48
	or	r11,r11,r12
	mtmsrd	r11
	isync
#endif
	blr

_GLOBAL(relative_toc)
	mflr	r0
	bcl	20,31,$+4
0:	mflr	r9
	ld	r2,(p_toc - 0b)(r9)
	add	r2,r2,r9
	mtlr	r0
	blr

p_toc:	.llong	__toc_start + 0x8000 - 0b

_INIT_STATIC(start_here_multiplatform)
	/* set up the TOC (real address) */
	bl	.relative_toc

	/* Clear out the BSS. It may have been done in prom_init,
	 * already but that's irrelevant since prom_init will soon
	 * be detached from the kernel completely. Besides, we need
	 * to clear it now for kexec-style entry.
	 */
	LOAD_REG_ADDR(r11,__bss_stop)
	LOAD_REG_ADDR(r8,__bss_start)
	sub	r11,r11,r8		/* bss size			*/
	addi	r11,r11,7		/* round up to an even double word */
	srdi.	r11,r11,3		/* shift right by 3		*/
	beq	4f
	addi	r8,r8,-8
	li	r0,0
	mtctr	r11			/* zero this many doublewords	*/
3:	stdu	r0,8(r8)
	bdnz	3b
4:

#ifndef CONFIG_PPC_BOOK3E
	mfmsr	r6
	ori	r6,r6,MSR_RI
	mtmsrd	r6			/* RI on */
#endif

#ifdef CONFIG_RELOCATABLE
	/* Save the physical address we're running at in kernstart_addr */
	LOAD_REG_ADDR(r4, kernstart_addr)
	clrldi	r0,r25,2
	std	r0,0(r4)
#endif

	/* The following gets the stack set up with the regs */
	/* pointing to the real addr of the kernel stack.  This is   */
	/* all done to support the C function call below which sets  */
	/* up the htab.  This is done because we have relocated the  */
	/* kernel but are still running in real mode. */

	LOAD_REG_ADDR(r3,init_thread_union)

	/* set up a stack pointer */
	addi	r1,r3,THREAD_SIZE
	li	r0,0
	stdu	r0,-STACK_FRAME_OVERHEAD(r1)

	/* Do very early kernel initializations, including initial hash table,
	 * stab and slb setup before we turn on relocation.	*/

	/* Restore parameters passed from prom_init/kexec */
	mr	r3,r31
	bl	.early_setup		/* also sets r13 and SPRG_PACA */

	LOAD_REG_ADDR(r3, .start_here_common)
	ld	r4,PACAKMSR(r13)
	mtspr	SPRN_SRR0,r3
	mtspr	SPRN_SRR1,r4
	RFI
	b	.	/* prevent speculative execution */
	
	/* This is where all platforms converge execution */
_INIT_GLOBAL(start_here_common)
	/* relocation is on at this point */
	std	r1,PACAKSAVE(r13)

	/* Load the TOC (virtual address) */
	ld	r2,PACATOC(r13)

	bl	.setup_system

	/* Load up the kernel context */
5:
	li	r5,0
	stb	r5,PACASOFTIRQEN(r13)	/* Soft Disabled */
#ifdef CONFIG_PPC_ISERIES
BEGIN_FW_FTR_SECTION
	mfmsr	r5
	ori	r5,r5,MSR_EE		/* Hard Enabled on iSeries*/
	mtmsrd	r5
	li	r5,1
END_FW_FTR_SECTION_IFSET(FW_FEATURE_ISERIES)
#endif
	stb	r5,PACAHARDIRQEN(r13)	/* Hard Disabled on others */

	bl	.start_kernel

	/* Not reached */
	BUG_OPCODE

	.section ".bss"

	.align	PAGE_SHIFT

	.globl	empty_zero_page
empty_zero_page:
	.space	PAGE_SIZE

	.globl	swapper_pg_dir
swapper_pg_dir:
	.space	PGD_TABLE_SIZE
