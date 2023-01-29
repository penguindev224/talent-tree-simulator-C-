#ifndef CHAR_H
#define CHAR_H
#include "TalentTree.h"
#include "LinkedList.h"

class Character : public TalentTree {


private:


	//Define the necessary properties to proceed the game
	string name;
	int Atk;
	int Magic;
	int HP;
	int MP;	
	int count;
	int cost;
	string type;
	string skills[30];
	string store[30];

	int SAtk;
	int SMagic;
	int SHP;
	int SMP;



public:


	//Initialize the variables those belong to character class
	Character();



	//return the name of the character
	string returnName();


	//Set profession and set the status which belong to the initial setting of the indicated profession
	void setType(char );


	//return current strength point
	int returnAtk();


	//return current intelligent point
	int returnMag();


	//return current health point
	int returnHP();


	//return current cost of the character
	int returnCost();


	//return the profession of character
	string returnType();


	//return current magic point
	int returnMP();


	//Roll back when the newly added node has been deleted
	void rollBack(int Id);


	//return the skills from the position of the skills array
	string returnskills(int );


	//Set the name of the object
	void setName(string in);


	//set the cost of character into 999
	void setInfinite();


	//get status or skills from nodes
	void obtainNodes(Node* in);


	//Obtain the list of the searched path
	void ObtainList(Node** SLL);


};

#endif