/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : main
*/


#include"PersonHashing.h"
#include "FriendshipHashing.h"
#include <fstream>

int main()
{
	PersonHashing ph;
	FriendshipHashing fh;

	ifstream myfile;
	myfile.open("input.txt");

	if (myfile.is_open())
	{
		string operation;

		

		do
		{
			myfile >> operation;

			if (operation == "P")
			{
				string name = "";
				myfile >> name;
				Person person(name);
				ph.insertTable(person);
			}

			else if (operation == "F")
			{
				string p1;	myfile >> p1;
				string p2;	myfile >> p2;
				Person* pe1 = ph.getPerson(p1);
				Person* pe2 = ph.getPerson(p2);

				Friendship fs(pe1, pe2);
				fh.insertFriendship(fs);
			}

			else if (operation == "U")
			{
				string p1;	myfile >> p1;
				string p2;	myfile >> p2;
				Person* pe1 = ph.getPerson(p1);
				Person* pe2 = ph.getPerson(p2);
				fh.deleteFreiendship(pe1, pe2);
			}
			else if (operation == "L")
			{
				string name = "";
				myfile >> name;
				Person* pe1 = ph.getPerson(name);
				pe1->printList();
			}
			else if (operation == "Q")
			{
				string p1;	myfile >> p1;
				string p2;	myfile >> p2;
				Person* pe1 = ph.getPerson(p1);
				Person* pe2 = ph.getPerson(p2);
				fh.find(pe1, pe2);
			}

		} while (operation != "X");
		myfile.close();
	}
	else cout << "Unable to open file";
	ph.terminate();
	return 0;
}