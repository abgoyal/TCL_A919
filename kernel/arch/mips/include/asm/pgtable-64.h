
#ifndef _ASM_PGTABLE_64_H
#define _ASM_PGTABLE_64_H

#include <linux/linkage.h>

#include <asm/addrspace.h>
#include <asm/page.h>
#include <asm/cachectl.h>
#include <asm/fixmap.h>

#ifdef CONFIG_PAGE_SIZE_64KB
#include <asm-generic/pgtable-nopmd.h>
#else
#include <asm-generic/pgtable-nopud.h>
#endif



/* PGDIR_SHIFT determines what a third-level page table entry can map */
#ifdef __PAGETABLE_PMD_FOLDED
#define PGDIR_SHIFT	(PAGE_SHIFT + PAGE_SHIFT + PTE_ORDER - 3)
#else

/* PMD_SHIFT determines the size of the area a second-level page table can map */
#define PMD_SHIFT	(PAGE_SHIFT + (PAGE_SHIFT + PTE_ORDER - 3))
#define PMD_SIZE	(1UL << PMD_SHIFT)
#define PMD_MASK	(~(PMD_SIZE-1))


#define PGDIR_SHIFT	(PMD_SHIFT + (PAGE_SHIFT + PMD_ORDER - 3))
#endif
#define PGDIR_SIZE	(1UL << PGDIR_SHIFT)
#define PGDIR_MASK	(~(PGDIR_SIZE-1))

#ifdef CONFIG_PAGE_SIZE_4KB
#define PGD_ORDER		1
#define PUD_ORDER		aieeee_attempt_to_allocate_pud
#define PMD_ORDER		0
#define PTE_ORDER		0
#endif
#ifdef CONFIG_PAGE_SIZE_8KB
#define PGD_ORDER		0
#define PUD_ORDER		aieeee_attempt_to_allocate_pud
#define PMD_ORDER		0
#define PTE_ORDER		0
#endif
#ifdef CONFIG_PAGE_SIZE_16KB
#define PGD_ORDER		0
#define PUD_ORDER		aieeee_attempt_to_allocate_pud
#define PMD_ORDER		0
#define PTE_ORDER		0
#endif
#ifdef CONFIG_PAGE_SIZE_32KB
#define PGD_ORDER		0
#define PUD_ORDER		aieeee_attempt_to_allocate_pud
#define PMD_ORDER		0
#define PTE_ORDER		0
#endif
#ifdef CONFIG_PAGE_SIZE_64KB
#define PGD_ORDER		0
#define PUD_ORDER		aieeee_attempt_to_allocate_pud
#define PMD_ORDER		aieeee_attempt_to_allocate_pmd
#define PTE_ORDER		0
#endif

#define PTRS_PER_PGD	((PAGE_SIZE << PGD_ORDER) / sizeof(pgd_t))
#ifndef __PAGETABLE_PMD_FOLDED
#define PTRS_PER_PMD	((PAGE_SIZE << PMD_ORDER) / sizeof(pmd_t))
#endif
#define PTRS_PER_PTE	((PAGE_SIZE << PTE_ORDER) / sizeof(pte_t))

#if PGDIR_SIZE >= TASK_SIZE
#define USER_PTRS_PER_PGD       (1)
#else
#define USER_PTRS_PER_PGD	(TASK_SIZE / PGDIR_SIZE)
#endif
#define FIRST_USER_ADDRESS	0UL

#define VMALLOC_START		(MAP_BASE + (2 * PAGE_SIZE))
#define VMALLOC_END	\
	(MAP_BASE + \
	 min(PTRS_PER_PGD * PTRS_PER_PMD * PTRS_PER_PTE * PAGE_SIZE, \
	     (1UL << cpu_vmbits)) - (1UL << 32))

#if defined(CONFIG_MODULES) && defined(KBUILD_64BIT_SYM32) && \
	VMALLOC_START != CKSSEG
/* Load modules into 32bit-compatible segment. */
#define MODULE_START	CKSSEG
#define MODULE_END	(FIXADDR_START-2*PAGE_SIZE)
#endif

#define pte_ERROR(e) \
	printk("%s:%d: bad pte %016lx.\n", __FILE__, __LINE__, pte_val(e))
#ifndef __PAGETABLE_PMD_FOLDED
#define pmd_ERROR(e) \
	printk("%s:%d: bad pmd %016lx.\n", __FILE__, __LINE__, pmd_val(e))
#endif
#define pgd_ERROR(e) \
	printk("%s:%d: bad pgd %016lx.\n", __FILE__, __LINE__, pgd_val(e))

extern pte_t invalid_pte_table[PTRS_PER_PTE];
extern pte_t empty_bad_page_table[PTRS_PER_PTE];


#ifndef __PAGETABLE_PMD_FOLDED
typedef struct { unsigned long pmd; } pmd_t;
#define pmd_val(x)	((x).pmd)
#define __pmd(x)	((pmd_t) { (x) } )


