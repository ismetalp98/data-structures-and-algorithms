/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : PersonHashing header
*/

#ifndef __PERSONHASHING_H
#define __PERSONHASHING_H

#include <iostream>
#include"Person.h"
using namespace std;

struct PersonListNode {
public:
	
	Person data;
	PersonListNode* next = NULL;
};

class PersonList {
public:
	PersonList() : root(NULL) {};
	PersonListNode* root;
	void terminate();
};

class PersonHashing
{
public:
	PersonHashing();
	void insertTable(Person key);
	Person* getPerson(string name);
	void terminate();
private:
	PersonList arr[11];
	
};

#endif