#ifndef MAZEPROJECT_QUEUE_H
#define MAZEPROJECT_QUEUE_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
typedef char Type;

class Queue
{
private:
    int head;
    int tail;
    Type* data;
    static int AddOne(int x);

public:
    Queue(int size);
    Queue();
    ~Queue();
    void MakeEmpty();
    int IsEmpty();
    Type Front();
    void EnQueue(Type item);
    Type DeQueue();
};


#endif //MAZEPROJECT_QUEUE_H
