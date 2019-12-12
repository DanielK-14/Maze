#ifndef MAZEPROJECT_POINT_H
#define MAZEPROJECT_POINT_H

#include <iostream>
using namespace std;

class Point
{
private:
    int row;
    int col;

public:
    Point() = default;
    Point(int _row,int _col)
    {
        row = _row;
        col = _col;
    }
    void Show()
    {
        cout << "(" << col << "," << row << ")";
    }

    friend class Stack;
    friend class Maze;
};
#endif //MAZEPROJECT_POINT_H
