#pragma once

template <typename T>
class Node
{
private:
	T _data;
	Node<T>* _prev;
	Node<T>* _next;
public:
	Node(T data) : _data(data) {};

	void setNext(Node<T>* node) {
		_next = node;
	};
	void setPrev(Node<T>* node) { _prev = node; };

	Node<T>* getPrev() { return _prev; };
	Node<T>* getNext() { return _next; };

	T Data() { return _data; };
};

