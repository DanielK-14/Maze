#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

typedef int Type;

class Stack {

private:
	Node* top;

public:
	Stack() {

		top = nullptr;
	}
	
	~Stack() {

		MakeEmpty();
	}
	
	void MakeEmpty();
	
	int IsEmpty() {
		return top == nullptr;
	}
	
	void Push(Type item) {
		top = new Node(item);
	}
	
	Type Pop() {
		if (IsEmpty()) {
			std::cout << "ERROR: STACK UNDERFLOW\n";
		}

		Node* temp = top;
		Type item = top->data;
		top = top->next;
		delete temp;
		return item;
	}
};
