using System;
using System.Collections.Generic;
using System.Text;

namespace DijkstraCSharp
{
    public class AdjacencyList2<T> : IGraph<T>
    {
        private bool _directed;
        private Dictionary<int, ValueTuple<Vertex<T>,Dictionary<Vertex<T>,float>>> _adjDict = new Dictionary<int, ValueTuple<Vertex<T>, Dictionary<Vertex<T>,float>>>();
        public AdjacencyList2(List<Vertex<T>> vertices, bool directed = false)
        {
            _directed = directed;
            int index = 0;
            //create lookup dictionary based in vertex ID
            foreach(var vertex in vertices)
            {
                //assign index to vertex
                vertex.Index = index;
                //create adjacency dictionary with infinite (invalid) edge weight
                _adjDict.Add(index, (vertex, new Dictionary<Vertex<T>,float>()));//(vertex, -1));
                ++index;
            }
        }

        public void AddEdge(int vertex1, int vertex2, float weight = 1)
        {
            _adjDict[vertex1].Item2.Add(GetVertex(vertex2), weight);
            if (!_directed)
            {
                _adjDict[vertex2].Item2.Add(GetVertex(vertex1), weight);
            }
        }

        public void AddEdge(Vertex<T> vertex1, Vertex<T> vertex2, float weight = 1)
        {
            _adjDict[vertex1.Index].Item2.Add(vertex2, weight);
            if (!_directed)
            {
                _adjDict[vertex2.Index].Item2.Add(vertex1, weight);
            }
        }

        public List<Vertex<T>> GetAdjacent(int vertexId)
        {
            var adjList = new List<Vertex<T>>();
            
            foreach(var vertex in _adjDict[vertexId].Item2)
            {
                adjList.Add(vertex.Key);
            }

            return adjList;
        }

        public List<Vertex<T>> GetAdjacent(Vertex<T> vertex)
        {
            var adjList = new List<Vertex<T>>();
            foreach(var key in _adjDict[vertex.Index].Item2.Keys)
            {
                adjList.Add(key);
            }
            return adjList;
        }

        public float GetEdgeWeight(int vertex1, int vertex2)
        {
            return _adjDict[vertex1].Item2[GetVertex(vertex2)];
        }

        public float GetEdgeWeight(Vertex<T> vertex1, Vertex<T> vertex2)
        {
            return _adjDict[vertex1.Index].Item2[vertex2];
        }

        //public int GetIndegree(int vertexId)
        //{
        //    throw new NotImplementedException();
        //}

        //public int GetIndegree(Vertex<T> vertex)
        //{
        //    throw new NotImplementedException();
        //}

        public Vertex<T> GetVertex(int vertexId)
        {
            return _adjDict[vertexId].Item1;
        }

        public int GetVertexId(T uniqueData)
        {
            int vertexId = -1;
            foreach(var element in _adjDict)
            {
                if (element.Value.Item1.Data.ToString() == uniqueData.ToString())
                {
                    vertexId = element.Key;
                    break;
                }
            }
            return vertexId;
        }

        public void Print()
        {
            throw new NotImplementedException();
        }

        public int VertexCount()
        {
            return _adjDict.Count;
        }
    }
}
