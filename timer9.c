#include <stdint.h>

#include "register.h"
#include "gpio.h"

void TIM1_BRK_TIM9_IRQHandler(void)
{
    //handle timer 9 global interrupt here
    //(*(volatile uint32_t *)(adress))
    //volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_PUPDR_OFFSET);
    
    if(TIM9_SR & 1u) //update interrupt
    {
        TIM9_SR &= ~(1u << 0u); // clear UIF
        if(!(GPIOC_ODR & (1 << 13)))
        {
            GPIO_WRITE('C', 13, 1);
            return;
        }
        else
        {
            GPIO_WRITE('C', 13, 0);
            return;
        }
    }
    return;
    

}

void TIM9_SETUP(void)
{
    /*
    what needs to be done to start up TIM9?
    it will ket APB timer clock -> goes trough AHB PREscaler and APB2 PREscaler and get x2 multiplication if APB2PREscaler is more than one
    it needs clock enabled trough APB2ENR

    values need to be set in various config register:

    CONTROL REGISTER bits::
    CEN: enabling the counter
    UDIS: if this bit is set then counter overflow/underflow doesnt generate update event, it can only be done with EVENT GENERATOR register by software
    URS: if this bit is set, then UPDATE GENERAOR cant generate update event
    OPM: one pulso mode, disables counter(by setting CEN 0) when first update event happens after setting this biz
    ARPE: auto reload preload enable, if this bit is set ARR register is buffered, if not then its not
    CKD: clock division, for internal sampling and dead time features(advanced)
    
    SLAVE MODE CONTROL REGISTER somehow configures timer as a slave to anothe rtimer setting triggers and events(advanced)


    DIER INTERRUPT ENABLE REGISTER:
    UIE: update interrupt enable
    CC1IE. capture compare 1 int enable
    CC2IE. capture compare 2 int enable
    TIE: trigger interrupt enable


    STATUS REGISTER: sets flags to be read by interrupt hndler to determine the cause of interrupt
    UIF: update interrupt flag
    CC1IF: capture compare 1 interrupt flag
    CC2IF: capture compare 2 interrupt flag
    TIF: trigger interrupt flag
    CC1OF: capture compare 1 over capture flag: a new value has been captured from the counter when the interrupt flag was still turned
    CC2OF: capture compare 2 over capture flag: a new value has been captured from the counter when the interrupt flag was still turned 


    EVENT GENERATION REGISTER
    UG: generating update event
    CC1G. generating event for capture compare 1
    CC2G. generating event for capture compare 2
    TG: generateing trigger event
    */
    //CPATURE COMPARE REGISTER 1

    //CPATURE COMPARE REGISTER 1

    //COUNTER REGISTER

    //PRESCALER REGISTER

    //AUTO RELAOD REGISTER

    RCC_APB2ENR |= (1 << 16); //bit16 is tim9, enabling APB2 clock

    //now timer clock is 16MHz
    
    
    // 16 MHz / (15999 + 1) = 1 kHz timer tick
    TIM9_PSC = 15999;
    // 1 kHz / (499 + 1) = 2 Hz update event (toggle every interrupt => 1 Hz blink)
    TIM9_ARR = 499;
    /*
    // Generate an update event so PSC/ARR are loaded immediately
    TIM9_EGR |= (1u << 0u);
    // Clear pending update flag before enabling interrupt
    TIM9_SR &= ~(1u << 0u);
    */
    
    NVIC_ISER0 |= (1 << 24); //enabling TIM1_BRK_TIM9_IRQ interrupt on position 24
    TIM9_DIER |= 1; //flipping bit 0 update interrupt enable bit
}


void TIM9_START(void)
{
    //flipping bit 0(counter enable) to 1
    TIM9_CR1 |= 1;
}
