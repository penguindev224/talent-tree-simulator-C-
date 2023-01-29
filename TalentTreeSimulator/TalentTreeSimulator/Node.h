
#ifndef node_H
#define node_H
#include <iostream>
using namespace std;

class Node {


	//Initialize all the properties to form linked list node
public:

	Node* next;
	int Atk;
	int Magic;
	int HP;
	int MP;
	string skill;
	int cost;
	int index;
	bool visit;
	bool modify;
	bool viable;
	bool Looped;

	//Initialize the components of node
	Node();
	//~Node();

};

#endif