#pragma once
using std::string;
class StringNode
{
private:
	string _data;
	StringNode* _prev;
	StringNode* _next;
public:
	StringNode(const string& data) : _data(data) {};
	StringNode()= default;
	~StringNode();
	void SetPrev(StringNode *prev);
	StringNode* GetPrev();
	string GetString() { return _data; };

};

