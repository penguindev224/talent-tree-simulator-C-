#include "LinkedList.h"

//Initialize 15 heads of linked list
LinkedList::LinkedList() {

	Node* head = new Node;
	Node* head2 = new Node;
	Node* head3 = new Node;
	Node* head4 = new Node;
	Node* head5 = new Node;
	Node* head6 = new Node;
	Node* head7 = new Node;
	Node* head8 = new Node;
	Node* head9 = new Node;
	Node* head10 = new Node;
	Node* head11 = new Node;
	Node* head12 = new Node;
	Node* head13 = new Node;
	Node* head14 = new Node;
	Node* head15 = new Node;

}


//release the dynamic memory of the heads
LinkedList::~LinkedList() {

	delete head,head2,head3,head4,head5,head6,head7,head8,head9,head10,head11,head12,head13,head14,head15;

}


//Return the address of the heads
Node* LinkedList::getHead(int in) {
	if (in == 1)
		return head;
	else if (in == 2)
		return head2;	
	else if (in == 3)
		return head3;	
	else if (in == 4)
		return head4;	
	else if (in == 5)
		return head5;	
	else if (in == 6)
		return head6;	
	else if (in == 7)
		return head7;	
	else if (in == 8)
		return head8;	
	else if (in == 9)
		return head9;
	else if (in == 10)
		return head10;
	else if (in == 11)
		return head11;
	else if (in == 12)
		return head12;
	else if (in == 13)
		return head13;
	else if (in == 14)
		return head14;
	else if (in == 15)
		return head15;
}


//Set the address as the head
void LinkedList::setHead(Node* in, int i) {

	if (i == 1)
		head = in;
	else if (i == 2)
		head2 = in;	
	else if (i == 3)
		head3 = in;	
	else if (i == 4)
		head4 = in;	
	else if (i == 5)
		head5 = in;	
	else if (i == 6)
		head6 = in;	
	else if (i == 7)
		head7 = in;	
	else if (i == 8)
		head8 = in;	
	else if (i == 9)
		head9 = in;	
	else if (i == 10)
		head10 = in;	
	else if (i == 11)
		head11 = in;	
	else if (i == 12)
		head12 = in;	
	else if (i == 13)
		head13 = in;	
	else if (i == 14)
		head14 = in;	
	else if (i == 15)
		head15 = in;

}

