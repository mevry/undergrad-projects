using System;
using System.Collections.Generic;
using System.Text;

namespace DijkstraCSharp
{
    public interface IGraph<T>// where T : Vertex<T>
    {

        //represent relationship between 2 vertices
        //default weight 1 (for unweighted graphs)
        void AddEdge(int vertex1, int vertex2, float weight = 1);
        void AddEdge(Vertex<T> vertex1, Vertex<T> vertex2, float weight = 1);

        Vertex<T> GetVertex(int vertexId);


        int GetVertexId(T uniqueData);
        
        //all of the nodes that are adjacent to a particular node
        List<Vertex<T>> GetAdjacent(int vertexId);
        List<Vertex<T>> GetAdjacent(Vertex<T> vertex);

        //retrieve the weight of an edge between two vertices
        float GetEdgeWeight(int vertex1, int vertex2);
        float GetEdgeWeight(Vertex<T> vertex1, Vertex<T> vertex2);

        //count
        int VertexCount();
        //display it
        void Print();



    }
}
