using System;
using System.Collections.Generic;
using System.Text;

namespace DijkstraCSharp
{
    //This is the matrix that represents the relationship between nodes.
    //This version uses 2-dimensional array
    public class FloatAdjacencyMatrix<T> : IGraph<T>// where T : Vertex<T>
    {
        //data structure to hold vertices
        private List<Vertex<T>> _vertices;
        public List<Vertex<T>> Vertices { get { return _vertices; } }

        //Is this directed?
        private bool _directed;
        private int _size;

        private readonly float[,] _matrix;

        public FloatAdjacencyMatrix(List<Vertex<T>> vertices, bool directed = false)
        {
            _vertices = vertices;
            _size = vertices.Count;
            //create matrix based on size of list of vertices
            _matrix = new float[_size,_size];
            //for each vertex, set index to corresponding index in matrix
            for(int i = 0; i < _size; i++)
            {
                _vertices[i].Index = i;
            }
            _directed = directed;
        }

        //two way relationship between nodes
        public void AddEdge(int vertex1, int vertex2, float weight = 1)
        {
            var v1 = vertex1;
            var v2 = vertex2;
            _matrix[v1, v2] = weight;
            if (!_directed)
            {
                _matrix[v2, v1] = weight;
            }
        }

        public void AddEdge(Vertex<T> vertex1, Vertex<T> vertex2, float weight = 1)
        {
            AddEdge(vertex1.Index, vertex2.Index, weight);
        }

        //GetEdgeWeight()
        public float GetEdgeWeight(int v1, int v2)
        {
            //sanity check 
            if(v1 >= _size || v2 >= _size || v1 < 0 || v2 < 0)
            {
                throw new System.ArgumentException("Vertex index out of bounds: cannot be < 0 or >= size of matrix");
            }
            return _matrix[v1,v2];
        }
        public float GetEdgeWeight(Vertex<T> vertex1, Vertex<T> vertex2)
        {
            return GetEdgeWeight(vertex1.Index, vertex2.Index);
        }

        //GetAdjacencyList()
        public List<Vertex<T>> GetAdjacent(int v)
        {
            //initialize list to hold adjacent vertices
            var adjList = new List<Vertex<T>>();
            //iterate over every index i on row v
            for (int i = 0; i < _size; i++)
            {
                //if not 0, then there is an adjacent
                if (_matrix[v, i] != 0)
                {
                    //find the associated whose index is equal to i
                    //and add it to the list of adjacent vertices
                    adjList.Add(_vertices.Find(vertex => vertex.Index == i));
                }        
            }    
            return adjList;
        }
        //wrapper for GetAdjacent(int v) in case I need to pass the vertex ref
        public List<Vertex<T>> GetAdjacent(Vertex<T> vertex)
        {
            return GetAdjacent(vertex.Index);
        }

        public int GetIndegree(int vertexId)
        {
            int indegree = 0;
            //iterate over each row i at vertex v
            for(int i = 0; i < _size; i++)
            {
                //if there is an edge flowing in to v
                //(that is, if it is adjacent to another node)
                if(_matrix[i, vertexId] != 0)
                {
                    //then increment the indegree counter
                    ++indegree;
                }
            }
            return indegree;
        }

        public int GetIndegree(Vertex<T> vertex)
        {
            return GetIndegree(vertex.Index);
        }

        public int VertexCount()
        {
            return _size;
        }

        public void Print()
        {
            Console.WriteLine("Not Implemented");
        }

        public Vertex<T> GetVertex(int vertexId)
        {
            return _vertices.Find(v => v.Index == vertexId);
        }

        public int GetVertexId(T uniqueData)
        {

            return _vertices.Find(v => v.Data.ToString() == uniqueData.ToString()).Index;

        }
    }
}
