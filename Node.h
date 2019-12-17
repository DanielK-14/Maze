#pragma once

#include "Point.h"
class Node {

public:
    Point data;
	Node *next;

	Node() {
		
		next = NULL;
	}

	Node(Point p, Node *ptr = NULL) {
		
		data = p;
		next = ptr;
	}

	void InsertAfter(Node *newNode) {
		
		newNode->next = next;
		next = newNode;
	}

	Node *DeleteAfter(void) {
		
		Node *temp = next;

		if (next == NULL) {
			return NULL;
		}

		next = temp->next;

		return temp;
	}

};
