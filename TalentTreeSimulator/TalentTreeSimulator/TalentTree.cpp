#include "TalentTree.h"
#include "Stack.h"
#include "Queue.h"
#include <string>




//Initialize the entire talent tree, 
//including each of the linked list and the connection between them
TalentTree::TalentTree() {
	

	//Properties a,b,c : become the head / nodes in the linked list using LinkedList.cpp, LinkedList.h
	Node* origin = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = NULL;


	//Linked list 1: upper position of origin
	obj.setHead(origin, 1);
	obj.getHead(1)->index = 1;
	obj.getHead(1)->visit = true;
	obj.getHead(1)->next = AddStatus(2, 5, "Atk");
	a = obj.getHead(1)->next;
	a->next = AddSkill(3, "Kick I");
	b = a->next;
	b -> next = AddStatus(4, 7, "MP");
	a = new Node;
	a = b->next;
	a->next = AddStatus(5, 9, "HP");
	c = a->next;


	//Linked list 2: left of HP+9
	b = new Node;
	b = AddSkill(6, "Guard");
	obj.setHead(b,2);


	//Linked list 3: left of MP+7
	b = new Node;
	b = AddSkill(7, "JUMP II");
	obj.setHead(b,3);
	obj.getHead(3)->next = AddStatus(8, 9, "Atk");
	a = new Node;
	a = obj.getHead(3)->next;
	a->next = AddSkill(9, "Explode");
	c = a->next;


	//Linked list4: right of MP7
	a = new Node;
	a = AddSkill(10, "Poison II");
	obj.setHead(a, 4);


	//Linked list5: right of Kick I
	a = new Node;
	a = AddSkill(11, "Spin");
	obj.setHead(a, 5);
	a->next = AddStatus(12, 7, "MP");
	b = new Node;
	b = a->next;
	b->next = AddSkill(13, "Pound");
	a = new Node;
	a = b->next;
	a->next = AddSkill(14, "Rage");
	c = a->next;


	//Linked list6: left of Str+5
	a = new Node;
	a = AddSkill(15, "Jump I");
	obj.setHead(a, 6);
	a->next = AddStatus(16, 7, "Atk");
	b = new Node;
	b = a->next;
	b->next = AddSkill(17, "Jump III");
	c = b->next;


	//Linked list 7: left of origin
	a = new Node;
	a = AddStatus(18, 5, "HP");
	obj.setHead(a, 7);
	a->next = AddSkill(19, "Splash");
	b = new Node;
	b = a->next;
	b->next = AddStatus(20, 9, "Magic");
	c = b->next;


	//Linked list 8: right of origin
	a = new Node;
	a = AddStatus(21, 5, "MP");
	obj.setHead(a, 8);
	a->next = AddSkill(22, "Poison I");
	b = new Node;
	b = a->next;
	b->next = AddStatus(23, 7, "HP");
	a = new Node;
	a = b->next;
	a->next = AddStatus(24, 9, "Atk");
	c = a->next;


	//Linked list 9: lower position of origin
	a = new Node;
	a = AddStatus(25, 5, "Magic");
	obj.setHead(a, 9);
	a->next = AddStatus(26, 5, "HP");
	b = new Node;
	b = a->next;
	b->next = AddStatus(27, 7, "Atk");
	a = new Node;
	a = b->next;
	a->next = AddStatus(28, 7, "MP");
	b = new Node;
	b = a->next;
	b->next = AddSkill(29, "Fire III");
	c = b->next;


	//Linked list 10: right of Fire III
	a = new Node;
	a = AddSkill(30, "Flare");
	obj.setHead(a, 10);


	//Linked list 11: left of Str+7 (Index: 27)
	a = new Node;
	a = AddStatus(31, 7, "Magic");
	obj.setHead(a, 11);
	a->next = AddSkill(32, "Fire II");
	b = new Node;
	b = a->next;
	b->next = AddStatus(33, 9, "Atk");
	c = b->next;


	//Linked list 12: right of Str+7 (Index: 27)
	a = new Node;
	a = AddStatus(34, 7, "MP");
	obj.setHead(a, 12);
	a->next = AddSkill(35, "Ice II");
	b = new Node;
	b = a->next;
	b->next = AddStatus(36, 9, "MP");
	c = b->next;


	//Linked list 13: left of HP+5 (Index: 26)
	a = new Node;
	a = AddSkill(37, "Ice I");
	obj.setHead(a, 13);
	a->next = AddSkill(38, "Shield");
	c = a->next;


	//Linked list 14: right of HP+5 (Index: 26)
	a = new Node;
	a = AddSkill(39, "Fire I");
	obj.setHead(a, 14);
	a->next = AddStatus(40, 7, "Magic");
	b = new Node;
	b = a->next;
	b->next = AddStatus(41, 9, "HP");
	a = new Node;
	a = b->next;
	a->next = AddSkill(42, "Cure II");
	c = a->next;


	//Linked list 15: left of Int+2 (Index: 25)
	a = new Node;
	a = AddSkill(43, "Cure I");
	obj.setHead(a, 15);
	a->next = AddStatus(44, 5, "MP");
	b = new Node;
	b = a->next;
	b->next = AddStatus(45, 7, "Magic");
	a = new Node;
	a = b->next;

	c = NULL;


	//Assign a pointer to the position with other direction to go
	for (Node* i = obj.getHead(1); i != NULL; i = i->next) {
		if (i->index == 2) {
			Id2 = i;
			continue;
		}
		else if (i->index == 3) {
			Id3 = i;
			continue;
		}
		else if (i->index == 4) {
			Id4 = i;
			continue;
		}
		else if (i->index == 5) {
			Id5 = i;
			continue;
		}
	}


	for (Node* i = obj.getHead(9); i != NULL; i = i->next) {
		if (i->index == 25) {
			Id25 = i;
			continue;
		}
		else if (i->index == 26) {
			Id26 = i;
			continue;
		}
		else if (i->index == 27) {
			Id27 = i;
			continue;
		}
		else if (i->index == 29) {
			Id29 = i;
			continue;
		}

	}


	//Set the viable way at the beginning
	Node* d = NULL;
	obj.getHead(1)->visit = true;
	obj.getHead(1)->viable = false;
	obj.getHead(1)->Looped = true;
	d = obj.getHead(1)->next;
	d->viable = true;
	obj.getHead(7)->visit = false;
	obj.getHead(7)->viable = true;
	obj.getHead(7)->Looped = false;
	obj.getHead(8)->visit = false;
	obj.getHead(8)->viable = true;
	obj.getHead(8)->Looped = false;
	obj.getHead(9)->visit = false;
	obj.getHead(9)->viable = true;
	obj.getHead(9)->Looped = false;

	d = NULL;


	//Define the unique index for the edit mode use
	indexCount = 46;


	//Call function to calculate the costs of existing nodes
	CostCal();


	//Create a new linked list for roll back use
	Node* z = new Node;
	storeNew.setHead(z,1);
	storeNew.setHead(NULL, 2);
	storeNew.setHead(NULL, 3);
	storeNew.setHead(NULL, 4);
	storeNew.setHead(NULL, 5);
	storeNew.setHead(NULL, 6);
	storeNew.setHead(NULL, 7);
	storeNew.setHead(NULL, 8);
	storeNew.setHead(NULL, 9);
	storeNew.setHead(NULL, 10);
	storeNew.setHead(NULL, 11);
	storeNew.setHead(NULL, 12);
	storeNew.setHead(NULL, 13);
	storeNew.setHead(NULL, 14);
	storeNew.setHead(NULL, 15);




}




