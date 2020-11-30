/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : Find the median of the numbers
*/


#include "QuickMedian.h"

void QuickMedian::insert(int val)
{
	int maxSize = heapMax.getSize();
	int minSize = heapMin.getSize();
	int median = 0;


	if (maxSize != 0 && minSize != 0)
	{
		if (minSize > maxSize)
			median = heapMin.getMin();
		if (minSize < maxSize)
			median = heapMax.getMax();
		else
			median = ( heapMax.getMax() + heapMin.getMin() ) / 2;
	}


	if (val > median)
		heapMin.insert(val);
	else
		heapMax.insert(val);

	maxSize = heapMax.getSize();
	minSize = heapMin.getSize();

	if (minSize > maxSize + 1)
	{
		int min = heapMin.removeMin();
		heapMax.insert(min);
	}
	else if (maxSize > minSize + 1)
	{
		int max = heapMax.removeMax();
		heapMin.insert(max);
	}
}

double QuickMedian::getMedian()
{
	int maxSize = heapMax.getSize();
	int minSize = heapMin.getSize();
	
	if (maxSize > minSize)
		return heapMax.getMax();
	if (maxSize < minSize)
		return heapMin.getMin();
	else
		return ((double)heapMax.getMax() + (double)heapMin.getMin() ) / 2;
}
