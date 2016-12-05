#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

int isPathBlocked = 0; 
const int b1 = PUSH1;
int b1State;
const int b2 = PUSH2;
int b2State;
const int b3 = PE_0;
int b3State;

void setupButton();  //setup the button values and set mode to input
void checkButton(int stage); //check the buttons and change values 

#endif
