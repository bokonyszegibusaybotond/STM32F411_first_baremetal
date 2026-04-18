#include <stdint.h>
#include "register.h"
#include "gpio.h"

void USART1_INIT(void)
{
    // enabling peripherial
    RCC_APB2ENR |= (1u << 4u);
    USART1_CR1 |= (1u << 13u); // setting UE bit


    //setting gpio-s to alternate funcitons
    GPIO_SET_AF('A', 9, 7);
    GPIO_SET_AF('A', 10, 7);

    //enabling interrupt
    NVIC_ISER1 |= (1 << 5); //enabling USART1_IRQ interrupt on position 37
    

    //setting baud rate to 9600
    USART1_BRR = 3 + (104 << 4u);

    

}



/*-----send string-----*/
static uint8_t buffer[64];
static uint8_t msg_len;
static int cnt = 0;

void USART1_SEND_MSG(uint8_t *msg, uint8_t len)
{
    msg_len = len;

    //enabling transmit
    USART1_CR1 |= (1u << 3u); 

    


    for(int i = 0; i < len; i++)
    {
        buffer[i] = msg[i];
    }

    if(USART1_SR & (1u << 7u))
    {
        USART1_DR = buffer[0];
        
        //setting TXEIE bit for interrupt
        USART1_CR1 |= (1u << 7u); 
        cnt = 1;
    }
}


void USART1_IRQHandler(void)
{
    if(!(USART1_SR & (1u << 6u)))
    {
        if(USART1_SR & (1u << 7u) && cnt < msg_len) // STATUS REGISTER TXE
        {
            USART1_DR = buffer[cnt]; // TXE flag is reset by writing to DR
            cnt++;
        }
    }
    else
    {
        USART1_SR &= ~(1u << 6u); // reset TC flag 

        //disabling transmit
        USART1_CR1 &= ~(1u << 3u); 

        //resetting TXEIE bit for interrupt
        USART1_CR1 &= ~(1u << 7u); 
    }
}

void USART1_SENDBYTE(uint8_t MES)
{
    USART1_DR = MES;
}