//Delete all the linked list and release the dynamic memory
TalentTree::~TalentTree() {

	Check(obj.getHead(1));
	Check(obj.getHead(2));
	Check(obj.getHead(3));
	Check(obj.getHead(4));
	Check(obj.getHead(5));
	Check(obj.getHead(6));
	Check(obj.getHead(7));
	Check(obj.getHead(8));
	Check(obj.getHead(9));
	Check(obj.getHead(10));
	Check(obj.getHead(11));
	Check(obj.getHead(12));
	Check(obj.getHead(13));
	Check(obj.getHead(14));
	Check(obj.getHead(15));

}




//Release the memory of linked list from its head position
void TalentTree::Check(Node* in) {

	Node* curr = in;
	Node* next = NULL;

	while (curr != NULL) {

		next = curr->next;

		delete curr;

		curr = next;

	}

}




//Check whether the linked list be established properly
void TalentTree::output(Node* head) {
	int counter = 0;

	for (Node* i = head; i != NULL; i = i->next) {
		cout << "Linked list -  POSITION: " << ++counter << endl;
		//cout << "Index: " << i->index << endl;
		cout << "Cost: " << i->cost << endl;
		if (i->Atk > 0) {
			cout << "Strength: " << i->Atk << endl;
			continue;
		}

		if (i->skill != "") {
			cout << "Skill: " << i->skill << endl;
			continue;
		}

		if (i->MP > 0) {
			cout << "MP: " << i->MP << endl;
			continue;
		}

		if (i->HP > 0) {
			cout << "HP: " << i->HP << endl;
			continue;
		}
		if (i->Magic > 0) {
			cout << "Int: " << i->Magic << endl;
			continue;
		}

	}

}




//Creat a new node with index and status according to the control data
//Programmer should input the control string listed below to obtain the type of status in the left
//Str = Atk;
//MP = MP;
//Int = Magic;
//HP = HP;
//This is the function for for programmer.
Node* TalentTree::AddStatus(int Id, int status,string control) {


	//Properity j: a new node to become a member of the existing linked list
	Node* j = new Node;


		//Compare the elements to the control string from function call
		//If it is match below, it will generate a new node with the amount of status from function call	
			if (control == "MP")
				j->MP = status;
			if (control == "HP")
				j->HP = status;
			if (control == "Atk")
				j->Atk = status;
			if (control == "Magic")
				j->Magic = status;

			//Generate a node with index id
			j->index = Id;

			return j;


}




//Add a new node with skill and index
//This is the function for for programmer.
Node* TalentTree::AddSkill(int Id, string skill) {


	//Properity j: a new node to become a member of the existing linked list
	Node* j = new Node;


	//Generate a new node with skill and index ID
			j->skill = skill;
			j->index = Id;

			return j;


}




//Travel thorugh all the nodes in linked list and return the total costs of the unvisited nodes
int TalentTree::totalCost() {

	int total = 0;

	for (int j = 1; j <=15; j++) {
		for (Node* i = obj.getHead(j); i != NULL; i = i->next) {
			if (i->visit == false)
				total += i->cost;
		}
	}

	return total;
}




//return the cost in the node
int TalentTree::returnCost(Node* in) {

	return (in->cost);

}




