#include "ball.h"

void updateBallPosition(){
  if (mazeArray[ballPos[0] + ballVel[0]][ballPos[1] + ballVel[1]] == 0){
    ballPos[0] += ballVel[0];
    ballPos[1] += ballVel[1];
  }
  //if the game mode includes walls and portals
  if (isPathBlocked == 1){
    int onPortal = checkIfOnPortal();
    if (onPortal > 0 && transferred == 0){
      transferBall(onPortal);
      transferred = 1;
    }
  }
}

int checkIfWin(){
  if ((ballPos[0] >= finishX && ballPos[1] >= finishY ) || (difficultySelected == 1 && viewNum == 0)){
    return 1;
  }
  return 0;
}

void transferBall(int i){
  ballPos[0] = portalPos[2 - i][0];
  ballPos[1] = portalPos[2 - i][1];
}

