#include <iostream>
#include "TreeNode.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("numbers.txt");
	int num;
	TreeType myTree = TreeType();
	while(infile >> num)
	{
		myTree.InsertItem(num);
	}
	infile.close();
	myTree.Inorder();
	cout << endl;
	myTree.Preorder();
	cout << endl;
	myTree.Postorder();
	cout << endl;
	myTree.DeleteItem(15);
	myTree.Inorder();
	cout << endl;
	myTree.FindAncestor(2);
	return 0;
}