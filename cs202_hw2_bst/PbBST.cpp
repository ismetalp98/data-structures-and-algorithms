/**
* Title : Binary Search Trees
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 2
* Description : This program makes operations in binary search tree
*/




#include "PbBST.h"
#include<cmath>
using namespace std;

// ------ insertion of key ---------------

void PbBST::insertKey(int key)
{
	PbBSTNode* node = new PbBSTNode(key);
	insertInorder(root, node);
}


PbBST::~PbBST()
{
	destructTree(root);
}


void PbBST::destructTree(PbBSTNode* node)
{
	if (node != NULL)
	{
		destructTree(node->leftChildPtr);
		destructTree(node->rightChildPtr);
		delete node;
	}
}


void PbBST::insertInorder(PbBSTNode*& treeptr, PbBSTNode* newNode)
{
	if (treeptr == NULL)
	{
		treeptr = newNode;
	}

	else if (newNode->item < treeptr->item)
	{
		insertInorder(treeptr->leftChildPtr, newNode);
	}
	else
	{
		insertInorder(treeptr->rightChildPtr, newNode);
	}
}


// ------ deletion of key ---------------

void PbBST::deleteKey(int key)
{
	deleteItem(root, key);
}


void PbBST::deleteItem(PbBSTNode*& treePtr, int searchKey)
{
	if (treePtr == NULL) // Empty tree
		return;

	// Position of deletion found
	else if (searchKey == treePtr->item)
		deleteNodeItem(treePtr);

	// Else search for the deletion position
	else if (searchKey < treePtr->item)
		deleteItem(treePtr->leftChildPtr, searchKey);
	else
		deleteItem(treePtr->rightChildPtr, searchKey);
}

void PbBST::deleteNodeItem(PbBSTNode*& nodePtr) {

	PbBSTNode* delPtr;
	int replacementItem;

	// (1)  Test for a leaf
	if ((nodePtr->leftChildPtr == NULL) &&
		(nodePtr->rightChildPtr == NULL)) {
		delete nodePtr;
		nodePtr = NULL;
	}


	// (2)  Test for no left child
	else if (nodePtr->leftChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;
		delete delPtr;
	}
	// (3)  Test for no right child
	else if (nodePtr->rightChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->leftChildPtr;
		delPtr->leftChildPtr = NULL;
		delete delPtr;
	}

	else {
		processLeftmost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}

}

void PbBST::processLeftmost(PbBSTNode*& nodePtr, int& treeItem) {

	if (nodePtr->leftChildPtr == NULL) {
		treeItem = nodePtr->item;
		PbBSTNode* delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; // defense
		delete delPtr;
	}
	else
		processLeftmost(nodePtr->leftChildPtr, treeItem);
}


// ------ calculate Nodes Required ---------------

int PbBST::getHeight()
{

	return getHeightHelper(root);
}

int PbBST::getHeightHelper(PbBSTNode* subTree)
{
	if (subTree == NULL)
		return 0;
	else
		return 1 + max(getHeightHelper(subTree->rightChildPtr), getHeightHelper(subTree->leftChildPtr));
}

int PbBST::getNodeCount()
{
	int nodecnt = 0;
	getNodeCountHelper(root, nodecnt);
	return nodecnt;
}

void PbBST::getNodeCountHelper(PbBSTNode* node, int& count)
{
	if (node == NULL)
		return;
	else
	{
		count++;
		getNodeCountHelper(node->rightChildPtr, count);
		getNodeCountHelper(node->leftChildPtr, count);
	}
}

int PbBST::findNodesRequired()
{
	int maxNodeCounter = 0;

	maxNodeCounter = (int)pow(2, getHeight()) - 1;

	return maxNodeCounter - getNodeCount();
}


// ------ mirror tree ---------------


void PbBST::mirrorTree()
{
	if (root == NULL)
	{
	}
	PbBST mt;
	mt.root = mirrorTreeHelper(root);
	mt.preorderTraversal();
}

PbBSTNode* PbBST::mirrorTreeHelper(PbBSTNode* node)
{
	if (node == NULL) 
		return NULL;
	PbBSTNode* left = mirrorTreeHelper(node->leftChildPtr);
	PbBSTNode* right = mirrorTreeHelper(node->rightChildPtr);
	PbBSTNode* current = new PbBSTNode();
	current->item = node->item;
	current->leftChildPtr = right;
	current->rightChildPtr = left;
	return current;
}


// ------ preorderTraversal ---------------

void PbBST::preorderTraversal()
{

	preorderTraversalHelper(root);
	cout << endl;
}



void PbBST::preorderTraversalHelper(PbBSTNode* node)
{
	if (node != NULL)
	{
		visit(node->item);
		preorderTraversalHelper(node->leftChildPtr);
		preorderTraversalHelper(node->rightChildPtr);
	}
}

void PbBST::visit(int item)
{
	cout << item << " ";
}


double PbBST::medianOfBST()
{
	int firstmedian = 0, secondmedian = 0, count = 0;
	medianOfTreeHelper(root, count, firstmedian, secondmedian);
	if (getNodeCount() % 2 == 1)
		return secondmedian;
	else
	{
		double res = (double)(firstmedian + secondmedian) / 2;
		return res;
	}
}


void PbBST::medianOfTreeHelper(PbBSTNode* node, int& count, int& firstmedian, int& secondmedian)
{
	if (node != NULL)
	{
		medianOfTreeHelper(node->leftChildPtr, count, firstmedian, secondmedian);
		count++;
		if (count == (getNodeCount() / 2) )
			firstmedian = node->item;
		if (count == (getNodeCount() / 2) + 1)
			secondmedian = node->item;
		medianOfTreeHelper(node->rightChildPtr, count, firstmedian, secondmedian);
	}
}


