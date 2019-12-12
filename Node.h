#pragma once

#include "Point.h"
class Node {

public:
    Point data;
	Node *next;

	Node() {
		
		next = nullptr;
	}

	Node(Point p, Node *ptr = nullptr) {
		
		data = p;
		next = ptr;
	}

	void InsertAfter(Node *newNode) {
		
		newNode->next = next;
		next = newNode;
	}

	Node *DeleteAfter(void) {
		
		Node *temp = next;

		if (next == nullptr) {
			return nullptr;
		}

		next = temp->next;

		return temp;
	}

};
