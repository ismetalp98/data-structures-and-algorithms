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

using namespace std;

int main()
{
	int compCountq = 0, moveCountq = 0;
	int compCounti = 0, moveCounti = 0;
	int compCounth = 0, moveCounth = 0;
	int size = 10;

	int arrq[10] = { 20, 1, 100, 57, 92, 43, 99, 93,17, 58 };
	int arri[10] = { 20, 1, 100, 57, 92, 43, 99, 93,17, 58 };
	int arrh[10] = { 20, 1, 100, 57, 92, 43, 99, 93,17, 58 };
	
	int* arrquick = arrq;
	int* arrinsertion = arri;
	int* arrhybrit = arrh;

	quickSort(arrquick, 0, size - 1, compCountq, moveCountq);
	insertionSort(arrinsertion, size, compCounti, moveCounti);
	hybridSort(arrhybrit, size, compCounth, moveCounth);

	printArray(arrquick, size);
	printArray(arrinsertion, size);
	printArray(arrhybrit, size);

	performanceAnalysis();

	return 0;
}