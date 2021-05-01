#pragma once
using std::string;

class StringNode
{
private:
	string _data;
	//head (where items are dequeued)
	StringNode *_next;
	//tail (where items are enqueued)
	StringNode *_prev;
public:
	StringNode(string data): _data(data) {};
	~StringNode();
	StringNode *GetPrev();
	void SetPrev(StringNode *node);
	string GetData();
	
};

