#include "MazeSolver.h"
#include "Queue.h"
#include "Node.h"
#include <windows.h>

void MazeSolver::SolveMaze(Maze * maze) {

	Queue * possibleMovesQueue = new Queue();

	// nodify maze

	int mazeMaxCols = maze->GetMazeCols();
	int mazeMaxRows = maze->GetMazeRows();

	// init maze entrance and exit
	Node * currentPathTaken = new Node(Point(1, 0));
	Point endPoint = Point(mazeMaxCols - 2, mazeMaxRows - 1);
	possibleMovesQueue->EnQueue(currentPathTaken);

	// dequeue queue, mark the current maze path with $ and enququ all possible paths from that path that we haven't traversed yet
	// loop this until found exit
	do {
		currentPathTaken = possibleMovesQueue->DeQueue();
		maze->SetMazeCharByPoint(currentPathTaken->data, '$');

		vector<Point> PossibleMovesVector = maze->GetPossibleMoves(currentPathTaken->data);
		for (Point possibeMovePoint : PossibleMovesVector)
		{
			possibleMovesQueue->EnQueue(new Node(possibeMovePoint));
		}
		//system("CLS");
		//maze->Show();
		//Sleep(200);
	} while (currentPathTaken->data != endPoint);
	
	delete possibleMovesQueue;
}