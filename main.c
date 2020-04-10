#include "mcc_generated_files/mcc.h"
#include "defs.h"
#include "disp_func.h"
#include "rpm_handling.h"
#ifdef DEBUG
#include <stdio.h>
#endif

void main(void)
{
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(HandleRPMTimerOverflowInterrupt);
    TMR1_SetInterruptHandler(HandleDispInterrupt);
    INT_SetInterruptHandler(HandleRPMInterrupt);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    printf("Starting timers...\n");
    
    TMR0_StartTimer();
    TMR1_StartTimer();
    //TMR0_ISR();
    //TMR1_ISR();
    
    PORTA = 0x0;
    TRISA = 0x0;
    
    printf("Device Ready.\n");
    //EUSART1_Write(i);
    while(1)
    {
        /*RA2 = ((_i++) % 2);
        //DispWriteValue(_i * 1000 + _i * 100 + _i * 10 + _i);
        DispWriteValue(122);
        //write_dato ();
        __delay_ms(100);
        if(_i >= 9)
            _i = 0;*/
    }
}
