#include "stdafx.h"
#include "StringList.h"
using std::cout;
using std::endl;

StringList::StringList(string data)
{
	StringNode *node = new StringNode(data);
	_head = node;
	_tail = node;
	++_count;
}


StringList::~StringList()
{
}

void StringList::AddToTail(string data)
{
	StringNode *node = new StringNode(data);
	if (_count > 0) {		
		_tail->SetNext(node);
		node->SetPrev(_tail);
		_tail = node;
	}
	else {
		_head = node;
		_tail = node;
	}
	++_count;
}

void StringList::AddToHead(string data)
{
	StringNode *node = new StringNode(data);
	if (_count > 0) {		
		_head->SetPrev(node);
		node->SetNext(_head);
		_head = node;
	}
	else {
		_head = node;
		_tail = node;
	}
	++_count;
}

void StringList::RemoveFromTail()
{
	//if there are 0 elements, do nothing
	if (_count > 0) {
		//set up pointer to be cleaned up at end of scope
		StringNode *removed = _tail;
		if (_count > 1) {
			//set the current tail to the previous tail
			_tail = _tail->GetPrev();
			//next is no longer a valid addr, so make it null
			_tail->SetNext(nullptr);
		}
		//if there is only one item left,
		//the pointers are handled differently
		else {
			_tail = nullptr;
			_head = nullptr;
		};
		//not certain if I need to do this since the *removed pointer
		//goes out of scope at the end of if
		delete removed;
		--_count;
	}
}

void StringList::RemoveFromHead()
{
	if (_count > 0) {
		StringNode *removed = _head;
		if (_count > 1) {
			_head = _head->GetNext();
			_head->SetPrev(nullptr);
		}
		else {
			_head = nullptr;
			_tail = nullptr;
		}
		delete removed;
		--_count;
	}
}

string StringList::find(int index)
{
	if (index < _count && index >= 0) {
		StringNode *currIndex = _head;
		for (int i = 0; i < index; i++) {
			currIndex = currIndex->GetNext();
		}
		return currIndex->GetString();
	}
	return "Invalid Index (Must be non-negative and within bounds)";
}

bool StringList::find(string str)
{
	StringNode *currIndex = _head;
	bool found = false;
	do
	{
		found = currIndex->GetString() == str ? true : false;
		currIndex = currIndex->GetNext();
	} while (found == false && currIndex->GetNext() != nullptr);
	return found;
}

void StringList::insert(string str, int index)
{
	//if index is in bounds
	if (index <= _count && index >= 0) {
		//0 is beginning of LinkedList
		if (index == 0) {
			//So call AddToHead
			AddToHead(str);
		}
		//_count is end of LinkedList
		else if (index == _count) {
			//So call add to tail
			AddToTail(str);
		}
		//otherwise index is between other nodes
		else
		{
			StringNode *newNode = new StringNode(str);
			//start at beginning
			StringNode *currIndex = _head;
			//iterate until we reach specified index
			for (int i = 0; i < index; i++) {
				currIndex = currIndex->GetNext();
			}
			//re-wire next/prev pointers
			newNode->SetPrev(currIndex->GetPrev());
			newNode->GetPrev()->SetNext(newNode);
			newNode->SetNext(currIndex);
			currIndex->SetPrev(newNode);
			++_count;
		}
		
	}
}

void StringList::Enumerate()
{
	StringNode *currentNode = _head;
	if (_count > 0) {
		for (int i = 0; i < _count; i++) {
			cout << _count << "  Node " << i << ": " << currentNode->GetString() << endl;
			currentNode = currentNode->GetNext();
		}
	}
	else {
		cout << _count << " Linked List Items" << endl;

	}
}
