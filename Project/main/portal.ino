#include "portal.h"

void updatePortalPosition(){
  for (int i = 0; i < 2; i++){
    do{
      portalPos[i][0] = random(128 / (pathWidth + 1) * (pathWidth + 1) - 1);
      portalPos[i][1] = random(32 / (pathWidth + 1) * (pathWidth + 1) - 1);
    } while (mazeArray[portalPos[i][0] - 1][portalPos[i][1]] == 1 || mazeArray[portalPos[i][0] + 1][portalPos[i][1]] == 1 || mazeArray[portalPos[i][0]][portalPos[i][1] - 1] == 1 || mazeArray[portalPos[i][0]][portalPos[i][1] + 1] == 1);
  }
}

int checkIfOnPortal(){
  int onPortal= 0;
  for (int i = 0; i < 2; i++){
    if ((ballPos[0] == portalPos[i][0] && ballPos[1] - portalPos[i][1] > -2 && ballPos[1] - portalPos[i][1] < 2) || (ballPos[1] == portalPos[i][1] && ballPos[0] - portalPos[i][0] > -2 && ballPos[0] - portalPos[i][0] < 2)){
      onPortal = i + 1;
    }
  }
  if (onPortal == 0){
    transferred = 0;
  }
  return onPortal;
}


