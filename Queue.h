#ifndef MAZEPROJECT_QUEUE_H
#define MAZEPROJECT_QUEUE_H

#include <iostream>
#include "Node.h"
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int head;
    int tail;
    Node * data;
    static int AddOne(int x);

public:
    Queue(int size);
    Queue();
    ~Queue();
    void MakeEmpty();
    int IsEmpty();
    Node * Front();
    void EnQueue(Node * item);
    Node * DeQueue();
};


#endif //MAZEPROJECT_QUEUE_H
