

#ifndef __ARCH_ARM_MACH_OMAP2_CM_REGBITS_44XX_H
#define __ARCH_ARM_MACH_OMAP2_CM_REGBITS_44XX_H

#include "cm.h"


/* Used by CM_L3_1_DYNAMICDEP, CM_MPU_DYNAMICDEP, CM_TESLA_DYNAMICDEP */
#define OMAP4430_ABE_DYNDEP_SHIFT				3
#define OMAP4430_ABE_DYNDEP_MASK				BITFIELD(3, 3)

#define OMAP4430_ABE_STATDEP_SHIFT				3
#define OMAP4430_ABE_STATDEP_MASK				BITFIELD(3, 3)

/* Used by CM_L4CFG_DYNAMICDEP */
#define OMAP4430_ALWONCORE_DYNDEP_SHIFT				16
#define OMAP4430_ALWONCORE_DYNDEP_MASK				BITFIELD(16, 16)

/* Used by CM_DUCATI_STATICDEP, CM_MPU_STATICDEP, CM_TESLA_STATICDEP */
#define OMAP4430_ALWONCORE_STATDEP_SHIFT			16
#define OMAP4430_ALWONCORE_STATDEP_MASK				BITFIELD(16, 16)

#define OMAP4430_AUTO_DPLL_MODE_SHIFT				0
#define OMAP4430_AUTO_DPLL_MODE_MASK				BITFIELD(0, 2)

/* Used by CM_L4CFG_DYNAMICDEP */
#define OMAP4430_CEFUSE_DYNDEP_SHIFT				17
#define OMAP4430_CEFUSE_DYNDEP_MASK				BITFIELD(17, 17)

/* Used by CM_DUCATI_STATICDEP, CM_MPU_STATICDEP, CM_TESLA_STATICDEP */
#define OMAP4430_CEFUSE_STATDEP_SHIFT				17
#define OMAP4430_CEFUSE_STATDEP_MASK				BITFIELD(17, 17)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ABE_24M_GFCLK_SHIFT		13
#define OMAP4430_CLKACTIVITY_ABE_24M_GFCLK_MASK			BITFIELD(13, 13)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ABE_ALWON_32K_CLK_SHIFT		12
#define OMAP4430_CLKACTIVITY_ABE_ALWON_32K_CLK_MASK		BITFIELD(12, 12)

