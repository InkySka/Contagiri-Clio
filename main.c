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

    TMR0_StartTimer();
    TMR1_StartTimer();
    //TMR0_ISR();
    //TMR1_ISR();
    
    //PORTA = 0x0;
    //TRISA = 0x0;
    
#ifdef DEBUG
    printf("\n. . . . . . . . . .\nDEVICE STARTUP\n\n");
#endif
    
    //EUSART1_Write(i);
    while(1)
    {
        if(hasToRefreshDisp)
        {
            lastDispWriteState = DispWriteValue(currentRPMCount);
        #ifdef DEBUG
            //RA2 = (_i++ % 2);
        #endif
            hasToRefreshDisp = 0;
        }
        
        if(receivedRPMSignal)
        {
            
            currentRPMCount = (currentRPMCount + (125*((short)60000/timeSinceLastRevolution)))/2;
            if(currentRPMCount % 10 == 9) ++currentRPMCount;
            if(currentRPMCount > 9999) currentRPMCount = 9999;
        #ifdef DEBUG
            printf("[%d\t%d]\t",((int)timeSinceLastRevolution), (unsigned int)(125*((unsigned int)60000/timeSinceLastRevolution)));
        #endif

            receivedRPMSignal = 0;
        }
        
    }
}
