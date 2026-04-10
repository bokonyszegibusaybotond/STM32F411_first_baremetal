#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#include "register.h"

void TIM1_BRK_TIM9_IRQHandler(void);

void TIM9_SETUP(void);
void TIM9_START(void);

#endif