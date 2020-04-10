#include "defs.h"
#include "rpm_handling.h"
#include "mcc_generated_files/tmr0.h"
#ifdef DEBUG
#include <stdio.h>
#endif

inline void HandleRPMTimerOverflowInterrupt()
{
    currentRPMCount = 0;
#ifdef DEBUG
    printf("RPM Timer Overflow");
#endif
    TMR0_Reload();
}

inline void HandleRPMInterrupt()
{
    currentRPMCount = (currentRPMCount + (60000/TMR0_ReadTimer()))/2;
#ifdef DEBUG
    printf("RPM: %d\n",currentRPMCount);
#endif
    TMR0_Reload();
}
