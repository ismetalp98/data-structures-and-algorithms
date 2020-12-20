/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : create a Person hash table and make some operations
*/


#include "PersonHashing.h"


PersonHashing::PersonHashing()
{
}



void PersonHashing::insertTable(Person key)
{
	int sum = 0;
	
	for (int i = 0; i < (int)key.name.length(); i++)
	{
		sum += (int)key.name[i];
	}

	sum = sum % 11;
	
	if (arr[sum].root == NULL)
	{
		arr[sum].root = new PersonListNode;
		arr[sum].root->data = key;
	}
	else
	{
		PersonListNode* newnode = new PersonListNode;
		newnode->data = key;
		newnode->next = arr[sum].root;
		arr[sum].root = newnode;
		
	}
}


Person* PersonHashing::getPerson(string name)
{
	int sum = 0;

	for (int i = 0; i < (int)name.length(); i++)
	{
		sum += (int)name[i];
	}
	sum = sum % 11;

	PersonListNode* tempt = arr[sum].root;
	while (tempt->data.name != name)
	{
		tempt = tempt->next;
	}
	return &(tempt->data);
}

void PersonHashing::terminate()
{
	for (int i = 0; i < 11; i++)
		arr[i].terminate();
}

void PersonList::terminate()
{
	PersonListNode* next, *current = root;
	while (current != NULL)
	{
		next = current->next;
		current->data.terminate();
		delete current;
		current = next;
	}
	root = NULL;
}
