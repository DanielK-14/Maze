//
// Created by Daniel Kalmykov on 03/12/2019.
//

#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include <string.h>
#include "Point.h"

using namespace std;

const int MAX_ROWS = 25;
const int MAX_COLS = 80;

class Maze
{
private:
    int cols;
    int rows;
    char** maze;

public:
    Maze();
    Maze(int _width, int _height);
    ~Maze();

    void MakeCleanMaze();
    void Show();
    void MakeMaze();
    Point* getPosibleMoves(const Point& p,int* movesAmount);
    void RemoveWalls(const Point& loc, const Point& dest);
    void CleanDollars();
};



#endif //__MAZE_H