//Display the whole view of talent tree
void TalentTree::Displaytree() {

	int count = 0;
	Node *a, *b, *c, *d;

	Stack stack(10);
	Stack s2(10);
	Stack s3(10);
	Stack s4(3);
	Stack h2(3);
	Queue q1(10);

	for (Node* i = obj.getHead(1); i != NULL; i = i->next) {
		stack.push(i);
	}
	for (Node* i = obj.getHead(3); i != NULL; i = i->next) {
		s2.push(i);
	}

	for (Node*i = obj.getHead(2); i != NULL; i = i->next) {
		h2.push(i);
	}




	//The Linked list in the top (Default: Guard<<HP+9, index 6)
	cout << endl; cout << endl;
	cout << "\t\t\t\t\t";

	for(Node* i = h2.pop(); i != NULL; i = h2.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
		if (i->next != NULL)
			cout << "<<";
	}

	cout << "<<<<" << "|\tID: " << stack.top()->index << "\t|" << endl;

	cout << "\t\t\t\t\t"; 
	for (Node*i = obj.getHead(2); i != NULL; i = i->next) {
		h2.push(i);
	}

	for (Node* i = h2.pop(); i != NULL; i = h2.pop()) {

		DisplayBlock(i);
		if (i->next != NULL)
			cout << "<<";
	}
	for (Node*i = obj.getHead(2); i != NULL; i = i->next) {
		h2.push(i);
	}

	cout << "<<<<"; DisplayBlock(stack.top()); cout<< endl;

	cout << "\t\t\t\t\t";
	for (Node*i = h2.pop(); i != NULL; i = h2.pop()) {
		cout << "|\tCost: ";
		cout << i->cost << "\t|";
		if (i->next != NULL)
			cout << "<<";
	}



	cout<< "<<<<" <<"|\t" << "Cost: " << returnCost(stack.top()) << "\t|" << endl;

	for (Node*i = obj.getHead(2); i != NULL; i = i->next) {
		h2.push(i);
	}
	cout << "\t\t\t\t\t";
	for (Node*i = h2.pop(); i != NULL; i = h2.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
		if (i->next != NULL)
			cout << "<<";
	}

	cout << "<<<<" << "|\t" << "Got: ";

	if (stack.pop()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|" << endl;

	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;

	for (Node* i = s2.pop(); i != NULL; i = s2.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
			cout << "<<";
	}

	cout << "\t|\tID: " << stack.top()->index << "\t|" << ">>>>";


	for (Node* i = obj.getHead(4); i != NULL; i = i->next) {
		s4.push(i);
	}

	for (Node* i = s4.pop(); i != NULL; i = s4.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;

	for (Node* i = obj.getHead(3); i != NULL; i = i->next) {
		s2.push(i);
	}


	//The second top linked list (Default: Explode to Posion II)
	for (Node* i = s2.pop(); i != NULL; i = s2.pop()) {

		DisplayBlock(i);
			cout << "<<";
	}


	for (Node* i = obj.getHead(3); i != NULL; i = i->next) {
		s2.push(i);
	}

	for (Node* i = obj.getHead(4); i != NULL; i = i->next) {
		s4.push(i);
	}


	cout << "\t"; DisplayBlock(stack.top()); cout << ">>>>";
	for (Node* i = s4.pop(); i != NULL; i = s4.pop()) {
		DisplayBlock(i);

		if (i->next != NULL)
			cout << ">>";
	}
	cout << endl;
	count = 0;

	for (Node*i = s2.pop(); i != NULL; i = s2.pop()) {
		++count;
		cout << "|\tCost: ";

		cout << i->cost << "\t|";
			cout << "<<";
	}
	for (Node* i = obj.getHead(4); i != NULL; i = i->next) {
		s4.push(i);
	}

	count = 0;
	cout << "\t|\tCost: " << stack.top()->cost << "\t|>>>>";



	for (Node*i = s4.pop(); i != NULL; i = s4.pop()) {
		cout << "|\tCost: ";
		cout << i->cost << "\t";
		if (count == 0)
			cout << "\t";
		cout << "|";
		if (i->next != NULL)
			cout << "<<";
	}
	cout << endl;



	for (Node* i = obj.getHead(3); i != NULL; i = i->next) {
		s2.push(i);
	}
	for (Node* i = s2.pop(); i != NULL; i = s2.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout  << "\t|";
			cout << "<<";
	}


	cout << "\t|\tGot: ";
	if (stack.pop()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|" << ">>>>";

	for (Node* i = obj.getHead(4); i != NULL; i = i->next) {
		s4.push(i);
	}
	for (Node* i = s4.pop(); i != NULL; i = s4.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t\t|" << endl;
		if (i->next != NULL)
			cout << "<<";
	}



	//The third top linked list (Default: Kick I to Rage, index 11~14)
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t";

	cout << "|\tID: " << stack.top()->index << "\t|"<<">>";
	count= 1;
	for (Node* i = obj.getHead(5); i != NULL; i = i->next) {
		q1.enqueue(i);
	}
	for (Node* i = q1.dequeue(); i != NULL; i = q1.dequeue()) {
		cout << "|\tID: ";
		cout << i->index;
		cout<<"\t|";
		if (i->next != NULL)
			cout << ">>";
		count++;
	}

	cout << endl;

	cout << "\t\t\t\t\t\t\t";
	DisplayBlock(stack.top()); cout << ">>";

	for (Node* i = obj.getHead(5); i != NULL; i = i->next) {
		q1.enqueue(i);
	}
	for (Node* i = q1.dequeue(); i != NULL; i = q1.dequeue()) {
		DisplayBlock(i);
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;

	

	for (Node* i = obj.getHead(5); i != NULL; i = i->next) {
		q1.enqueue(i);
	}

	cout << "\t\t\t\t\t\t\t"; cout << "|\tCost: " << stack.top()->cost << "\t|>>";

	for (Node*i = q1.dequeue(); i != NULL; i = q1.dequeue()) {
		cout << "|\tCost: ";
		cout << i->cost << "\t";
		cout << "|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;



	cout << "\t\t\t\t\t\t\t"; cout << "|\tGot: ";
	if (stack.pop()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|"<<">>";


	for (Node* i = obj.getHead(5); i != NULL; i = i->next) {
		q1.enqueue(i);
	}
	for (Node*i = q1.dequeue(); i != NULL; i = q1.dequeue()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;


	//The Fourth top linked list (Default: Jump II to Str+5, index15~17)
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;

	for (Node* i = obj.getHead(6); i != NULL; i = i->next) {
		s3.push(i);
	}
	count = 0;
	for (Node* i = s3.pop(); i != NULL; i = s3.pop()) {
		++count;
		cout << "|\tID: ";
		cout << i->index;
		if (count == 1)
			cout << "\t";
		cout<<"\t|";
			cout << "<<";
	}

	cout << "<<|\tID: " << stack.top()->index << "\t|";

	cout << endl;


	for (Node* i = obj.getHead(6); i != NULL; i = i->next) {
			s3.push(i);
	}

	for (Node* i = s3.pop(); i != NULL; i = s3.pop()) {

			DisplayBlock(i); 
			cout << "<<";
	}

	cout << "<<"; DisplayBlock(stack.top()); cout << endl;

	for (Node* i = obj.getHead(6); i != NULL; i = i->next) {
		s3.push(i);
	}

	count = 0;
	for (Node* i = s3.pop(); i != NULL; i = s3.pop()) {

		cout << "|\tCost: ";
		if (count == 0) {
			cout << "\t";
			count++;
		}
		cout<< i->cost << "\t|";

			cout << "<<";
	}

	cout<< "<<|\tCost: " << stack.top()->cost << "\t|"<<endl;

	for (Node* i = obj.getHead(6); i != NULL; i = i->next) {
		s3.push(i);
	}
	count = 0;
	for (Node*i = s3.pop(); i != NULL; i = s3.pop()) {
		++count;
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		if (count == 1)
			cout << "\t";
		cout << "\t|";
			cout << "<<";
	}

	cout << "<<|\tGot: ";
	if (stack.pop()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|" << endl;


	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "^" << endl;


	//The left of the linked list (Default: Int+9 to HP+5 , index18~20)
	Stack h7(10);

	for (Node* i = obj.getHead(7); i != NULL; i = i->next) {
		h7.push(i);
	}
	for (Node* i = h7.pop(); i != NULL; i = h7.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
		cout << "<<";
	}

	cout << "|\tID: " << stack.top()->index << "\t\t|>>";


	//The right of the linked list (Default: MP+5to Str+9 , index21~24)
	Queue h8(10);

	for (Node*i = obj.getHead(8); i != NULL; i = i->next) {
		h8.enqueue(i);
	}
	count = 0;

	for (Node* i = h8.dequeue(); i != NULL; i = h8.dequeue()) {
		++count;
		cout << "|\tID: ";
		cout << i->index;
		if (count == 2)
			cout << "\t";
		cout<<"\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;


	for (Node* i = obj.getHead(7); i != NULL; i = i->next) {
		h7.push(i);
	}

	for (Node* i = h7.pop(); i != NULL; i = h7.pop()) {

		DisplayBlock(i);

			cout << "<<";
	}

	cout<<"|\tOrigin (START)\t|>>"; 




	for (Node* i = obj.getHead(8); i != NULL; i = i->next) {
		h8.enqueue(i);
	}

	for (Node* i = h8.dequeue(); i != NULL; i = h8.dequeue()) {
		DisplayBlock(i);
		if (i->next != NULL)
			cout << ">>";
	}



	cout << endl;




	for (Node* i = obj.getHead(7); i != NULL; i = i->next) {
		h7.push(i);
	}

	for (Node* i = h7.pop(); i != NULL; i = h7.pop()) {
		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		cout << "<<";
	}


	cout << "|\tCost: N/A\t|>>";

	count = 0;
	for (Node* i = obj.getHead(8); i != NULL; i = i->next) {
		h8.enqueue(i);
	}
	for (Node* i = h8.dequeue(); i != NULL; i = h8.dequeue()) {
		++count;
		cout << "|\tCost: ";
		cout << i->cost; 
		if (count != 2)
			cout << "\t|";
		else
			cout << "\t\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;

	for (Node*i = obj.getHead(7); i != NULL; i = i->next) {
		h7.push(i);
	}
	for (Node*i = h7.pop(); i != NULL; i = h7.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
			cout << "<<";
	}


	cout << "|\tGot: ";
	if (stack.pop()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t\t|>>";

	count = 0;
	for (Node*i = obj.getHead(8); i != NULL; i = i->next) {
		h8.enqueue(i);
	}
	for (Node*i = h8.dequeue(); i != NULL; i = h8.dequeue()) {
		++count;
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		if (count == 2)
			cout << "\t";
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;


	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;

	cout << "\t";


	//The bottom of the linked list (Default: Int+5 to Fire III , index25~29)
	Queue h9(10);

	//The first linked list under the origin (Default: Cure I to Int+7 , index43~45)
	Stack h15(10);

	for (Node* i = obj.getHead(9); i != NULL; i = i->next) {
		h9.enqueue(i);
	}
	for (Node*i = obj.getHead(15); i != NULL; i = i->next) {
		h15.push(i);
	}

	for (Node* i = h15.pop(); i != NULL; i = h15.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
			cout << "<<";
	}

	cout << "|\tID: " << h9.look()->index << "\t|" ;

	cout << endl;



	for (Node* i = obj.getHead(15); i != NULL; i = i->next) {
		h15.push(i);
	}

	cout << "\t";

	for (Node* i = h15.pop(); i != NULL; i = h15.pop()) {
		DisplayBlock(i);
			cout << "<<";
	}

	DisplayBlock(h9.look()); 

	cout << endl; cout << "\t";

	for (Node* i = obj.getHead(15); i != NULL; i = i->next) {
		h15.push(i);
	}
	for (Node* i = h15.pop(); i != NULL; i = h15.pop()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		cout << "<<";
	}

	cout << "|\tCost: " << h9.look()->cost << "\t|" << endl;

	cout << "\t";

	for (Node* i = obj.getHead(15); i != NULL; i = i->next) {
		h15.push(i);
	}
	for (Node*i = h15.pop(); i != NULL; i = h15.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
			cout << "<<";
	}

	cout << "|\tGot: ";
	if (h9.dequeue()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|" << endl;



	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t";
	

	//The second left linked list under origin (Default: Sheild to Ice I , index37~38)
	Stack h13(5);

	//The second right linked list under origin (Default: Fire I to Cure II , index39~42)
	Queue h14(10);

	for (Node* i = obj.getHead(13); i != NULL; i = i->next) {
		h13.push(i);
	}
	for (Node* i = h13.pop(); i != NULL; i = h13.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
			cout << "<<";
	}

	cout << "|\tID: " << h9.look()->index << "\t|>>";
	for (Node* i = obj.getHead(14); i != NULL; i = i->next) {
		h14.enqueue(i);
	}
	for (Node* i = h14.dequeue(); i != NULL; i = h14.dequeue()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;

	cout << "\t\t\t";
	for (Node* i = obj.getHead(13); i != NULL; i = i->next) {
		h13.push(i);
	}
	for (Node* i = h13.pop(); i != NULL; i = h13.pop()) {
		DisplayBlock(i);
		cout << "<<";
	}

	DisplayBlock(h9.look()); cout << ">>";


	for (Node* i = obj.getHead(14); i != NULL; i = i->next) {
		h14.enqueue(i);
	}
	for (Node* i = h14.dequeue(); i != NULL; i = h14.dequeue()) {
		DisplayBlock(i);
		if(i->next!=NULL)
			cout << ">>";
	}

	cout << endl;
	cout << "\t\t\t"; 

	for (Node* i = obj.getHead(13); i != NULL; i = i->next) {
		h13.push(i);
	}
	for (Node* i = obj.getHead(14); i != NULL; i = i->next) {
		h14.enqueue(i);
	}
	for (Node* i = h13.pop(); i != NULL; i = h13.pop()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		cout << "<<";
	}
	cout << "|\tCost: " << h9.look()->cost << "\t|>>";
	for (Node* i = h14.dequeue(); i != NULL; i = h14.dequeue()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		if(i->next!=NULL)
			cout << ">>";

	}

	cout << endl; cout << "\t\t\t";

	for (Node* i = obj.getHead(13); i != NULL; i = i->next) {
		h13.push(i);
	}
	for (Node* i = obj.getHead(14); i != NULL; i = i->next) {
		h14.enqueue(i);
	}

	for (Node*i = h13.pop(); i != NULL; i = h13.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
			cout << "<<";
	}


	cout << "|\tGot: ";
	if (h9.dequeue()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|>>";



	for (Node*i = h14.dequeue(); i != NULL; i = h14.dequeue()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}




	cout << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;

	cout << endl;
	cout << "\t";



	//The third left linked list under origin (Default: Str+9 to Int+7 , index31~33)
	Stack h11(5);

	//The third right linked list under origin (Default: MP+7 to MP+9 , index34~36)
	Queue h12(10);
	for (Node* i = obj.getHead(11); i != NULL; i = i->next) {
		h11.push(i);
	}
	for (Node* i = obj.getHead(12); i != NULL; i = i->next) {
		h12.enqueue(i);
	}

	for (Node* i = h11.pop(); i != NULL; i = h11.pop()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
			cout << "<<";
	}

	cout <<"|\tID: " << h9.look()->index << "\t|>>";

	for (Node* i = h12.dequeue(); i != NULL; i = h12.dequeue()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}



	cout << endl;
	cout << "\t";

	for (Node* i = obj.getHead(11); i != NULL; i = i->next) {
		h11.push(i);
	}
	for (Node* i = obj.getHead(12); i != NULL; i = i->next) {
		h12.enqueue(i);
	}
	for (Node* i = h11.pop(); i != NULL; i = h11.pop()) {
		DisplayBlock(i);
		cout << "<<";
	}

	DisplayBlock(h9.look()); cout << ">>";

	for (Node* i = h12.dequeue(); i != NULL; i = h12.dequeue()) {
		DisplayBlock(i);
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;	cout << "\t";
	
	for (Node* i = obj.getHead(11); i != NULL; i = i->next) {
		h11.push(i);
	}
	for (Node* i = obj.getHead(12); i != NULL; i = i->next) {
		h12.enqueue(i);
	}
	for (Node* i = h11.pop(); i != NULL; i = h11.pop()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		cout << "<<";
	}

	cout << "|\tCost: " << h9.look()->cost << "\t|>>";

	for (Node* i = h12.dequeue(); i != NULL; i = h12.dequeue()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";

	}
	cout << endl;
	cout << "\t";
	
	for (Node* i = obj.getHead(11); i != NULL; i = i->next) {
		h11.push(i);
	}
	for (Node* i = obj.getHead(12); i != NULL; i = i->next) {
		h12.enqueue(i);
	}

	for (Node*i = h11.pop(); i != NULL; i = h11.pop()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
			cout << "<<";
	}

	cout << "|\tGot: ";
	if (h9.dequeue()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|>>";

	for (Node*i = h12.dequeue(); i != NULL; i = h12.dequeue()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}



	cout << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;

	cout << "\t\t\t\t\t\t\t" << "|\tID: " << h9.look()->index << "\t|" << endl;
	cout << "\t\t\t\t\t\t\t"; DisplayBlock(h9.look()); cout << endl;
	cout << "\t\t\t\t\t\t\t"; cout<<"|\tCost: "<<h9.look()->cost<<"\t|"; cout << endl;
	cout << "\t\t\t\t\t\t\t";
	cout << "|\tGot: ";
	if (h9.dequeue()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t|" << endl;

	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "v" << endl;



	//The fourth linked list under origin (Default: Flare , index30)
	Queue h10(5);
	cout << "\t\t\t\t\t\t\t" << "|\tID: " << h9.look()->index << "\t\t|>>";
	for (Node* i = obj.getHead(10); i != NULL; i = i->next) {
		h10.enqueue(i);
	}
	for (Node* i = h10.dequeue(); i != NULL; i = h10.dequeue()) {
		cout << "|\tID: ";
		cout << i->index << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;

	cout << "\t\t\t\t\t\t\t"; DisplayBlock(h9.look()); cout << ">>";


	for (Node* i = obj.getHead(10); i != NULL; i = i->next) {
		h10.enqueue(i);
	}
	for (Node* i = h10.dequeue(); i != NULL; i = h10.dequeue()) {
		DisplayBlock(i);
		if (i->next != NULL)
			cout << ">>";
	}

	cout << endl;
	cout << "\t\t\t\t\t\t\t";
	cout << "|\tCost: " << h9.look()->cost << "\t\t|>>";

	for (Node* i = obj.getHead(10); i != NULL; i = i->next) {
		h10.enqueue(i);
	}
	for (Node* i = h10.dequeue(); i != NULL; i = h10.dequeue()) {

		cout << "|\tCost: ";
		cout << i->cost;
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";

	}

	cout << endl;	cout << "\t\t\t\t\t\t\t";

	cout << "|\tGot: ";
	if (h9.dequeue()->visit == true)
		cout << "Y";
	else
		cout << "N";
	cout << "\t\t|>>";


	for (Node* i = obj.getHead(10); i != NULL; i = i->next) {
		h10.enqueue(i);
	}
	for (Node*i = h10.dequeue(); i != NULL; i = h10.dequeue()) {
		cout << "|\tGot: ";
		if (i->visit == true)
			cout << "Y";
		else
			cout << "N";
		cout << "\t|";
		if (i->next != NULL)
			cout << ">>";
	}


}




//Display the skill or status with alignment
void TalentTree::DisplayBlock(Node* in) {


		if (in->skill!="") {
			cout << "|\t" << in->skill << "\t|";
		}
		else if (in->MP > 0) {
			cout <<"|\t"<< "MP+" << in->MP << "\t|";
		}
		else if (in->HP > 0) {
			cout << "|\t"<<"HP+" << in->HP << "\t|";
		}
		else if (in->Magic > 0) {
			cout << "|\t"<<"Int+" << in->Magic << "\t|";
		}
		else if (in->Atk > 0) {
			cout << "|\t"<<"Str+" << in->Atk << "\t|";
		}

}




//Output which node is available to be obtained by user
//Condition: node->Looped==false, node->visit==false, j->viable==ture
void TalentTree::FindViable() {


	for (int i = 1; i <= 15; i++) {
		for (Node*j = obj.getHead(i); j != NULL; j = j->next) {
			if (j->Looped ==false && j->visit ==false && j->viable ==true) {
				cout << "|\tIndex: " << j->index << "\t|"<<endl;
				DisplayBlock(j); cout << endl;
				cout << "|\tCost: " << j->cost << "\t\t|"<<endl;
				cout << endl;
			}
		}
	}
	cout << endl;

}




//Find the minimum cost of the nodes those are in the path of the search function
int TalentTree::findMinCost(int index) {

	int min=1000;
	Node** storeArr;
	
	storeArr = returnListedNodes(FindHeadNUM(index,findIndex(index)), findIndex(index));

	for (int i = 0; i < 30; i++) {
		if (storeArr[i] != NULL) {
			if (storeArr[i]->cost < min)
				min = storeArr[i]->cost;
		}
	}


	return min;

}




//Find the address of node with the required index number
Node* TalentTree::findIndex(int n) {


	for (int j = 1; j <= 15; j++) {
		for (Node* i = obj.getHead(j); i != NULL; i = i->next) {
			if (n == i->index)
				return i;
		}
	}

	return NULL;

}




//Enable the node->viable to true if the adjacent node has been obtained
void TalentTree::autoCheck(Node* in) {

	Node* a = NULL;
	Node* d = NULL;


	if (in->viable == false && in->visit == true && in->Looped == true) {
		if (in->next != NULL) {
			//cout << "SUCCESS IN " << endl;
			a = in->next;
			a->viable = true;
		}
	}

	if (in == Id2) {
		if (Id2->visit == true && Id2->viable == false && Id2->Looped == true) {
			a = obj.getHead(6);
			a->viable = true;
		}
	}
	if (in == Id3) {
		if (Id3->visit == true && Id3->viable == false && Id3->Looped == true) {
			obj.getHead(5)->viable = true;
		}
	}
	if (in == Id4) {
		if (Id4->visit == true && Id4->viable == false && Id4->Looped == true) {
			obj.getHead(4)->viable = true;
			obj.getHead(3)->viable = true;
		}
	}
	if (Id5 == in) {
		if (Id5->visit == true && Id5->viable == false && Id5->Looped == true) {
			obj.getHead(2)->viable = true;
		}
	}

	if (Id25 == in) {
		if (Id25->visit == true && Id25->viable == false && Id25->Looped == true) {
			obj.getHead(15)->viable = true;
		}
	}
	if (Id26 == in) {
		if (Id26->visit == true && Id26->viable == false && Id26->Looped == true) {
			obj.getHead(13)->viable = true;
			obj.getHead(14)->viable = true;
		}
	}
	if (Id27 == in) {
		if (Id27->visit == true && Id27->viable == false && Id27->Looped == true) {
			obj.getHead(11)->viable = true;
			obj.getHead(12)->viable = true;
		}
	}
	if (Id29 == in) {
		if (Id29->visit == true && Id29->viable == false && Id29->Looped == true) {
			obj.getHead(10)->viable = true;
		}
	}

}




//Set the node->viable = false , node->visit = true, node->Looped = true as the condition check
//so that the user never travel the same node again
void TalentTree::Nodestatus(Node* in) {

	in->viable = false;
	in->visit = true;
	in->Looped = true;

}




//Edit Mode: open for user to add node into the existing linked list
//Figure out the user demand and call the corresponding functions (Addskill and AddStatus functions)
//to creat a new node and build the connection with the corresponding linked list
void TalentTree::Addnode(int Id,string skill,int status, string control, char type) {


	Node* a = new Node;

	if (type == 's' || type=='S') {
		a = AddSkill(indexCount, skill);
		indexCount++;
	}
	else if (type == 'c'||type=='C') {
		a = AddStatus(indexCount, status, control);
		indexCount++;
	}

	Node* b = NULL;
	b = findIndex(Id);
	for (Node* i = b; i != NULL; i = i->next) {
		if (i->next == NULL) {
			i->next = a;
			break;
		}
	}

	CostCal();


	cout << endl; cout << endl;
	cout << "The new node has been added successfully." << endl;
	DisplayBlock(a); cout << endl;
	cout << "|\tCost: " << a->cost << "\t|" << endl;
	cout << "|\tIndex: " << a->index << "\t|" << endl;
	cout << endl; cout << endl;

}




//Edit Mode: open for user to delete node from the existing linked list
void TalentTree::EditDeletion(int Id) {


	Node* a = new Node;
	a = findIndex(Id);

	for (int j = 1; j <= 15; j++) {
		Node* a = NULL;
		Node* b = obj.getHead(j);
		while (b && b->index != Id)
		{
			a = b;
			b = b->next;
		}
		if (b) {
			if (a) {
				a->next = b->next;
				delete b;
				cout << "The node has been deleted successfully." << endl;
			}

		}
	}




}




//Calcalate the cost of the talent tree nodes
//Defalut cost is 3. Each 2 nodes will have 2 costs increment.
//The amount of costs are determined by the position of the poiner-to-pointer array
void TalentTree::CostCal() {

	Node** a1 = new Node*[10];
	Node** a2 = new Node*[10];
	Node** a3 = new Node*[10];
	Node** a4 = new Node*[10];
	Node** a5 = new Node*[10];
	Node** a6 = new Node*[10];
	Node** a7 = new Node*[10];
	Node** a8 = new Node*[10];
	Node** a9 = new Node*[10];
	Node** a10 = new Node*[10];
	Node** a11 = new Node*[10];
	Node** a12 = new Node*[10];
	Node** a13 = new Node*[10];

	for (int i = 0; i < 10; i++) {
		a1[i] = NULL; a2[i] = NULL; a3[i] = NULL; a4[i] = NULL; a5[i] = NULL;
		a6[i] = NULL; a7[i] = NULL; a8[i] = NULL; a9[i] = NULL; a10[i] = NULL;
		a11[i] = NULL; a12[i] = NULL; a13[i] = NULL;
	}

	int countarr = 0;
	//a1 = pointer array from head to head2 (Index 1-6)

		for (Node* j = obj.getHead(1)->next; j != NULL; j = j->next) {
			a1[countarr++] = j;
		}

		for (Node* j = obj.getHead(2); j != NULL; j = j->next) {
			a1[countarr++] = j;
		}


	countarr = 0;
	//a2 = pointer array from head to head3 (Index 1-4, 7-9)
	for (Node* j = obj.getHead(1)->next; j != NULL; j = j->next) {
		a2[countarr++] = j;
		if (j->index == 4)
			break;
	}
	for (Node* j = obj.getHead(3); j != NULL; j = j->next) {
		a2[countarr++] = j;
	}




		countarr = 0;
	//a3 = pointer array from head to head3 (Index 1-4, 10)
	for (Node* j = obj.getHead(1)->next; j != NULL; j = j->next) {
		a3[countarr++] = j;
		if (j->index == 4)
			break;
	}
	for (Node* j = obj.getHead(4); j != NULL; j = j->next) {
		a3[countarr++] = j;
	}


	countarr = 0;
	//a4 = head to head5(Index 1-3,11-14)
	for (Node* j = obj.getHead(1)->next; j != NULL; j = j->next) {
		a4[countarr++] = j;
		if (j->index == 3)
			break;
	}
	for (Node* j = obj.getHead(5); j != NULL; j = j->next) {
		a4[countarr++] = j;
	}


	countarr = 0;
	//a5 = head to head6(Index 1-2,15-17)
	for (Node* j = obj.getHead(1)->next; j != NULL; j = j->next) {
		a5[countarr++] = j;
		if (j->index == 2)
			break;
	}
	for (Node* j = obj.getHead(6); j != NULL; j = j->next) {
		a5[countarr++] = j;
	}

	countarr = 0;
	//a6 = head7(18-20)
	for (Node* j = obj.getHead(7); j != NULL; j = j->next) {
		a6[countarr++] = j;
	}

	countarr = 0;
	//a7 = head8(21-24)
	for (Node* j = obj.getHead(8); j != NULL; j = j->next) {
		a7[countarr++] = j;
	}

	countarr = 0;
	//a8 = head9 to head10(Index 25-30)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a8[countarr++] = j;
	}
	for (Node* j = obj.getHead(10); j != NULL; j = j->next) {
		a8[countarr++] = j;
	}

	countarr = 0;
	//a9 = head9 to head11(Index 25-27, 31-33)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a9[countarr++] = j;
		if (j->index == 27)
			break;
	}
	for (Node* j = obj.getHead(11); j != NULL; j = j->next) {
		a9[countarr++] = j;
	}


	countarr = 0;
	//a10 = head9 to head11(Index 25-27, 31-33)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a10[countarr++] = j;
		if (j->index == 27)
			break;
	}
	for (Node* j = obj.getHead(12); j != NULL; j = j->next) {
		a10[countarr++] = j;
	}


	countarr = 0;
	//a11 = head9 to head13(Index 25-26, 37-38)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a11[countarr++] = j;
		if (j->index == 26)
			break;
	}
	for (Node* j = obj.getHead(13); j != NULL; j = j->next) {
		a11[countarr++] = j;
	}

	countarr = 0;
	//a12 = head9 to head14(Index 25-26, 39-42)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a12[countarr++] = j;
		if (j->index == 26)
			break;
	}
	for (Node* j = obj.getHead(14); j != NULL; j = j->next) {
		a12[countarr++] = j;
	}

	countarr = 0;
	//a13 = head9 to head15(Index 25, 43-45)
	for (Node* j = obj.getHead(9); j != NULL; j = j->next) {
		a13[countarr++] = j;
		if (j->index == 25)
			break;
	}
	for (Node* j = obj.getHead(15); j != NULL; j = j->next) {
		a13[countarr++] = j;
	}


	cout << endl;

	//Assign the costs by calling function LoopCost
	LoopCost(a1); LoopCost(a2); LoopCost(a3); LoopCost(a4); LoopCost(a5); LoopCost(a6); 
	LoopCost(a7); LoopCost(a8); LoopCost(a9); LoopCost(a10); LoopCost(a11); LoopCost(a12);
	LoopCost(a13);


	//Release all the dynamic memory usage
	FreeArr(a1); FreeArr(a2); FreeArr(a3); FreeArr(a4); FreeArr(a5); FreeArr(a6); FreeArr(a7);
	FreeArr(a8); FreeArr(a9); FreeArr(a10); FreeArr(a11); FreeArr(a12); FreeArr(a13);


}




//Assign the value of costs using specific algorithm
//The default cost is 3. After travelling the first 2 nodes, the costs start increment 2 costs in each 2 nodes.
void TalentTree::LoopCost(Node** arr) {
	int cost = 3;
	int call = 0;
	for (int k = 0; k < 10; k++) {
		++call;
		if (arr[k] != NULL) {
			if (call == 1 || call == 2) {
				arr[k]->cost = cost;
				continue;
			}
			if (k % 2 == 0) {
				cost += 2;
				arr[k]->cost = cost;
				continue;
			}
			else {
				arr[k]->cost = cost;
				continue;
			}
		}
	}

}



//Free the dynamic memory allocation of the pointer-to-pointer array
void TalentTree::FreeArr(Node** in) {

	for (int i = 0; i < 10; i++) {
		in[i] == NULL;
	}

	delete[] in;

}




//store the status / skills of the newly added node in the storeNew linked list
//for roll back purpose in the future
void TalentTree::storeAddedChange(Node* node) {

	if (node->index >= 46) {
		for (Node* i = storeNew.getHead(1); i != NULL; i = i->next) {
			if (i->next == NULL) {
				Node* y = new Node;
				i->next = y;
				if(node->Atk > 0)
					y->Atk = node->Atk;
				if (node->Magic > 0)
					y->Magic = node->Magic;
				if (node->MP > 0) 
					y->MP = node->MP;
				if (node->HP > 0)
					y->HP = node->HP;
				if (node->skill != "")
					y->skill = node->skill;

				y->index = node->index;
				break;
			}
		}
	}

}



//return the head of storeNew for roll back function
Node* TalentTree::returnStoredHead() {

	return (storeNew.getHead(1));

}



//Search and print the path to the required node from user
void TalentTree::searchFuction(Node* in) {

	int storedHeadNum = 0;

	if (in != NULL) {

		storedHeadNum = FindHeadNUM(in->index, in);

		//Full form of stCost = stored cost
		int stCost = 0;


		if (storedHeadNum >= 1 && storedHeadNum <= 15) {
			printSearch(storedHeadNum, stCost, in);
		}
		else {
			cout << "Invalid linked list ID! Please check again." << endl;
		}

	}
	else {

		cout << "Error! The index does not exist." << endl;

	}


}


//Find the specific number of head for the required linked list
int TalentTree::FindHeadNUM(int index,Node* in) {

	int storedHeadNum = 0;

	if (in != NULL) {
			for (int i = 1; i <= 15; i++) {
			for (Node* j = obj.getHead(i); j != NULL; j = j->next) {
				if (j->index == in->index) {
					storedHeadNum = i;
				}
			}
		}
	}


	return storedHeadNum;

}



//Print out the search result
void TalentTree::printSearch(int n, int& cost, Node* in) {

	Node* lastVisited = NULL;
	int DerivedNodeID = 0;


	if (n == 1 || n == 9 || n == 7 || n == 8) {
		for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

			if (j->visit == true) {
				if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 25 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29))
					break;
				lastVisited = j;

			}


		}

	}
	else {

		if (n >= 9 && n <= 15) {

				lastVisited = obj.getHead(1);

			for (Node* j = obj.getHead(9); j != NULL; j = j->next) {

				if (j->visit == true) {
					if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 25 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29))
						break;
					lastVisited = j;
				}
			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {


				if (j->visit == true)
					lastVisited = j;

				if (in->index == j->index)
					break;


			}
		}
		else {

			for (Node* j = obj.getHead(1); j != NULL; j = j->next) {

				if (j->visit == true) {
					if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 25 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29))
						break;
					lastVisited = j;
				}

			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == true) {
					lastVisited = j;
					if (in->index == j->index)
						break;
				}

			}

		}
	}


	for (int i = 1; i <= 15; i++) {
		for (Node* j = obj.getHead(i); j != NULL; j = j->next) {
			if (j->visit == true) {
				if ((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29)) {
					lastVisited = j;
					break;
				}

			}
		}

	}


		if (lastVisited != NULL) {
		
			cout << "You current position: " << endl; cout << endl;
			cout << "|\tIndex: " << lastVisited->index << "\t|" << endl;
			DisplayBlock(lastVisited); cout << endl;
			DerivedNodeID = lastVisited->index;
		
		}



		if (DerivedNodeID > in->index)
			DerivedNodeID = 0;



	//print out the route toward the input index
		cout << endl; cout << endl;
		cout << "The way you should go for the required node: " << endl;
		cout << endl; cout << endl;

	if (n == 1 || n == 9 || n==7 || n==8 ) {
		for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

			if (DerivedNodeID > j->index)
				continue;


			if (j->visit == false) {
				cout << "|\tIndex: " << j->index << "\t|" << endl;
				DisplayBlock(j); cout << endl;
				cout << "|\tCost: " << j->cost << "\t|" << endl;
				cost += j->cost;
				if (in->index == j->index)
					break;
				cout << endl; cout << "\tv" << endl; cout << "\tv" << endl; cout << endl;
			}


		}

	}
	else {

		if (n >= 9 && n <= 15) {

			for (Node* j = obj.getHead(9); j != NULL; j = j->next) {

				if (DerivedNodeID > j->index)
					continue;


				if (j->visit == false) {

					cout << "|\tIndex: " << j->index << "\t|" << endl;
					DisplayBlock(j); cout << endl;
					cout << "|\tCost: " << j->cost << "\t|" << endl;
					cost += j->cost;

				}
				if (!((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29)))
					cout << endl; cout << "\tv" << endl; cout << "\tv" << endl; cout << endl;


				if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29)) {
					break;
				}
					
			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == false) {
					cout << "|\tIndex: " << j->index << "\t|" << endl;
					DisplayBlock(j); cout << endl;
					cout << "|\tCost: " << j->cost << "\t|" << endl;
					cost += j->cost;
					cout << endl;
					if (in->index == j->index)
						break;
					cout << endl; cout << "\tv" << endl; cout << "\tv" << endl; cout << endl;
				}



			}


		}
		else {

			for (Node* j = obj.getHead(1); j != NULL; j = j->next) {

				if (DerivedNodeID > j->index)
					continue;

				if (j->visit == false) {
					cout << "|\tIndex: " << j->index << "\t|" << endl;
					DisplayBlock(j); cout << endl;
					cout << "|\tCost: " << j->cost << "\t|" << endl;
					cost += j->cost;
					cout << endl;
				}

				if (!((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29)))
					cout << endl; cout << "\tv" << endl; cout << "\tv" << endl; cout << endl;

				if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29)) {
					break;
				}
			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == false) {
					cout << "|\tIndex: " << j->index << "\t|" << endl;
					DisplayBlock(j); cout << endl;
					cout << "|\tCost: " << j->cost << "\t|" << endl;
					cost += j->cost;
					cout << endl;
					if (in->index == j->index)
						break;
					cout << endl; cout << "\tv" << endl; cout << "\tv" << endl; cout << endl;
				}

			}

		}

	}

	cout << endl; cout << endl;
	cout << "You have to pay " << cost << " costs to derive all the nodes listed here." << endl;


}



