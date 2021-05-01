#pragma once
#include <unordered_set>
#include <unordered_map>

using namespace std;


template<typename TKey, typename TValue>
//represents each node in the graph
class Vertex
{
private:
	TKey _identifier;
	TValue _data;
	//will contain the node's adjacent nodes
	unordered_map<TKey, Vertex*> _neighbors = unordered_map<TKey, Vertex*>{};

public:
	TKey Identifier { get {return _identifier; } }
	TValue Data{ get{return _data; } }

	Vertex(TKey id, TValue data) : _data(data), _identifier(id) {};

};


