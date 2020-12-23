/**
* Title : Hash
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 4
* Description : create Friendship hash tabe and make some operations
*/


#include "FriendshipHashing.h"
#include <cmath>

FriendshipHashing::FriendshipHashing()
{
}

void FriendshipHashing::insertFriendship(Friendship fs)
{
	int sum = 0;
	for (int i = 0; i < (int)fs.tag.length(); i++)
	{
		sum += fs.tag[i];
	}

	sum = sum % 71;

	if (arr[sum].condition != "occupied")
	{
		arr[sum] = fs;
	}
	else
	{
		int i = 1;
		while (arr[sum].condition == "occupied")
		{
			sum += pow(i, 2);
			sum = sum % 71;
			i++;
		}
		arr[sum] = fs;
	}

}

void FriendshipHashing::deleteFreiendship(Person* p1, Person* p2)
{

	int sum = 0;
	string tag;
	if (p1->name < p2->name)
		tag = p1->name + p2->name;
	else
		tag = p2->name + p1->name;



	for (int i = 0; i < (int)tag.length(); i++)
	{
		sum += tag[i];
	}
	sum = sum % 71;


	int i = 1;
	bool founded = false;

	while (arr[sum].condition != "empty")
	{
		if (arr[sum].tag == tag)
		{
			founded = true;
			break;
		}
		else
		{
			sum += pow(i, 2);
			sum = sum % 71;
			i++;
		}
	}

	if (founded)
	{
		if (p1->name != arr[sum].p1->data.name)
		{
			p1->deleteFriend(arr[sum].p1);
			p2->deleteFriend(arr[sum].p2);
		}
		else
		{
			p1->deleteFriend(arr[sum].p2);
			p2->deleteFriend(arr[sum].p1);
		}

		arr[sum].tag = "";
		arr[sum].condition = "deleted";
	}
}

void FriendshipHashing::find(Person* p1, Person* p2)
{

	int sum = 0;
	string tag = "";
	if (p1->name < p2->name)
	{
		tag = p1->name + p2->name;
	}
	else
		tag = p2->name + p1->name;


	for (int i = 0; i < (int)tag.length(); i++)
	{
		sum += tag[i];
	}
	sum = sum % 71;


	int i = 1;
	bool founded = false;
	while (arr[sum].condition != "empty")
	{
		if (arr[sum].tag == tag)
		{
			founded = true;
			cout << "yes" << endl;
			break;
		}
		else
		{
			sum += pow(i, 2);
			sum = sum % 71;
			i++;
		}
	}
	if(!founded)
		cout << "no" << endl;
}




