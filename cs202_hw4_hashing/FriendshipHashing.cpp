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
	for (int i = 0; i < fs.tag.length(); i++)
	{
		sum += fs.tag[i];
	}

	sum = sum % 71;

	if (arr[sum].tag == "")
	{
		arr[sum] = fs;
	}
	else
	{
		int i = 1;
		while (arr[sum].tag != "")
		{
			sum += pow(i,2);
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

	

	for (int i = 0; i < tag.length(); i++)
	{
		sum += tag[i];
	}
	sum = sum % 71;


	int i = 1;
	while (arr[sum].tag != tag)
	{
		sum += pow(i, 2);
		sum = sum % 71;
		i++;
	}


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

	arr[sum] = Friendship();
}

void FriendshipHashing::find(Person* p1, Person* p2)
{

	string tag = "";
	if (p1->name[0] < p2->name[0])
	{
		tag = p1->name + p2->name;
	}
	else
		tag = p2->name + p1->name;



	for (int i = 0; i < 71; i++)
	{
		if (arr[i].tag == tag)
		{
			cout << "yes" << endl;
			return;
		}
	}
	cout << "no" << endl;;
}




