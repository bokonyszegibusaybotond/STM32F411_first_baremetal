#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

#define REG32(adress)  (*(volatile uint32_t *)(adress))


/*-----RCC register definiton-----*/ //RESET and CLOCK CONTROL

    #define RCC_BASE 0x40023800// base adress of RCC peripheral
        #define CR_OFFSET 0x00 // controls clock sources
        #define PLLCFG_OFFSET 0x04 // configuring PLL
        #define CFGR_OFFSET 0x08 // clock configuration, selecting system clock, setting microcontroller clock outputs, setting prescalers for AHB and APB clocks
        #define CIR_OFFSET 0x0C // clock interrupt register
        #define AHB1RSTR_OFFSET 0x10 // AHB1 peripheral reset register
        #define AHB2RSTR_OFFSET 0x14 // AHB2 peripheral reset register
        #define APB1RSTR_OFFESET 0x20 // APB1 peripheral reset register
        #define APB2RSTR_OFFSET 0x24 // APB2 peripheral reset register
        #define AHB1ENR_OFFSET 0x30 // AHB1 peripheral enable register
        #define AHB2ENR_OFFSET 0x34 // AHB2 peripheral enable register
        #define APB1ENR_OFFSET 0x40 // APB1 peripheral enable register
        #define APB2ENR_OFFSET 0x44 // APB2 peripheral enable register
        #define AHB1LPENR_OFFSET 0x50 // AHB1 peripheral clock enable low power register
        #define AHB2LPENR_OFFSET 0x54 // AHB2 peripheral clock enable low power register
        #define APB1LPENR_OFFSET 0x60 // APB1 peripheral clock enable low power register
        #define APB2LPENR_OFFSET 0x64 // APB2 peripheral clock enable low power register
        #define BDCR_OFFSET 0x70 // backup domain control register
        #define CSR_OFFSET 0x74 // clock control and status register
        #define SSCGR_OFFSET 0x80 // spread spectrum clock generation register
        #define PLLI2SCFGR_OFFSET 0x84 // PLLI2S configuration register
        #define DCKCFGR_OFFSET 0x8C // dedicated dlocks donfiguration register


    #define RCC_CR REG32(RCC_BASE + CR_OFFSET)
    #define RCC_PLLCFG REG32(RCC_BASE + PLLCFG_OFFSET)
    #define RCC_CFGR REG32(RCC_BASE + CFGR_OFFSET)
    #define RCC_CIR REG32(RCC_BASE + CIR_OFFSET)
    #define RCC_AHB1RSTR REG32(RCC_BASE + AHB1RSTR_OFFSET)
    #define RCC_AHB2RSTR REG32(RCC_BASE + AHB2RSTR_OFFSET)
    #define RCC_APB1RSTR REG32(RCC_BASE + APB1RSTR_OFFESET)
    #define RCC_APB2RSTR REG32(RCC_BASE + APB2RSTR_OFFSET)
    #define RCC_AHB1ENR REG32(RCC_BASE + AHB1ENR_OFFSET)
    #define RCC_AHB2ENR REG32(RCC_BASE + AHB2ENR_OFFSET)
    #define RCC_APB1ENR REG32(RCC_BASE + APB1ENR_OFFSET)
    #define RCC_APB2ENR REG32(RCC_BASE + APB2ENR_OFFSET)
    #define RCC_AHB1LPENR REG32(RCC_BASE + AHB1LPENR_OFFSET)
    #define RCC_AHB2LPENR REG32(RCC_BASE + AHB2LPENR_OFFSET)
    #define RCC_APB1LPENR REG32(RCC_BASE + APB1LPENR_OFFSET)
    #define RCC_APB2LPENR REG32(RCC_BASE + APB2LPENR_OFFSET)
    #define RCC_BDCR REG32(RCC_BASE + BDCR_OFFSET)
    #define RCC_CSR REG32(RCC_BASE + CSR_OFFSET)
    #define RCC_SSCGR REG32(RCC_BASE + SSCGR_OFFSET)
    #define RCC_PLLI2SCFGR REG32(RCC_BASE + PLLI2SCFGR_OFFSET)
    #define RCC_DCKCFGR REG32(RCC_BASE + DCKCFGR_OFFSET)





