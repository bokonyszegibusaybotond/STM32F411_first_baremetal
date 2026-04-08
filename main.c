/*
registers needed for led blink on PC13 GPIO

    RCC_AHB1ENR: able to enable clock for peripherapls assigned to it
    Adress offset: 0x30

    |-------------------------------------------

    GPIOC_MODER(MODE_REGISTER): set mode for pin
    Adress offset: 0x00


    |-------------------------------------------

    GPIOC_OTYPER(OUTPUT_TYPE_REGISTER): sets output pins to either open-drain, or push-pull mode.
    Adress offset: 0x04

    |-------------------------------------------

    GPIOC_OSPEEDR(OUTPUT_SPEED_REGISTER): 
    Adress offset: 0x08

    |-------------------------------------------

    GPIOC_PUPDR(PULLUP_PULLDOWN_REGISTER): assigns a weak pullup or pulldown resistor to the pin internally
    Adress offset: 0x0C

    |-------------------------------------------

    GPIOC_ODR(OUTPUT_DATA_REGISTER): 16 bit long sets the absolute state of each pin
    Adress offset: 0x14

    |-------------------------------------------

    GPIOC_BSRR(BIT_SET_RESET_REGISTER): 32 bit long. if you set a bit 1 in first half it sets the corresponfig bit in _ODR 1,
    if a bit is set to 1 in second half(16-31), it sets corresponding bit in _OD 0.
    in other words, it controls change, not absolute state
    Adress offset: 0x18

*/
#include <stdint.h>
#include <stddef.h>


#include "register.h"
#include "gpio.h"



static void delay(uint32_t count);







static void setup()
{
    GPIO_PER_EN('C'); // enableing GPIOC peripheral

    //configuration left default with empty registers


    // setting PC13 to HIGH to disable led
    GPIO_WRITE('C', 13, 1);
    GPIO_PIN_MODE('C', 13, 'O'); 
}

static void loop()
{
    GPIO_WRITE('C', 13, 0);
    delay(1000000);
    GPIO_WRITE('C', 13, 1);
    delay(1000000);
}

static void delay(uint32_t count)
{
    for(uint32_t i = 0; i < count; i++)
    {
        __asm__("nop");
    }
}

int main(void)
{
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}