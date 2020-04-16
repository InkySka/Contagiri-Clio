#include "defs.h"
#include "rpm_handling.h"
#include "mcc_generated_files/tmr0.h"

#ifdef DEBUG
#include <stdio.h>
#endif

void HandleRPMTimerOverflowInterrupt()
{
    currentRPMCount = 0;
#ifdef DEBUG
    printf("RPM Timer Overflow\n");
#endif

    TMR0_Reload();
}

void HandleRPMInterrupt()
{
    timeSinceLastRevolution = TMR0_ReadTimer();
    TMR0_Reload();
    receivedRPMSignal = 1;
}
