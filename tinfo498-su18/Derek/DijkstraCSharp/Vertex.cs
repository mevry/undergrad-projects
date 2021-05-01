using System;
using System.Collections.Generic;
using System.Text;

namespace DijkstraCSharp
{
    public class Vertex<T> 
    {
        //this is the data to be stored
        private T _data;
        public T Data { get { return _data; } }

        //public Dictionary<int, ValueTuple<Vertex<T>, float>> Adjacent { get; set; }
        public Dictionary<Vertex<T>, float> Neighbors { get; set; } = new Dictionary<Vertex<T>, float>();
        //this is how we look up a vertex in a matrix
        //it is assigned at
        public int Index { get; set; }
        
        public Vertex(T data)
        {
            _data = data;
            //initialize to invalid value
            Index = -1;
        }
    }
}
