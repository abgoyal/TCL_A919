#ifndef _ASM_MC146818RTC_H
#define _ASM_MC146818RTC_H

#include <asm/arch/irqs.h>
#include <asm/io.h>

#ifndef RTC_PORT
#define RTC_PORT(x)	(0x70 + (x))
#define RTC_ALWAYS_BCD	1	/* RTC operates in binary mode */
#endif

#define CMOS_READ(addr) ({ \
outb_p((addr),RTC_PORT(0)); \
inb_p(RTC_PORT(1)); \
})
#define CMOS_WRITE(val, addr) ({ \
outb_p((addr),RTC_PORT(0)); \
outb_p((val),RTC_PORT(1)); \
})

#endif /* _ASM_MC146818RTC_H */
