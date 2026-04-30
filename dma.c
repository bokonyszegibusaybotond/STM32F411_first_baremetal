#include <stdint.h>
#include "usart1.h"



void DMA_INIT(void)
{
    //USART1
        //USART1 dma request channels are:
            //rx: STREAM5 CHANNEL4
            //tx: STREAM7 CHANNEL4
    //bits needed:
        // CHSEL in CR to select channel in stream
        // MISZE and PSIZE in CR to set data unit to bytes
        // MINC in CR to enable increment mode to fill a buffer



    
}

