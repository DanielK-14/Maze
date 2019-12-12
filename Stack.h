#ifndef MAZEPROJECT_STACK_H
#define MAZEPROJECT_STACK_H

#include "Node.h"
#include <iostream>
#include "Point.h"

using namespace std;

class Point;

class Stack {

private:
	Node* top;

public:
	Stack()
	{
		top = nullptr;
	}
	
	~Stack()
	{
		MakeEmpty();
	}
	
	void MakeEmpty();
	
	int IsEmpty()
	{
		return top == nullptr;
	}
	
	void Push(Point p)
	{
	    if(top == nullptr)
		    top = new Node(p);
        else
        {
            Node* temp = new Node(p,top);
            top = temp;
        }
	}
	
	Point Pop()
	{
		if (IsEmpty())
		{
			std::cout << "ERROR: STACK UNDERFLOW\n";
		}

		Node* temp = top;
        Point p = top->data;
		top = top->next;
		delete temp;
		return p;
	}
};

#endif //MAZEPROJECT_STACK_H
