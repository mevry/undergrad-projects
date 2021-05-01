#include "stdafx.h"
#include "StringQueue.h"


StringQueue::StringQueue()
{
	//_tail = _head;
}


StringQueue::~StringQueue()
{
}

void StringQueue::enqueue(string data)
{
	//create new pointer
	StringNode *sn = new StringNode(data);
	//if elements already exist,
	if (_count > 0) {
		//point the existing tail to what will be the new tail
		_tail->SetPrev(sn);
		//set the new pointer as the tail
		_tail = sn;
	}
	//otherwise head and tail must point to something
	else
	{
		//point head to new pointer
		_head = sn;
		//head and tail are same since there is only 1 element
		_tail = _head;
	}
	++_count;
}

string StringQueue::dequeue()
{
	if (_count > 0) {
		StringNode *dequeued = _head;
		_head = _head->GetPrev();
		--_count;
		std::cout << "Dequeued: " << dequeued->GetData() << std::endl;
		return dequeued->GetData();
	}
	return "END OF QUEUE";
}
