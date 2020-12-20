/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : FriendshipHashing header
*/

#ifndef __FRIENDSHIPHASHING_H
#define __FRIENDSHIPHASHING_H

#include <iostream>
#include"Friendship.h"
using namespace std;



class FriendshipHashing
{
public:
	FriendshipHashing();
	void insertFriendship(Friendship fs);
	void deleteFreiendship(Person* p1, Person* p2);
	void find(Person* p1, Person* p2);
private:
	Friendship arr[71];

};

#endif

