#pragma once
#include "stdafx.h"
#include <unordered_map>
#include <tuple>
#include <vector>

using namespace std;
template<typename TKey, typename TValue>
class Graph
{
private:
	bool _directed;
	unordered_map<TKey, tuple<Vertex<TKey,TValue>*, float>> _graph = new unordered_map<TKey, tuple<Vertex<TKey,TValue>*,float>>();

public:
	Graph<TKey>(vector<Vertex<TKey,TValue>*> vertices, bool directed);

};

template<typename TId>
inline Graph<TKey>::Graph(vector<Vertex<TKey,TValue>*> vertices, bool directed)
{
	_g
}
