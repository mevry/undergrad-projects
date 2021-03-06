// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"

using std::cout;
using std::endl;

//print bool as string
std::string boolText(bool tf) {
	return tf ? "true" : "false";
}
int main()
{
	BST<int>* bst = new BST<int>(5);

	bst->insert(4);
	bst->insert(6);
	bst->insert(3);
	bst->insert(12);
	bst->insert(4);
	bst->insert(7);
	bst->insert(52039);
	bst->insert(-6420);

	cout << "Initial Tree" << endl;
	bst->enumerate();

	cout << endl;
	cout << "Remove(6)" << endl;
	bst->remove(6);
	
	bst->enumerate();
	
	cout << endl;
	cout << "Contains Tests" << endl;
	cout << "==============" << endl;
	cout << "Contains 12: " << boolText(bst->contains(12)) << endl;
	cout << "Contains 0: " << boolText(bst->contains(0)) << endl;
	cout << "Contains 52039: " << boolText(bst->contains(52039)) << endl;
	cout << "Remove(52039)" << endl;
	bst->remove(52039);
	cout << "Contains 52039: " << boolText(bst->contains(52039)) << endl;
	
	std::cout << std::endl;
    return 0;
}


