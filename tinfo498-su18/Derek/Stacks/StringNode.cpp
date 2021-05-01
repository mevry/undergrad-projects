#include "stdafx.h"
#include "StringNode.h"
using std::string;




StringNode::~StringNode()
{
}

void StringNode::SetPrev(StringNode *prev)
{
	_prev = prev;
}

StringNode * StringNode::GetPrev()
{
	return _prev;
}


/*
- Must track base/top
- If base is null, no pop operation possible
- push will change top's pointer to new node
	-old top next will point to new top
	-new top prev will point to old top


- If next is null, then it is top



*/