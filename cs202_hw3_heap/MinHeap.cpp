/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Min-Heap implementation
*/


#include "MinHeap.h"



MinHeap::MinHeap()
{
	size = 0;
}

void MinHeap::insert(int val)
{
	if (size >= MIN_HEAP - 1)
	{
		cout << "Size error" << endl << endl;
		return;
	}

	items[size] = val;

	int place = size;
	int parent = (place - 1) / 2;

	while ((place > 0) && (items[place] < items[parent])) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
}

int MinHeap::getMin()
{
	return items[0];
}

int MinHeap::removeMin()
{
	int min = getMin();
	items[0] = items[size - 1];
	size--;
	heapRebuild(0);
	return min;
}

int MinHeap::getSize()
{
	return size;
}

int MinHeap::getHeight()
{
	return ceil(log2(size + 1));
}

int* MinHeap::getLessThan(int val)
{
	int* arr = new int[MIN_HEAP];
	int count = 0;
	if (val < getMin())
		return NULL;
	if (val == getMin())
		arr[count++] = val;
	else
		isLessThan(count, val, count, arr);
	arr[count] = printCheck();
	return arr;
}


void MinHeap::isLessThan(int location, int& val, int& count, int* arr)
{
	if (location < size)
	{
		if (items[location] < val)
		{
			arr[count] = items[location]; count++;
			isLessThan((2 * location) + 1, val, count, arr);
			isLessThan((2 * location) + 2, val, count, arr);
		}
	}
}


void MinHeap::heapRebuild(int root)
{
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) &&
			(items[rightChild] < items[child]))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (items[root] > items[child]) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
