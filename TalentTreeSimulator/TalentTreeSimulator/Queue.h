#ifndef queue_h
#define queue_h
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Queue {


	//Initialize the necessary component for queue
private:

	Node** nodes;
	int front;
	int back;
	int counter;
	int maxSize;


public:


	//Initialize the necessary component for queue
	Queue(int);

	//Release the dynamic memory allocation of node** array
	~Queue();


	//return the value without put out that from the queue
	Node* look();

	//Check whether the queue is empty
	bool Empty() const;

	//return the value and put it out from the queue
	Node* dequeue();	

	//Check whether the queue is full
	bool Full() const;

	//Put the value into queue
	void enqueue(Node* );



};


#endif