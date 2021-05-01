#pragma once
#include "StackNode.h"

template <typename T>
class Stack
{
private:
	StackNode<T>* _top;
	int _count;
public:
	Stack() = default;
	Stack(T* base);
	
	void push(T* topNode);
	T *pop();
	void enumerate();
};

template<typename T>
inline Stack<T>::Stack(T * base)
{
	_top = new StackNode<T>(base);
	++_count;
}

template<typename T>
inline void Stack<T>::push(T* topNode)
{
	StackNode<T> *newNode = new StackNode<T>(topNode);
	newNode->SetPrev(_top);
	_top = newNode;
	++_count;
}
template<typename T>
inline T* Stack<T>::pop()
{
	if (_count > 0) {
		T *data = _top->GetData();
		auto oldTop = _top;
		_top = _top->GetPrev();
		--_count;
		delete oldTop;
		return data;
	}
	throw std::out_of_range("Stack is empty");
}

template<typename T>
inline void Stack<T>::enumerate()
{
	if (_count > 0) {
		StackNode<T> *current = _top;
		for (int i = _count-1; i >= 0; i--) {
			std::cout << "Item " << i << ": " << *current->GetData() << std::endl;

			//for printing booleans
			std::cout << std::boolalpha;
			current = current->GetPrev();
		}
	}
}
