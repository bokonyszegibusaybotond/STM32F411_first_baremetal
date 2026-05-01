#include <stdint.h>
#include "register.h"
#include "usart1.h"

void EXTI_ENABLE()
{

    //enabeling SYSCONFIG clock
    RCC_APB2ENR |= (1u << 14u);

    //EXTI is always enabled

    //SYSCONFIG EXTI0 to PA0
    SYSCFG_EXTICR1 &= ~(0xF);

    // disabling interrupt mask
    EXTI_IMR |= 1u;
    
    //setting edge detection to rising edge
    EXTI_RTSR |= 1u;

    //nested vector interrupt controller
    NVIC_ISER0 |= (1 << 6);

}
void EXTI0_IRQHandler(void)
{

    //reset pendig bit
    EXTI_PR = EXTI_PR;
    uint8_t tosend[] = "alma\r";
    USART1_SEND_MSG(tosend, sizeof(tosend));
}