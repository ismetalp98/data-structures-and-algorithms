/**
* Title : Binary Search Trees
* Author : Ýsmet Alp Eren
* ID: 21703786
* Section : 1
* Assignment : 2
* Description : This program makes operations in binary search tree
*/


#ifndef __PBBST_H
#define __PBBST_H

#include "PbBSTNode.h"

using namespace std;
class PbBST {
public:
	PbBST() : root(NULL) {};
	~PbBST();
	void insertKey(int key);
	void deleteKey(int key);
	int  getHeight();
	int  getNodeCount();
	int  findNodesRequired();
	void mirrorTree();
	void preorderTraversal();
	double medianOfBST();

private:
	PbBSTNode* root = NULL;
	void insertInorder(PbBSTNode *&treeptr, PbBSTNode *newNode);
	void deleteItem(PbBSTNode*& treePtr, int searchKey);
	void deleteNodeItem(PbBSTNode*& nodePtr);
	void processLeftmost(PbBSTNode*& nodePtr, int& treeItem);
	void getNodeCountHelper(PbBSTNode* node, int& count);
	int getHeightHelper(PbBSTNode* subTree);
	PbBSTNode* mirrorTreeHelper(PbBSTNode* node);
	void preorderTraversalHelper(PbBSTNode* node);
	void visit(int item);
	void destructTree(PbBSTNode* node);
	void medianOfTreeHelper(PbBSTNode* node, int& median, int& firstmedian, int&secondmedian);
};


#endif
