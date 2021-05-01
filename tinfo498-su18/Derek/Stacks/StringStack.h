#pragma once
#include "StringNode.h"
using std::string;

class StringStack
{
private:
	StringNode* _top;
	int _count;
public:
	StringStack();
	StringStack(string base);
	~StringStack();
	void getStats();
	void push(string data);
	string pop();
};

