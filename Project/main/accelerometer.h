#ifndef ACCELEROMETER_H_INCLUDED
#define ACCELEROMETER_H_INCLUDED

#include <Wire.h>

uint8_t const accelSensor = 0x1d;
const int shakeThreshold = 40000;
const int tiltThreshold = 20;

void setupAccelerometer();  //initialize and connect to accelerometer
void checkAccelerometer();  //gets values from accelerometer and starts game when the device is shaken
int checkShake(int shake);  //checks for device being shaken
void checkTilt(int x, int y);  //changes the ball velocity as the device tilts

#endif