/* Used by CM_WKUP_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ABE_LP_CLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_ABE_LP_CLK_MASK			BITFIELD(9, 9)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ABE_SYSCLK_SHIFT			11
#define OMAP4430_CLKACTIVITY_ABE_SYSCLK_MASK			BITFIELD(11, 11)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ABE_X2_CLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_ABE_X2_CLK_MASK			BITFIELD(8, 8)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_ASYNC_DLL_CLK_SHIFT		11
#define OMAP4430_CLKACTIVITY_ASYNC_DLL_CLK_MASK			BITFIELD(11, 11)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_ASYNC_PHY1_CLK_SHIFT		12
#define OMAP4430_CLKACTIVITY_ASYNC_PHY1_CLK_MASK		BITFIELD(12, 12)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_ASYNC_PHY2_CLK_SHIFT		13
#define OMAP4430_CLKACTIVITY_ASYNC_PHY2_CLK_MASK		BITFIELD(13, 13)

/* Used by CM_CAM_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_CAM_PHY_CTRL_GCLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_CAM_PHY_CTRL_GCLK_MASK		BITFIELD(9, 9)

/* Used by CM_EMU_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_CORE_DPLL_EMU_CLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_CORE_DPLL_EMU_CLK_MASK		BITFIELD(9, 9)

/* Used by CM_CEFUSE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_CUST_EFUSE_SYS_CLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_CUST_EFUSE_SYS_CLK_MASK		BITFIELD(9, 9)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DLL_CLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_DLL_CLK_MASK			BITFIELD(9, 9)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT10_GFCLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_DMT10_GFCLK_MASK			BITFIELD(9, 9)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT11_GFCLK_SHIFT			10
#define OMAP4430_CLKACTIVITY_DMT11_GFCLK_MASK			BITFIELD(10, 10)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT2_GFCLK_SHIFT			11
#define OMAP4430_CLKACTIVITY_DMT2_GFCLK_MASK			BITFIELD(11, 11)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT3_GFCLK_SHIFT			12
#define OMAP4430_CLKACTIVITY_DMT3_GFCLK_MASK			BITFIELD(12, 12)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT4_GFCLK_SHIFT			13
#define OMAP4430_CLKACTIVITY_DMT4_GFCLK_MASK			BITFIELD(13, 13)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_DMT9_GFCLK_SHIFT			14
#define OMAP4430_CLKACTIVITY_DMT9_GFCLK_MASK			BITFIELD(14, 14)

/* Used by CM_DSS_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_DSS_ALWON_SYS_CLK_SHIFT		10
#define OMAP4430_CLKACTIVITY_DSS_ALWON_SYS_CLK_MASK		BITFIELD(10, 10)

/* Used by CM_DSS_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_DSS_FCLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_DSS_FCLK_MASK			BITFIELD(9, 9)

/* Used by CM_DUCATI_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_DUCATI_GCLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_DUCATI_GCLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_EMAC_50MHZ_CLK_SHIFT		10
#define OMAP4430_CLKACTIVITY_EMAC_50MHZ_CLK_MASK		BITFIELD(10, 10)

/* Used by CM_EMU_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_EMU_SYS_CLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_EMU_SYS_CLK_MASK			BITFIELD(8, 8)

/* Used by CM_CAM_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_FDIF_GFCLK_SHIFT			10
#define OMAP4430_CLKACTIVITY_FDIF_GFCLK_MASK			BITFIELD(10, 10)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_FUNC_12M_GFCLK_SHIFT		15
#define OMAP4430_CLKACTIVITY_FUNC_12M_GFCLK_MASK		BITFIELD(15, 15)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_FUNC_24M_GFCLK_SHIFT		10
#define OMAP4430_CLKACTIVITY_FUNC_24M_GFCLK_MASK		BITFIELD(10, 10)

/* Used by CM_DSS_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_HDMI_PHY_48MHZ_GFCLK_SHIFT		11
#define OMAP4430_CLKACTIVITY_HDMI_PHY_48MHZ_GFCLK_MASK		BITFIELD(11, 11)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_HSIC_P1_480M_GFCLK_SHIFT		20
#define OMAP4430_CLKACTIVITY_HSIC_P1_480M_GFCLK_MASK		BITFIELD(20, 20)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_HSIC_P1_GFCLK_SHIFT		26
#define OMAP4430_CLKACTIVITY_HSIC_P1_GFCLK_MASK			BITFIELD(26, 26)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_HSIC_P2_480M_GFCLK_SHIFT		21
#define OMAP4430_CLKACTIVITY_HSIC_P2_480M_GFCLK_MASK		BITFIELD(21, 21)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_HSIC_P2_GFCLK_SHIFT		27
#define OMAP4430_CLKACTIVITY_HSIC_P2_GFCLK_MASK			BITFIELD(27, 27)

/* Used by CM_L3INIT_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_INIT_32K_GFCLK_SHIFT		31
#define OMAP4430_CLKACTIVITY_INIT_32K_GFCLK_MASK		BITFIELD(31, 31)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_48MC_GFCLK_SHIFT		13
#define OMAP4430_CLKACTIVITY_INIT_48MC_GFCLK_MASK		BITFIELD(13, 13)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_48M_GFCLK_SHIFT		12
#define OMAP4430_CLKACTIVITY_INIT_48M_GFCLK_MASK		BITFIELD(12, 12)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_60M_P1_GFCLK_SHIFT		28
#define OMAP4430_CLKACTIVITY_INIT_60M_P1_GFCLK_MASK		BITFIELD(28, 28)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_60M_P2_GFCLK_SHIFT		29
#define OMAP4430_CLKACTIVITY_INIT_60M_P2_GFCLK_MASK		BITFIELD(29, 29)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_96M_GFCLK_SHIFT		11
#define OMAP4430_CLKACTIVITY_INIT_96M_GFCLK_MASK		BITFIELD(11, 11)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_HSI_GFCLK_SHIFT		16
#define OMAP4430_CLKACTIVITY_INIT_HSI_GFCLK_MASK		BITFIELD(16, 16)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_HSMMC1_GFCLK_SHIFT		17
#define OMAP4430_CLKACTIVITY_INIT_HSMMC1_GFCLK_MASK		BITFIELD(17, 17)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_HSMMC2_GFCLK_SHIFT		18
#define OMAP4430_CLKACTIVITY_INIT_HSMMC2_GFCLK_MASK		BITFIELD(18, 18)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_INIT_HSMMC6_GFCLK_SHIFT		19
#define OMAP4430_CLKACTIVITY_INIT_HSMMC6_GFCLK_MASK		BITFIELD(19, 19)

/* Used by CM_CAM_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_ISS_GCLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_ISS_GCLK_MASK			BITFIELD(8, 8)

/* Used by CM_IVAHD_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_IVAHD_ROOT_CLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_IVAHD_ROOT_CLK_MASK		BITFIELD(8, 8)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L3INIT_DPLL_ALWON_CLK_SHIFT	14
#define OMAP4430_CLKACTIVITY_L3INIT_DPLL_ALWON_CLK_MASK		BITFIELD(14, 14)

/* Used by CM_L3_1_CLKSTCTRL, CM_L3_1_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L3_1_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_1_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3_2_CLKSTCTRL, CM_L3_2_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L3_2_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_2_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_D2D_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_D2D_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_D2D_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_SDMA_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_DMA_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_DMA_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_DSS_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_DSS_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_DSS_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L3_EMIF_GICLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_L3_EMIF_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_GFX_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_GFX_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L3_GFX_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L3_INIT_GICLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_L3_INIT_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INSTR_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_INSTR_GICLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_L3_INSTR_GICLK_MASK		BITFIELD(8, 8)

/* Used by CM_L4SEC_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L3_SECURE_GICLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_L3_SECURE_GICLK_MASK		BITFIELD(8, 8)

/* Used by CM_ALWON_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L4_AO_ICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L4_AO_ICLK_MASK			BITFIELD(8, 8)

/* Used by CM_CEFUSE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L4_CEFUSE_GICLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_L4_CEFUSE_GICLK_MASK		BITFIELD(8, 8)

/* Used by CM_L4CFG_CLKSTCTRL, CM_L4CFG_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L4_CFG_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L4_CFG_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_D2D_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L4_D2D_GICLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_L4_D2D_GICLK_MASK			BITFIELD(9, 9)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L4_INIT_GICLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_L4_INIT_GICLK_MASK			BITFIELD(9, 9)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_L4_PER_GICLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_L4_PER_GICLK_MASK			BITFIELD(8, 8)

/* Used by CM_L4SEC_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L4_SECURE_GICLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_L4_SECURE_GICLK_MASK		BITFIELD(9, 9)

/* Used by CM_WKUP_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_L4_WKUP_GICLK_SHIFT		12
#define OMAP4430_CLKACTIVITY_L4_WKUP_GICLK_MASK			BITFIELD(12, 12)

/* Used by CM_MPU_CLKSTCTRL, CM_MPU_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_MPU_DPLL_CLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_MPU_DPLL_CLK_MASK			BITFIELD(8, 8)

/* Used by CM1_ABE_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_OCP_ABE_GICLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_OCP_ABE_GICLK_MASK			BITFIELD(9, 9)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_24MC_GFCLK_SHIFT		16
#define OMAP4430_CLKACTIVITY_PER_24MC_GFCLK_MASK		BITFIELD(16, 16)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_32K_GFCLK_SHIFT		17
#define OMAP4430_CLKACTIVITY_PER_32K_GFCLK_MASK			BITFIELD(17, 17)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_48M_GFCLK_SHIFT		18
#define OMAP4430_CLKACTIVITY_PER_48M_GFCLK_MASK			BITFIELD(18, 18)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_96M_GFCLK_SHIFT		19
#define OMAP4430_CLKACTIVITY_PER_96M_GFCLK_MASK			BITFIELD(19, 19)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_ABE_24M_GFCLK_SHIFT		25
#define OMAP4430_CLKACTIVITY_PER_ABE_24M_GFCLK_MASK		BITFIELD(25, 25)

/* Used by CM_EMU_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_PER_DPLL_EMU_CLK_SHIFT		10
#define OMAP4430_CLKACTIVITY_PER_DPLL_EMU_CLK_MASK		BITFIELD(10, 10)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_MCASP2_GFCLK_SHIFT		20
#define OMAP4430_CLKACTIVITY_PER_MCASP2_GFCLK_MASK		BITFIELD(20, 20)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_MCASP3_GFCLK_SHIFT		21
#define OMAP4430_CLKACTIVITY_PER_MCASP3_GFCLK_MASK		BITFIELD(21, 21)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_MCBSP4_GFCLK_SHIFT		22
#define OMAP4430_CLKACTIVITY_PER_MCBSP4_GFCLK_MASK		BITFIELD(22, 22)

/* Used by CM_L4PER_CLKSTCTRL, CM_L4PER_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PER_SYS_GFCLK_SHIFT		24
#define OMAP4430_CLKACTIVITY_PER_SYS_GFCLK_MASK			BITFIELD(24, 24)

/* Used by CM_MEMIF_CLKSTCTRL, CM_MEMIF_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_PHY_ROOT_CLK_SHIFT			10
#define OMAP4430_CLKACTIVITY_PHY_ROOT_CLK_MASK			BITFIELD(10, 10)

/* Used by CM_GFX_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_SGX_GFCLK_SHIFT			9
#define OMAP4430_CLKACTIVITY_SGX_GFCLK_MASK			BITFIELD(9, 9)

/* Used by CM_ALWON_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_SR_CORE_SYSCLK_SHIFT		11
#define OMAP4430_CLKACTIVITY_SR_CORE_SYSCLK_MASK		BITFIELD(11, 11)

/* Used by CM_ALWON_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_SR_IVA_SYSCLK_SHIFT		10
#define OMAP4430_CLKACTIVITY_SR_IVA_SYSCLK_MASK			BITFIELD(10, 10)

/* Used by CM_ALWON_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_SR_MPU_SYSCLK_SHIFT		9
#define OMAP4430_CLKACTIVITY_SR_MPU_SYSCLK_MASK			BITFIELD(9, 9)

/* Used by CM_WKUP_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_SYS_CLK_SHIFT			8
#define OMAP4430_CLKACTIVITY_SYS_CLK_MASK			BITFIELD(8, 8)

/* Used by CM_TESLA_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_TESLA_ROOT_CLK_SHIFT		8
#define OMAP4430_CLKACTIVITY_TESLA_ROOT_CLK_MASK		BITFIELD(8, 8)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_TLL_CH0_GFCLK_SHIFT		22
#define OMAP4430_CLKACTIVITY_TLL_CH0_GFCLK_MASK			BITFIELD(22, 22)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_TLL_CH1_GFCLK_SHIFT		23
#define OMAP4430_CLKACTIVITY_TLL_CH1_GFCLK_MASK			BITFIELD(23, 23)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_TLL_CH2_GFCLK_SHIFT		24
#define OMAP4430_CLKACTIVITY_TLL_CH2_GFCLK_MASK			BITFIELD(24, 24)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_USB_DPLL_HS_CLK_SHIFT		15
#define OMAP4430_CLKACTIVITY_USB_DPLL_HS_CLK_MASK		BITFIELD(15, 15)

/* Used by CM_WKUP_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_USIM_GFCLK_SHIFT			10
#define OMAP4430_CLKACTIVITY_USIM_GFCLK_MASK			BITFIELD(10, 10)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_UTMI_P3_GFCLK_SHIFT		30
#define OMAP4430_CLKACTIVITY_UTMI_P3_GFCLK_MASK			BITFIELD(30, 30)

/* Used by CM_L3INIT_CLKSTCTRL, CM_L3INIT_CLKSTCTRL_RESTORE */
#define OMAP4430_CLKACTIVITY_UTMI_ROOT_GFCLK_SHIFT		25
#define OMAP4430_CLKACTIVITY_UTMI_ROOT_GFCLK_MASK		BITFIELD(25, 25)

