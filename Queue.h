#ifndef MAZEPROJECT_QUEUE_H
#define MAZEPROJECT_QUEUE_H

#include <iostream>
#include "Node.h"
#include "Point.h"

using namespace std;

const int MAX_SIZE = 1001; // default max size in case maze 25x80 , 1 is to be letf empty

class Queue
{
private:
    int head;
    int tail;
    Point* data;
    static int AddOne(int x);

public:
    Queue(int size);
    Queue();
    ~Queue();
    void MakeEmpty();
    int IsEmpty();
    Point Front();
    void EnQueue(const Point& point);
    Point DeQueue();
};


#endif //MAZEPROJECT_QUEUE_H
