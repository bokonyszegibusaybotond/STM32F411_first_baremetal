#include <stdint.h>

#include "register.h"


TIM1_BRK_TIM9_IRQHandler(void)
{
    //handle timer 9 global interrupt here
    volatile uint32_t *STATUS = TIM9_SR;

}

void TIM9_SETUP()
{
    // turn LSE clock on in RCC_BDCR register
    
}
