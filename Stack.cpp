#include "Stack.h"

void Stack::MakeEmpty() {

	Node *temp;

	while (top != NULL) {
		temp = top;
		top = top->next;
		delete temp;
	}
}