#include <iostream>
#include "Maze.h"
using namespace std;


int main() {
    int choise;
    int rows, cols;
    char string[81];
    srand(time(nullptr));

    cout << "Maze: 1) From input 2) Random";
    cin >> choise;
    if(choise != 1 && choise != 2)
    {
        cout << "Wrong input!";
        exit(1);
    }
    cin.ignore();
    cin >> rows;
    cin >> cols;
    cin.ignore();

    if (rows > 25 || cols > 80 || rows < 1 || cols < 1) {
        cout << "\ninvalid input";
        exit(1);
    }

    Maze maze(cols, rows);

    if (choise == 1) {
        for (int i = 0; i < rows; i++) {
            cin.getline(string, 81);
            if (!maze.buildMazeWithRows(string, i)) {
                cout << "\ninvalid input";
                exit(1);
            }
        }
    } else
    {
        if(rows % 2 == 0 || cols % 2 == 0 )
        {
            cout << "\ninvalid input";
            exit(1);
        }
        maze.MakeMaze();
    }

    maze.SolveMaze();
    maze.Show();

    return 0;
}