#include "button.h"

void setupButton(){
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT);
}

void checkButton(int stage){
  if (stage == 0){
    b2State = digitalRead(b2);
    
    if (b2State==LOW){
      viewNum++;
      
      if (viewNum > 6){
        //does not go back to zero, because you should only be allowed the one chance to win immediately... ;)
        viewNum = 1;
      }
      pathWidth -= 2;

      if (viewNum == 1){
        pathWidth = 8;
        isPathBlocked = 0;  //normal game mode
      }
      
      if (viewNum == 4){
        pathWidth = 8;
        isPathBlocked = 1;  //portal game mode
      }
      
      finishX = 128 / (pathWidth + 1) * (pathWidth + 1) - 5;
      finishY = 32 / (pathWidth + 1) * (pathWidth + 1);
    }
    
    b1State = digitalRead(b1);
    if(b1State == LOW){
      difficultySelected = 1;
      createMaze();
      t = millis();
      timer = millis();
      if (isPathBlocked == 1){
        pathBlock();
        updatePortalPosition();
      }
    }
  }

  if (stage == 1){
    b3State = digitalRead(b3);
    if (b3State == HIGH){ //1 when pressed, 0 when released
      gameStarted = 1;
    }
  }
}






