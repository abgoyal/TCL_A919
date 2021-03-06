

#ifndef __ARCH_ARM_STMX3XXX_CLOCK_H__
#define __ARCH_ARM_STMX3XXX_CLOCK_H__

#ifndef __ASSEMBLER__

struct clk_ops {
	int (*enable) (struct clk *);
	int (*disable) (struct clk *);
	long (*get_rate) (struct clk *);
	long (*round_rate) (struct clk *, u32);
	int (*set_rate) (struct clk *, u32);
	int (*set_parent) (struct clk *, struct clk *);
};

struct clk {
	struct clk *parent;
	u32 rate;
	u32 flags;
	u8 scale_shift;
	u8 enable_shift;
	u8 bypass_shift;
	u8 busy_bit;
	s8 usage;
	int enable_wait;
	int enable_negate;
	u32 saved_div;
	void __iomem *enable_reg;
	void __iomem *scale_reg;
	void __iomem *bypass_reg;
	void __iomem *busy_reg;
	struct clk_ops *ops;
};

#endif /* __ASSEMBLER__ */

/* Flags */
#define RATE_PROPAGATES      (1<<0)
#define NEEDS_INITIALIZATION (1<<1)
#define PARENT_SET_RATE      (1<<2)
#define FIXED_RATE           (1<<3)
#define ENABLED	             (1<<4)
#define NEEDS_SET_PARENT     (1<<5)

#endif
