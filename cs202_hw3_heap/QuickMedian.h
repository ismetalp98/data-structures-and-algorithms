/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Find the median of the numbers
*/


#ifndef __QUICKMEDIAN_H
#define __QUICKMEDIAN_H

#include <iostream>
#include"MaxHeap.h"
#include"MinHeap.h"
using namespace std;

class QuickMedian {
public:
	void insert(int val); // inserts an element into QuickMedian
	double getMedian(); // returns the median of elements

private:
	MaxHeap heapMax;
	MinHeap heapMin;
};

#endif