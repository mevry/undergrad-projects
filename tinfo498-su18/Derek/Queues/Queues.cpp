// Queues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringQueue.h"
#include "Queue.h"
#include <vector>

using namespace std;
int main()
{
	vector<string> stringVector = vector<string>{
		"string 6",
		"string 5",
		"string 4",
		"string 3",
		"string 2",
		"string 1",
	};

	Queue<string> *str_queue = new Queue<string>();

	for(string str : stringVector) {
		str_queue->enqueue(str);
	}
	

	cout << "Current Queue:" << endl;
	cout << "--------------" << endl;
	str_queue->Enumerate();
	cout << "--------------" << endl;

	cout << endl;
	cout << "Dequeuing First 5 Strings:" << endl;
	cout << "--------------------------" << endl;

	for (int i = 0; i < 5; i++) {
		cout << str_queue->dequeue() << endl;
	}
	cout << "--------------------------" << endl;

	cout << endl;
	cout << "Remaining in Queue:" << endl;
	cout << "-------------------" << endl;
	str_queue->Enumerate();
	cout << "-------------------" << endl;

    return 0;
}