/* Used by CM_WKUP_CLKSTCTRL */
#define OMAP4430_CLKACTIVITY_WKUP_32K_GFCLK_SHIFT		11
#define OMAP4430_CLKACTIVITY_WKUP_32K_GFCLK_MASK		BITFIELD(11, 11)

#define OMAP4430_CLKSEL_SHIFT					24
#define OMAP4430_CLKSEL_MASK					BITFIELD(24, 24)

#define OMAP4430_CLKSEL_0_0_SHIFT				0
#define OMAP4430_CLKSEL_0_0_MASK				BITFIELD(0, 0)

/* Renamed from CLKSEL Used by CM_BYPCLK_DPLL_IVA, CM_BYPCLK_DPLL_MPU */
#define OMAP4430_CLKSEL_0_1_SHIFT				0
#define OMAP4430_CLKSEL_0_1_MASK				BITFIELD(0, 1)

/* Renamed from CLKSEL Used by CM_L3INIT_HSI_CLKCTRL */
#define OMAP4430_CLKSEL_24_25_SHIFT				24
#define OMAP4430_CLKSEL_24_25_MASK				BITFIELD(24, 25)

/* Used by CM_L3INIT_USB_OTG_CLKCTRL */
#define OMAP4430_CLKSEL_60M_SHIFT				24
#define OMAP4430_CLKSEL_60M_MASK				BITFIELD(24, 24)

/* Used by CM1_ABE_AESS_CLKCTRL */
#define OMAP4430_CLKSEL_AESS_FCLK_SHIFT				24
#define OMAP4430_CLKSEL_AESS_FCLK_MASK				BITFIELD(24, 24)

/* Used by CM_CLKSEL_CORE_RESTORE, CM_CLKSEL_CORE */
#define OMAP4430_CLKSEL_CORE_SHIFT				0
#define OMAP4430_CLKSEL_CORE_MASK				BITFIELD(0, 0)

/* Renamed from CLKSEL_CORE Used by CM_SHADOW_FREQ_CONFIG2 */
#define OMAP4430_CLKSEL_CORE_1_1_SHIFT				1
#define OMAP4430_CLKSEL_CORE_1_1_MASK				BITFIELD(1, 1)

/* Used by CM_WKUP_USIM_CLKCTRL */
#define OMAP4430_CLKSEL_DIV_SHIFT				24
#define OMAP4430_CLKSEL_DIV_MASK				BITFIELD(24, 24)

/* Used by CM_CAM_FDIF_CLKCTRL */
#define OMAP4430_CLKSEL_FCLK_SHIFT				24
#define OMAP4430_CLKSEL_FCLK_MASK				BITFIELD(24, 25)

/* Used by CM_L4PER_MCBSP4_CLKCTRL */
#define OMAP4430_CLKSEL_INTERNAL_SOURCE_SHIFT			25
#define OMAP4430_CLKSEL_INTERNAL_SOURCE_MASK			BITFIELD(25, 25)

#define OMAP4430_CLKSEL_INTERNAL_SOURCE_CM1_ABE_DMIC_SHIFT	26
#define OMAP4430_CLKSEL_INTERNAL_SOURCE_CM1_ABE_DMIC_MASK	BITFIELD(26, 27)

/* Used by CM_CLKSEL_CORE_RESTORE, CM_CLKSEL_CORE */
#define OMAP4430_CLKSEL_L3_SHIFT				4
#define OMAP4430_CLKSEL_L3_MASK					BITFIELD(4, 4)

/* Renamed from CLKSEL_L3 Used by CM_SHADOW_FREQ_CONFIG2 */
#define OMAP4430_CLKSEL_L3_SHADOW_SHIFT				2
#define OMAP4430_CLKSEL_L3_SHADOW_MASK				BITFIELD(2, 2)

/* Used by CM_CLKSEL_CORE_RESTORE, CM_CLKSEL_CORE */
#define OMAP4430_CLKSEL_L4_SHIFT				8
#define OMAP4430_CLKSEL_L4_MASK					BITFIELD(8, 8)

