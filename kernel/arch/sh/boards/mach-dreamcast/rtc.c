

#include <linux/time.h>
#include <asm/rtc.h>
#include <asm/io.h>

#define TWENTY_YEARS ((20 * 365LU + 5) * 86400)

#define AICA_RTC_SECS_H		0xa0710000
#define AICA_RTC_SECS_L		0xa0710004

static void aica_rtc_gettimeofday(struct timespec *ts)
{
	unsigned long val1, val2;

	do {
		val1 = ((__raw_readl(AICA_RTC_SECS_H) & 0xffff) << 16) |
			(__raw_readl(AICA_RTC_SECS_L) & 0xffff);

		val2 = ((__raw_readl(AICA_RTC_SECS_H) & 0xffff) << 16) |
			(__raw_readl(AICA_RTC_SECS_L) & 0xffff);
	} while (val1 != val2);

	ts->tv_sec = val1 - TWENTY_YEARS;

	/* Can't get nanoseconds with just a seconds counter. */
	ts->tv_nsec = 0;
}

static int aica_rtc_settimeofday(const time_t secs)
{
	unsigned long val1, val2;
	unsigned long adj = secs + TWENTY_YEARS;

	do {
		__raw_writel((adj & 0xffff0000) >> 16, AICA_RTC_SECS_H);
		__raw_writel((adj & 0xffff), AICA_RTC_SECS_L);

		val1 = ((__raw_readl(AICA_RTC_SECS_H) & 0xffff) << 16) |
			(__raw_readl(AICA_RTC_SECS_L) & 0xffff);

		val2 = ((__raw_readl(AICA_RTC_SECS_H) & 0xffff) << 16) |
			(__raw_readl(AICA_RTC_SECS_L) & 0xffff);
	} while (val1 != val2);

	return 0;
}

void aica_time_init(void)
{
	rtc_sh_get_time = aica_rtc_gettimeofday;
	rtc_sh_set_time = aica_rtc_settimeofday;
}

