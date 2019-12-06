#include "Stack.h"

void Stack::MakeEmpty() {

	Node *temp;

	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
	}
}