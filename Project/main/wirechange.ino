#include "wirechange.h"

static TwoWire mazeWire(0);

void WireInit() {
  mazeWire.begin();
}

void WireWrite(int address, uint8_t value) {
  mazeWire.beginTransmission(address);
  mazeWire.write(value);
  mazeWire.endTransmission();
}

void WireWriteTwo(int address, uint8_t value, uint8_t value2){
  mazeWire.beginTransmission(address);
  mazeWire.write(value);
  mazeWire.write(value2);
  mazeWire.endTransmission();
}

void GetValueArray(uint8_t address, uint32_t *ValArray, uint8_t len) {
  mazeWire.requestFrom(address, len);
  do {
    while (!mazeWire.available());
    *(ValArray++) = mazeWire.read();
  }
  while (--len > 0);
}


