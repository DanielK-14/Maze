#include "Maze.h"
#include "Point.h"
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

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

void Maze::MakeMaze()
{
    MakeCleanMaze();
    Stack stack;
    stack.Push(Point(1,1));
    maze[1][1] = '$';

    while(!stack.IsEmpty())
    {
        Point p = stack.Pop();
        int movesAmount = 0;
        Point* moves = getPosibleMoves(p,&movesAmount,2);
        if(moves != nullptr)
        {
            int rand_move = rand() % movesAmount+1;
            RemoveWalls(p,moves[rand_move-1]);
            maze[moves[rand_move-1].col][moves[rand_move-1].row] = '$';
            stack.Push(p);
            stack.Push(moves[rand_move-1]);
            delete[] moves;
        }
    }
    CleanDollars();
}

Point* Maze::getPosibleMoves(const Point& point,int* movesAmount, int val)
{
    Point* moves = new Point[3];
    if(point.col + val <= cols-val && maze[point.col+val][point.row] == ' ')   ///Right
    {
        moves[*movesAmount] = Point(point.row , point.col+val);
        (*movesAmount)++;
    }
    if(point.row + val <= rows-val && maze[point.col][point.row+val] == ' ')   ///Down
    {
        moves[*movesAmount] = Point(point.row + val, point.col);
        (*movesAmount)++;
    }
    if(point.col - val >= 1 && maze[point.col-val][point.row] == ' ')   ///Left
    {
        moves[*movesAmount] = Point(point.row , point.col-val);
        (*movesAmount)++;
    }
    if(point.row - val >= 1 && maze[point.col][point.row-val] == ' ')   ///Up
    {
        moves[*movesAmount] = Point(point.row - val, point.col);
        (*movesAmount)++;
    }
    if(*movesAmount < 3)
    {
        if(*movesAmount == 0)
            return nullptr;
        Point* movesNew = new Point[*movesAmount];
        for (int i = 0; i < *movesAmount; i++)
        {
            movesNew[i] = moves[i];
        }
        delete[] moves;
        return movesNew;
    }
    return moves;
}

void Maze::RemoveWalls(const Point& loc, const Point& dest)
{
    if(dest.col == loc.col+2) /// Right
        maze[loc.col+1][loc.row] = ' ';

    else if(dest.row == loc.row+2) /// Down
        maze[loc.col][loc.row+1] = ' ';

    else if(dest.col == loc.col-2) /// Left
        maze[loc.col-1][loc.row] = ' ';

    else /// Up
        maze[loc.col][loc.row-1] = ' ';
}

void Maze::CleanDollars()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(maze[j][i] == '$')
                maze[j][i] = ' ';
        }
    }
}

void Maze::Show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << maze[j][i];
        }
        cout << endl;
    }
}

bool Maze::buildMazeWithRows(const char *row, int line)
{
    for (int i = 0; i < cols ; i++)
    {
        if(row[i] != ' ' && row[i] != '*')
            return false;

        if((line == rows-1 || line == 0) && row[i] != '*')
            return false;

        if((row[0] != '*' && line != 1) || (row[cols-1] != '*' && line != rows-2))
            return false;

        if((line == 1 && row[0] != ' ') || (line == rows-2 && row[cols-1] != ' '))
            return false;

        maze[i][line] = row[i];
    }
    return true;
}

void Maze::SolveMaze()
{
    Point end(rows-2,cols-1);
    Point start(1,0);
    Queue movesQueue(rows*cols);
    movesQueue.EnQueue(start);

    while(!movesQueue.IsEmpty())
    {
        Point point = movesQueue.DeQueue();
        maze[point.col][point.row] = '$';

        if(point == end)   ///Reached to the end of the maze
            break;

        else
        {
            int movesAmount = 0;
            Point* moves = getPosibleMoves(point,&movesAmount,1);
            for (int i = 0; i < movesAmount; i++)
                movesQueue.EnQueue(moves[i]);
        }
    }
}