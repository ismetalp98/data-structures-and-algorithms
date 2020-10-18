/**
* Title : Algorithm Efficiency and Sorting
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 1
* Description : This program will compare three diffrent sorting algorithm
*/


#include "sorting.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>

void quickSort(int* arr, int f, int l, int& compCount, int& moveCount)
{
	int pivotIndex;

	if (f < l) {
		// create the partition: S1, pivot, S2
		partition(arr, f, l, pivotIndex, compCount, moveCount);

		// sort regions S1 and S2
		quickSort(arr, f, pivotIndex - 1, compCount, moveCount);
		quickSort(arr, pivotIndex + 1, l, compCount, moveCount);
	}
}


void partition(int theArray[], int first, int last, int& pivotIndex, int& compCount, int& moveCount)
{
	int pivot = theArray[first];  moveCount++; // copy pivot 

	int lastS1 = first;       // index of last item in S1
	int firstUnknown = first + 1;

	// move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) {

		// move item from unknown to proper region
		if (theArray[firstUnknown] < pivot) {  	// belongs to S1
			++lastS1;
			compCount++;
			swap(theArray[firstUnknown], theArray[lastS1], compCount, moveCount);
		}	// else belongs to S2
	}
	// place pivot in proper position and mark its location
	swap(theArray[first], theArray[lastS1], compCount, moveCount);
	pivotIndex = lastS1;
}

void swap(int& x, int& y, int& compCount, int& moveCount)
{
	int temp = x;
	x = y;
	y = temp;
	moveCount = moveCount + 3;
}




void insertionSort(int* arr, int size, int& compCount, int& moveCount)
{
	for (int unsorted = 1; unsorted < size; ++unsorted) {

		int nextItem = arr[unsorted]; moveCount++;
		int loc = unsorted;

		for (;(loc > 0) && (arr[loc - 1] > nextItem); --loc)
		{
			arr[loc] = arr[loc - 1];
			moveCount++;
			compCount++;
		}
		arr[loc] = nextItem;
		moveCount++;
	}
}

void hybridSort(int* arr, int size, int& compCount, int& moveCount)
{
	quickSorthb(arr, 0, size-1, compCount, moveCount);
}

void quickSorthb(int* arr, int first, int last, int& compCount, int& moveCount)
{
	int pivotIndex;
	if (last - first < 10)
	{
		insertionSort(arr, last-first+1, compCount, moveCount);
	}
	else
	{
		partition(arr, first, last, pivotIndex, compCount, moveCount);
		
		quickSorthb(arr, first, pivotIndex -1 , compCount, moveCount);
		quickSorthb(arr, pivotIndex + 1, last, compCount, moveCount);
	} 
}



void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void performanceAnalysis()
{
	int** arrquick = new int* [10];
	int** arrinsert = new int* [10];
	int** arrhybrid = new int* [10];
	int k = 0;

	for (int i = 2; i <= 20; i = i + 2)
	{

		int size = i * 1000;

		int* arrq = new int[size];
		int* arri = new int[size];
		int* arrh = new int[size];


		for (int j = 0; j < size; j++)
		{
			int v2 = rand() % size + 1;
			arrq[j] = v2;
			arri[j] = v2;
			arrh[j] = v2;
		}

		arrquick[k] = arrq;
		arrinsert[k] = arri;
		arrhybrid[k] = arrh;

		k++;
	}

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Part a - Time analysis of Quick Sort" << endl;
	cout << "Array Size     Time Elapsed(ms)      compCount         moveCount" << endl;

	int compCount = 0, moveCount = 0;
	int j = 2;
	for (int i = 0; i < 10; i++)
	{

		int size = (j) * 1000;
		int* arr = arrquick[i];

		clock_t start = clock();
		quickSort(arr, 0, size - 1, compCount, moveCount);
		clock_t end = clock();
		double diffticks = (double)end - (double)start;
		double diffms = diffticks / (CLOCKS_PER_SEC/1000);

		cout << size << "\t\t" << diffms << "\t\t\t" << compCount << "\t\t  " << moveCount << endl;

		j = j + 2;
		delete[] arr;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;





	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Part b - Time analysis of Insertion Sort" << endl;
	cout << "Array Size     Time Elapsed(ms)         compCount         moveCount" << endl;

	compCount = 0, moveCount = 0;
	j = 2;
	for (int i = 0; i < 10; i++)
	{
		int size = (j) * 1000;
		int* arr = arrinsert[i];
		

		clock_t start = clock();
		insertionSort(arr, size, compCount, moveCount);

		clock_t end = clock();
		double diffticks = end - start;
		double diffms = diffticks / (CLOCKS_PER_SEC / 1000);

		cout << size << "\t\t" << diffms << "\t\t\t" << compCount << "  \t    " << moveCount << endl;

		j = j + 2;
		delete[] arr;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;






	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Part c - Time analysis of Hybrit Sort" << endl;
	cout << "Array Size    Time Elapsed(ms)       compCount        moveCount" << endl;

	compCount = 0, moveCount = 0;
	j = 2;
	for (int i = 0; i < 10; i++)
	{
		int size = (j) * 1000;
		int* arr = arrhybrid[i];
		
		clock_t start = clock();
		hybridSort(arr, size, compCount, moveCount);

		clock_t end = clock();
		double diffticks = end - start;
		double diffms = diffticks / (CLOCKS_PER_SEC/1000 );

		cout << size << "\t\t" << diffms << "\t\t\t" << compCount << "\t\t" << moveCount << endl;

		j = j + 2;
		delete[] arr;
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;

	delete[] arrquick;
	delete[] arrinsert;
	delete[] arrhybrid;
}

