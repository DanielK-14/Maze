#include <iostream>
#include "Maze.h"
#include "MazeSolver.h"
using namespace std;


int main()
{
    Maze maze = Maze(15,15);
    maze.MakeCleanMaze();
    maze.Show();

    cout << "\n\n" ;
	//srand(time(nullptr));
    maze.MakeMaze();
    maze.Show();

	MazeSolver::SolveMaze(&maze);
	maze.Show();

    return 0;
}
