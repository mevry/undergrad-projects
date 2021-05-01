#include "stdafx.h"
#include "StringStack.h"
using std::string;
using std::cout;
using std::endl;
StringStack::StringStack() {}
StringStack::StringStack(string base)
{
	_top = new StringNode(base);
	++_count;
	cout << "String Stack Initialized; Stack Count: " << _count << endl;
	cout << "Ct: " << _count << " Pushed Node: \"" << _top->GetString() << "\"" << endl;
}
StringStack::~StringStack()
{

}

void StringStack::getStats()
{
	std::cout << "Stack Count: " << _count << std::endl;
}

void StringStack::push(string data)
{
	StringNode *newNode = new StringNode(data);
	newNode->SetPrev(_top);
	_top = newNode;
	++_count;
	cout << "Ct: " <<_count << " Pushed Node: \"" << newNode->GetString() << "\"" << endl;
}

string StringStack::pop()
{
	if (_count > 0) {
		StringNode *popped = _top;
		_top = _top->GetPrev();
		--_count;
		cout <<"Ct: " << _count << " Popped Node: \"" << popped->GetString() << "\"" << endl;
		return popped->GetString();
	}
	else
	{
		cout << "END OF STACK" << endl;
		return "END OF STACK";
	}
}
