#include "Character.h"
#include "Node.h"
#include "LinkedList.h"
#include "TalentTree.h"
#include <iostream>
#include <string>
using namespace std;




//The initial screen for the program
//User can input value according to the menu to use the functions
//Many data checkings are implemented here
int main() {


	Character ch;
	cout << "============================================================" << endl;
	cout << "		Talent Tree Simulator" << endl;
	cout << "============================================================" << endl;


	string n;
	char m;
	char node;
	char condition;

	
	cout << "Please creat a new character first." << endl;


	do {
		cout << endl;
		cout << "What is your name?" << endl;
		cout << "Input: ";
		cin >> n;
		ch.setName(n);
		cout << endl;
		cout << "Are you sure to proceed with the name '" << ch.returnName() << "' ?" << endl;
		cout << "Please press Y as yes, N for no." << endl;
		cin >> condition;

	} while (condition != 'y' && condition != 'Y');

	cout << "======================================================================" << endl;

	do {
		do {
			cout << endl;
			cout << "Which type of profession would you want?" << endl;
			cout << "Input M for mage, who has stronger power in magic attack and higher amount of MP." << endl;
			cout << "Input W for warrior, who has stronger power in physical attack and higher amount of HP." << endl;
			cout << "Input: ";
			cin >> m;
			if (m != 'm' && m != 'M' && m != 'w' && m != 'W') {
				cout << endl;
				cout << "Error! Please input correctly." << endl;
				cout << endl;
			}
		} while (m != 'm' && m != 'M' && m != 'w' && m != 'W');

		ch.setType(m);
		cout << endl;
		cout << "Are you sure to proceed with the profession '" << ch.returnType() << "' ?" << endl;
		cout << "With the initial status of " << endl;
		cout << "---------" << endl;
		cout << "|HP: " << ch.returnHP() << "	|" << endl;
		cout << "|Str: " << ch.returnAtk() << "|" << endl;
		cout << "|MP: " << ch.returnMP() << "	|" << endl;
		cout << "|Int: " << ch.returnMag() << "|" << endl;
		cout << "---------" << endl;
		cout << "Please press Y as yes, N for no." << endl;
		cin >> condition;

	} while (condition != 'y' && condition != 'Y');
	
	
	//For testing purpose
	//ch.setType('m');
	//ch.setName("ABC");


	cout << endl;	cout << endl;

	cout << "Welcome to the Talent Tree Simulator!!" << endl;
	cout << "You can raise your own character with the talent tree and edit the tree. Have fun!!" << endl;
	cout << endl;	cout << endl;


	cout << endl;	cout << endl;
	cout << "Reminder : You can obtain costs required from talent tree in the '6. Obtain infinite costs' below" << endl;
	cout << endl;	cout << endl;


	/*
	Function 1: Call the menu again
	Function 2: Show the current status of the character
	Function 3: Show the overview of talent tree , the costs to derive the nodes on entire talent tree, the minimum cost to get the next node
	Function 4: Search the node according to the index and show the path and provide a short cut for users to derive all of them
	Function 5: Obtain the viable nodes one by one
	Function 6: Set the costs of the character object to 99999
	Function 7: Provide add / delection functions of the talent tree
	Function 8: Provide a official website for commenting
	Function 9: Quit the game
	*/


	int control = 0;
	cout << endl;	cout << endl;
	cout << "Input the corresponding number if you want to use the functions below" << endl;
	cout << endl; cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|Menu\t\t\t\t\t|" << endl;
	cout << "|1. Call the Menu\t\t\t|" << endl;
	cout << "|2. Current Status of the Character\t|" << endl;
	cout << "|3. Overview of Talent Tree\t\t|" << endl;
	cout << "|4. Search Nodes\t\t\t|" << endl;
	cout << "|5. Obtain status/ skills in Talent Tree|" << endl;
	cout << "|6. Obtain infinite costs";
	if (ch.returnCost() == 0)
		cout << " (IMPORTANT!!)";
	else if (ch.returnCost() != 0)
		cout << "\t";
	cout << "	|" << endl;
	cout << "|7. Edit Talent Tree			|" << endl;
	cout << "|8. Official Website			|" << endl;
	cout << "|9. Quit the game			|" << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;	cout << endl;

		do {
			condition = 'n';

			cout << endl;	cout << endl; cout << endl;	cout << endl; cout << endl;	cout << endl;
			cout << "What do you want to do now? (Please input the number in the menu or type 1 to call menu)" << endl;
			cout << "Input: ";
			cin >> control;

			cout << endl;
			if (control == 1) {
				cout << endl;	cout << endl; cout << endl; cout << endl;
				cout << "Input the corresponding number if you want to use the functions below" << endl;
				cout << endl; cout << endl;
				cout << "-----------------------------------------" << endl;
				cout << "|Menu\t\t\t\t\t|" << endl;
				cout << "|1. Call the Menu\t\t\t|" << endl;
				cout << "|2. Current Status of the Character\t|" << endl;
				cout << "|3. Overview of Talent Tree\t\t|" << endl;
				cout << "|4. Search Nodes\t\t\t|" << endl;
				cout << "|5. Obtain status/ skills in Talent Tree|" << endl;
				cout << "|6. Obtain infinite costs";
				if (ch.returnCost() == 0)
					cout << " (IMPORTANT!!)";
				else if (ch.returnCost() != 0)
					cout << "\t";
				cout << "	|" << endl;
				cout << "|7. Edit Talent Tree			|" << endl;
				cout << "|8. Official Website			|" << endl;
				cout << "|9. Quit the game			|" << endl;
				cout << "-----------------------------------------" << endl;
				cout << endl;	cout << endl; cout << endl; cout << endl;
			}

			else if (control == 2) {
				cout << endl; cout << endl;
				cout << "Current Status of the Character" << endl;
				cout << "Name: " << ch.returnName() << endl;
				cout << "Profession: " << ch.returnType() << endl;
				cout << endl;
				cout << "--------------" << endl;
				cout << "HP: " << ch.returnHP()  << endl;
				cout << "Str: " << ch.returnAtk()  << endl;
				cout << "MP: " << ch.returnMP()  << endl;
				cout << "Int: " << ch.returnMag() << endl;
				cout << "Cost: " << ch.returnCost()  << endl;
				cout << "Skills: "<< endl;
				cout << endl;
				for (int i = 0; i < 30; i++) {
					if (ch.returnskills(i) != "")
						cout <<  ch.returnskills(i)  << endl;
				}
				cout << "--------------" << endl;
				cout << endl; cout << endl;cout << endl; cout << endl;
			}

			else if (control==3) {
				cout << endl; cout << endl; 
				ch.Displaytree();
				cout << endl; cout << endl;	cout << endl; cout << endl;
				cout << "Id = index (unique representative) of the node" << endl;
				cout << "Got: Y = the node has been visited" << endl;
				cout << "Got: N = the node has not been visited yet" << endl;
				cout << endl; cout << endl;
				cout << "The remaining cost to derive all the nodes is " << ch.totalCost() <<" in total."<< endl;
				cout << endl; cout << endl;
			}

			else if (control == 4) {

				int indexNum = 0;
				Node** pointerStored = NULL;
				char confirmation = ' ';
				
				do {				
					
					cout << endl; cout << endl;

					cout << "Which node do you want to search? Please input the index of the node." << endl;
					cout << "If you want to review the talent tree, please input -1 to quit and view talent tree."<<endl;
					cout << "Index: ";
					cin >> indexNum;

					if (indexNum == -1)
						break;

					cout << endl; cout << endl;

					ch.searchFuction(ch.findIndex(indexNum));

					cout << "The minimun cost to get one of these node is " << ch.findMinCost(indexNum) <<" costs."<< endl;

					cout << endl; cout << endl;
					do {
						
						if (ch.findIndex(indexNum) == NULL)
							break;

						cout << "Do you want to derive all the nodes listed here?" << endl;
						cout << "Input 'y' for confirmation, 'n' to quit" << endl;
						cin >> confirmation;
					
						if (confirmation == 'y' || confirmation == 'Y') {
							pointerStored = ch.returnListedNodes(ch.FindHeadNUM(indexNum,ch.findIndex(indexNum)), ch.findIndex(indexNum));


							ch.ObtainList(pointerStored);

							cout << endl; cout << endl;
							cout << "Now the status has been updated." << endl;
							cout << endl; cout << endl;
							cout << "Current Status of the Character" << endl;
							cout << "--------------" << endl;
							cout << "HP: " << ch.returnHP() << endl;
							cout << "Str: " << ch.returnAtk() << endl;
							cout << "MP: " << ch.returnMP() << endl;
							cout << "Int: " << ch.returnMag() << endl;
							cout << "Cost: " << ch.returnCost() << endl;
							cout << "Skills: " << endl;
							cout << endl;
							for (int i = 0; i < 30; i++) {
								if (ch.returnskills(i) != "")
									cout << ch.returnskills(i) << endl;
							}
							cout << "--------------" << endl;
							cout << endl;
							break;
					}

				} while (confirmation!='n' && confirmation != 'N');

			} while (indexNum!=-1);


				continue;

			}

			else if (control == 5) {
				cout << endl; cout << endl;
				int num = 0;
				do {				
				ch.FindViable();
				cout << "Which node do you want to obtain?(Please input the index number , -1 for quit)" << endl;
				cout << "Input: ";
				cin >> num;
				if (num == -1)
					break;
				ch.obtainNodes(ch.findIndex(num));
				cout << endl;
				cout << endl; cout << endl; 
				cout << "Current Status of the Character" << endl;
				cout << "--------------" << endl;
				cout << "HP: " << ch.returnHP() << endl;
				cout << "Str: " << ch.returnAtk() << endl;
				cout << "MP: " << ch.returnMP() << endl;
				cout << "Int: " << ch.returnMag() << endl;
				cout << "Cost: " << ch.returnCost() << endl;
				cout << "Skills: " << endl;
				cout << endl;
				for (int i = 0; i < 30; i++) {
					if (ch.returnskills(i) != "")
						cout << ch.returnskills(i) << endl;
				}
				cout << "--------------" << endl;
				cout << endl;


				cout << endl; cout << endl;
				} while (num!=-1);


			}

			else if (control == 6) {
				cout << endl; cout << endl;
				ch.setInfinite();
				cout << endl; cout << endl;
			}

			else if (control == 7) {
				int num = 0;
				int indexNum = 0;
				bool pass = false;
				do {
					cout << endl; cout << endl;
					cout << "Please Enter the command for node insertion (1) , deletion(2) or quit(-1)." << endl;
					cout << "Input: ";
					cin >> num;
					if (num == -1)
						break;
					if (num == 1) {
						char type=' ';
							do {
								cout << "Please input what position do you want to insert. (Or input -1 for quit)" << endl;
								cout << "After index: ";
								cin >> indexNum;
								if (indexNum == -1)
									break;
								if (indexNum < -1) {
									cout << "Error! Please input again." << endl;
									continue;
								}
								pass = true;
							} while (pass == false);


							do {

								cout << "Please input which type of node do you wish to insert." << endl;
								cout << "Input 's' for skill, 'c'for status; only one character is allowed." << endl;
								cout << "Or you can type 0 to leave" << endl;
								cout << "Input: ";
								cin >> type;
								cout << endl;

								if (type == 'c' || type == 'C' || type == 'S' || type == 's' || type == 0) {
									if (type == 'c' || type == 'C') {

										char control;
										string statusC;
										int amount = 0;


											cout << endl;
											cout << "Please input the type of status that you want." << endl;
											cout << "m for MP, h for HP, i for Int, s for Str." << endl;
											cout << "Or you can type 0 to leave" << endl;
											cout << "Input: ";
											cin >> control;


										if (control == 'm' || control == 'M') {
											statusC = "MP";
										}
										else if (control == 'h' || control == 'H') {
											statusC = "HP";
										}
										else if (control == 'i' || control == 'I') {
											statusC = "Magic";
										}
										else if (control == 's' || control == 'S') {
											statusC = "Atk";
										}
										else { break; }

										cout << "How many point would you want to add into the node?" << endl;
										cout << "Input: ";
										cin >> amount;

										ch.Addnode(indexNum, "", amount, statusC, type);

										break;

									}
									if (type == 'S' || type == 's') {
										string skill;
										cout << "Please input the name of the skill" << endl;
										cin >> skill;
										ch.Addnode(indexNum, skill, 10, "", type);

										break;

									}

									continue;
								}
								else {

									break;

								}
								cout << endl;

							} while (type != 'c' || type != 'C' || type != 'S' || type != 's' || type != 0);

						}

					else if (num == 2){
						int Del = 0;
						Node* a = NULL;
						do {
							cout << endl; cout << endl;
							cout << "Please enter which node do you want to delete OR you can type -1 to quit." << endl;
							cout << "Notice: User is only allowed to delete the existing nodes AND the newly added nodes (Index>=46) ." << endl;
							cout << "Index: ";
							cin >> Del;

							if (Del <= 1) {
								break;
							}

							a = ch.findIndex(Del);

							if (a == NULL) {
								cout << "Unexisted Node ! Please input again." << endl;
								continue;
							}
							if (Del >= 2 && Del <= 45) {
								cout << "Error! User is not allowed to modify the existing talent tree." << endl;
								continue;
							}

						} while (Del<=1 || (Del>=2 && Del<=45) || a==NULL);

						if (Del <= 1) {
							break;
						}

						ch.rollBack(Del);
						ch.EditDeletion(Del);

						break;

					}

					else { break; }

				} while (num!=-1);

			}

			else if (control == 8) {
				cout << endl; cout << endl;
				cout << "Thanks for your interest of this game !"<<endl;
				cout << "If you want to comment, please go to" << endl;
				cout << "http://simulator.hk/group1/disscussion.html" << endl;
				cout << "We are looking forward for your participation!" << endl;
				cout << endl; cout << endl;
			}

			else if (control == 9) {
				cout << endl; cout << endl;
				cout << "Are you sure to quit the game?" << endl;
				cout << "Press Y for yes, N for no." << endl;
				cout << "Input: ";
				cin >> condition;
				if (condition == 'Y' || condition == 'y') {
					cout << endl;
					cout << "Thanks for your Joining, User " << ch.returnName() <<" !"<<endl;
					cout << "See you next time =)" << endl;
					cout << endl; cout << endl; cout << endl; cout << endl;
					system("pause");
					return 0;
				}
			}
			else {

				cout << "Invaild input ! Please type the command according to the menu." << endl;
				continue;

			}
		} while (condition=='n' || condition=='N');



	system("pause");
	return 0;
}