/* Used by CM_CLKSEL_ABE */
#define OMAP4430_CLKSEL_OPP_SHIFT				0
#define OMAP4430_CLKSEL_OPP_MASK				BITFIELD(0, 1)

/* Used by CM_GFX_GFX_CLKCTRL */
#define OMAP4430_CLKSEL_PER_192M_SHIFT				25
#define OMAP4430_CLKSEL_PER_192M_MASK				BITFIELD(25, 26)

/* Used by CM_EMU_DEBUGSS_CLKCTRL */
#define OMAP4430_CLKSEL_PMD_STM_CLK_SHIFT			27
#define OMAP4430_CLKSEL_PMD_STM_CLK_MASK			BITFIELD(27, 29)

/* Used by CM_EMU_DEBUGSS_CLKCTRL */
#define OMAP4430_CLKSEL_PMD_TRACE_CLK_SHIFT			24
#define OMAP4430_CLKSEL_PMD_TRACE_CLK_MASK			BITFIELD(24, 26)

/* Used by CM_GFX_GFX_CLKCTRL */
#define OMAP4430_CLKSEL_SGX_FCLK_SHIFT				24
#define OMAP4430_CLKSEL_SGX_FCLK_MASK				BITFIELD(24, 24)

#define OMAP4430_CLKSEL_SOURCE_SHIFT				24
#define OMAP4430_CLKSEL_SOURCE_MASK				BITFIELD(24, 25)

/* Renamed from CLKSEL_SOURCE Used by CM_L4PER_MCBSP4_CLKCTRL */
#define OMAP4430_CLKSEL_SOURCE_24_24_SHIFT			24
#define OMAP4430_CLKSEL_SOURCE_24_24_MASK			BITFIELD(24, 24)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_CLKSEL_UTMI_P1_SHIFT				24
#define OMAP4430_CLKSEL_UTMI_P1_MASK				BITFIELD(24, 24)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_CLKSEL_UTMI_P2_SHIFT				25
#define OMAP4430_CLKSEL_UTMI_P2_MASK				BITFIELD(25, 25)

#define OMAP4430_CLKTRCTRL_SHIFT				0
#define OMAP4430_CLKTRCTRL_MASK					BITFIELD(0, 1)

/* Used by CM_EMU_OVERRIDE_DPLL_CORE */
#define OMAP4430_CORE_DPLL_EMU_DIV_SHIFT			0
#define OMAP4430_CORE_DPLL_EMU_DIV_MASK				BITFIELD(0, 6)

/* Used by CM_EMU_OVERRIDE_DPLL_CORE */
#define OMAP4430_CORE_DPLL_EMU_MULT_SHIFT			8
#define OMAP4430_CORE_DPLL_EMU_MULT_MASK			BITFIELD(8, 18)

/* Used by CM_L3_2_DYNAMICDEP, CM_L4CFG_DYNAMICDEP */
#define OMAP4430_D2D_DYNDEP_SHIFT				18
#define OMAP4430_D2D_DYNDEP_MASK				BITFIELD(18, 18)

/* Used by CM_MPU_STATICDEP */
#define OMAP4430_D2D_STATDEP_SHIFT				18
#define OMAP4430_D2D_STATDEP_MASK				BITFIELD(18, 18)

#define OMAP4430_DELTAMSTEP_SHIFT				0
#define OMAP4430_DELTAMSTEP_MASK				BITFIELD(0, 19)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_DLL_OVERRIDE_SHIFT				2
#define OMAP4430_DLL_OVERRIDE_MASK				BITFIELD(2, 2)

/* Renamed from DLL_OVERRIDE Used by CM_DLL_CTRL */
#define OMAP4430_DLL_OVERRIDE_0_0_SHIFT				0
#define OMAP4430_DLL_OVERRIDE_0_0_MASK				BITFIELD(0, 0)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_DLL_RESET_SHIFT				3
#define OMAP4430_DLL_RESET_MASK					BITFIELD(3, 3)

#define OMAP4430_DPLL_BYP_CLKSEL_SHIFT				23
#define OMAP4430_DPLL_BYP_CLKSEL_MASK				BITFIELD(23, 23)

/* Used by CM_CLKDCOLDO_DPLL_USB */
#define OMAP4430_DPLL_CLKDCOLDO_GATE_CTRL_SHIFT			8
#define OMAP4430_DPLL_CLKDCOLDO_GATE_CTRL_MASK			BITFIELD(8, 8)

/* Used by CM_CLKSEL_DPLL_CORE_RESTORE, CM_CLKSEL_DPLL_CORE */
#define OMAP4430_DPLL_CLKOUTHIF_CLKSEL_SHIFT			20
#define OMAP4430_DPLL_CLKOUTHIF_CLKSEL_MASK			BITFIELD(20, 20)

#define OMAP4430_DPLL_CLKOUTHIF_DIV_SHIFT			0
#define OMAP4430_DPLL_CLKOUTHIF_DIV_MASK			BITFIELD(0, 4)

#define OMAP4430_DPLL_CLKOUTHIF_DIVCHACK_SHIFT			5
#define OMAP4430_DPLL_CLKOUTHIF_DIVCHACK_MASK			BITFIELD(5, 5)

#define OMAP4430_DPLL_CLKOUTHIF_GATE_CTRL_SHIFT			8
#define OMAP4430_DPLL_CLKOUTHIF_GATE_CTRL_MASK			BITFIELD(8, 8)

/* Used by CM_DIV_M2_DPLL_PER, CM_DIV_M2_DPLL_UNIPRO, CM_DIV_M2_DPLL_ABE */
#define OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_SHIFT			10
#define OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK			BITFIELD(10, 10)

#define OMAP4430_DPLL_CLKOUT_DIV_SHIFT				0
#define OMAP4430_DPLL_CLKOUT_DIV_MASK				BITFIELD(0, 4)

/* Renamed from DPLL_CLKOUT_DIV Used by CM_DIV_M2_DPLL_USB */
#define OMAP4430_DPLL_CLKOUT_DIV_0_6_SHIFT			0
#define OMAP4430_DPLL_CLKOUT_DIV_0_6_MASK			BITFIELD(0, 6)

#define OMAP4430_DPLL_CLKOUT_DIVCHACK_SHIFT			5
#define OMAP4430_DPLL_CLKOUT_DIVCHACK_MASK			BITFIELD(5, 5)

/* Renamed from DPLL_CLKOUT_DIVCHACK Used by CM_DIV_M2_DPLL_USB */
#define OMAP4430_DPLL_CLKOUT_DIVCHACK_M2_USB_SHIFT		7
#define OMAP4430_DPLL_CLKOUT_DIVCHACK_M2_USB_MASK		BITFIELD(7, 7)

