// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringList.h"
#include "LinkedList.h"
#include <vector>

using namespace std;
using std::cout;
using std::endl;
int main()
{
	vector<int> numberList;
	for (int i = 1; i <= 20; i+=2) {
		numberList.push_back(i);
	}

	LinkedList<int>* int_list = new LinkedList<int>();

	for (auto integer : numberList) {
		int_list->addToHead(integer);
	}

	cout << "Initial List of Integers" << endl;
	cout << "------------------------" << endl;
	int_list->enumerate();

	cout << endl;
	cout << "Removing 2 from front, 2 from tail" << endl;
	cout << "----------------------------------" << endl;

	int_list->removeFromHead();
	int_list->removeFromHead();
	int_list->removeFromTail();
	int_list->removeFromTail();

	int_list->enumerate();
	cout << endl;
    return 0;
}

