#include "maze.h" //createMaze
#include "displayOnLED.h" //contains all displaying function: setupLED(), drawMaze(), drawBall(), showResult(), showSelectBallInstruction(), showStartInstruction()
#include "accelerometer.h" //contains functions involving accelerometer: setupAccelerometer(), checkAccelerometer()
#include "wirechange.h" //contains functions involving getting values from accelerometer.
#include "button.h" //contains functions involving buttons: setupButton(), checkButton()
#include "ball.h" //updateBallPosition(), checkIfWin()
#include "portal.h" //updatePortalPosition(), checkIfOnPortal()

int gameStarted = 0;
int difficultySelected = 0;
//counter for the timer during the finish screen
unsigned long t;
unsigned long timer;

void setup() {
  setupLED();
  setupAccelerometer();
  setupButton(); 
  OrbitOledSetCharUpdate(0);
  //use an unconnected pin as the seed to get random numbers for random()
  randomSeed(analogRead(0));
}

void loop() {
  OrbitOledClearBuffer();
  //checking up the tiva is shaken
  checkAccelerometer();
  
  if (gameStarted){
    if (difficultySelected){
      if (isPathBlocked == 1){
        if (millis() - t >= 5000){
          pathUnblock();
          pathBlock();
          updatePortalPosition();
          t = millis();
        }
        drawPortal();
      }
      drawMaze(mazeArray);
      updateBallPosition();
      drawBall(ballPos);
      
      if (checkIfWin()){
        //reset game and show finish screen
        gameStarted = 0;
        t = millis();
        timer = (millis() - timer) / 1000;
        
        while (millis() - t < 5000){
          showResult();
          checkButton(1);
          
          if (gameStarted == 1) break;  
        }
        difficultySelected = 0;
        ballPos[0] = 1;
        ballPos[1] = 1; 
        viewNum = 0;
        pathWidth = 8;
        pathNum = 0;
      } 
    }
    
    else {
      //game has started, allow user to select the maze they want
      checkButton(0);
      showSelectDifficultyInstruction(); 
    } 
  }
  
  else {
    //game has not started. prompt to shake device
    showStartInstruction(); 
  }
  OrbitOledUpdate();
  delay(150);
}
