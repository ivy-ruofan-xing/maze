#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

int ballVel[2] = {1, 0};
int ballPos[2] = {1, 1};
int transferred = 0;

void updateBallPosition();  //update the ball position so it can be redrawn

int checkIfWin(); //check of the ball is at the finish, or if the level is zero. (because level zero should automatically win)

void transferBall(int i);

#endif
