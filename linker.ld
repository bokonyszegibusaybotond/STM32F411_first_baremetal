
/*entry point of the program*/
ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = 0x20020000;

SECTIONS
{
    /*vector table expected by mcu*/
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH AT > FLASH

    /*the actual code + constant objects,
    that live only in the flash memory*/
    .text :
    {
        *(.text*)
        *(.rodata*)
    } > FLASH AT > FLASH

    /*variables, these live in the RAM, but are stored in
    flash in case of power down(or sth like that)*/
    .data :
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM AT > FLASH

     _sidata = LOADADDR(.data);
     
    /*THINGS that live only in RAM*/
    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM AT > RAM

}
