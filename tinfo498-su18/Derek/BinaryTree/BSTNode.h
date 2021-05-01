#pragma once

template <typename T>
class BSTNode
{
private:
	T _data;
	BSTNode<T>* _parent;
	BSTNode<T>* _left;
	BSTNode<T>* _right;
public:
	BSTNode<T>(T data) : _data(data) {};
	T Data() { return _data; };
	BSTNode<T>* Right() { return _right; };
	void Right(BSTNode<T>* pointer) {
		_right = pointer;
	}
	BSTNode<T>* Left() { return _left; };
	void Left(BSTNode<T>* pointer) {
		_left = pointer;
	};

	BSTNode<T>* Parent() { return _parent; };
	void Parent(BSTNode<T>* parent) { _parent = parent; };
};

