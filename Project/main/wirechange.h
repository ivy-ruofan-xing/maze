#ifndef WIRECHANGE_H_INCLUDED
#define WIRECHANGE_H_INCLUDED

#include <Wire.h>

void WireInit();  //initialize the wire
void WireWrite(int address, uint8_t value);  //writes one value
void WireWriteTwo(int address, uint8_t value, uint8_t value2);  //writes two values
void GetValueArray(int address, uint32_t *ValArray, uint8_t len);  //creates an array of values

#endif