/*-----GPIO register definiton-----*/ //GENERAL PURPOSE INPUT OUTPUT

    // base adresses of GPIO peripherals
    #define GPIOA_BASE 0x40020000
    #define GPIOB_BASE 0x40020400
    #define GPIOC_BASE 0x40020800
    #define GPIOD_BASE 0x40020C00
    #define GPIOE_BASE 0x40021000
    #define GPIOH_BASE 0x40021C00
        #define GPIOx_MODER_OFFSET 0x00  //set mode(IN, OUT, ANALOG, ALTERNATE)
        #define GPIOx_OTYPER_OFFSET 0x04 // set type(PUSH-PULL or OPEN-DRAIN)
        #define GPIOx_OSPEEDR_OFFSET 0x08 // set rising edge time(LOW, MEDIUM, FAST, HIGH)
        #define GPIOx_PUPDR_OFFSET 0x0C // (assign internal pullup or pulldown resistor)
        #define GPIOx_IDR_OFFSET 0x10 // read only register, where value is written in input
        #define GPIOx_ODR_OFFSET 0x14 // write absoulte state of output pins
        #define GPIOx_BSRR_OFFSET 0x18 // SET/RESET for ODR reg
        #define GPIOx_LCKR_OFFSET 0x1C //lock config for the pin until peripheral reser
        #define GPIOx_AFRL_OFFSET 0x20 //pick between 16 alternate function options for the **first 8 pins
        #define GPIOx_AFRH_OFFSET 0x24 //pick between 16 alternate function options for the **second 8 pins

    // GPIOA
    #define GPIOA_MODER REG32(GPIOA_BASE + GPIOx_MODER_OFFSET)
    #define GPIOA_OTYPER REG32(GPIOA_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOA_OSPEEDR REG32(GPIOA_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOA_PUPDR REG32(GPIOA_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOA_ODR REG32(GPIOA_BASE + GPIOx_ODR_OFFSET)
    #define GPIOA_BSRR REG32(GPIOA_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOA_LCKR REG32(GPIOA_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOA_AFRL REG32(GPIOA_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOA_AFRH REG32(GPIOA_BASE + GPIOx_AFRH_OFFSET)

    //GPIOB
    #define GPIOB_MODER REG32(GPIOB_BASE + GPIOx_MODER_OFFSET)
    #define GPIOB_OTYPER REG32(GPIOB_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOB_OSPEEDR REG32(GPIOB_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOB_PUPDR REG32(GPIOB_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOB_ODR REG32(GPIOB_BASE + GPIOx_ODR_OFFSET)
    #define GPIOB_BSRR REG32(GPIOB_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOB_LCKR REG32(GPIOB_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOB_AFRL REG32(GPIOB_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOB_AFRH REG32(GPIOB_BASE + GPIOx_AFRH_OFFSET)

    //GPIOC
    #define GPIOC_MODER REG32(GPIOC_BASE + GPIOx_MODER_OFFSET)
    #define GPIOC_OTYPER REG32(GPIOC_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOC_OSPEEDR REG32(GPIOC_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOC_PUPDR REG32(GPIOC_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOC_ODR REG32(GPIOC_BASE + GPIOx_ODR_OFFSET)
    #define GPIOC_BSRR REG32(GPIOC_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOC_LCKR REG32(GPIOC_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOC_AFRL REG32(GPIOC_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOC_AFRH REG32(GPIOC_BASE + GPIOx_AFRH_OFFSET)

    //GPIOD
    #define GPIOD_MODER REG32(GPIOD_BASE + GPIOx_MODER_OFFSET)
    #define GPIOD_OTYPER REG32(GPIOD_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOD_OSPEEDR REG32(GPIOD_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOD_PUPDR REG32(GPIOD_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOD_ODR REG32(GPIOD_BASE + GPIOx_ODR_OFFSET)
    #define GPIOD_BSRR REG32(GPIOD_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOD_LCKR REG32(GPIOD_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOD_AFRL REG32(GPIOD_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOD_AFRH REG32(GPIOD_BASE + GPIOx_AFRH_OFFSET)

    //GPIOE
    #define GPIOE_MODER REG32(GPIOE_BASE + GPIOx_MODER_OFFSET)
    #define GPIOE_OTYPER REG32(GPIOE_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOE_OSPEEDR REG32(GPIOE_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOE_PUPDR REG32(GPIOE_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOE_ODR REG32(GPIOE_BASE + GPIOx_ODR_OFFSET)
    #define GPIOE_BSRR REG32(GPIOE_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOE_LCKR REG32(GPIOE_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOE_AFRL REG32(GPIOE_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOE_AFRH REG32(GPIOE_BASE + GPIOx_AFRH_OFFSET)

    //GPIOH
    #define GPIOH_MODER REG32(GPIOH_BASE + GPIOx_MODER_OFFSET)
    #define GPIOH_OTYPER REG32(GPIOH_BASE + GPIOx_OTYPER_OFFSET)
    #define GPIOH_OSPEEDR REG32(GPIOH_BASE + GPIOx_OSPEEDR_OFFSET)
    #define GPIOH_PUPDR REG32(GPIOH_BASE + GPIOx_PUPDR_OFFSET)
    #define GPIOH_ODR REG32(GPIOH_BASE + GPIOx_ODR_OFFSET)
    #define GPIOH_BSRR REG32(GPIOH_BASE + GPIOx_BSRR_OFFSET)
    #define GPIOH_LCKR REG32(GPIOH_BASE + GPIOx_LCKR_OFFSET)
    #define GPIOH_AFRL REG32(GPIOH_BASE + GPIOx_AFRL_OFFSET)
    #define GPIOH_AFRH REG32(GPIOH_BASE + GPIOx_AFRH_OFFSET)


