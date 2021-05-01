using System;
using System.Collections.Generic;
using System.Text;

namespace DijkstraCSharp
{
    public class AdjacencyList<T> : IGraph<T>
    {
        private bool _directed;
        private Dictionary<int, Vertex<T>> _adjDict = new Dictionary<int, Vertex<T>>();
        public AdjacencyList(List<Vertex<T>> vertices, bool directed = false)
        {
            _directed = directed;
            int index = 0;
            //create lookup dictionary based in vertex ID
            foreach(var vertex in vertices)
            {
                //assign index to vertex
                vertex.Index = index;
                //create adjacency dictionary with infinite (invalid) edge weight
                _adjDict.Add(index, vertex);//(vertex, -1));
                ++index;
            }
        }

        public void AddEdge(int vertex1, int vertex2, float weight = 1)
        {
            _adjDict[vertex1].Neighbors.Add(_adjDict[vertex2], weight);
            if (!_directed)
            {
                _adjDict[vertex2].Neighbors.Add(_adjDict[vertex1], weight);
            }
        }

        public void AddEdge(Vertex<T> vertex1, Vertex<T> vertex2, float weight = 1)
        {
            _adjDict[vertex1.Index].Neighbors.Add(vertex2, weight);
            if (!_directed)
            {
                _adjDict[vertex2.Index].Neighbors.Add(vertex1, weight);
            }
        }

        public List<Vertex<T>> GetAdjacent(int vertexId)
        {
            var adjList = new List<Vertex<T>>();
            
            foreach(var vertex in _adjDict[vertexId].Neighbors)
            {
                adjList.Add(vertex.Key);
            }

            return adjList;
        }

        public List<Vertex<T>> GetAdjacent(Vertex<T> vertex)
        {
            var adjList = new List<Vertex<T>>();
            foreach(var v in vertex.Neighbors)
            {
                adjList.Add(v.Key);
            }
            return adjList;
        }

        public float GetEdgeWeight(int vertex1, int vertex2)
        {
            return GetEdgeWeight(_adjDict[vertex1],_adjDict[vertex2]);
        }

        public float GetEdgeWeight(Vertex<T> vertex1, Vertex<T> vertex2)
        {
            return vertex1.Neighbors[vertex2];
        }

        public Vertex<T> GetVertex(int vertexId)
        {
            return _adjDict[vertexId];
        }

        public int GetVertexId(T uniqueData)
        {
            int vertexId = -1;
            foreach(var element in _adjDict)
            {
                if (element.Value.Data.ToString() == uniqueData.ToString())
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
