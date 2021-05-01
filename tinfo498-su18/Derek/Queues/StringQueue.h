#pragma once
#include "StringNode.h"
class StringQueue
{
private:
	StringNode * _tail;
	StringNode * _head;
	int _count;
public:
	StringQueue();
	~StringQueue();
	void enqueue(string data);
	string dequeue();

};

