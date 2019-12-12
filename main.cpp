#include <iostream>
#include "Maze.h"
using namespace std;


int main()
{
    Maze maze = Maze(15,15);
    maze.MakeCleanMaze();
    maze.Show();

    cout << "\n\n" ;

    maze.MakeMaze();
    maze.Show();

    return 0;
}
