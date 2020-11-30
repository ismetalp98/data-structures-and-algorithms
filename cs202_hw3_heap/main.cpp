/**
* Title : Heaps
* Author : Ismet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 3
* Description : driver file
*/


#include"MinHeap.h"
#include"MaxHeap.h"
#include"QuickMedian.h"


int main()
{

	MinHeap minHeap;
	MaxHeap maxHeap;

	cout << endl << endl << "------------------------------Min Heap---------------------------------" << endl<<endl;

	minHeap.insert(15);
	minHeap.insert(50);
	minHeap.insert(45);
	minHeap.insert(30);
	minHeap.insert(60);
	minHeap.insert(55);
	minHeap.insert(20);
	minHeap.insert(35);
	minHeap.insert(10);
	minHeap.insert(25);
	minHeap.insert(65);



	cout << "Minimum item: " << minHeap.getMin() << endl;
	cout << "Size: " << minHeap.getSize() << endl;
	cout << "Height: " << minHeap.getHeight() << endl << endl;
	int* arrMin = minHeap.getLessThan(40);

	cout << "Items less than 40:  ";

	int i = 0;
	while (arrMin[i] != minHeap.printCheck())
	{
		cout << arrMin[i] << " ";
		i++;
	}

		

	delete[] arrMin;
	cout << endl << endl << "------------------------------Max Heap---------------------------------" << endl << endl;

	maxHeap.insert(15);
	maxHeap.insert(50);
	maxHeap.insert(45);
	maxHeap.insert(30);
	maxHeap.insert(60);
	maxHeap.insert(55);
	maxHeap.insert(20);
	maxHeap.insert(35);
	maxHeap.insert(10);
	maxHeap.insert(25);
	maxHeap.insert(65);

	cout << "Maximum item: " << maxHeap.getMax() << endl;
	cout << "Size: " << maxHeap.getSize() << endl;
	cout << "Height: " << maxHeap.getHeight() << endl << endl;

	int* arrMax = maxHeap.getGreaterThan(40);

	cout << "Items greater than 40:  ";

	i = 0;
	while (arrMax[i] != maxHeap.printCheck())
	{
		cout << arrMax[i] << " ";
		i++;
	}


		

	delete[] arrMax;
	cout << endl << endl << "------------------------------Meadian---------------------------------" << endl;

	QuickMedian med;

	med.insert(10);
	med.insert(40);
	med.insert(30);
	med.insert(50);
	med.insert(70);
	med.insert(60);
	med.insert(20);
	med.insert(90);
	med.insert(100);
	med.insert(110);
	med.insert(0);
	med.insert(25);
	med.insert(123);
	med.insert(11);
	med.insert(200);

	cout << endl << "Meadian is: "<< med.getMedian() << endl;

	return 0;
}