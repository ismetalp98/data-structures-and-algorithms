/**
* Title : Binary Search Trees
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 2
* Description : Node of tree
*/


using namespace std;
#include <iostream>

class PbBSTNode { 	// a node in the tree
private:

	int item; 		// a data item in the tree
	PbBSTNode* leftChildPtr;	// pointers to children 
	PbBSTNode* rightChildPtr;


	// friend class - can access private parts
	friend class PbBST;

public:
	PbBSTNode() { }
	PbBSTNode(const int& nodeItem, PbBSTNode* left = NULL, PbBSTNode* right = NULL)
		: item(nodeItem), leftChildPtr(left), rightChildPtr(right) { }
};
