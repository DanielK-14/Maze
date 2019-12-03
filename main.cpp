#include <iostream>
#include "Maze.h"
using namespace std;


int main()
{
    cout << "Hello, World!" << std::endl;

    Maze maze = Maze(11,11);
    maze.MakeCleanMaze();
    maze.Show();

    return 0;
}