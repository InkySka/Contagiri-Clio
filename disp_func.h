/* 
 * File:   dispfunc.h
 * Author: Marco
 *
 * Created on March 18, 2020, 12:14 AM
 */

#ifndef DISPFUNC_H
#define	DISPFUNC_H

#include "mcc_generated_files\mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
// 1 = 10 microseconds = 0.01 milliseconds --- 65536 = 655.36 milliseconds

volatile i2c2_error_t lastDispWriteState;

void HandleDispInterrupt();
i2c2_error_t DispWriteValue(const unsigned short _val);
i2c2_error_t SendI2CData(const char* _data, const unsigned short _dataSize);


#ifdef	__cplusplus
}
#endif

#endif	/* DISPFUNC_H */

