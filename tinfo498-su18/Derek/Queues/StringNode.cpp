#include "stdafx.h"
#include "StringNode.h"



StringNode::~StringNode()
{
}

StringNode * StringNode::GetPrev()
{
	return _prev;
}

void StringNode::SetPrev(StringNode * node)
{
	_prev = node;
}

string StringNode::GetData()
{
	return _data;
}
