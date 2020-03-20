#include "func.h"
#include "defs.h"

char DispWriteValue(short _val) 
{
    char packets[4];
    char result;

    //Display id: upper four bits
    //Value: lower four bits
    packets[3] = 0b10000000;
    packets[3] |= (_val%10);
    packets[2] = 0b01000000;
    packets[2] |= ((_val/10)%10);
    packets[1] = 0b00100000;
    packets[1] |= ((_val/100)%10);
    packets[0] = 0b00010000;
    packets[0] |= _val/1000;
    
    result = SendI2CData(packets,4);
    
    return result;
}

char SendI2CData(char* _data, const short _dataSize) 
{
    i2c1_error_t result;
    char data[4];
    data[0] = _data[0];
    data[1] = _data[1];
    data[2] = _data[2];
    data[3] = _data[3];
    char i;
    /*
     Tries to connect 10 times
     */
    do {
        result = I2C1_Open(DISP_MODULE_ADDR);
        if (result == I2C1_FAIL)
            return I2C1_FAIL;
        ++i;
        //__delay_ms(1);
        
    } while (result == I2C1_BUSY && i < 10);
    //if still busy, return
    if (result == I2C1_BUSY)
        return I2C1_BUSY;

    I2C1_SetBuffer((char*)_data, _dataSize);
    result = I2C1_MasterOperation(false);
    I2C1_Close();
    return result;
}
