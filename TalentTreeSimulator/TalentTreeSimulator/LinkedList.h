#ifndef List_h
#define List_h
#include "Node.h"

class LinkedList {


	//Initialize the neccessary properties for the program
public:
	Node* head;
	Node* head2;
	Node* head3;
	Node* head4;
	Node* head5;
	Node* head6;
	Node* head7;
	Node* head8;
	Node* head9;
	Node* head10;
	Node* head11;
	Node* head12;
	Node* head13;
	Node* head14;
	Node* head15;


	//Initialize 15 heads of linked list
	LinkedList();

	//release the dynamic memory of the heads
	~LinkedList();

	//Return the address of the heads
	Node* getHead(int in);

	//Set the address as the head
	void setHead(Node* in, int i);

};

#endif