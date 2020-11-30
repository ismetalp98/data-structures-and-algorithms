/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Max-Heap implementation
*/

#ifndef __MAXHEAP_H
#define __MAXHEAP_H

#include <iostream>
#include <cmath>

using namespace std;
const int MAX_HEAP = 1000;

class MaxHeap
{
public:
	MaxHeap();
	void insert(int val); // inserts an element into heap
	int getMax(); // retrieves the minimum element
	int removeMax(); // retrieves and removes the minimum element
	int getSize(); // returns the number of elements in heap in O(1) time
	int getHeight(); // returns the height of heap in O(1) time
	int* getGreaterThan(int val); // returns an array of integer elements that are less than given value by doing a preorder traversal on the heap
	int printCheck() { return 999999; }
	

protected:
	void heapRebuild(int root);
	void isGreaterThan(int location, int val, int& count, int* arr);

private:

	int items[MAX_HEAP];
	int size;
};

#endif