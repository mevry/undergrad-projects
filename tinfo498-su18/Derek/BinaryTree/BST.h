#pragma once
#include "stdafx.h"
#include "BSTNode.h"


template <typename T>
class BST
{
private:
	BSTNode<T>* _root;
	int enumCount = 0;

	void insert(T data, BSTNode<T> *node);
	bool remove(T Data, BSTNode<T> *node);
	void enumerate(BSTNode<T>* node);
	bool contains(T data, BSTNode<T> *node);
public:
	BST<T>()=default;
	BST<T>(T data);

	void insert(T data);	
	bool remove(T data);
	void enumerate();
	bool contains(T data);
};

template<typename T>
inline BST<T>::BST(T data)
{
	_root = new BSTNode<T>(data);
}

//this one is publicly called (starts at _root node)
template<typename T>
inline void BST<T>::insert(T data)
{
	//if the tree is empty, set node as root
	if (_root == nullptr) {
		_root= new BSTNode<T>(data);
	}
	//otherwise find the location that it
	//should be added to
	else {
		insert(data, _root);
	}
}

template<typename T>
inline void BST<T>::insert(T data, BSTNode<T> *node)
{
	//if data is smaller than current node...
	if (data < node->Data())
	{
		//and the left is null,
		//create new node at left and set parent
		if (node->Left() == nullptr) {
			node->Left(new BSTNode<T>(data));
			node->Left()->Parent(node);
		}
		//otherwise traverse left one node
		else {
			insert(data, node->Left());
		}
	}
	//if the data is >= current node
	else {
		//and the right is null
		//create new node at right and set parent
		if (node->Right() == nullptr) {
			node->Right(new BSTNode<T>(data));
			node->Right()->Parent(node);
		}
		//otherwise traverse right
		else {
			insert(data, node->Right());
		}
	}
}

template<typename T>
inline bool BST<T>::remove(T data)
{
	if (_root == nullptr) {
		throw std::out_of_range("BST is empty");
	}
	else {
		return remove(data, _root);
	}
}
template<typename T>
inline bool BST<T>::remove(T data, BSTNode<T>* node)
{
	//traverse tree to find desired node
	BSTNode<T> *currentNode = node;
	//while we dont have a match AND we don't run into null
	while (data != currentNode->Data()) {
		//if data is less, move to the left
		if (data < currentNode->Data()) {
			currentNode = currentNode->Left();
		}
		//if data is greater than, move to the right
		else {
			currentNode = currentNode->Right();
		}
		//must be null, therefore not in the tree
		if (currentNode == nullptr) {
			return false;
		}
	}
	//If we made it this far, we have found a match
	
	//It will be useful to know whether the match's parent
	//is pointing to it via LEFT or RIGHT branch
	bool isLeft = currentNode->Parent()->Left() == currentNode ? true : false;
	
	//if the current node is a left branch, then it's parent's left
	//branch will need to be rewired
	if (isLeft) {
		//SCENARIO 1: node w/no right child
		//Must promote current node's left child (even if null)
		if (currentNode->Right() == nullptr) {
			//point current's parent to current's left
			currentNode->Parent()->Left(currentNode->Left());
			//point current's left to parent
			if (currentNode->Left()) {
				currentNode->Left()->Parent(currentNode->Parent());
			}
			//everything rewired, get rid of current
			delete currentNode;
		}
		//SCENARIO 2: node w/right child w/no left child
		//Must promote the right child
		else if (currentNode->Right()->Left() == nullptr) {
			currentNode->Right()->Left(currentNode->Left());
			currentNode->Right()->Parent(currentNode->Parent());
			currentNode->Parent()->Left(currentNode->Right());
			currentNode->Left()->Parent(currentNode->Right());
			delete currentNode;
		}
		//SCENARIO 3: node w/right child w/left child
		//Must promote the right child's left-most child
		else {
			//Get first left grandchild
			BSTNode<T> *leftmostGrandChild = currentNode->Right()->Left();
			//traverse down to leftmost grandchild
			while (leftmostGrandChild->Left() != nullptr) {
				leftmostGrandChild = leftmostGrandChild->Left();
			}
			//rewire pointers
			//start with null the old parent's left pointer
			leftmostGrandChild->Parent()->Left(nullptr);
			leftmostGrandChild->Left(currentNode->Left());
			leftmostGrandChild->Right(currentNode->Right());
			leftmostGrandChild->Parent(currentNode->Parent());
			currentNode->Parent()->Left(leftmostGrandChild);
			//this was causing a bug - if there is a left child of current,
			//then point it's parent to the new parent:
			if (currentNode->Left() != nullptr) {
				currentNode->Left()->Parent(leftmostGrandChild);
			}
			delete currentNode;
		}
	}
	//if the current node is a right branch, then it's parent's right
	//branch will need to be rewired
	else {
		if (currentNode->Right() == nullptr) {
			currentNode->Parent()->Right(currentNode->Left());
			if (currentNode->Left()) {
				currentNode->Left()->Parent(currentNode->Parent());
			}
			delete currentNode;
		}
		else if (currentNode->Right()->Left() == nullptr) {
			currentNode->Right()->Left(currentNode->Left());
			currentNode->Right()->Parent(currentNode->Parent());
			currentNode->Parent()->Right(currentNode->Right());
			currentNode->Left()->Parent(currentNode->Right());
			delete currentNode;
		}
		else {
			BSTNode<T> *leftmostGrandChild = currentNode->Right()->Left();
			while (leftmostGrandChild->Left() != nullptr) {
				leftmostGrandChild = leftmostGrandChild->Left();
			}
			leftmostGrandChild->Parent()->Left(nullptr);
			leftmostGrandChild->Left(currentNode->Left());
			leftmostGrandChild->Right(currentNode->Right());
			leftmostGrandChild->Parent(currentNode->Parent());
			currentNode->Parent()->Right(leftmostGrandChild);
			if (currentNode->Left() != nullptr) {
				currentNode->Left()->Parent(leftmostGrandChild);
			}
			delete currentNode;
		}
	}
	return true;
}

template<typename T>
inline void BST<T>::enumerate()
{
	std::cout << "====================" << std::endl;
	enumCount = 0;
	enumerate(_root);
	std::cout << "====================" << std::endl;
}

template<typename T>
inline void BST<T>::enumerate(BSTNode<T>* node)
{
	if (node == nullptr) {
		return;
	}
	enumerate(node->Left());
	std::cout << "Node " << enumCount << ": " << node->Data() << std::endl;
	++enumCount;
	enumerate(node->Right());	
}

template<typename T>
inline bool BST<T>::contains(T data, BSTNode<T> *node) {
	BSTNode<T> *currentNode = node;
	//while we dont have a match AND we don't run into null
	while (data != currentNode->Data()) {
		//if data is less, move to the left
		if (data < currentNode->Data()) {
			currentNode = currentNode->Left();
		}
		//if data is greater than, move to the right
		else {
			currentNode = currentNode->Right();
		}
		//must be null, therefore not in the tree
		if(currentNode == nullptr) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool BST<T>::contains(T data)
{
	return contains(data, _root);
}