#include <stdint.h>
#include "usart1.h"
#include "register.h"


void DMA_INIT(void)
{
    //USART1
        //USART1 dma request channels are:
            //DMA2:
                //rx: STREAM5 CHANNEL4
                //tx: STREAM7 CHANNEL4
    //bits needed:
        // CHSEL in CR to select channel in stream
        // MISZE[1:0] and PSIZE[1:0] in CR to set data unit to bytes
        // MINC in CR to enable increment mode to fill a buffer
        // SxNDTR register to set the data transfer length
        // DIR[1:0] to set direction to peripheral to memory: 00
        // TCIE bit in CR to enable tranfer complete interrupt
        // EN in CR to enable dma ( should be set aftter all setting ate set up)
    //rx:
    // selecting channel 4 : 0b100 to CHSEL bits
    DMA2_S5CR &= ~(7u << 25u);
    DMA2_S5CR |= (4u << 25u); 

    // setting data width to bytes
    DMA2_S5CR &= ~(3u << 13u);
    //they are set to 00
    DMA2_S5CR &= ~(3u << 11u);
    //they are set to 00

    //enabling memory increment mode
    DMA2_S5CR |= (1u << 10u); 

    // direction to peripheral to memory
    DMA2_S5CR &= ~(3u << 6u);

    //enabling transmission complete interrupt
    DMA2_S5CR |= (1u << 4u);

    //transfer length to 8 bytes
    DMA2_S5NDTR = 8u; 

    //enable the dma
    DMA2_S5CR |= 1u;
    
}

void DMA2_STREAM5_IRQHandler()
{
    
}

