#include "Queue.h"

Queue::Queue(int size)  ///Size by user
{
    head = 2;
    tail = 1;
    data = new Node[size + 1];
}

Queue::Queue() ///Default size with out user input
{
    head = 1;
    tail = 0;
    data = new Node[2001];
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

Node * Queue::Front()
{
    if(IsEmpty())
    {
        cout << "Error: QUEUE EMPTY\n"; exit(1);
    }
    return(&data[head]);
}

void Queue::EnQueue(Node * item)
{
    if(AddOne(AddOne(tail)) == head)
    {
        cout << "Error: QUEUE FULL\n"; exit(1);
    }
    tail = AddOne(tail);
    data[tail] = *item;
}

Node * Queue::DeQueue()
{
    if(IsEmpty())
    {
        cout << "Error QUEUE EMPTY\n"; exit(1);
    }
    Node * item = &data[head];
    head = AddOne(head);
    return(item);
}