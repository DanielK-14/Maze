#include "Queue.h"

Queue::Queue(int size)  ///Size by user
{
    head = 1;
    tail = 0;
    data = new Point[size/2 + 1];
}

Queue::Queue() ///Default size with out user input
{
    head = 1;
    tail = 0;
    data = new Point[MAX_SIZE];
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::MakeEmpty()
{
    head = 1;
    tail = 0;
}

int Queue::AddOne(int x)
{
    return ((1+x) % MAX_SIZE);
}

int Queue::IsEmpty()
{
    return (AddOne(tail) == head);
}

Point Queue::Front()
{
    if(IsEmpty())
    {
        cout << "Error: QUEUE EMPTY\n"; exit(1);
    }
    return(data[head]);
}

void Queue::EnQueue(const Point& point)
{
    if(AddOne(AddOne(tail)) == head)
    {
        cout << "Error: QUEUE FULL\n"; exit(1);
    }
    tail = AddOne(tail);
    data[tail] = point;
}

Point Queue::DeQueue()
{
    if(IsEmpty())
    {
        cout << "Error QUEUE EMPTY\n"; exit(1);
    }
    Point item = data[head];
    head = AddOne(head);
    return(item);
}