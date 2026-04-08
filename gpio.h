#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "register.h"

// handling GPIO peripheral using RCC peripheral
uint8_t GPIO_PER_EN(char PER);

//uint8_t GPIO_PER_RST(char PER);

// pin configuration
void GPIO_PIN_MODE(char PER, uint8_t PIN, char MODE);

void GPIO_PIN_PUPD(char PER, uint8_t PIN, char PUPD);

void GPIO_PIN_TYPE(char PER, uint8_t PIN, char TYPE);

void GPIO_PIN_SPEED(char PER, uint8_t PIN, char SPEED);

// READ/WRITE
void GPIO_WRITE(char PER, uint8_t PIN, uint8_t STATE);

uint8_t GPIO_READ(char PER, uint8_t PIN);

// alternate functions
void GPIO_SET_AF(char PER, uint8_t PIN, uint8_t AF);

#endif