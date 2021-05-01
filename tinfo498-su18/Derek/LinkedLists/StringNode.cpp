#include "stdafx.h"
#include "StringNode.h"





StringNode::~StringNode()
{
}

void StringNode::SetPrev(StringNode * prev)
{
	_prev = prev;
}

void StringNode::SetNext(StringNode * next)
{
	_next = next;
}

StringNode* StringNode::GetNext()
{
	return _next;
}

StringNode * StringNode::GetPrev()
{
	return _prev;
}
