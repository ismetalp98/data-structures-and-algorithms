/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : Person header
*/

#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;

struct FrindListNode;

class Person
{
public:
	Person();
	Person(string name);
	string getName();
	void insertFriend(string p1);
	void printList();
	void terminate();
	void deleteFriend(FrindListNode* node);

private:
	string name;
	FrindListNode* root;

	friend class PersonHashing;
	friend class Friendship;
	friend class FriendshipHashing;
};

struct FrindListNode {
public:
	Person data;
	FrindListNode* next = NULL;
	FrindListNode* prev = NULL;
};

#endif
