#pragma once

typedef	int Type;
class Node {

public:	

	Type data;
	Node *next;

	Node() {
		
		next = nullptr;
	}

	Node(Type item, Node *ptr = nullptr) {
		
		data = item;
		next = ptr;
	}

	~Node();

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
