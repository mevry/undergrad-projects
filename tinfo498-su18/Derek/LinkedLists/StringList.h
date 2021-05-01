#pragma once
#include "StringNode.h"
class StringList
{
private:
	StringNode *_head;
	StringNode *_tail;
	int _count;
public:
	StringList(string data);
	StringList() = default;
	~StringList();

	void AddToTail(string data);
	void AddToHead(string data);

	void RemoveFromTail();
	void RemoveFromHead();

	string find(int index);
	bool find(string str);

	void insert(string str, int index);
	int Length() { return _count; };
	void Enumerate();
};

