#include "maze.h"

int orientation(int width, int height){
  if (width == height) return random(2);
  return (width < height);
}

void setMaze(int x, int y, int width, int height, int horizontal){
  if (width <  2 || height < 2){
    return;
  }

  //start point of wall
  int wx = x + (horizontal ? 0 : random(width - 2) + 1);
  int wy = y + (horizontal ? random(height - 2) + 1 : 0);

  //passage position
  int px = wx + (horizontal ? random(width) : 0);
  int py = wy + (horizontal ? 0 : random(height));
  

  //wall direction
  int dx = horizontal;
  int dy = 1 - horizontal;

  //changed the dynamic array to hold the location and orientation of the paths
  pathArray = (int*)realloc(pathArray, (pathNum + 1) * 4 * sizeof(int));
  pathArray[(pathNum * 4)] = px;
  pathArray[(pathNum * 4) + 1] = py;
  pathArray[(pathNum * 4) + 2] = dx;
  pathArray[(pathNum * 4) + 3] = dy;
  pathNum++;

  //length of wall
  int len = horizontal ? width : height;

  //change grid
  for (int i = 0; i < len; i ++){
    if (i * dx + x == px || i * dy + y == py) continue;
    for (int j = 0; j <= pathWidth + 1; j++){
      int ax = (wx + dx * i) * (pathWidth + 1) + j * dx;
      int ay = (wy + dy * i) * (pathWidth + 1) + j * dy;

      mazeArray[ax][ay] = 1;
    }
  }

  //recurse
  //upper or left
  int nx = x;
  int ny = y;
  int nw = horizontal ? width : wx - x;
  int nh = horizontal ? wy - y : height;
  setMaze(nx, ny, nw, nh, orientation(nw, nh));
  
  //lower or right
  nx = horizontal ? x : wx;
  ny = horizontal ? wy : y;
  nw = horizontal ? width : x + width - wx;
  nh = horizontal ? y + height - wy : height;
  setMaze(nx, ny, nw, nh, orientation(nw, nh));
  
}

void createMaze(){
  //initialize mazeArray[128][32]
  for(int i = 0; i < 128; i++){
    for(int j = 0; j < 32; j++){
      mazeArray[i][j] = 0;
    } 
  }

  int width = 128 / (pathWidth + 1);
  int height = 32 / (pathWidth + 1);
  
  for(int i = 0;i<width * (pathWidth + 1);i++){
    mazeArray[i][0] = 1;
    mazeArray[i][height * (pathWidth + 1)] = 1;
  }
  for(int j = 0;j<height * (pathWidth + 1);j++){
    mazeArray[0][j] = 1;
    mazeArray[width * (pathWidth + 1)][j] = 1;
  }
  
  //set the walls to 1
  setMaze(0, 0, width, height, orientation(width, height));
  
}

