#ifndef stack_h
#define stack_h
#include "Node.h"

class Stack {


	//Define the neccessary components for stack
private:

	Node** nodes;	
	int max;
	int currTop;


public:



	//Initialize the neccessary components for stack
	Stack(int);

	//release the dynamic memory usage of the pointer-to-pointer array
	~Stack();

	//Check whether the stack is empty currently
	bool Empty() const;

	//Push the element into the stack
	void push(Node* );

	//Take a look on the top of the stack
	Node* top() const;

	//Check whether the stack is full currently
	bool Full() const;	

	//Release the space of stack and output the elements on the top of the stack
	Node* pop();



};


#endif