
/**
* Title : Algorithm Efficiency and Sorting
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 1
* Description : This program will compare three diffrent sorting algorithm
*/

#ifndef __SORTING_H
#define __SORTING_H

using namespace std;

void quickSort(int* arr, int f, int l, int& compCount, int& moveCount);
void swap(int& x, int& y, int& compCount, int& moveCount);
void partition(int theArray[], int first, int last, int& pivotIndex, int& compCount, int& moveCount);

void insertionSort(int* arr, int size, int& compCount, int& moveCount);
void hybridSort(int* arr, int size, int& compCount, int& moveCount);
void quickSorthb(int* arr, int first, int last, int& compCount, int& moveCount);

void printArray(int* arr, int size);

void performanceAnalysis();

#endif