/*----TIMER peripherals register definiton-----*/
    #define TIM1_BASE 0x40010000
    #define TIM2_BASE 0x40000000
    #define TIM3_BASE 0x40000400
    #define TIM4_BASE 0x40000800
    #define TIM5_BASE 0x40000C00
    #define TIM9_BASE 0x40014000
   #define TIM10_BASE 0x40014400
   #define TIM11_BASE 0x40014800

    /*-----REGISTER OFFSETS-----*/ //not all timer peripherals include all of them but the offset of these registers are always consistent
                                      //   1      2-5      9        10-11     
        #define TIMx_CR1_OFFSET 0x00  //   x       x       x          x           CONTROL REGISTER 1                  enableing and configuring important things like counters anf events or modes
        #define TIMx_CR2_OFFSET 0x04  //   x       x                              CONTROL REGISTER 2                  enableing and configuring important things like counters anf events or modes
        #define TIMx_SMCR_OFFSET 0x08 //   x       x       x                      SLAVE MODE CONTROL REGISTER         configuring beheviour when linking timers together
        #define TIMx_DIER_OFFSET 0x0C //   x       x       x          x           DMA/INTERRUPT ENABLE REGISTER       enableing interrupt and dma requests and events
        #define TIMx_SR_OFFSET 0x10   //   x       x       x          x           STATUS REGISTER                     interrupt flags to read with interrupt handler function
        #define TIMx_EGR_OFFSET 0x14  //   x       x       x          x           EVENT GENERATION REGISTER           used to generate events by flipping bits in this register
        #define TIMx_CCMR1_OFFSET 0x18//   x       x       x          x           CAPTURE/COMPARE MODE REGISTER 1     channel configuration for cahnnel 1 and 2; works differently in capture and compare mode
        #define TIMx_CCMR2_OFFSET 0x1C//   x       x                              CAPTURE/COMPARE MODE REGISTER 2     channel configuration for cahnnel 3 and 4; works differently in
        #define TIMx_CCER_OFFSET 0x20 //   x       x       x          x           CAPTURE/COMPARE ENABLE REGISTER     enableing channels and choosing polarity(rising/falling edge; active high/low) and setting complementary outputs
        #define TIMx_CNT_OFFSET 0x24  //   x       x       x          x           COUNTER REGISTER                    where the actual counter is ticking, can be read on the fly
        #define TIMx_PSC_OFFSET 0x28  //   x       x       x          x           PRESCALER REGISTER                  devides the clock frequency by register value of 16 bits for the counter
        #define TIMx_ARR_OFFSET 0x2C  //   x       x       x          x           AUTO RELOAD REGISTER                when counter value reaches ARR register value, it triggers update event
        #define TIMx_RCR_OFFSET 0x30  //   x                                      REPETITION COUNTER REGISTER         some advanced bullshit   
        #define TIMx_CCR1_OFFSET 0x34 //   x       x       x          x           CAPTURE/COMPARE REGISTER 1          capture compare value
        #define TIMx_CCR2_OFFSET 0x38 //   x       x       x                      CAPTURE/COMPARE REGISTER 2          capture compare value
        #define TIMx_CCR3_OFFSET 0x3C //   x       x                              CAPTURE/COMPARE REGISTER 3          capture compare value
        #define TIMx_CCR4_OFFSET 0x40 //   x       x                              CAPTURE/COMPARE REGISTER 4          capture compare value
        #define TIMx_BDTR_OFFSET 0x44 //   x                                      BREAK AND DEAD TIME REGISTER        some advanced configuration stuff about break events and other shit
        #define TIMx_DCR_OFFSET 0x48  //   x       x                              DMA CONTROL REGISTER                configuring DMA bursts
        #define TIMx_DMAR_OFFSET 0x4C //   x       x                              DMA ADRESS FOR FULL TRANSFER        a full 32 bit adress for DMA burst
        #define TIM2_OR_OFFSET 0x50   //                                          TIMER2 OPTION REGISTER              option to make USB OTG use the TIM2_ITR1 interrupt
        #define TIM5_OR_OFFSET 0x50   //                                          TIMER5 OPTION REGISTER              option to connect LSI or LSE clock or RTC wake-up interrupt to channel 4 of TIM5 for calibration
        #define TIM11_OR_OFFSET 0x50  //                                          TIMER11 OPTION REGISTER             option to connect HSE_RTC clock to cahnnel 1 for measurement purposes
        
        //TIM1
        #define TIM1_CR1 REG32(TIM1_BASE + TIMx_CR1_OFFSET)
        #define TIM1_CR2 REG32(TIM1_BASE + TIMx_CR2_OFFSET)
        #define TIM1_SMCR REG32(TIM1_BASE + TIMx_SMCR_OFFSET)
        #define TIM1_DIER REG32(TIM1_BASE + TIMx_DIER_OFFSET)
        #define TIM1_SR REG32(TIM1_BASE + TIMx_SR_OFFSET)
        #define TIM1_EGR REG32(TIM1_BASE + TIMx_EGR_OFFSET)
        #define TIM1_CCMR1 REG32(TIM1_BASE + TIMx_CCMR1_OFFSET)
        #define TIM1_CCMR2 REG32(TIM1_BASE + TIMx_CCMR2_OFFSET)
        #define TIM1_CCER REG32(TIM1_BASE + TIMx_CCER_OFFSET)
        #define TIM1_CNT REG32(TIM1_BASE + TIMx_CNT_OFFSET)
        #define TIM1_PSC REG32(TIM1_BASE + TIMx_PSC_OFFSET)
        #define TIM1_ARR REG32(TIM1_BASE + TIMx_ARR_OFFSET)
        #define TIM1_RCR REG32(TIM1_BASE + TIMx_RCR_OFFSET)
        #define TIM1_CCR1 REG32(TIM1_BASE + TIMx_CCR1_OFFSET)
        #define TIM1_CCR2 REG32(TIM1_BASE + TIMx_CCR2_OFFSET)
        #define TIM1_CCR3 REG32(TIM1_BASE + TIMx_CCR3_OFFSET)
        #define TIM1_CCR4 REG32(TIM1_BASE + TIMx_CCR4_OFFSET)
        #define TIM1_BDTR REG32(TIM1_BASE + TIMx_BDTR_OFFSET)
        #define TIM1_DCR REG32(TIM1_BASE + TIMx_DCR_OFFSET)
        #define TIM1_DMAR REG32(TIM1_BASE + TIMx_DMAR_OFFSET)

        //TIM2
        #define TIM2_CR1 REG32(TIM2_BASE + TIMx_CR1_OFFSET)
        #define TIM2_CR2 REG32(TIM2_BASE + TIMx_CR2_OFFSET)
        #define TIM2_SMCR REG32(TIM2_BASE + TIMx_SMCR_OFFSET)
        #define TIM2_DIER REG32(TIM2_BASE + TIMx_DIER_OFFSET)
        #define TIM2_SR REG32(TIM2_BASE + TIMx_SR_OFFSET)
        #define TIM2_EGR REG32(TIM2_BASE + TIMx_EGR_OFFSET)
        #define TIM2_CCMR1 REG32(TIM2_BASE + TIMx_CCMR1_OFFSET)
        #define TIM2_CCMR2 REG32(TIM2_BASE + TIMx_CCMR2_OFFSET)
        #define TIM2_CCER REG32(TIM2_BASE + TIMx_CCER_OFFSET)
        #define TIM2_CNT REG32(TIM2_BASE + TIMx_CNT_OFFSET)
        #define TIM2_PSC REG32(TIM2_BASE + TIMx_PSC_OFFSET)
        #define TIM2_ARR REG32(TIM2_BASE + TIMx_ARR_OFFSET)
        #define TIM2_CCR1 REG32(TIM2_BASE + TIMx_CCR1_OFFSET)
        #define TIM2_CCR2 REG32(TIM2_BASE + TIMx_CCR2_OFFSET)
        #define TIM2_CCR3 REG32(TIM2_BASE + TIMx_CCR3_OFFSET)
        #define TIM2_CCR4 REG32(TIM2_BASE + TIMx_CCR4_OFFSET)
        #define TIM2_DCR REG32(TIM2_BASE + TIMx_DCR_OFFSET)
        #define TIM2_DMAR REG32(TIM2_BASE + TIMx_DMAR_OFFSET)
        #define TIM2_OR REG32(TIM2_BASE + TIM2_OR_OFFSET)
        
        //TIM3
        #define TIM3_CR1 REG32(TIM3_BASE + TIMx_CR1_OFFSET)
        #define TIM3_CR2 REG32(TIM3_BASE + TIMx_CR2_OFFSET)
        #define TIM3_SMCR REG32(TIM3_BASE + TIMx_SMCR_OFFSET)
        #define TIM3_DIER REG32(TIM3_BASE + TIMx_DIER_OFFSET)
        #define TIM3_SR REG32(TIM3_BASE + TIMx_SR_OFFSET)
        #define TIM3_EGR REG32(TIM3_BASE + TIMx_EGR_OFFSET)
        #define TIM3_CCMR1 REG32(TIM3_BASE + TIMx_CCMR1_OFFSET)
        #define TIM3_CCMR2 REG32(TIM3_BASE + TIMx_CCMR2_OFFSET)
        #define TIM3_CCER REG32(TIM3_BASE + TIMx_CCER_OFFSET)
        #define TIM3_CNT REG32(TIM3_BASE + TIMx_CNT_OFFSET)
        #define TIM3_PSC REG32(TIM3_BASE + TIMx_PSC_OFFSET)
        #define TIM3_ARR REG32(TIM3_BASE + TIMx_ARR_OFFSET)
        #define TIM3_CCR1 REG32(TIM3_BASE + TIMx_CCR1_OFFSET)
        #define TIM3_CCR2 REG32(TIM3_BASE + TIMx_CCR2_OFFSET)
        #define TIM3_CCR3 REG32(TIM3_BASE + TIMx_CCR3_OFFSET)
        #define TIM3_CCR4 REG32(TIM3_BASE + TIMx_CCR4_OFFSET)
        #define TIM3_DCR REG32(TIM3_BASE + TIMx_DCR_OFFSET)
        #define TIM3_DMAR REG32(TIM3_BASE + TIMx_DMAR_OFFSET)

        //TIM4
        #define TIM4_CR1 REG32(TIM4_BASE + TIMx_CR1_OFFSET)
        #define TIM4_CR2 REG32(TIM4_BASE + TIMx_CR2_OFFSET)
        #define TIM4_SMCR REG32(TIM4_BASE + TIMx_SMCR_OFFSET)
        #define TIM4_DIER REG32(TIM4_BASE + TIMx_DIER_OFFSET)
        #define TIM4_SR REG32(TIM4_BASE + TIMx_SR_OFFSET)
        #define TIM4_EGR REG32(TIM4_BASE + TIMx_EGR_OFFSET)
        #define TIM4_CCMR1 REG32(TIM4_BASE + TIMx_CCMR1_OFFSET)
        #define TIM4_CCMR2 REG32(TIM4_BASE + TIMx_CCMR2_OFFSET)
        #define TIM4_CCER REG32(TIM4_BASE + TIMx_CCER_OFFSET)
        #define TIM4_CNT REG32(TIM4_BASE + TIMx_CNT_OFFSET)
        #define TIM4_PSC REG32(TIM4_BASE + TIMx_PSC_OFFSET)
        #define TIM4_ARR REG32(TIM4_BASE + TIMx_ARR_OFFSET)
        #define TIM4_CCR1 REG32(TIM4_BASE + TIMx_CCR1_OFFSET)
        #define TIM4_CCR2 REG32(TIM4_BASE + TIMx_CCR2_OFFSET)
        #define TIM4_CCR3 REG32(TIM4_BASE + TIMx_CCR3_OFFSET)
        #define TIM4_CCR4 REG32(TIM4_BASE + TIMx_CCR4_OFFSET)
        #define TIM4_DCR REG32(TIM4_BASE + TIMx_DCR_OFFSET)
        #define TIM4_DMAR REG32(TIM4_BASE + TIMx_DMAR_OFFSET)
        
        //TIM5
        #define TIM5_CR1 REG32(TIM5_BASE + TIMx_CR1_OFFSET)
        #define TIM5_CR2 REG32(TIM5_BASE + TIMx_CR2_OFFSET)
        #define TIM5_SMCR REG32(TIM5_BASE + TIMx_SMCR_OFFSET)
        #define TIM5_DIER REG32(TIM5_BASE + TIMx_DIER_OFFSET)
        #define TIM5_SR REG32(TIM5_BASE + TIMx_SR_OFFSET)
        #define TIM5_EGR REG32(TIM5_BASE + TIMx_EGR_OFFSET)
        #define TIM5_CCMR1 REG32(TIM5_BASE + TIMx_CCMR1_OFFSET)
        #define TIM5_CCMR2 REG32(TIM5_BASE + TIMx_CCMR2_OFFSET)
        #define TIM5_CCER REG32(TIM5_BASE + TIMx_CCER_OFFSET)
        #define TIM5_CNT REG32(TIM5_BASE + TIMx_CNT_OFFSET)
        #define TIM5_PSC REG32(TIM5_BASE + TIMx_PSC_OFFSET)
        #define TIM5_ARR REG32(TIM5_BASE + TIMx_ARR_OFFSET)
        #define TIM5_CCR1 REG32(TIM5_BASE + TIMx_CCR1_OFFSET)
        #define TIM5_CCR2 REG32(TIM5_BASE + TIMx_CCR2_OFFSET)
        #define TIM5_CCR3 REG32(TIM5_BASE + TIMx_CCR3_OFFSET)
        #define TIM5_CCR4 REG32(TIM5_BASE + TIMx_CCR4_OFFSET)
        #define TIM5_DCR REG32(TIM5_BASE + TIMx_DCR_OFFSET)
        #define TIM5_DMAR REG32(TIM5_BASE + TIMx_DMAR_OFFSET)
        #define TIM5_OR REG32(TIM5_BASE + TIM5_OR_OFFSET)

        //TIM9
        #define TIM9_CR1 REG32(TIM9_BASE + TIMx_CR1_OFFSET)
        #define TIM9_SMCR REG32(TIM9_BASE + TIMx_SMCR_OFFSET)
        #define TIM9_DIER REG32(TIM9_BASE + TIMx_DIER_OFFSET)
        #define TIM9_SR REG32(TIM9_BASE + TIMx_SR_OFFSET)
        #define TIM9_EGR REG32(TIM9_BASE + TIMx_EGR_OFFSET)
        #define TIM9_CCMR1 REG32(TIM9_BASE + TIMx_CCMR1_OFFSET)
        #define TIM9_CCER REG32(TIM9_BASE + TIMx_CCER_OFFSET)
        #define TIM9_CNT REG32(TIM9_BASE + TIMx_CNT_OFFSET)
        #define TIM9_PSC REG32(TIM9_BASE + TIMx_PSC_OFFSET)
        #define TIM9_ARR REG32(TIM9_BASE + TIMx_ARR_OFFSET)
        #define TIM9_CCR1 REG32(TIM9_BASE + TIMx_CCR1_OFFSET)

        //TIM10
        #define TIM10_CR1 REG32(TIM10_BASE + TIMx_CR1_OFFSET)
        #define TIM10_DIER REG32(TIM10_BASE + TIMx_DIER_OFFSET)
        #define TIM10_SR REG32(TIM10_BASE + TIMx_SR_OFFSET)
        #define TIM10_EGR REG32(TIM10_BASE + TIMx_EGR_OFFSET)
        #define TIM10_CCMR1 REG32(TIM10_BASE + TIMx_CCMR1_OFFSET)
        #define TIM10_CCER REG32(TIM10_BASE + TIMx_CCER_OFFSET)
        #define TIM10_CNT REG32(TIM10_BASE + TIMx_CNT_OFFSET)
        #define TIM10_PSC REG32(TIM10_BASE + TIMx_PSC_OFFSET)
        #define TIM10_ARR REG32(TIM10_BASE + TIMx_ARR_OFFSET)
        #define TIM10_CCR1 REG32(TIM10_BASE + TIMx_CCR1_OFFSET)

        //TIM11
        #define TIM11_CR1 REG32(TIM11_BASE + TIMx_CR1_OFFSET)
        #define TIM11_DIER REG32(TIM11_BASE + TIMx_DIER_OFFSET)
        #define TIM11_SR REG32(TIM11_BASE + TIMx_SR_OFFSET)
        #define TIM11_EGR REG32(TIM11_BASE + TIMx_EGR_OFFSET)
        #define TIM11_CCMR1 REG32(TIM11_BASE + TIMx_CCMR1_OFFSET)
        #define TIM11_CCER REG32(TIM11_BASE + TIMx_CCER_OFFSET)
        #define TIM11_CNT REG32(TIM11_BASE + TIMx_CNT_OFFSET)
        #define TIM11_PSC REG32(TIM11_BASE + TIMx_PSC_OFFSET)
        #define TIM11_ARR REG32(TIM11_BASE + TIMx_ARR_OFFSET)
        #define TIM11_CCR1 REG32(TIM11_BASE + TIMx_CCR1_OFFSET)
        #define TIM11_OR REG32(TIM11_BASE + TIM11_OR_OFFSET)



        /*-----NVIC REGISTERS -----*/ // NESTED VECTORED INTERRUPT CONTROLLER

    #define NVIC_ISRx_BASE 0xE000E000

            //eanbling interrupts
            #define NVIC_ISR0_OFFSET 0x100
            #define NVIC_ISR1_OFFSET 0x104
            #define NVIC_ISR2_OFFSET 0x108
            #define NVIC_ISR3_OFFSET 0x10C
            #define NVIC_ISR4_OFFSET 0x110
            #define NVIC_ISR5_OFFSET 0x114
            #define NVIC_ISR6_OFFSET 0x118
            #define NVIC_ISR7_OFFSET 0x11C           

            #define NVIC_ICER0_OFFSET 0x180
            #define NVIC_ICER1_OFFSET 0x184
            #define NVIC_ICER2_OFFSET 0x188
            #define NVIC_ICER3_OFFSET 0x18C
            #define NVIC_ICER4_OFFSET 0x190
            #define NVIC_ICER5_OFFSET 0x194
            #define NVIC_ICER6_OFFSET 0x198
            #define NVIC_ICER7_OFFSET 0x19C

            #define NVIC_ISPR0_OFFSET 0x200
            #define NVIC_ISPR1_OFFSET 0x204
            #define NVIC_ISPR2_OFFSET 0x208
            #define NVIC_ISPR3_OFFSET 0x20C
            #define NVIC_ISPR4_OFFSET 0x210
            #define NVIC_ISPR5_OFFSET 0x214
            #define NVIC_ISPR6_OFFSET 0x218
            #define NVIC_ISPR7_OFFSET 0x21C

            #define NVIC_ICPR0_OFFSET 0x280
            #define NVIC_ICPR1_OFFSET 0x284
            #define NVIC_ICPR2_OFFSET 0x288
            #define NVIC_ICPR3_OFFSET 0x28C
            #define NVIC_ICPR4_OFFSET 0x290
            #define NVIC_ICPR5_OFFSET 0x294
            #define NVIC_ICPR6_OFFSET 0x298
            #define NVIC_ICPR7_OFFSET 0x29C

            #define NVIC_IABR0_OFFSET 0x300
            #define NVIC_IABR1_OFFSET 0x304
            #define NVIC_IABR2_OFFSET 0x308
            #define NVIC_IABR3_OFFSET 0x30C
            #define NVIC_IABR4_OFFSET 0x310
            #define NVIC_IABR5_OFFSET 0x314
            #define NVIC_IABR6_OFFSET 0x318
            #define NVIC_IABR7_OFFSET 0x31C

            //setting priority of interrupts
            #define NVIC_IPR0_OFFSET 0x400
            #define NVIC_IPR1_OFFSET 0x404
            #define NVIC_IPR2_OFFSET 0x408
            #define NVIC_IPR3_OFFSET 0x40C
            #define NVIC_IPR4_OFFSET 0x410
            #define NVIC_IPR5_OFFSET 0x414
            #define NVIC_IPR6_OFFSET 0x418
            #define NVIC_IPR7_OFFSET 0x41C

            #define NVIC_STIR_OFFSET 0xE00

        #define NVIC_ISR0 REG32(NVIC_ISRx_BASE + NVIC_ISR0_OFFSET)
        #define NVIC_ISR1 REG32(NVIC_ISRx_BASE + NVIC_ISR1_OFFSET)
        #define NVIC_ISR2 REG32(NVIC_ISRx_BASE + NVIC_ISR2_OFFSET)
        #define NVIC_ISR3 REG32(NVIC_ISRx_BASE + NVIC_ISR3_OFFSET)
        #define NVIC_ISR4 REG32(NVIC_ISRx_BASE + NVIC_ISR4_OFFSET)
        #define NVIC_ISR5 REG32(NVIC_ISRx_BASE + NVIC_ISR5_OFFSET)
        #define NVIC_ISR6 REG32(NVIC_ISRx_BASE + NVIC_ISR6_OFFSET)
        #define NVIC_ISR7 REG32(NVIC_ISRx_BASE + NVIC_ISR7_OFFSET)

        #define NVIC_ICER0 REG32(NVIC_ISRx_BASE + NVIC_ICER0_OFFSET)
        #define NVIC_ICER1 REG32(NVIC_ISRx_BASE + NVIC_ICER1_OFFSET)
        #define NVIC_ICER2 REG32(NVIC_ISRx_BASE + NVIC_ICER2_OFFSET)
        #define NVIC_ICER3 REG32(NVIC_ISRx_BASE + NVIC_ICER3_OFFSET)
        #define NVIC_ICER4 REG32(NVIC_ISRx_BASE + NVIC_ICER4_OFFSET)
        #define NVIC_ICER5 REG32(NVIC_ISRx_BASE + NVIC_ICER5_OFFSET)
        #define NVIC_ICER6 REG32(NVIC_ISRx_BASE + NVIC_ICER6_OFFSET)
        #define NVIC_ICER7 REG32(NVIC_ISRx_BASE + NVIC_ICER7_OFFSET)

        #define NVIC_ISPR0 REG32(NVIC_ISRx_BASE + NVIC_ISPR0_OFFSET)
        #define NVIC_ISPR1 REG32(NVIC_ISRx_BASE + NVIC_ISPR1_OFFSET)
        #define NVIC_ISPR2 REG32(NVIC_ISRx_BASE + NVIC_ISPR2_OFFSET)
        #define NVIC_ISPR3 REG32(NVIC_ISRx_BASE + NVIC_ISPR3_OFFSET)
        #define NVIC_ISPR4 REG32(NVIC_ISRx_BASE + NVIC_ISPR4_OFFSET)
        #define NVIC_ISPR5 REG32(NVIC_ISRx_BASE + NVIC_ISPR5_OFFSET)
        #define NVIC_ISPR6 REG32(NVIC_ISRx_BASE + NVIC_ISPR6_OFFSET)
        #define NVIC_ISPR7 REG32(NVIC_ISRx_BASE + NVIC_ISPR7_OFFSET)

        #define NVIC_ICPR0 REG32(NVIC_ISRx_BASE + NVIC_ICPR0_OFFSET)
        #define NVIC_ICPR1 REG32(NVIC_ISRx_BASE + NVIC_ICPR1_OFFSET)
        #define NVIC_ICPR2 REG32(NVIC_ISRx_BASE + NVIC_ICPR2_OFFSET)
        #define NVIC_ICPR3 REG32(NVIC_ISRx_BASE + NVIC_ICPR3_OFFSET)
        #define NVIC_ICPR4 REG32(NVIC_ISRx_BASE + NVIC_ICPR4_OFFSET)
        #define NVIC_ICPR5 REG32(NVIC_ISRx_BASE + NVIC_ICPR5_OFFSET)
        #define NVIC_ICPR6 REG32(NVIC_ISRx_BASE + NVIC_ICPR6_OFFSET)
        #define NVIC_ICPR7 REG32(NVIC_ISRx_BASE + NVIC_ICPR7_OFFSET)

        #define NVIC_IABR0 REG32(NVIC_ISRx_BASE + NVIC_IABR0_OFFSET)
        #define NVIC_IABR1 REG32(NVIC_ISRx_BASE + NVIC_IABR1_OFFSET)
        #define NVIC_IABR2 REG32(NVIC_ISRx_BASE + NVIC_IABR2_OFFSET)
        #define NVIC_IABR3 REG32(NVIC_ISRx_BASE + NVIC_IABR3_OFFSET)
        #define NVIC_IABR4 REG32(NVIC_ISRx_BASE + NVIC_IABR4_OFFSET)
        #define NVIC_IABR5 REG32(NVIC_ISRx_BASE + NVIC_IABR5_OFFSET)
        #define NVIC_IABR6 REG32(NVIC_ISRx_BASE + NVIC_IABR6_OFFSET)
        #define NVIC_IABR7 REG32(NVIC_ISRx_BASE + NVIC_IABR7_OFFSET)

        #define NVIC_IPR0 REG32(NVIC_ISRx_BASE + NVIC_IPR0_OFFSET)
        #define NVIC_IPR1 REG32(NVIC_ISRx_BASE + NVIC_IPR1_OFFSET)
        #define NVIC_IPR2 REG32(NVIC_ISRx_BASE + NVIC_IPR2_OFFSET)
        #define NVIC_IPR3 REG32(NVIC_ISRx_BASE + NVIC_IPR3_OFFSET)
        #define NVIC_IPR4 REG32(NVIC_ISRx_BASE + NVIC_IPR4_OFFSET)
        #define NVIC_IPR5 REG32(NVIC_ISRx_BASE + NVIC_IPR5_OFFSET)
        #define NVIC_IPR6 REG32(NVIC_ISRx_BASE + NVIC_IPR6_OFFSET)
        #define NVIC_IPR7 REG32(NVIC_ISRx_BASE + NVIC_IPR7_OFFSET)

        #define NVIC_STIR REG32(NVIC_ISRx_BASE + NVIC_STIR_OFFSET)
#endif