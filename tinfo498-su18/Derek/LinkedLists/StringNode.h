#pragma once
using std::string;
class StringNode
{
private:
	string _data;
	StringNode* _prev;
	StringNode* _next;

public:
	StringNode(string data) : _data(data) {};
	StringNode() = default;
	~StringNode();

	void SetPrev(StringNode *prev);
	void SetNext(StringNode *next);

	StringNode* GetNext();
	StringNode* GetPrev();

	string GetString() { return _data; };
	
	

};

