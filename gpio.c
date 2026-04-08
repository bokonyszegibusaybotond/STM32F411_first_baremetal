
#include <stdint.h>
#include "register.h"
#include "gpio.h"

static uintptr_t CHAR_PER_BASE(char PER)
{
    switch(PER){
        case 'A':
        {
            return GPIOA_BASE;
            break;
        }
        case 'B':
        {
            return GPIOB_BASE;
            break;
        }
        case 'C':
        {
            return GPIOC_BASE;
            break;
        }
        case 'D':
        {
            return GPIOD_BASE;
            break;
        }
        case 'E':
        {
            return GPIOE_BASE;
            break;
        }
        case 'H':
        {
            return GPIOH_BASE;
            break;
        }
        default:
            return 0x00000000; //returning something...
    }
}

static unsigned int CHAR_MODE(char MODE){
    switch(MODE)
    {
        case 'I': //INPUT
            return 0b00;
            break;
        case 'O': //OUTPUT
            return 0b01;
            break;
        case 'L': // ALTERNATE
            return 0b10;
            break;
        case 'A': // ANALOG
            return 0b11;
            break;
        default:
            return 0b00;  // in case of invalid char, set to input mode
    }
}

static unsigned int CHAR_TYPE(char TYPE){
    switch(TYPE)
    {
        case 'O':  // OPEN-DRAIN
            return 1;
            break;
        default:
            return 0;  // if its not 'O' for open-drain, than its set to push-pull
    }
}



static unsigned int CHAR_PUPD(char PUPD){
    switch(PUPD)
    {
        case 'N':  // NONE
            return 0b00;
            break;
        case 'U': // PULLUP
            return 0b01;
            break;
        case 'D': // PULLDOWN
            return 0b10;
            break;
        // 11 is reserved
        default:
            return 0b00;  // in case of invalid char, set to NONE
    }
}

static unsigned int CHAR_SPEED(char SPEED){
    switch(SPEED)
    {
        case 'L':  //LOW
            return 0b00;
            break;
        case 'M': //MEDIUM
            return 0b01;
            break;
        case 'F': // FAST
            return 0b10;
            break;
        case 'H': // HIGH
            return 0b11;
            break;
        default:
            return 0b00;  // in case of invalid cahr, set to LOW SPEED
    }
}


uint8_t GPIO_PER_EN(char PER)
{
    switch(PER){
        case 'A':
        {
            RCC_AHB1ENR |= (1u << 0u);
            break;
        }
        case 'B':
        {
            RCC_AHB1ENR |= (1u << 1u);
            break;
        }
        case 'C':
        {
            RCC_AHB1ENR |= (1u << 2u);
            break;
        }
        case 'D':
        {
            RCC_AHB1ENR |= (1u << 3u);
            break;
        }
        case 'E':
        {
            RCC_AHB1ENR |= (1u << 4u);
            break;
        }
        case 'H':
        {
            RCC_AHB1ENR |= (1u << 7u);
            break;
        }
        default:
            return 1;
    }
    return 0;
}

/*
uint8_t GPIO_PER_RST(char PER)
{
    switch(PER){
        case 'A':
        {
            RCC_AHB1RSTR |= (1u << 0u);
            break;
        }
        case 'B':
        {
            RCC_AHB1RSTR |= (1u << 1u);
            break;
        }
        case 'C':
        {
            RCC_AHB1RSTR |= (1u << 2u);
            break;
        }
        case 'D':
        {
            RCC_AHB1RSTR |= (1u << 3u);
            break;
        }
        case 'E':
        {
            RCC_AHB1RSTR |= (1u << 4u);
            break;
        }
        case 'H':
        {
            RCC_AHB1RSTR |= (1u << 7u);
            break;
        }
        default:
            return 1;
    }
    return 0;
}
*/

void GPIO_PIN_MODE(char PER, uint8_t PIN, char MODE)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - MODE: pick mode for pin; options{I(input), O(output), L(alternate f.), A(analog)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_MODER_OFFSET);
    *REG &= ~(0x3 << 2*PIN);
    *REG |= (CHAR_MODE(MODE) << 2*PIN);
}

void GPIO_PIN_PUPD(char PER, uint8_t PIN, char PUPD)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - MODE: pick pullup/~down res for pin; options{U(pullup), D(pulldown), N(none)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_PUPDR_OFFSET);
    *REG &= ~(0x3 << 2*PIN);
    *REG |= (CHAR_PUPD(PUPD) << 2*PIN);
}

void GPIO_PIN_TYPE(char PER, uint8_t PIN, char TYPE)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - MODE: pick type(open drain or push-pull) for pin; options{O(open-drain), anything else(push-pull)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_OTYPER_OFFSET);
    *REG |= (CHAR_TYPE(TYPE) << PIN);
}

void GPIO_PIN_SPEED(char PER, uint8_t PIN, char SPEED)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - MODE: pick rising edge speed for pin; options{L(low), M(medium), F(fast), H(high)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_OSPEEDR_OFFSET);
    *REG &= ~(0x3 << 2*PIN);
    *REG |= (CHAR_SPEED(SPEED) << 2*PIN);
}

void GPIO_WRITE(char PER, uint8_t PIN, uint8_t STATE)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - STATE: pick digital output state for pin; options{ZERO(low), NON-ZERO(high)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_BSRR_OFFSET);
    if(STATE)
    {
        *REG = (1 << PIN);
    }
    else{
        *REG = (1 << (PIN + 16));
    }
}

uint8_t GPIO_READ(char PER, uint8_t PIN)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
    returns: state of the given pin; options{0(low), 1(high)}
    */
    volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_IDR_OFFSET);
   return ((*REG & (1 << PIN)) >> PIN);
}

void GPIO_SET_AF(char PER, uint8_t PIN, uint8_t AF)
{
    /*
    parameters:
        - PER: pick GPIO peripheral; options{A, B, C, D, E, H}
        - PIN: pick pin from 0-15
        - AF: pick alternate function from 0-15. AF parameter !!!SHALL NOT EXCEED 15!!!
    */
    if(PIN < 8)
    {
        volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_AFRL_OFFSET);
        *REG &= ~(0xF << 4*PIN);
        *REG |= (AF << 4*PIN);
    }
    else
    {
        volatile uint32_t *REG = (volatile uint32_t *)(CHAR_PER_BASE(PER) + GPIOx_AFRH_OFFSET);
        *REG &= ~(0xF << 4*(PIN-8));
        *REG |= (AF << 4*(PIN-8));
    }
}


