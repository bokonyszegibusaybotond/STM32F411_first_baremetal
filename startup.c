#include <stdint.h>
#include <stddef.h>

extern int main(void);

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

typedef void (*isr_handler_t)(void);


void WWDG_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI16_PVD_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void EXTI21_TAMP_STAMP_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EXTI22_RTC_WKUP_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM4_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM5_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM6_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)__attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void EXTI17_RTC_ALARM_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EXTI18_OTG_FS_WKUP_IRQHandler(void)__attribute__((weak, alias("Default_Handler")));
void DMA1_STREAM7_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)  			__attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM4_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM5_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM6_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void DMA2_STREAM7_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)			__attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void)				__attribute__((weak, alias("Default_Handler")))	;


#if defined(__GNUC__)
#define SECTION_ATTR(name) __attribute__((section(name)))
#else
#define SECTION_ATTR(name)
#endif



 
/*break from 18-23 , 38-40 , 42-47 , 51-56 , 60-67 , 73-81*/
SECTION_ATTR(".isr_vector")
const isr_handler_t vector_table[] = {
	(isr_handler_t)&_estack,
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	DebugMon_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,/*
	

	
	*/
	WWDG_IRQHandler,
	EXTI16_PVD_IRQHandler,
	EXTI21_TAMP_STAMP_IRQHandler, 
	EXTI22_RTC_WKUP_IRQHandler, 
	FLASH_IRQHandler,
	RCC_IRQHandler, 
	EXTI0_IRQHandler, 
	EXTI1_IRQHandler, 
	EXTI2_IRQHandler, 
	EXTI3_IRQHandler,
	EXTI4_IRQHandler, 
	DMA1_STREAM0_IRQHandler, 
	DMA1_STREAM1_IRQHandler, 
	DMA1_STREAM2_IRQHandler, 
	DMA1_STREAM3_IRQHandler,
	DMA1_STREAM4_IRQHandler, 
	DMA1_STREAM5_IRQHandler, 
	DMA1_STREAM6_IRQHandler, 
	ADC_IRQHandler, 
	Default_Handler, //these are left out in the manual
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	TIM1_BRK_TIM9_IRQHandler,
	TIM1_UP_TIM10_IRQHandler, 
	TIM1_TRG_COM_TIM11_IRQHandler, 
	TIM1_CC_IRQHandler, 
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler, 
	I2C1_EV_IRQHandler, 
	I2C1_ER_IRQHandler, 
	I2C2_EV_IRQHandler, 
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler, 
	SPI2_IRQHandler,
	USART1_IRQHandler, 
	USART2_IRQHandler, 
	Default_Handler, /**/
	EXTI15_10_IRQHandler, 
	EXTI17_RTC_ALARM_IRQHandler, 
	EXTI18_OTG_FS_WKUP_IRQHandler, 
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	DMA1_STREAM7_IRQHandler, 
	Default_Handler, /**/
	SDIO_IRQHandler,
	TIM5_IRQHandler, 
	SPI3_IRQHandler, 
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	DMA2_STREAM0_IRQHandler, 
	DMA2_STREAM1_IRQHandler, 
	DMA2_STREAM2_IRQHandler, 
	DMA2_STREAM3_IRQHandler,
	DMA2_STREAM4_IRQHandler, 
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	OTG_FS_IRQHandler,
	DMA2_STREAM5_IRQHandler, 
	DMA2_STREAM6_IRQHandler, 
	DMA2_STREAM7_IRQHandler, 
	USART6_IRQHandler, 
	I2C3_EV_IRQHandler, 
	I2C3_ER_IRQHandler, 
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	Default_Handler, /**/
	FPU_IRQHandler,
	SPI4_IRQHandler,
	SPI5_IRQHandler
};



void NMI_Handler(void) { Default_Handler(); }
void HardFault_Handler(void) { Default_Handler(); }
void MemManage_Handler(void) { Default_Handler(); }
void BusFault_Handler(void) { Default_Handler(); }
void UsageFault_Handler(void) { Default_Handler(); }
void SVC_Handler(void) { Default_Handler(); }
void DebugMon_Handler(void) { Default_Handler(); }
void PendSV_Handler(void) { Default_Handler(); }
void SysTick_Handler(void) { Default_Handler(); }


void Reset_Handler(void)
{
	uint32_t *src = &_sidata;
	uint32_t *dst = &_sdata;

	while (dst < &_edata) {
		*dst++ = *src++;
	}

	dst = &_sbss;
	while (dst < &_ebss) {
		*dst++ = 0;
	}

	(void)main();

	while (1) {
	}
}

void Default_Handler(void)
{
	while (1) {
	}
}
