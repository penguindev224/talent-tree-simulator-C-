#include "Queue.h"


//Initialize the necessary component for queue
Queue::Queue(int size) {

	nodes = new Node*[size];
	maxSize = size;
	front = 0;
	back = -1;
	counter = 0;

}


//Release the dynamic memory allocation of node** array
Queue::~Queue() {

	delete[] nodes;

}



//Check whether the queue is empty
bool Queue::Empty() const {

	if (counter)
		return false;

	else
		return true;

}



//Check whether the queue is full
bool Queue::Full() const {

	if (counter < maxSize)
		return false;

	else
		return true;

}



//Put the value into queue
void Queue::enqueue(Node* in) {

		back = (back + 1) % maxSize;
		nodes[back] = in;
		counter++;
	
}


//return the value and put it out from the queue
Node* Queue::dequeue() {

	Node* a = NULL;

	if (Empty())
		return NULL;
	else {
		a = nodes[front];
		front = (front + 1) % maxSize;
		counter--;
		return a;
	}

}


//return the value without put out that from the queue
Node* Queue::look() {

	Node* a = NULL;

	if (Empty())
		return NULL;

	else {
		a = nodes[front];
		return a;
	}

}