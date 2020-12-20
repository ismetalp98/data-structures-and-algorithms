/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : Create Friendship
*/


#include "Friendship.h"


Friendship::Friendship(Person* pe1, Person* pe2)
{
	if (pe1->name[0] < pe2->name[0])
	{
		tag = pe1->name + pe2->name;
	}
	else
		tag = pe2->name + pe1->name;

	pe1->insertFriend(pe2->name);
	pe2->insertFriend(pe1->name);

	Friendship::p1 = pe2->root;
	Friendship::p2 = pe1->root;


}



Friendship::Friendship()
{
	tag = "";
}
