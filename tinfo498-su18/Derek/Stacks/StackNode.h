#pragma once

template<typename T>
class StackNode
{
private:
	T* _data;
	StackNode<T> *_prev;
public:
	StackNode(T* data): _data(data) {};

	void SetPrev(StackNode<T> *prev) { _prev = prev; };

	StackNode<T> *GetPrev() { return _prev; };

	T* GetData() { return _data; };

};


