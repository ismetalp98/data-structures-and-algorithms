/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : Friendship header

*/

#ifndef __FRIENDSHIP_H
#define __FRIENDSHIP_H

#include <iostream>
#include "Person.h"
using namespace std;

class Friendship
{
public:
	Friendship(Person* p1, Person* p2);
	Friendship();

private:
	string tag;
	FrindListNode* p1 = NULL;
	FrindListNode* p2 = NULL;
	string condition;

	friend class FriendshipHashing;
};

#endif

