#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include <string.h>
#include "Point.h"
#include <vector>

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
    Point* getPosibleMoves(const Point& p,int* movesAmount, int val);
    void RemoveWalls(const Point& loc, const Point& dest);
    void CleanDollars();

    // returns maze char by points coordinats
    char GetMazeCharByPoint(Point coordPoint) { return maze[coordPoint.col][coordPoint.row]; }

    // sets maze char by points coordinats
    void SetMazeCharByPoint(Point coordPoint, char charToSet) { maze[coordPoint.col][coordPoint.row] = charToSet; }

    // returns mazes' number of columns
    int GetMazeCols() { return cols; }

    // returns mazes' number of rows
    int GetMazeRows() { return rows; }

    // returns a vector of possible paths in a made maze
//	vector<Point> GetPossibleMoves(const Point&);

    // returns false if the maze is not correct.
    bool buildMazeWithRows(const char* row, int line);

    // Marks possible path with '$' until it finds the exist to the maze
    void SolveMaze();
};

#endif //__MAZE_H
