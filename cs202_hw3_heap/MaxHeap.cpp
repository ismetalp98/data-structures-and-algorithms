/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Max-Heap implementation
*/



#include "MaxHeap.h"



MaxHeap::MaxHeap()
{
	size = 0;
}

void MaxHeap::insert(int val)
{
	if (size >= MAX_HEAP - 1)
	{
		cout << "Size error" << endl << endl;
	}

	items[size] = val;

	int place = size;
	int parent = (place - 1) / 2;

	while ((place > 0) && (items[place] > items[parent])) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
}

int MaxHeap::getMax()
{
	return items[0];
}

int MaxHeap::removeMax()
{
	int max = getMax();
	items[0] = items[size - 1];
	size--;
	heapRebuild(0);
	return max;
}

int MaxHeap::getSize()
{
	return size;
}

int MaxHeap::getHeight()
{	
	return ceil(log2(size + 1));
}

int* MaxHeap::getGreaterThan(int val)
{
	int* arr = new int[MAX_HEAP];
	int count = 0;
	if (val > getMax())
		return NULL;
	if (val == getMax())
		arr[count++] = val;
	else
		isGreaterThan(count, val, count, arr);
	arr[count] = printCheck();
	return arr;
}

void MaxHeap::isGreaterThan(int location, int val, int& count, int* arr)
{
	if (location < size)
	{
		if (items[location] > val)
		{
			arr[count] = items[location];
			count++;
			isGreaterThan((2 * location) + 1, val, count, arr);
			isGreaterThan((2 * location) + 2, val, count, arr);
		}
	}
}


void MaxHeap::heapRebuild(int root)
{
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) &&
			(items[rightChild] > items[child]))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (items[root] < items[child]) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
