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

    USART1_CR1 |= (1u << 2u); //enabling recieve

    USART1_CR1 |= (1u << 5u); // enabling recieve not empty interrupt enable

}



/*-----send string-----*/
static uint8_t TXbuffer[64];
static uint8_t msg_len;
static int cnt = 0;

void USART1_SEND_MSG(uint8_t *msg, uint8_t len)
{
    if(len > 64 || len == 0 || !(USART1_SR & (1u << 6u))) // validating msg length and checking TC bit 
    {
        return;
    }
    msg_len = len;

    //enabling transmit
    USART1_CR1 |= (1u << 3u); 

    


    for(int i = 0; i < len; i++)
    {
        TXbuffer[i] = msg[i];
    }

    if(USART1_SR & (1u << 7u))
    {
        USART1_DR = TXbuffer[0];
        
        //setting TXEIE bit for interrupt
        USART1_CR1 |= (1u << 7u); 
        cnt = 1;
    }
    return;
}

// RX 
uint8_t RXbuffer[64];

void USART1_IRQHandler(void)
{
    if(!(USART1_SR & (1u << 5u))) // checking RXNE bit
    {
        //transmitting
        if(!(USART1_SR & (1u << 6u))) // checkign TC bit
        {
            //mid transmission
            if(USART1_SR & (1u << 7u) && cnt < (msg_len-1)) // STATUS REGISTER TXE
            {
                USART1_DR = TXbuffer[cnt]; // TXE flag is reset by writing to DR
                cnt++;
            }
        }
        else
        {
            //transmisison ended

            //disabling transmit
            USART1_CR1 &= ~(1u << 3u); 

            //resetting TXEIE bit for interrupt
            USART1_CR1 &= ~(1u << 7u); 
        }
    }
    else
    {
        //recieving
        uint8_t rx = USART1_DR;

        USART1_SEND_MSG(&rx, sizeof(rx));
    }
}

void USART1_SENDBYTE(uint8_t MES)
{
    USART1_DR = MES;
}