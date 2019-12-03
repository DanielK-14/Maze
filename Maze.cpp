//
// Created by Daniel Kalmykov on 03/12/2019.
//

#include "Maze.h"

Maze::Maze()
{
    cols = MAX_COLS;
    rows = MAX_ROWS;
    maze = new char*[cols];
    for (int i = 0; i < cols; i++)
        maze[i] = new char[rows];
}

Maze::Maze(int _width, int _height)
{
    cols = _width;
    rows = _height;
    maze = new char*[cols];
    for (int i = 0; i < cols; i++)
        maze[i] = new char[rows];
}

Maze::~Maze()
{
    cout << endl << "D'tor" << endl;
    delete[] *maze;
    delete[] maze;
}

void Maze::MakeCleanMaze()
{
    for(int i = 0 ; i < cols ; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if(j==0 || j==rows-1 || i==0 || i==cols-1 || i%2==0 || j%2==0)
                maze[i][j] = '*';
            else
                maze[i][j] = ' ';
        }
    }
    maze[0][1] = ' ';
    maze[cols-1][rows-2] = ' ';
}

void Maze::Show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << maze[j][i] << " ";
        }
        cout << endl;
    }
}