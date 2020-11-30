/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Min-Heap implementation
*/


#ifndef __MINHEAP_H
#define __MINHEAP_H

#include <iostream>
#include<cmath>
using namespace std;
const int MIN_HEAP = 1000;

class MinHeap
{
public:
	MinHeap();
	void insert(int val); // inserts an element into heap
	int getMin(); // retrieves the minimum element
	int removeMin(); // retrieves and removes the minimum element
	int getSize(); // returns the number of elements in heap in O(1) time
	int getHeight(); // returns the height of heap in O(1) time
	int* getLessThan(int val); // returns an array of integer elements that are less than given value by doing a preorder traversal on the heap
	int printCheck() { return 999999; }

protected:
	void heapRebuild(int root);
	void isLessThan(int location, int& val, int& count, int* arr);

private:
	
	int items[MIN_HEAP];
	int size;
	
};

#endif