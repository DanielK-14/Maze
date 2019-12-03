#include <iostream>
#include "Maze.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    Maze maze2 = Maze(11,11);
    maze2.MakeCleanMaze();
    maze2.Show();

    return 0;
}

