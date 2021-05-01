#pragma once
#include "stdafx.h"
#include "Node.h"

template <typename T>
class LinkedList
{
private: 
	Node<T>* _head;
	Node<T>* _tail;
	int _count = 0;
	void initialize(T Data);
public:
	LinkedList()=default;
	LinkedList(T data);
	void addToHead(T data);
	void addToTail(T data);
	T removeFromHead();
	T removeFromTail();
	T find(int index);
	bool contains(T data);
	void insert(T data, int index);
	int Length() { return _count; };
	void enumerate();
};

template<typename T>
//used to create initial node
inline void LinkedList<T>::initialize(T data)
{
	_head = new Node<T>(data);
	_tail = _head;
	++_count;
}
template<typename T>
inline LinkedList<T>::LinkedList(T data)
{
	initialize(data);
}

template<typename T>
//i defined head to be *end* of LL
inline void LinkedList<T>::addToHead(T data)
{
	if (_count > 0) {
		Node<T> *node = new Node<T>(data);
		_head->setNext(node);
		node->setPrev(_head);
		_head = node;
		++_count;
	}
	else {
		initialize(data);
	}
	
}

template<typename T>
inline void LinkedList<T>::addToTail(T data)
{
	if (_count > 0) {
		Node<T> *node = new Node<T>(data);
		_tail->setPrev(node);
		node->setNext(_tail);
		_tail = node;
		++_count;
	}
	else {
		initialize(data);
	}
	
}

template<typename T>
inline T LinkedList<T>::removeFromHead()
{
	//Bounds checking, don't continue if empty
	if (_count <= 0) {
		throw std::out_of_range("Linked List is empty");
	}
	//Otherwise, safe to continue
	T temp = _head->Data();
	if (_count > 1) {	
		_head = _head->getPrev();
		_head->setNext(nullptr);
	}
	//One node left in list is handled differently
	else if (_count == 1) {
		_head = nullptr;
		_tail = nullptr;
	}
	--_count;
	return temp;
	
}

template<typename T>
inline T LinkedList<T>::removeFromTail()
{
	//Bounds checking, don't continue if empty
	if (_count <= 0) {
		throw std::out_of_range("Linked List is empty");
	}
	//Otherwise, safe to continue
	T temp = _tail->Data();
	if (_count > 1) {
		_tail = _tail->getNext();
		_tail->setPrev(nullptr);
	}
	//One node left in list is handled differently
	else if (_count == 1) {
		_head = nullptr;
		_tail = nullptr;
	}
	--_count;
	return temp;
}

template<typename T>
//pass in index, get data
inline T LinkedList<T>::find(int index)
{
	//bounds checking
	if (index < _count && index >= 0) {
		//set up current pointer
		Node<T> *current = _head;
		//iterate over pointer until arrive at index
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		return current->Data();
	}
	throw std::out_of_range("Index Out of Range");
}

template<typename T>
//pass in data, get bool
//i think passed type must have
//comparator operator overload (==)
inline bool LinkedList<T>::contains(T  data)
{
	Node<T>* current = _head;
	bool found = false;
	//iterate over list until data is found
	//or reach end of list
	do {
		found = current->Data == data ? true : false;
		current = current->getNext();
	} while (found == false && current->getNext() != nullptr);
	return found;
}

template<typename T>
//insert data at specific index
inline void LinkedList<T>::insert(T data, int index)
{
	//if index is in bounds
	if (index <= _count && index >= 0) {
		//0 is beginning of LinkedList
		if (index == 0) {
			//So call AddToHead
			addToHead(data);
		}
		//_count is end of LinkedList
		else if (index == _count) {
			//So call add to tail
			addToTail(data);
		}
		//otherwise index is between other nodes
		else
		{
			Node<T> *newNode = new Node<T>(data);
			//start at beginning
			Node<T> *currIndex = _head;
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
	throw std::out_of_range("Index is out of range");
}

template<typename T>
inline void LinkedList<T>::enumerate()
{
	cout << "TOTAL NODES: " << _count << endl;
	if (_count > 0) {
		Node<T>* current = _tail;
		for (int i = 0; i < _count; i++) {
			std::cout << "Node " << i << ": " << current->Data() << std::endl;
			current = current->getNext();
		}
	}
	else {
		std::cout << "No Nodes in LinkedList." << std::endl;
	}
}


