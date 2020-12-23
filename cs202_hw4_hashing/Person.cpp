/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : creates a Person
*/

#include "Person.h"

Person::Person()
{
	name = "";
}

Person::Person(string name)
{
	Person::name = name;
	root = NULL;
}


string Person::getName()
{
	return name;
}

void Person::insertFriend(string name)
{
	if (root == NULL)
	{
		root = new FrindListNode;
		Person p(name);
		root->data = p;
		p.terminate();
	}
	else
	{
		FrindListNode* newNode = new FrindListNode;
		Person p(name);
		newNode->data = p;
		newNode->next = root;
		root->prev = newNode;
		root = newNode;
		p.terminate();
	}
}


void Person::printList()
{
	FrindListNode* tempt = root;
	while (tempt != NULL)
	{
		cout << tempt->data.name <<"  ";
		tempt = tempt->next;
	}
	cout << endl;
}



void Person::terminate()
{
	FrindListNode* next, * current = root;
	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}
	root = NULL;
}

void Person::deleteFriend(FrindListNode* node)
{
	if (node->prev == NULL)
	{
		root = root->next;
		delete node;
	}
	else
	{
		node->prev->next = node->next;
		delete node;
	}
}


