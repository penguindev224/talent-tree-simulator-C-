
#ifndef tree_h
#define tree_h
#include "LinkedList.h"



class TalentTree {


	//Initialize all the neccessary properties for further process
private:

	Node* Id5;
	Node* Id4;
	Node* Id3;
	Node* Id2;
	Node* Id25;
	Node* Id26;
	Node* Id27;
	Node* Id29;

	LinkedList obj;
	LinkedList storeNew;

	int indexCount;


public:


	//Initialize the entire talent tree, 
	//including each of the linked list and the connection between them
	TalentTree();

	//Delete all the linked list and release the dynamic memory
	~TalentTree();



	//Free the dynamic memory allocation of the pointer-to-pointer array
	void FreeArr(Node** );

	//Assign the value of costs using specific algorithm
	void LoopCost(Node** );

	//Calcalate the cost of the talent tree nodes
	void CostCal();

	//Edit Mode: open for user to add node into the existing linked list
	void Addnode(int Id, string skill, int status, string control, char type);

	//Creat a new node with index and status according to the control data
	Node* AddStatus(int Id, int status,string control);

	//Add a new node with skill and index
	Node* AddSkill(int Id, string skill);

	//Edit Mode: open for user to delete node from the existing linked list
	void EditDeletion(int Id);

	//Release the memory of linked list from its head position
	void Check(Node*);

	//Check whether the linked list be established properly
	void output(Node* );

	//return the total costs of the unvisited nodes
	int totalCost();

	//return the cost in the node
	int returnCost(Node* );

	//Display the whole view of talent tree
	void Displaytree();

	//Display the skill or status with alignment
	void DisplayBlock(Node* in);

	//Output which node is available to be obtained by user
	void FindViable();

	//Find the minimum cost of the nodes which is able to be obtained
	int findMinCost(int indexNum);

	//Take role as a indicator to determine the way to go
	void autoCheck(Node* );

	//Find the node with the required index number
	Node* findIndex(int n);

	//Set the viable = false ,visit = true,looped = true in the node
	//so that the user never travel the same node again
	void Nodestatus(Node* );

	//store the status / skills of the newly added node
	//for roll back purpose in the future
	void storeAddedChange(Node* in);

	//return the head for roll back function
	Node* returnStoredHead();

	//Search and print the path to derive the node
	void searchFuction(Node* );

	//Print out the search result
	void printSearch(int n, int& cost,Node* in);

	//Store the nodes of the searched path into a pointer-to-pointer array and return the first position of the array
	Node** returnListedNodes(int n, Node* in);

	//Find the head number
	int FindHeadNUM(int index, Node* in);


};


#endif