//Store the nodes of the searched path into a pointer-to-pointer array and return the first position of the array
Node** TalentTree::returnListedNodes(int n, Node* in) {

	Node** storedList = new Node*[30];

	for (int j = 0; j < 30; j++) 
		storedList[j] = NULL;
	

	int sLcounter = 0;

	Node* lastVisited = NULL;
	int DerivedNodeID = 0;

	if (n == 1 || n == 9 || n == 7 || n == 8) {

		lastVisited = obj.getHead(1);

		for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

			if (j->visit == true) {
				if ((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29))
					break;
				lastVisited = j;
			}


		}

	}
	else {

		if (n >= 9 && n <= 15) {

			for (Node* j = obj.getHead(9); j != NULL; j = j->next) {

				if (j->visit == true) {
					if ((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29))
						break;
					lastVisited = j;
				}
			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {


				if (j->visit == true)
					lastVisited = j;

				if (in->index == j->index)
					break;


			}
		}
		else {

			for (Node* j = obj.getHead(1); j != NULL; j = j->next) {

				if (j->visit == true) {
					if ((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29))
						break;
					lastVisited = j;
				}

			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == true) {
					lastVisited = j;
					if (in->index == j->index)
						break;
				}

			}

		}
	}


	if (lastVisited != NULL) 
		DerivedNodeID = lastVisited->index;
	

	if (DerivedNodeID > in->index)
		DerivedNodeID = 0;


	//Stored all the listed nodes
	if (n == 1 || n == 9 || n == 7 || n == 8) {
		for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

			if (DerivedNodeID > j->index)
				continue;

			if (j->visit == false) {
				storedList[sLcounter++] = j;
				if (in->index == j->index)
					break;

			}


		}

	}
	else {

		if (n >= 9 && n <= 15) {

			for (Node* j = obj.getHead(9); j != NULL; j = j->next) {

				if (DerivedNodeID > j->index)
					continue;

				if (j->visit == false) {

					storedList[sLcounter++] = j;

				}

				if ((in->index == 6 && j->index == 5) || (in->index == 7 && j->index == 4) || (in->index == 10 && j->index == 4) || (in->index == 11 && j->index == 3) || (in->index == 15 && j->index == 2) || (in->index == 18 && j->index == 1) || (in->index == 21 && j->index == 1) || (in->index == 25 && j->index == 1) || (in->index == 43 && j->index == 25) || (in->index == 37 && j->index == 26) || (in->index == 39 && j->index == 26) || (in->index == 31 && j->index == 27) || (in->index == 34 && j->index == 27) || (in->index == 30 && j->index == 29)) {
					break;
				}

			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == false) {

					storedList[sLcounter++] = j;

					if (in->index == j->index)
						break;

				}



			}


		}
		else {

			for (Node* j = obj.getHead(1); j != NULL; j = j->next) {

				if (DerivedNodeID > j->index)
					continue;

				if (j->visit == false) {

					storedList[sLcounter++] = j;

				}

				if ((in->index == 6 && j->index == 5) || ((in->index >= 7 && in->index <= 9) && j->index == 4) || (in->index == 10 && j->index == 4) || ((in->index >= 11 && in->index <= 14) && j->index == 3) || ((in->index >= 15 && in->index <= 17) && j->index == 2) || ((in->index >= 18 && in->index <= 20) && j->index == 1) || ((in->index >= 21 && in->index <= 24) && j->index == 1) || ((in->index >= 25 && in->index <= 29) && j->index == 1) || ((in->index >= 43 && in->index <= 45) && j->index == 25) || ((in->index >= 37 && in->index <= 38) && j->index == 26) || ((in->index >= 39 && in->index <= 42) && j->index == 26) || ((in->index >= 31 && in->index <= 33) && j->index == 27) || ((in->index >= 34 && in->index <= 36) && j->index == 27) || (in->index == 30 && j->index == 29)) {
					break;
				}
			}

			for (Node* j = obj.getHead(n); j != NULL; j = j->next) {

				if (j->visit == false) {

					storedList[sLcounter++] = j;

					if (in->index == j->index)
						break;

				}

			}

		}

	}

	return storedList;

}