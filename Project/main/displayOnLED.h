#ifndef DISPLAYONLED_H_INCLUDED
#define DISPLAYONLED_H_INCLUDED

#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

int finishX = 128 / (pathWidth + 1) * (pathWidth + 1) - 5;
int finishY = 32 / (pathWidth + 1) * (pathWidth + 1);
int viewNum = 0;
int blockedPath = 0;

void setupLED(); //initialize the Oled, and set the LED to output

void createFinish();  //setup and draw the finish of the maze

void pathBlock();  //randomly block one of the paths in the maze

void pathUnblock();  //remove the current block on the maze

void drawMaze(int mazeArray[128][32]);  //draw the maze

void drawBall(int ballPos[]); //draw the ball

void showResult(); //show result screen

void showSelectDifficultyInstruction(); //show the difficulty selection screen

void showStartInstruction(); //show the shake to begin screen

#endif
