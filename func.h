/* 
 * File:   dispfunc.h
 * Author: Marco
 *
 * Created on March 18, 2020, 12:14 AM
 */

#ifndef DISPFUNC_H
#define	DISPFUNC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/mcc.h"
    
char DispWriteValue(short _val);
char SendI2CData(char* _data, const short _dataSize);


#ifdef	__cplusplus
}
#endif

#endif	/* DISPFUNC_H */