extern pmd_t invalid_pmd_table[PTRS_PER_PMD];
extern pmd_t empty_bad_pmd_table[PTRS_PER_PMD];
#endif

static inline int pmd_none(pmd_t pmd)
{
	return pmd_val(pmd) == (unsigned long) invalid_pte_table;
}

#define pmd_bad(pmd)		(pmd_val(pmd) & ~PAGE_MASK)

static inline int pmd_present(pmd_t pmd)
{
	return pmd_val(pmd) != (unsigned long) invalid_pte_table;
}

static inline void pmd_clear(pmd_t *pmdp)
{
	pmd_val(*pmdp) = ((unsigned long) invalid_pte_table);
}
#ifndef __PAGETABLE_PMD_FOLDED

static inline int pud_none(pud_t pud)
{
	return pud_val(pud) == (unsigned long) invalid_pmd_table;
}

static inline int pud_bad(pud_t pud)
{
	return pud_val(pud) & ~PAGE_MASK;
}

static inline int pud_present(pud_t pud)
{
	return pud_val(pud) != (unsigned long) invalid_pmd_table;
}

static inline void pud_clear(pud_t *pudp)
{
	pud_val(*pudp) = ((unsigned long) invalid_pmd_table);
}
#endif

#define pte_page(x)		pfn_to_page(pte_pfn(x))

#ifdef CONFIG_CPU_VR41XX
#define pte_pfn(x)		((unsigned long)((x).pte >> (PAGE_SHIFT + 2)))
#define pfn_pte(pfn, prot)	__pte(((pfn) << (PAGE_SHIFT + 2)) | pgprot_val(prot))
#else
#define pte_pfn(x)		((unsigned long)((x).pte >> _PFN_SHIFT))
#define pfn_pte(pfn, prot)	__pte(((pfn) << _PFN_SHIFT) | pgprot_val(prot))
#endif

#define __pgd_offset(address)	pgd_index(address)
#define __pud_offset(address)	(((address) >> PUD_SHIFT) & (PTRS_PER_PUD-1))
#define __pmd_offset(address)	pmd_index(address)

/* to find an entry in a kernel page-table-directory */
#define pgd_offset_k(address) pgd_offset(&init_mm, address)

#define pgd_index(address)	(((address) >> PGDIR_SHIFT) & (PTRS_PER_PGD-1))
#define pmd_index(address)	(((address) >> PMD_SHIFT) & (PTRS_PER_PMD-1))

/* to find an entry in a page-table-directory */
#define pgd_offset(mm, addr)	((mm)->pgd + pgd_index(addr))

#ifndef __PAGETABLE_PMD_FOLDED
static inline unsigned long pud_page_vaddr(pud_t pud)
{
	return pud_val(pud);
}
#define pud_phys(pud)		virt_to_phys((void *)pud_val(pud))
#define pud_page(pud)		(pfn_to_page(pud_phys(pud) >> PAGE_SHIFT))

/* Find an entry in the second-level page table.. */
static inline pmd_t *pmd_offset(pud_t * pud, unsigned long address)
{
	return (pmd_t *) pud_page_vaddr(*pud) + pmd_index(address);
}
#endif

/* Find an entry in the third-level page table.. */
#define __pte_offset(address)						\
	(((address) >> PAGE_SHIFT) & (PTRS_PER_PTE - 1))
#define pte_offset(dir, address)					\
	((pte_t *) pmd_page_vaddr(*(dir)) + __pte_offset(address))
#define pte_offset_kernel(dir, address)					\
	((pte_t *) pmd_page_vaddr(*(dir)) + __pte_offset(address))
#define pte_offset_map(dir, address)					\
	((pte_t *)page_address(pmd_page(*(dir))) + __pte_offset(address))
#define pte_offset_map_nested(dir, address)				\
	((pte_t *)page_address(pmd_page(*(dir))) + __pte_offset(address))
#define pte_unmap(pte) ((void)(pte))
#define pte_unmap_nested(pte) ((void)(pte))

extern void pgd_init(unsigned long page);
extern void pmd_init(unsigned long page, unsigned long pagetable);

static inline pte_t mk_swap_pte(unsigned long type, unsigned long offset)
{ pte_t pte; pte_val(pte) = (type << 32) | (offset << 40); return pte; }

#define __swp_type(x)		(((x).val >> 32) & 0xff)
#define __swp_offset(x)		((x).val >> 40)
#define __swp_entry(type, offset) ((swp_entry_t) { pte_val(mk_swap_pte((type), (offset))) })
#define __pte_to_swp_entry(pte)	((swp_entry_t) { pte_val(pte) })
#define __swp_entry_to_pte(x)	((pte_t) { (x).val })

#define PTE_FILE_MAX_BITS	56

#define pte_to_pgoff(_pte)	((_pte).pte >> 8)
#define pgoff_to_pte(off)	((pte_t) { ((off) << 8) | _PAGE_FILE })

#endif /* _ASM_PGTABLE_64_H */
