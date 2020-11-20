#include "PbBST.h"
#include "analysis.h"

int main()
{
	PbBST reg;
	reg.insertKey(42);
	reg.insertKey(19);
	reg.insertKey(22);
	reg.insertKey(35);
	reg.insertKey(56);
	reg.insertKey(11);
	reg.insertKey(94);
	reg.insertKey(32);
	reg.insertKey(28);
	reg.insertKey(8);
	reg.insertKey(6);
	reg.insertKey(81);
	reg.insertKey(63);
	reg.insertKey(13);
	reg.insertKey(45);

	
	cout << "Nodes requared to fill the tree" << ":  "<< reg.findNodesRequired() << endl<<endl;
	

	reg.deleteKey(56);
	reg.deleteKey(19);

	cout <<"Median of tree is: " << reg.medianOfBST() << endl<<endl;

	cout << "PreOrder Traversal of mirrored tree is:" << endl;
	reg.mirrorTree();  //!!! because method creates new PbBST and dont have return value or parametre, I can't print new mirrored tree in the main.
	cout << endl;


	heightAnalysis();

	return 0;
}