#define OMAP4430_DPLL_CLKOUT_GATE_CTRL_SHIFT			8
#define OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK			BITFIELD(8, 8)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_DPLL_CORE_DPLL_EN_SHIFT			8
#define OMAP4430_DPLL_CORE_DPLL_EN_MASK				BITFIELD(8, 10)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_DPLL_CORE_M2_DIV_SHIFT				11
#define OMAP4430_DPLL_CORE_M2_DIV_MASK				BITFIELD(11, 15)

/* Used by CM_SHADOW_FREQ_CONFIG2 */
#define OMAP4430_DPLL_CORE_M5_DIV_SHIFT				3
#define OMAP4430_DPLL_CORE_M5_DIV_MASK				BITFIELD(3, 7)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_DPLL_CORE_SYS_REF_CLKSEL_SHIFT			1
#define OMAP4430_DPLL_CORE_SYS_REF_CLKSEL_MASK			BITFIELD(1, 1)

#define OMAP4430_DPLL_DIV_SHIFT					0
#define OMAP4430_DPLL_DIV_MASK					BITFIELD(0, 6)

/* Renamed from DPLL_DIV Used by CM_CLKSEL_DPLL_USB */
#define OMAP4430_DPLL_DIV_0_7_SHIFT				0
#define OMAP4430_DPLL_DIV_0_7_MASK				BITFIELD(0, 7)

#define OMAP4430_DPLL_DRIFTGUARD_EN_SHIFT			8
#define OMAP4430_DPLL_DRIFTGUARD_EN_MASK			BITFIELD(8, 8)

/* Renamed from DPLL_DRIFTGUARD_EN Used by CM_CLKMODE_DPLL_UNIPRO */
#define OMAP4430_DPLL_DRIFTGUARD_EN_3_3_SHIFT			3
#define OMAP4430_DPLL_DRIFTGUARD_EN_3_3_MASK			BITFIELD(3, 3)

#define OMAP4430_DPLL_EN_SHIFT					0
#define OMAP4430_DPLL_EN_MASK					BITFIELD(0, 2)

#define OMAP4430_DPLL_LPMODE_EN_SHIFT				10
#define OMAP4430_DPLL_LPMODE_EN_MASK				BITFIELD(10, 10)

#define OMAP4430_DPLL_MULT_SHIFT				8
#define OMAP4430_DPLL_MULT_MASK					BITFIELD(8, 18)

/* Renamed from DPLL_MULT Used by CM_CLKSEL_DPLL_USB */
#define OMAP4430_DPLL_MULT_USB_SHIFT				8
#define OMAP4430_DPLL_MULT_USB_MASK				BITFIELD(8, 19)

#define OMAP4430_DPLL_REGM4XEN_SHIFT				11
#define OMAP4430_DPLL_REGM4XEN_MASK				BITFIELD(11, 11)

/* Used by CM_CLKSEL_DPLL_USB */
#define OMAP4430_DPLL_SD_DIV_SHIFT				24
#define OMAP4430_DPLL_SD_DIV_MASK				BITFIELD(24, 31)

#define OMAP4430_DPLL_SSC_ACK_SHIFT				13
#define OMAP4430_DPLL_SSC_ACK_MASK				BITFIELD(13, 13)

#define OMAP4430_DPLL_SSC_DOWNSPREAD_SHIFT			14
#define OMAP4430_DPLL_SSC_DOWNSPREAD_MASK			BITFIELD(14, 14)

#define OMAP4430_DPLL_SSC_EN_SHIFT				12
#define OMAP4430_DPLL_SSC_EN_MASK				BITFIELD(12, 12)

/* Used by CM_L3_2_DYNAMICDEP, CM_L4CFG_DYNAMICDEP, CM_L4PER_DYNAMICDEP */
#define OMAP4430_DSS_DYNDEP_SHIFT				8
#define OMAP4430_DSS_DYNDEP_MASK				BITFIELD(8, 8)

#define OMAP4430_DSS_STATDEP_SHIFT				8
#define OMAP4430_DSS_STATDEP_MASK				BITFIELD(8, 8)

/* Used by CM_L3_2_DYNAMICDEP */
#define OMAP4430_DUCATI_DYNDEP_SHIFT				0
#define OMAP4430_DUCATI_DYNDEP_MASK				BITFIELD(0, 0)

/* Used by CM_SDMA_STATICDEP, CM_SDMA_STATICDEP_RESTORE, CM_MPU_STATICDEP */
#define OMAP4430_DUCATI_STATDEP_SHIFT				0
#define OMAP4430_DUCATI_STATDEP_MASK				BITFIELD(0, 0)

/* Used by CM_SHADOW_FREQ_CONFIG1_RESTORE, CM_SHADOW_FREQ_CONFIG1 */
#define OMAP4430_FREQ_UPDATE_SHIFT				0
#define OMAP4430_FREQ_UPDATE_MASK				BITFIELD(0, 0)

/* Used by CM_L3_2_DYNAMICDEP */
#define OMAP4430_GFX_DYNDEP_SHIFT				10
#define OMAP4430_GFX_DYNDEP_MASK				BITFIELD(10, 10)

/* Used by CM_DUCATI_STATICDEP, CM_MPU_STATICDEP */
#define OMAP4430_GFX_STATDEP_SHIFT				10
#define OMAP4430_GFX_STATDEP_MASK				BITFIELD(10, 10)

/* Used by CM_SHADOW_FREQ_CONFIG2 */
#define OMAP4430_GPMC_FREQ_UPDATE_SHIFT				0
#define OMAP4430_GPMC_FREQ_UPDATE_MASK				BITFIELD(0, 0)

#define OMAP4430_HSDIVIDER_CLKOUT1_DIV_SHIFT			0
#define OMAP4430_HSDIVIDER_CLKOUT1_DIV_MASK			BITFIELD(0, 4)

#define OMAP4430_HSDIVIDER_CLKOUT1_DIVCHACK_SHIFT		5
#define OMAP4430_HSDIVIDER_CLKOUT1_DIVCHACK_MASK		BITFIELD(5, 5)

#define OMAP4430_HSDIVIDER_CLKOUT1_GATE_CTRL_SHIFT		8
#define OMAP4430_HSDIVIDER_CLKOUT1_GATE_CTRL_MASK		BITFIELD(8, 8)

#define OMAP4430_HSDIVIDER_CLKOUT1_PWDN_SHIFT			12
#define OMAP4430_HSDIVIDER_CLKOUT1_PWDN_MASK			BITFIELD(12, 12)

#define OMAP4430_HSDIVIDER_CLKOUT2_DIV_SHIFT			0
#define OMAP4430_HSDIVIDER_CLKOUT2_DIV_MASK			BITFIELD(0, 4)

#define OMAP4430_HSDIVIDER_CLKOUT2_DIVCHACK_SHIFT		5
#define OMAP4430_HSDIVIDER_CLKOUT2_DIVCHACK_MASK		BITFIELD(5, 5)

