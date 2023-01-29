
#include "Node.h"


//Initialize the components of node
Node::Node() {

	next = NULL;
	Atk = 0;
	Magic = 0;
	HP = 0;
	MP = 0;
	skill = "";
	cost = 0;
	index = 0;
	visit = false;
	viable = false;
	Looped = false;

}
