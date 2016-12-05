#include "accelerometer.h"

void setupAccelerometer() {
  WireInit();
  WireWriteTwo(accelSensor, 0x31, 1);
  WireWriteTwo(accelSensor, 0x2D, 1<<3);
}

void checkAccelerometer() {
  
  size_t const dataLength = 6;
  uint32_t data[dataLength] = {0};
  
  WireWrite(accelSensor, 0x32);
  GetValueArray(accelSensor, data, dataLength);

  uint16_t xi = (data[1] << 8 | data[0]);
  uint16_t yi = (data[3] << 8 | data[2]);
  uint16_t zi = (data[5] << 8 | data[4]);
  int x = *(int16_t*)(&xi);
  int y = *(int16_t*)(&yi);
  int z = *(int16_t*)(&zi);


  int shake = x * x + y * y + z * z;
  
  if (gameStarted == 0){
    gameStarted = checkShake(shake);
  }
  checkTilt(x, y);
}

int checkShake(int shake){
  return (shake >= shakeThreshold) ? 1 : 0;
}

void checkTilt(int x, int y){
  ballVel[0] = 0;
  ballVel[1] = 0;
  
  if (x - tiltThreshold > 0){
    ballVel[0] = -1;
  }
  
  if (x + tiltThreshold < 0){
    ballVel[0] = 1;
  }
 
  if (y - tiltThreshold > 0){
    ballVel[1] = 1;
  }
 
  if (y + tiltThreshold < 0){
    ballVel[1] = -1;
  }
}