#define OMAP4430_HSDIVIDER_CLKOUT2_GATE_CTRL_SHIFT		8
#define OMAP4430_HSDIVIDER_CLKOUT2_GATE_CTRL_MASK		BITFIELD(8, 8)

#define OMAP4430_HSDIVIDER_CLKOUT2_PWDN_SHIFT			12
#define OMAP4430_HSDIVIDER_CLKOUT2_PWDN_MASK			BITFIELD(12, 12)

#define OMAP4430_HSDIVIDER_CLKOUT3_DIV_SHIFT			0
#define OMAP4430_HSDIVIDER_CLKOUT3_DIV_MASK			BITFIELD(0, 4)

#define OMAP4430_HSDIVIDER_CLKOUT3_DIVCHACK_SHIFT		5
#define OMAP4430_HSDIVIDER_CLKOUT3_DIVCHACK_MASK		BITFIELD(5, 5)

#define OMAP4430_HSDIVIDER_CLKOUT3_GATE_CTRL_SHIFT		8
#define OMAP4430_HSDIVIDER_CLKOUT3_GATE_CTRL_MASK		BITFIELD(8, 8)

#define OMAP4430_HSDIVIDER_CLKOUT3_PWDN_SHIFT			12
#define OMAP4430_HSDIVIDER_CLKOUT3_PWDN_MASK			BITFIELD(12, 12)

#define OMAP4430_HSDIVIDER_CLKOUT4_DIV_SHIFT			0
#define OMAP4430_HSDIVIDER_CLKOUT4_DIV_MASK			BITFIELD(0, 4)

#define OMAP4430_HSDIVIDER_CLKOUT4_DIVCHACK_SHIFT		5
#define OMAP4430_HSDIVIDER_CLKOUT4_DIVCHACK_MASK		BITFIELD(5, 5)

#define OMAP4430_HSDIVIDER_CLKOUT4_GATE_CTRL_SHIFT		8
#define OMAP4430_HSDIVIDER_CLKOUT4_GATE_CTRL_MASK		BITFIELD(8, 8)

#define OMAP4430_HSDIVIDER_CLKOUT4_PWDN_SHIFT			12
#define OMAP4430_HSDIVIDER_CLKOUT4_PWDN_MASK			BITFIELD(12, 12)

#define OMAP4430_IDLEST_SHIFT					16
#define OMAP4430_IDLEST_MASK					BITFIELD(16, 17)

/* Used by CM_DUCATI_DYNAMICDEP, CM_L3_2_DYNAMICDEP, CM_L4CFG_DYNAMICDEP */
#define OMAP4430_ISS_DYNDEP_SHIFT				9
#define OMAP4430_ISS_DYNDEP_MASK				BITFIELD(9, 9)

#define OMAP4430_ISS_STATDEP_SHIFT				9
#define OMAP4430_ISS_STATDEP_MASK				BITFIELD(9, 9)

/* Used by CM_L3_2_DYNAMICDEP, CM_TESLA_DYNAMICDEP */
#define OMAP4430_IVAHD_DYNDEP_SHIFT				2
#define OMAP4430_IVAHD_DYNDEP_MASK				BITFIELD(2, 2)

#define OMAP4430_IVAHD_STATDEP_SHIFT				2
#define OMAP4430_IVAHD_STATDEP_MASK				BITFIELD(2, 2)

/* Used by CM_L3_2_DYNAMICDEP, CM_L4CFG_DYNAMICDEP, CM_L4PER_DYNAMICDEP */
#define OMAP4430_L3INIT_DYNDEP_SHIFT				7
#define OMAP4430_L3INIT_DYNDEP_MASK				BITFIELD(7, 7)

#define OMAP4430_L3INIT_STATDEP_SHIFT				7
#define OMAP4430_L3INIT_STATDEP_MASK				BITFIELD(7, 7)

#define OMAP4430_L3_1_DYNDEP_SHIFT				5
#define OMAP4430_L3_1_DYNDEP_MASK				BITFIELD(5, 5)

#define OMAP4430_L3_1_STATDEP_SHIFT				5
#define OMAP4430_L3_1_STATDEP_MASK				BITFIELD(5, 5)

#define OMAP4430_L3_2_DYNDEP_SHIFT				6
#define OMAP4430_L3_2_DYNDEP_MASK				BITFIELD(6, 6)

#define OMAP4430_L3_2_STATDEP_SHIFT				6
#define OMAP4430_L3_2_STATDEP_MASK				BITFIELD(6, 6)

/* Used by CM_L3_1_DYNAMICDEP */
#define OMAP4430_L4CFG_DYNDEP_SHIFT				12
#define OMAP4430_L4CFG_DYNDEP_MASK				BITFIELD(12, 12)

#define OMAP4430_L4CFG_STATDEP_SHIFT				12
#define OMAP4430_L4CFG_STATDEP_MASK				BITFIELD(12, 12)

/* Used by CM_L3_2_DYNAMICDEP */
#define OMAP4430_L4PER_DYNDEP_SHIFT				13
#define OMAP4430_L4PER_DYNDEP_MASK				BITFIELD(13, 13)

#define OMAP4430_L4PER_STATDEP_SHIFT				13
#define OMAP4430_L4PER_STATDEP_MASK				BITFIELD(13, 13)

/* Used by CM_L3_2_DYNAMICDEP, CM_L4PER_DYNAMICDEP */
#define OMAP4430_L4SEC_DYNDEP_SHIFT				14
#define OMAP4430_L4SEC_DYNDEP_MASK				BITFIELD(14, 14)

#define OMAP4430_L4SEC_STATDEP_SHIFT				14
#define OMAP4430_L4SEC_STATDEP_MASK				BITFIELD(14, 14)

/* Used by CM_L4CFG_DYNAMICDEP */
#define OMAP4430_L4WKUP_DYNDEP_SHIFT				15
#define OMAP4430_L4WKUP_DYNDEP_MASK				BITFIELD(15, 15)

#define OMAP4430_L4WKUP_STATDEP_SHIFT				15
#define OMAP4430_L4WKUP_STATDEP_MASK				BITFIELD(15, 15)

#define OMAP4430_MEMIF_DYNDEP_SHIFT				4
#define OMAP4430_MEMIF_DYNDEP_MASK				BITFIELD(4, 4)

#define OMAP4430_MEMIF_STATDEP_SHIFT				4
#define OMAP4430_MEMIF_STATDEP_MASK				BITFIELD(4, 4)

#define OMAP4430_MODFREQDIV_EXPONENT_SHIFT			8
#define OMAP4430_MODFREQDIV_EXPONENT_MASK			BITFIELD(8, 10)

#define OMAP4430_MODFREQDIV_MANTISSA_SHIFT			0
#define OMAP4430_MODFREQDIV_MANTISSA_MASK			BITFIELD(0, 6)

#define OMAP4430_MODULEMODE_SHIFT				0
#define OMAP4430_MODULEMODE_MASK				BITFIELD(0, 1)

