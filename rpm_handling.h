/* 
 * File:   timer_func.h
 * Author: Marco
 *
 * Created on 31 March 2020, 22:55
 */

#ifndef TIMER_FUNC_H
#define	TIMER_FUNC_H

#ifdef	__cplusplus
extern "C" {
#endif

void HandleRPMTimerOverflowInterrupt();
void HandleRPMInterrupt();
void DebugRPMCount();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_FUNC_H */

