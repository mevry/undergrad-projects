#pragma once
#include "stdafx.h"
#include "QueueNode.h"

template<typename T>
class Queue
{
private:
	QueueNode<T>* _head;
	QueueNode<T>* _tail;
	int _count;
public:
	Queue() = default;
	Queue(T data);

	void enqueue(T data);
	T dequeue();

	void Enumerate();
};

template<typename T>
inline Queue<T>::Queue(T data)
{
	//construct new node, point head & tail to it
	_head = new QueueNode<T>(data);
	//_tail = _head;
	++_count;
}

template<typename T>
inline void Queue<T>::enqueue(T data)
{
	//create new node
	QueueNode<T> *newNode = new QueueNode<T>(data);
	//if existing nodes exist,
	//add to tail
	if (_count > 0) {		
		_tail->SetPrev(newNode);
		_tail = newNode;
	}
	//otherwise, head/tail are same
	else {
		_head = newNode;
		_tail = _head;
	}
	++_count;
}

template<typename T>
inline T Queue<T>::dequeue()
{
	if (_count > 0) {
		T data = _head->GetData();
		auto oldHead = _head;
		//set head to previous
		_head = _head->GetPrev();
		--_count;
		//delete old head
		delete oldHead;
		return data;
	}
	throw std::out_of_range("Empty Queue");
}

template<typename T>
inline void Queue<T>::Enumerate()
{
	QueueNode<T> *curr = _head;
	for (int i = 0; i < _count; i++) {
		std::cout << curr->GetData() << std::endl;
		curr = curr->GetPrev();
	}
}


