#include "Stack.h"

//Initialize the neccessary components for stack
Stack::Stack(int size) {

	max = size;
	nodes = new Node*[size];
	currTop = -1;

}


//release the dynamic memory usage of the pointer-to-pointer array
Stack::~Stack() {

	delete[] nodes;

}


//Check whether the stack is empty currently
bool Stack::Empty() const {

	return currTop == -1;

}


//Check whether the stack is full currently
bool Stack::Full() const {

	return currTop == max;

}


//Push the element into the stack
void Stack::push(Node* x) {

		nodes[++currTop] = x;

}


//Release the space of stack and output the elements on the top of the stack
Node* Stack::pop() {

	if (Empty())
		return NULL;
	else
		return nodes[currTop--];

}


//Take a look on the top of the stack
Node* Stack::top() const {

	if (Empty()) 
		return NULL;
	else
		return nodes[currTop];

}
