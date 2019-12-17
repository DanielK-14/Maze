#include "Maze.h"
#include "Point.h"
#include "Stack.h"
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
    Stack stack;
    stack.Push(Point(1,1));
    maze[1][1] = '$';

    while(!stack.IsEmpty())
    {
        Point p = stack.Pop();
        int movesAmount = 0;
        Point* moves = getPosibleMoves(p,&movesAmount);
        if(moves != NULL)
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

Point* Maze::getPosibleMoves(const Point& point,int* movesAmount)
{
    Point* moves = new Point[4];
    if(point.col + 2 <= cols-2 && maze[point.col+2][point.row] != '$')   ///Right
    {
        moves[*movesAmount] = Point(point.row , point.col+2);
        (*movesAmount)++;
    }
    if(point.row + 2 <= rows-2 && maze[point.col][point.row+2] != '$')   ///Down
    {
        moves[*movesAmount] = Point(point.row + 2, point.col);
        (*movesAmount)++;
    }
    if(point.col - 2 >= 1 && maze[point.col-2][point.row] != '$')   ///Left
    {
        moves[*movesAmount] = Point(point.row , point.col-2);
        (*movesAmount)++;
    }
    if(point.row - 2 >= 1 && maze[point.col][point.row-2] != '$')   ///Up
    {
        moves[*movesAmount] = Point(point.row - 2, point.col);
        (*movesAmount)++;
    }
    if(*movesAmount < 4)
    {
        if(*movesAmount == 0)
            return NULL;
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

vector<Point> Maze::GetPossibleMoves(const Point& point) {

	vector<Point> moves;
 
	if (point.col + 1 <= cols - 1 && maze[point.col + 1][point.row] == ' ')   ///Right
	{
		moves.push_back(Point(point.row, point.col + 1));
	}
	if (point.row + 1 <= rows - 1 && maze[point.col][point.row + 1] == ' ')   ///Down
	{
		moves.push_back(Point(point.row + 1, point.col));
	}
	if (point.col - 1 >= 1 && maze[point.col - 1][point.row] == ' ')   ///Left
	{
		moves.push_back(Point(point.row, point.col - 1));
	}
	if (point.row - 1 >= 1 && maze[point.col][point.row - 1] == ' ')   ///Up
	{
		moves.push_back(Point(point.row - 1, point.col));
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
            cout << maze[j][i] << " ";
        }
        cout << endl;
    }
}