/* Used by CM_DSS_DSS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_48MHZ_CLK_SHIFT			9
#define OMAP4430_OPTFCLKEN_48MHZ_CLK_MASK			BITFIELD(9, 9)

/* Used by CM_WKUP_BANDGAP_CLKCTRL */
#define OMAP4430_OPTFCLKEN_BGAP_32K_SHIFT			8
#define OMAP4430_OPTFCLKEN_BGAP_32K_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_USBPHYOCP2SCP_CLKCTRL */
#define OMAP4430_OPTFCLKEN_CLK32K_SHIFT				9
#define OMAP4430_OPTFCLKEN_CLK32K_MASK				BITFIELD(9, 9)

/* Used by CM_CAM_ISS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_CTRLCLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_CTRLCLK_MASK				BITFIELD(8, 8)

#define OMAP4430_OPTFCLKEN_DBCLK_SHIFT				8
#define OMAP4430_OPTFCLKEN_DBCLK_MASK				BITFIELD(8, 8)

/* Used by CM_MEMIF_DLL_CLKCTRL, CM_MEMIF_DLL_H_CLKCTRL */
#define OMAP4430_OPTFCLKEN_DLL_CLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_DLL_CLK_MASK				BITFIELD(8, 8)

/* Used by CM_DSS_DSS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_DSSCLK_SHIFT				8
#define OMAP4430_OPTFCLKEN_DSSCLK_MASK				BITFIELD(8, 8)

/* Used by CM1_ABE_SLIMBUS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_FCLK0_SHIFT				8
#define OMAP4430_OPTFCLKEN_FCLK0_MASK				BITFIELD(8, 8)

/* Used by CM1_ABE_SLIMBUS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_FCLK1_SHIFT				9
#define OMAP4430_OPTFCLKEN_FCLK1_MASK				BITFIELD(9, 9)

/* Used by CM1_ABE_SLIMBUS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_FCLK2_SHIFT				10
#define OMAP4430_OPTFCLKEN_FCLK2_MASK				BITFIELD(10, 10)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_FUNC48MCLK_SHIFT			15
#define OMAP4430_OPTFCLKEN_FUNC48MCLK_MASK			BITFIELD(15, 15)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_HSIC480M_P1_CLK_SHIFT		13
#define OMAP4430_OPTFCLKEN_HSIC480M_P1_CLK_MASK			BITFIELD(13, 13)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_HSIC480M_P2_CLK_SHIFT		14
#define OMAP4430_OPTFCLKEN_HSIC480M_P2_CLK_MASK			BITFIELD(14, 14)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_HSIC60M_P1_CLK_SHIFT			11
#define OMAP4430_OPTFCLKEN_HSIC60M_P1_CLK_MASK			BITFIELD(11, 11)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_HSIC60M_P2_CLK_SHIFT			12
#define OMAP4430_OPTFCLKEN_HSIC60M_P2_CLK_MASK			BITFIELD(12, 12)

/* Used by CM_L4PER_SLIMBUS2_CLKCTRL */
#define OMAP4430_OPTFCLKEN_PER24MC_GFCLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_PER24MC_GFCLK_MASK			BITFIELD(8, 8)

/* Used by CM_L4PER_SLIMBUS2_CLKCTRL */
#define OMAP4430_OPTFCLKEN_PERABE24M_GFCLK_SHIFT		9
#define OMAP4430_OPTFCLKEN_PERABE24M_GFCLK_MASK			BITFIELD(9, 9)

/* Used by CM_L3INIT_USBPHYOCP2SCP_CLKCTRL */
#define OMAP4430_OPTFCLKEN_PHY_48M_SHIFT			8
#define OMAP4430_OPTFCLKEN_PHY_48M_MASK				BITFIELD(8, 8)

/* Used by CM_L4PER_SLIMBUS2_CLKCTRL */
#define OMAP4430_OPTFCLKEN_SLIMBUS_CLK_SHIFT			10
#define OMAP4430_OPTFCLKEN_SLIMBUS_CLK_MASK			BITFIELD(10, 10)

/* Renamed from OPTFCLKEN_SLIMBUS_CLK Used by CM1_ABE_SLIMBUS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_SLIMBUS_CLK_11_11_SHIFT		11
#define OMAP4430_OPTFCLKEN_SLIMBUS_CLK_11_11_MASK		BITFIELD(11, 11)

/* Used by CM_DSS_DSS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_SYS_CLK_SHIFT			10
#define OMAP4430_OPTFCLKEN_SYS_CLK_MASK				BITFIELD(10, 10)

/* Used by CM_DSS_DSS_CLKCTRL */
#define OMAP4430_OPTFCLKEN_TV_CLK_SHIFT				11
#define OMAP4430_OPTFCLKEN_TV_CLK_MASK				BITFIELD(11, 11)

/* Used by CM_L3INIT_UNIPRO1_CLKCTRL */
#define OMAP4430_OPTFCLKEN_TXPHYCLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_TXPHYCLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_USB_TLL_CLKCTRL, CM_L3INIT_USB_TLL_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_USB_CH0_CLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_USB_CH0_CLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_USB_TLL_CLKCTRL, CM_L3INIT_USB_TLL_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_USB_CH1_CLK_SHIFT			9
#define OMAP4430_OPTFCLKEN_USB_CH1_CLK_MASK			BITFIELD(9, 9)

/* Used by CM_L3INIT_USB_TLL_CLKCTRL, CM_L3INIT_USB_TLL_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_USB_CH2_CLK_SHIFT			10
#define OMAP4430_OPTFCLKEN_USB_CH2_CLK_MASK			BITFIELD(10, 10)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_UTMI_P1_CLK_SHIFT			8
#define OMAP4430_OPTFCLKEN_UTMI_P1_CLK_MASK			BITFIELD(8, 8)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_UTMI_P2_CLK_SHIFT			9
#define OMAP4430_OPTFCLKEN_UTMI_P2_CLK_MASK			BITFIELD(9, 9)

/* Used by CM_L3INIT_USB_HOST_CLKCTRL, CM_L3INIT_USB_HOST_CLKCTRL_RESTORE */
#define OMAP4430_OPTFCLKEN_UTMI_P3_CLK_SHIFT			10
#define OMAP4430_OPTFCLKEN_UTMI_P3_CLK_MASK			BITFIELD(10, 10)

/* Used by CM_L3INIT_USB_OTG_CLKCTRL */
#define OMAP4430_OPTFCLKEN_XCLK_SHIFT				8
#define OMAP4430_OPTFCLKEN_XCLK_MASK				BITFIELD(8, 8)

/* Used by CM_EMU_OVERRIDE_DPLL_PER, CM_EMU_OVERRIDE_DPLL_CORE */
#define OMAP4430_OVERRIDE_ENABLE_SHIFT				19
#define OMAP4430_OVERRIDE_ENABLE_MASK				BITFIELD(19, 19)

