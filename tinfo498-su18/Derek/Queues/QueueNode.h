#pragma once

template <typename T>
class QueueNode
{
private:
	T _data;
	QueueNode<T>* _prev;
public:
	QueueNode(T data) : _data(data) {};

	QueueNode<T>* GetPrev() { return _prev; };

	void SetPrev(QueueNode<T>* node) { _prev = node; };

	T GetData() { return _data; };
};

