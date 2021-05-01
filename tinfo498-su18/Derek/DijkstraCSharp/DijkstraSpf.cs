using System;
using System.Collections.Generic;
using System.Text;
using PriorityQueue = Priority_Queue.SimplePriorityQueue<int>;

namespace DijkstraCSharp
{
    public class DijkstraSpf<T> //where T : Vertex<T>
    {
        //Dictionary<VertexID, ValueTuple<Distance, Preceding Node>>
        private Dictionary<int, ValueTuple<float, int>> _distanceTable;// = new Dictionary<int, (float, int)>();
        private PriorityQueue _queue;// = new PriorityQueue();
        
        public DijkstraSpf()
        {
            
        }

        public void BuildDistanceTable(IGraph<T> graph, int sourceId, bool dijkstra = true)
        {
            _distanceTable = new Dictionary<int, (float, int)>();
            _queue = new PriorityQueue();
            var sourceIndex = sourceId;

            //for every vertex in graph, set the distance to infinity
            //and initialize the preceding node to -1 

            for (int i = 0; i < graph.VertexCount(); i++)
            {
                _distanceTable[i] = (-1, -1);
            }
            //Set source node distance to 0 and previous node to itself
            _distanceTable[sourceIndex] = (0, sourceIndex);
            //add source node to priority queue
            _queue.Enqueue(sourceIndex, 0);

            //while there are nodes to be processed,
            while (_queue.Count > 0)
            {
                //dequeue next item for processing
                var currentId = _queue.Dequeue();
                // retrieve the vertex's distance from the distance table
                var currentDistance = _distanceTable[currentId].Item1;
                //iterate over that vertex's adjacent nodes and
                foreach (var adjacent in graph.GetAdjacent(currentId))
                {
                    // add the edge weight of each to the current distance
                    var newDistance = currentDistance + graph.GetEdgeWeight(currentId, adjacent.Index);
                    // retrieve the last known distance of this adjacent node
                    // to the source node (will be infinity if unvisited)
                    var currAdjacentDistance = _distanceTable[adjacent.Index].Item1;

                    //check if the neighbor is unvisited or the current path's distance is less than the recorded distance
                    if (currAdjacentDistance == -1 || newDistance < currAdjacentDistance)
                    {
                        //update the distance table with new distance and preceding node
                        _distanceTable[adjacent.Index] = (newDistance, currentId);

                        //add the neighbor to the queue for later processing
                        _queue.Enqueue(adjacent.Index, newDistance);
                    }


                }

            }
        }
        public void PrintDistanceTable()
        {
            foreach(var row in _distanceTable)
            {
                Console.WriteLine($"Node: {row.Key}  Distance: {row.Value.Item1}  Previous: {row.Value.Item2}");
            }
        }
        public void PrintShortestPath(IGraph<T> graph, T sourceId, T destinationId)
        {
            PrintShortestPath(graph, graph.GetVertexId(sourceId), graph.GetVertexId(destinationId));
        }
        public void PrintShortestPath(IGraph<T> graph, int sourceId, int destinationId)
        {
            //Use stack to hold the path
            var shortestPath = new Stack<int>();            
            //Add destination to stack
            shortestPath.Push(destinationId);
            //Access previous vertex (from destination)
            var previousVertex = _distanceTable[destinationId].Item2;
            //iterate through the previous vertices in the distance table until previous is none or previous is the source
            while(previousVertex != sourceId && previousVertex != -1)
            {
                shortestPath.Push(previousVertex);
                previousVertex = _distanceTable[previousVertex].Item2;
            }
            //add one last vertex to the stack (should be source if path exists)
            if(previousVertex == sourceId)
            {
                shortestPath.Push(previousVertex);
            }
            //Print out path (if one exists)
            if (previousVertex == -1)
            {
                Console.WriteLine("No path exists to destination");
            }
            else
            {
                string spfHeader = $"\nShortest Path from {graph.GetVertex(sourceId).Data} -> {graph.GetVertex(destinationId).Data}";
                Console.WriteLine(spfHeader);
                foreach(char c in spfHeader)
                {
                    Console.Write("-");
                }
                Console.WriteLine();
                while (shortestPath.Count > 0)
                {
                    if (shortestPath.Count > 1)
                        Console.Write($"{graph.GetVertex(shortestPath.Pop()).Data} -> ");
                    else
                        Console.WriteLine($"{graph.GetVertex(shortestPath.Pop()).Data}");
                    
                }
                Console.WriteLine();
            }

        }

        
    }
}




//SHORTEST PATH
//requires the graph, source, destination
//set up distance table