/* Used by CM_CLKSEL_ABE */
#define OMAP4430_PAD_CLKS_GATE_SHIFT				8
#define OMAP4430_PAD_CLKS_GATE_MASK				BITFIELD(8, 8)

/* Used by CM_CORE_DVFS_CURRENT, CM_IVA_DVFS_CURRENT */
#define OMAP4430_PERF_CURRENT_SHIFT				0
#define OMAP4430_PERF_CURRENT_MASK				BITFIELD(0, 7)

#define OMAP4430_PERF_REQ_SHIFT					0
#define OMAP4430_PERF_REQ_MASK					BITFIELD(0, 7)

/* Used by CM_EMU_OVERRIDE_DPLL_PER */
#define OMAP4430_PER_DPLL_EMU_DIV_SHIFT				0
#define OMAP4430_PER_DPLL_EMU_DIV_MASK				BITFIELD(0, 6)

/* Used by CM_EMU_OVERRIDE_DPLL_PER */
#define OMAP4430_PER_DPLL_EMU_MULT_SHIFT			8
#define OMAP4430_PER_DPLL_EMU_MULT_MASK				BITFIELD(8, 18)

/* Used by CM_RESTORE_ST */
#define OMAP4430_PHASE1_COMPLETED_SHIFT				0
#define OMAP4430_PHASE1_COMPLETED_MASK				BITFIELD(0, 0)

/* Used by CM_RESTORE_ST */
#define OMAP4430_PHASE2A_COMPLETED_SHIFT			1
#define OMAP4430_PHASE2A_COMPLETED_MASK				BITFIELD(1, 1)

/* Used by CM_RESTORE_ST */
#define OMAP4430_PHASE2B_COMPLETED_SHIFT			2
#define OMAP4430_PHASE2B_COMPLETED_MASK				BITFIELD(2, 2)

/* Used by CM_EMU_DEBUGSS_CLKCTRL */
#define OMAP4430_PMD_STM_MUX_CTRL_SHIFT				20
#define OMAP4430_PMD_STM_MUX_CTRL_MASK				BITFIELD(20, 21)

/* Used by CM_EMU_DEBUGSS_CLKCTRL */
#define OMAP4430_PMD_TRACE_MUX_CTRL_SHIFT			22
#define OMAP4430_PMD_TRACE_MUX_CTRL_MASK			BITFIELD(22, 23)

/* Used by CM_DYN_DEP_PRESCAL */
#define OMAP4430_PRESCAL_SHIFT					0
#define OMAP4430_PRESCAL_MASK					BITFIELD(0, 5)

/* Used by REVISION_CM2, REVISION_CM1 */
#define OMAP4430_REV_SHIFT					0
#define OMAP4430_REV_MASK					BITFIELD(0, 7)

#define OMAP4430_SAR_MODE_SHIFT					4
#define OMAP4430_SAR_MODE_MASK					BITFIELD(4, 4)

/* Used by CM_SCALE_FCLK */
#define OMAP4430_SCALE_FCLK_SHIFT				0
#define OMAP4430_SCALE_FCLK_MASK				BITFIELD(0, 0)

/* Used by CM_L4CFG_DYNAMICDEP */
#define OMAP4430_SDMA_DYNDEP_SHIFT				11
#define OMAP4430_SDMA_DYNDEP_MASK				BITFIELD(11, 11)

/* Used by CM_DUCATI_STATICDEP, CM_MPU_STATICDEP */
#define OMAP4430_SDMA_STATDEP_SHIFT				11
#define OMAP4430_SDMA_STATDEP_MASK				BITFIELD(11, 11)

/* Used by CM_CLKSEL_ABE */
#define OMAP4430_SLIMBUS_CLK_GATE_SHIFT				10
#define OMAP4430_SLIMBUS_CLK_GATE_MASK				BITFIELD(10, 10)

#define OMAP4430_STBYST_SHIFT					18
#define OMAP4430_STBYST_MASK					BITFIELD(18, 18)

#define OMAP4430_ST_DPLL_CLK_SHIFT				0
#define OMAP4430_ST_DPLL_CLK_MASK				BITFIELD(0, 0)

/* Used by CM_CLKDCOLDO_DPLL_USB */
#define OMAP4430_ST_DPLL_CLKDCOLDO_SHIFT			9
#define OMAP4430_ST_DPLL_CLKDCOLDO_MASK				BITFIELD(9, 9)

#define OMAP4430_ST_DPLL_CLKOUT_SHIFT				9
#define OMAP4430_ST_DPLL_CLKOUT_MASK				BITFIELD(9, 9)

#define OMAP4430_ST_DPLL_CLKOUTHIF_SHIFT			9
#define OMAP4430_ST_DPLL_CLKOUTHIF_MASK				BITFIELD(9, 9)

/* Used by CM_DIV_M2_DPLL_PER, CM_DIV_M2_DPLL_UNIPRO, CM_DIV_M2_DPLL_ABE */
#define OMAP4430_ST_DPLL_CLKOUTX2_SHIFT				11
#define OMAP4430_ST_DPLL_CLKOUTX2_MASK				BITFIELD(11, 11)

#define OMAP4430_ST_HSDIVIDER_CLKOUT1_SHIFT			9
#define OMAP4430_ST_HSDIVIDER_CLKOUT1_MASK			BITFIELD(9, 9)

#define OMAP4430_ST_HSDIVIDER_CLKOUT2_SHIFT			9
#define OMAP4430_ST_HSDIVIDER_CLKOUT2_MASK			BITFIELD(9, 9)

#define OMAP4430_ST_HSDIVIDER_CLKOUT3_SHIFT			9
#define OMAP4430_ST_HSDIVIDER_CLKOUT3_MASK			BITFIELD(9, 9)

#define OMAP4430_ST_HSDIVIDER_CLKOUT4_SHIFT			9
#define OMAP4430_ST_HSDIVIDER_CLKOUT4_MASK			BITFIELD(9, 9)

/* Used by CM_SYS_CLKSEL */
#define OMAP4430_SYS_CLKSEL_SHIFT				0
#define OMAP4430_SYS_CLKSEL_MASK				BITFIELD(0, 2)

/* Used by CM_L4CFG_DYNAMICDEP */
#define OMAP4430_TESLA_DYNDEP_SHIFT				1
#define OMAP4430_TESLA_DYNDEP_MASK				BITFIELD(1, 1)

/* Used by CM_DUCATI_STATICDEP, CM_MPU_STATICDEP */
#define OMAP4430_TESLA_STATDEP_SHIFT				1
#define OMAP4430_TESLA_STATDEP_MASK				BITFIELD(1, 1)

#define OMAP4430_WINDOWSIZE_SHIFT				24
#define OMAP4430_WINDOWSIZE_MASK				BITFIELD(24, 27)
#endif
