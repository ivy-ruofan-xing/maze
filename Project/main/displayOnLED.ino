#include "displayOnLED.h"

void setupLED() {
  OrbitOledInit();
  OrbitOledClearBuffer();
}

void showStartInstruction(){
  //display is 16 chars horizontally and four lines vertically
  OrbitOledSetCursor(3, 0);
  OrbitOledPutString("WELCOME TO");
  OrbitOledSetCursor(4, 1);
  OrbitOledPutString("The Maze");
  OrbitOledSetCursor(1, 3);
  OrbitOledPutString("shake to start");
}

void showSelectDifficultyInstruction(){
  OrbitOledSetCursor(0, 0);
  OrbitOledPutString("difficulty:");
  OrbitOledSetCursor(7, 1);
  char temp = 48 + viewNum;
  OrbitOledPutChar(temp);
  OrbitOledSetCursor(0, 2);
  OrbitOledPutString("Right BTN:+");
  OrbitOledSetCursor(0, 3);
  OrbitOledPutString("Left BTN: OK");
}

void showResult(){
  OrbitOledClearBuffer();
  OrbitOledSetCursor(4, 0);
  OrbitOledPutString("YOU WIN!");
  OrbitOledSetCursor(0, 1);
  OrbitOledPutString("Time taken: ");
  //total time it took the player to get to the exit
  char timeUnits = 48 + timer % 10;
  char timeTens = 48 + timer % 100 / 10;
  char timeHundreds = 48 + timer / 100;
  OrbitOledSetCursor(12, 1);
  OrbitOledPutChar(timeHundreds);
  OrbitOledSetCursor(13, 1);
  OrbitOledPutChar(timeTens);
  OrbitOledSetCursor(14, 1);
  OrbitOledPutChar(timeTens);
  OrbitOledSetCursor(15, 1);
  OrbitOledPutString("s");
  OrbitOledSetCursor(0, 2);
  OrbitOledPutString("up BTN: new game");
  OrbitOledSetCursor(0, 3);
  OrbitOledPutString("Time to exit: ");
  //time left to start new game
  char temp = 49 + (5000 - millis() + t) / 1000;
  OrbitOledSetCursor(15, 3);
  OrbitOledPutChar(temp);
  OrbitOledUpdate();
}

void drawBall(int ballPos[]){
  //128 columns, 32 rows
  OrbitOledMoveTo(ballPos[0], ballPos[1]);
  OrbitOledDrawPixel();
  OrbitOledUpdate();
  OrbitOledUpdate();
}

void drawMaze(int mazeArray[128][32]){
  
  for(int i = 0; i < 128; i++){
    for(int j = 0; j < 32; j++){
      OrbitOledMoveTo(i, j);
      if(mazeArray[i][j] == 1){
        OrbitOledDrawPixel();
      }
    }
  }
  
  OrbitOledSetDrawColor(0);  //change the colour to the same as the background to erase
  for(int i = finishX; i < 127; i++){
    mazeArray[i][finishY] = 0;
    OrbitOledMoveTo(i, finishY);
    OrbitOledDrawPixel();
  }
  OrbitOledSetDrawColor(0x01);  //return to white to be able see the next drawn things
}

void pathBlock(){
  blockedPath = random(pathNum);
  
  for(int i = 1; i < pathWidth + 1; i++){
    int ax = (pathArray[blockedPath * 4] * (pathWidth + 1)) + (i) * pathArray[blockedPath * 4 + 2];
    int ay = (pathArray[blockedPath * 4 + 1] * (pathWidth + 1)) + (i) * pathArray[blockedPath * 4 + 3];
    mazeArray[ax][ay] = 1;
  }
}

void pathUnblock(){
  for(int i = 1; i < pathWidth + 1; i++){
    int ax = (pathArray[blockedPath * 4] * (pathWidth + 1)) + (i) * pathArray[blockedPath * 4 + 2];
    int ay = (pathArray[blockedPath * 4 + 1] * (pathWidth + 1)) + (i) * pathArray[blockedPath * 4 + 3];
    mazeArray[ax][ay] = 0;
  }
}

void drawPortal(){
  for (int i = 0; i < 2; i++){
    OrbitOledMoveTo(portalPos[i][0], portalPos[i][1]);
    OrbitOledDrawPixel();
    OrbitOledMoveTo(portalPos[i][0] - 1, portalPos[i][1]);
    OrbitOledDrawPixel();
    OrbitOledMoveTo(portalPos[i][0] + 1, portalPos[i][1]);
    OrbitOledDrawPixel();
    OrbitOledMoveTo(portalPos[i][0], portalPos[i][1] - 1);
    OrbitOledDrawPixel();
    OrbitOledMoveTo(portalPos[i][0], portalPos[i][1] + 1);
    OrbitOledDrawPixel();
  }
}

