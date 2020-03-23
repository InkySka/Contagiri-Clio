#include "func.h"
#include "defs.h"
unsigned char write_dato (void) {
    
}
char DispWriteValue(short _val) 
{
    char packets[8];
    char result;

    //Display id: upper four bits
    //Value: lower four bits
    packets[0] = 0b00001110 | ((_val%10)<<4); 
    packets[1] = (packets[0] | (0b00001111));
    packets[2] = 0b00001101 | (((_val/10)%10)<<4); 
    packets[3] = (packets[2] | (0b00001111));
    packets[4] = 0b00001011 | (((_val/100)%10)<<4); 
    packets[5] = (packets[4] | (0b00001111));
    packets[6] = 0b00000111 | ((_val/1000)<<4); 
    packets[7] = (packets[6] | (0b00001111));
    
    result = SendI2CData(packets,8);
    
    return result;
}

char SendI2CData(char* _data, const short _dataSize) 
{
    i2c2_error_t result;
    
    char i;
    /*
     Tries to connect 10 times
     */
    do {
        result = I2C2_Open(DISP_MODULE_ADDR);
        if (result == I2C2_FAIL)
            return I2C2_FAIL;
        ++i;
        //__delay_ms(1);
        
    } while (result == I2C2_BUSY && i < 10);
    //if still busy, return
    if (result == I2C2_BUSY)
        return I2C2_BUSY;

    I2C2_SetBuffer((char*)_data, _dataSize);
    result = I2C2_MasterOperation(false);
    I2C2_Close();
    return result;
}
