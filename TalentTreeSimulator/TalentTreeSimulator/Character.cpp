
#include "Character.h"



//Initialize the variables those belong to character class
Character::Character() {

	name = "";
	Atk = 0;
	Magic = 0;
	HP = 0;
	MP = 0;
	cost = 99999;
	count = 1;
	type = "";

	for (int i = 0; i < 30; i++) {
		skills[i] = "";
	}




}



//Set profession and set the status which belong to the initial setting of the profession
void Character::setType(char in) {

	if (in == 'm' || in == 'M') {
		type = "Mage";
		HP = 20;
		Magic = 30;
		MP = 25;
		Atk = 5;
	}
	else if (in == 'w' || in == 'W') {
		type = "Warrior";
		HP = 30;
		Magic = 10;
		MP = 10;
		Atk = 30;
	}

}


//Set the name of the object
void Character::setName(string in) {

	name = in;

}


//return the name of the character
string Character::returnName() {
	return name;
}


//return current strength point
int Character::returnAtk() {
	return Atk;
}


//return current intelligent point
int Character::returnMag() {
	return Magic;
}


//return current magic point
int Character::returnMP() {
	return MP;
}


//return current health point
int Character::returnHP() {
	return HP;
}


//return current cost of the character
int Character::returnCost() {
	return cost;
}


//return the profession of character
string Character::returnType() {
	return type;
}


//set the cost of character into 99999
void Character::setInfinite() {

	cost = 99999;
	cout << "The cost has been updated sucessfully."<<endl;
	cout << "Now you have " << cost << " costs." << endl;

}


//get status or skills from nodes
//and store it into the character status
void Character::obtainNodes(Node* in) {

	
	if (in != NULL) {
			if (cost < in->cost) {
			cout << "Error! You have not enough costs!" << endl;
		}
		else if (in->visit == false && in->viable == true) {

			if (in->skill != "") {
				skills[count] = in->skill;
				count++;
			}
			if (in->MP > 0) {
				MP += in->MP;
			}
			if (in->HP > 0) {
				HP +=  in->HP;
			}
			if (in->Magic > 0) {
				Magic += in->Magic;
			}
			if (in->Atk > 0) {
				Atk += in->Atk;
			}

			cost -= in->cost;


			//Set the node condition into visited
			//and the same node cannot be obtained again
			in->viable = false;
			in->visit = true;
			in->Looped = true;


			//Check the next viable way after obtaining the node
			autoCheck(in);


			//Store the obtained newly added node(index>=46) for roll back purpose in future
			storeAddedChange(in);


		}
	}
		else {
		
			cout << "Error! The node has been visited." << endl;
		
		}




	}



//return the skills from the position of the skills array
string Character::returnskills(int num) {

	return (skills[num]);

}



//Roll back when the newly added node (node which is added in edit mode) has been deleted
void Character::rollBack(int Id) {


	if (Id >= 46) {
		for (Node* i = returnStoredHead(); i != NULL; i = i->next) {
			if (Id == i->index) {
				Atk -= i->Atk;
				MP -= i->MP;
				HP -= i->HP;
				Magic -= i->Magic;
				if (i->skill != "") {
					for (int k = 0; k < 30; k++) {
						if (skills[k] == i->skill)
							skills[k] = "";
					}
				}
			}

		}

	}
}



//Obtain the list of nodes of the searched path
void Character::ObtainList(Node** SLL) {

	for (int i = 0; i < 30; i++) {
		if (SLL[i] != NULL) {
			obtainNodes(SLL[i]);
		}
		else { break; }
	}

}