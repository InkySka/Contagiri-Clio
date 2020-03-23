#include "mcc_generated_files/mcc.h"
#include "defs.h"
#include "func.h"

char i = 0;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //I2C1_SetTimeout((char)255);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    PORTA = 0x0;
    TRISA = 0x0;
    
    //EUSART1_Write(i);
    while(1)
    {
        RA2 = ((i++) % 2);
        DispWriteValue(7777);
        //write_dato ();
        __delay_ms(200);
    }
}
/**
 End of File
*/