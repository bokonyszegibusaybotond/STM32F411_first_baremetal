/*
what do i need for usart peripheral?

RCC: enable clock

USART peripheral:

enable: USART_CR1 - > UE bit

word length: M bit

set TE bit to tr

write to data register



*/
#include <stdint.h>

#ifndef USART1_H
#define USART1_H

void USART1_INIT(void);
void USART1_SEND_MSG(uint8_t *msg, uint8_t len);
void USART1_IRQHandler(void);
void USART1_BAUD(void);
void USART1_SENDBYTE(uint8_t MES);

extern uint8_t RXbuffer[64];

#endif
