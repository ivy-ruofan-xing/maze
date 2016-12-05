#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

int pathWidth = 8;
int pathNum = 0;
int *pathArray = (int*)malloc(4 * sizeof(int));  //holds the values for the paths between the drawn lines
int mazeArray[128][32];  //holds the values for the maze. 0 means empty space, 1 means wall etc
 

int orientation(int width, int height);  //is the wall horizontal or vertical
void setMaze(int x, int y, int width, int height, int horizontal);  //the recursive function to make the maze
void createMaze();  //calls setmaze(), and sets the walls to be drawn

#endif
