#pragma once

#include <iostream>
#include <string.h>
#include "Point.h"
#include "Maze.h"
#include <vector>

class MazeSolver {
private:

public:

	// Marks possible path with '$' until it finds the exist to the maze
	static void SolveMaze(Maze * maze);
};
