#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS


#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile unsigned long *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile unsigned long *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile unsigned long *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile unsigned long *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile unsigned long *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile unsigned long *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile unsigned long *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile unsigned long *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile unsigned long *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile unsigned long *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile unsigned long *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile unsigned long *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile unsigned long *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile unsigned long *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile unsigned long *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile unsigned long *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile unsigned long *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile unsigned long *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile unsigned long *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile unsigned long *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile unsigned long *)0x4002541C))


/*System Control*/
typedef struct
{
    volatile unsigned long SYS_CTRL_RESC[24];
    unsigned long Reserved_0[40];
    volatile unsigned long SYS_CTRL_RCC[24];
    unsigned long Reserved_1[40];
    volatile unsigned long SYS_CTRL_SLEEP_MODE_GC_REGS[24];
    unsigned long Reserved_2[40];
    volatile unsigned long SYS_CTRL_DEEP_SLEEP_MODE_GC_REGS[24];
    unsigned long Reserved_3[104];
    volatile unsigned long SYS_CTRL_PERIPHERAL_READY_REGS[24];
} SYS_CTRL_config_REGS;


#define SYSCTL_REGCGC2_REG        (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGCGPIO_REG         (*((volatile unsigned long *)0x400FE608))
#define SYS_CTRL_REGS ((SYS_CTRL_config_REGS *)(SCB_BASE_ADDRESS + 0x500))

#define SCB_BASE_ADDRESS 0x400FE000

typedef struct
{
    unsigned long MOSCDIS : 1;
    unsigned long : 3;
    unsigned long OSCSRC : 2;
    unsigned long XTAL : 5;
    unsigned long BYPASS : 1;
    unsigned long : 1;
    unsigned long PWRDN : 1;
    unsigned long : 3;
    unsigned long PWMDIV : 3;
    unsigned long USEPWMDIV : 1;
    unsigned long : 1;
    unsigned long USESYSDIV : 1;
    unsigned long SYSDIV : 4;
    unsigned long ACG : 1;
    unsigned long : 4;
} RCC_BIT_FIELD;

typedef union
{
    unsigned long R;
    RCC_BIT_FIELD B;
} RCC_Tag;
#define SYS_CTRL_RCC_REG ((volatile RCC_Tag *)(SCB_BASE_ADDRESS + 0x060))
	
#define SYS_CTRL_MOSCCTL_REG *((volatile unsigned long *)(SCB_BASE_ADDRESS + 0x07C))


/*****************************************************************************
Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile unsigned long *)0xE000E018))


/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define NVIC_PRI0_REG             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile unsigned long *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))


/*General Purpose Timer*/

#define GPT_16_32_0_BASE_ADDRESS 0x40030000
#define GPT_16_32_1_BASE_ADDRESS 0x40031000
#define GPT_16_32_2_BASE_ADDRESS 0x40032000
#define GPT_16_32_3_BASE_ADDRESS 0x40033000
#define GPT_16_32_4_BASE_ADDRESS 0x40034000
#define GPT_16_32_5_BASE_ADDRESS 0x40035000

#define GPT_32_64_WIDE_6_BASE_ADDRESS 0x40036000
#define GPT_32_64_WIDE_7_BASE_ADDRESS 0x40037000
#define GPT_32_64_WIDE_8_BASE_ADDRESS 0x4004C000
#define GPT_32_64_WIDE_9_BASE_ADDRESS 0x4004D000
#define GPT_32_64_WIDE_10_BASE_ADDRESS 0x4004E000
#define GPT_32_64_WIDE_11_BASE_ADDRESS 0x4004F000



typedef struct
{
    volatile unsigned long GPTMCFG;
    volatile unsigned long GPTMT_A_B_MR[2]; /*TimerA, TimerB Mode*/
    volatile unsigned long GPTMCTL;
    volatile unsigned long GPTMSYNC;
    volatile unsigned long Reserved_1;
    volatile unsigned long GPTMIMR;             /*Interrupt Mask Register*/
    volatile unsigned long GPTMRIS;             /*Raw Interrupt Status*/
    volatile unsigned long GPTMMIS;             /*Masked Interrupt Status*/
    volatile unsigned long GPTMICR;             /*Interrupt Clear*/
    volatile unsigned long GPTMT_A_B_ILR[2];    /*TimerA, TimerB interval load*/
    volatile unsigned long GPTMT_A_B_MATCHR[2]; /*TimerA, TimerB Match*/
    volatile unsigned long GPTMT_A_B_PR[2];     /*TimerA, TimerB Prescale*/
    volatile unsigned long GPTMT_A_B_PMR[2];    /*TimerA, TimerB Prescale Match*/
    volatile unsigned long GPTMT_A_B_R[2];      /*TimerA, TimerB*/
    volatile unsigned long GPTMT_A_B_V[2];      /*TimerA, TimerB Value*/
} GPT_REGS_CONFIG;

#define GPT0_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_0_BASE_ADDRESS))
#define GPT1_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_1_BASE_ADDRESS))
#define GPT2_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_2_BASE_ADDRESS))
#define GPT3_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_3_BASE_ADDRESS))
#define GPT4_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_4_BASE_ADDRESS))
#define GPT5_16_32_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_16_32_5_BASE_ADDRESS))

#define GPT0_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_6_BASE_ADDRESS))
#define GPT1_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_7_BASE_ADDRESS))
#define GPT2_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_8_BASE_ADDRESS))
#define GPT3_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_9_BASE_ADDRESS))
#define GPT4_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_10_BASE_ADDRESS))
#define GPT5_32_64_WIDE_BIT_REGS ((GPT_REGS_CONFIG *)(GPT_32_64_WIDE_11_BASE_ADDRESS))



/*This Section is for NVIC Registers*/


#define EN(offset)                         (*((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x100+offset)))
#define EN0                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

#define DIS(offset)                         (*((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x180+offset)))
#define DIS0                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4                                      *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

#define PEND0                                       *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))  
#define PEND1                                       *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))  
#define PEND2                                       *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))  
#define PEND3                                       *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))  
#define PEND4                                       *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))  


#define UNPEND0                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))  
#define UNPEND1                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))  
#define UNPEND2                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))  
#define UNPEND3                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
#define UNPEND4                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))

#define ACTIVE0                                   *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define ACTIVE1                                   *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
#define ACTIVE2                                   *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
#define ACTIVE3                                   *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
#define ACTIVE4                                   *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))

#define PRI_BASE_MASK                       0xE000E400
#define PRI(offset)                         (*((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x400+offset)))
#define PRI0                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define PRI5                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define PRI6                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define PRI7                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define PRI8                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define PRI9                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define PRI10                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define PRI11                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define PRI12                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define PRI13                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define PRI14                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define PRI15                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define PRI16                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define PRI17                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define PRI18                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define PRI19                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define PRI20                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define PRI21                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define PRI22                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define PRI23                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define PRI24                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define PRI25                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define PRI26                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define PRI27                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define PRI28                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define PRI29                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define PRI30                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define PRI31                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define PRI32                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define PRI33                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define PRI34                                     *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))

#endif
