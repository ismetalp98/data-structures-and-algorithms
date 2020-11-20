/**
* Title : Binary Search Trees
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 2
* Description : Analize the tree operations
*/


#include "analysis.h"
#include "PbBST.h"
#include <stdlib.h> 

void heightAnalysis()
{
	PbBST root;
	int maxsize = 15000, currentsize = 1500, arrsize = 1;
	int* arr = new int[15000];
	arr[0] = rand() % maxsize;

	cout << endl << "Creating array...... It takes some time because creating 15000 unique number requires time " << endl << endl;

	//create array of 15000 random generated unique number
	for (int i = 1; i < maxsize; i++)
	{
		int rn = rand() % maxsize ;
		bool exist = false;
		for (int j = 0; j < arrsize ; j++)
		{
			if (rn == arr[j])
			{
				exist = true;
				break;
			}
		}
		if(exist)
			i--;
		else
		{
			arr[i] = rn;
			arrsize++;
		}
	}

	//part-1 of analysis heigth

	cout << "Part e - Height analysis of Binary Search Tree - part 1" << endl
		<< "---------------------------------------------------------" << endl
		<< "Tree Size Tree Height" << endl
		<< "---------------------------------------------------------" << endl;

	for (int i = 0; i < maxsize; i++)
	{
		root.insertKey(arr[i]);
	
		if (i == currentsize)
		{
			cout << i << "\t" << root.getHeight() << endl;
			currentsize += 1500;
		}
	}
	cout << currentsize << "\t" << root.getHeight() << endl;
	currentsize = maxsize - 1500;


	//shuffle array---------------------
	for (int i = 0; i < 15000; i++)
	{
		int from = rand() % maxsize;
		int to = rand() % maxsize;
		int tempt = arr[to];
		arr[to] = arr[from];
		arr[from] = tempt;
	}

	//part-2 of analysis heigth

	cout <<endl <<"Part e - Height analysis of Binary Search Tree - part 2" << endl
		<< "---------------------------------------------------------" << endl
		<< "Tree Size Tree Height" << endl
		<< "---------------------------------------------------------" << endl;

	

	for(int i = maxsize -1; i > 0; i--)
	{
		int tempt = arr[i];
		root.deleteKey(tempt);
		if (i == currentsize)
		{
			cout << i << "\t" << root.getHeight() << endl;
			currentsize -= 1500;
		}
	}
	root.deleteKey(arr[0]);
	cout << currentsize << "\t" << root.getHeight() << endl;
	delete[] arr;
}