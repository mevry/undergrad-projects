using System;
using System.Collections.Generic;
using System.Diagnostics;
namespace DijkstraCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
           
            DijkstraSpf<string> dijkstra = new DijkstraSpf<string>();

            //create vertices
            var vertices = new List<Vertex<string>>() {
                    new Vertex<string>("Router1"),
                    new Vertex<string>("Router2"),
                    new Vertex<string>("Router3"),
                    new Vertex<string>("Router4"),
                    new Vertex<string>("Router5")
                };
            //create adjacency matrix from vertices
            var routerGraph = new AdjacencyList<string>(vertices, true);

            //add all the edges
            var routerEdges = new List<(int, int, int)>
            {
                (0,1,9),
                (0,4,5),
                (1,2,12),
                (2,0,3),
                (2,1,12),
                (2,3,2),
                (4,0,5),
                (4,1,1)
            };
            buildGraph(routerGraph, routerEdges);


            //create the distance table

            Console.WriteLine("Router Distance Table");
            Console.WriteLine("---------------------");
            dijkstra.BuildDistanceTable(routerGraph, 0);
            dijkstra.PrintDistanceTable();
            dijkstra.PrintShortestPath(routerGraph, 0, 3);

            var cities = new List<Vertex<string>>() {
                       new Vertex<string>("King's Landing"),
                       new Vertex<string>("Casterly Rock"),
                       new Vertex<string>("Winterfell"),
                       new Vertex<string>("Whiterun"),
                       new Vertex<string>("Riften"),
                       new Vertex<string>("Citadel"),
                       new Vertex<string>("Arcturus Station"),
                       new Vertex<string>("Tacoma")
            };

            var cityEdges = new List<(int, int, int)>()
            {
                (0,1,4),
                (0, 7, 29),
                (1,2,1),
                (1,4,5),
                (1,5,3),
                (2,3,2),
                (3,4,5),
                (4,6,1),
                (6,7,1)
            };


            //ADJACENCY MATRIX (2D Float Array)
            TimeSpan adjMatrixBuildTime;
            TimeSpan adjMatrixPrintTime;

            var dijkstraAdjMatr = new DijkstraSpf<string>();
            var floatAdjacencyMatrix = new FloatAdjacencyMatrix<string>(cities);
            buildGraph(floatAdjacencyMatrix, cityEdges);

            Console.WriteLine("Cities Distance Table");
            Console.WriteLine("---------------------");

            stopwatch.Restart();
                dijkstraAdjMatr.BuildDistanceTable(floatAdjacencyMatrix, 0);
            stopwatch.Stop();
            adjMatrixBuildTime = stopwatch.Elapsed;

            dijkstraAdjMatr.PrintDistanceTable();

            stopwatch.Restart();
                dijkstraAdjMatr.PrintShortestPath(floatAdjacencyMatrix, "King's Landing", "Tacoma");
            stopwatch.Stop();
            adjMatrixPrintTime = stopwatch.Elapsed;

            

            //ADJACENCY MATRIX (2D Float Array w/DICTIONARY)
            TimeSpan adjMatrixDictBuild;
            TimeSpan adjMatrixDictPrint;

            var dijkstraAdjMatrDict = new DijkstraSpf<string>();
            var floatAdjMatrDict = new FloatAdjMatrDict<string>(cities);
            buildGraph(floatAdjMatrDict, cityEdges);

            Console.WriteLine("Cities Distance Table");
            Console.WriteLine("---------------------");

            stopwatch.Restart();
                dijkstraAdjMatrDict.BuildDistanceTable(floatAdjMatrDict, 0);
            stopwatch.Stop();
            adjMatrixDictBuild = stopwatch.Elapsed;

            dijkstraAdjMatrDict.PrintDistanceTable();

            stopwatch.Restart();
                dijkstraAdjMatrDict.PrintShortestPath(floatAdjMatrDict, "King's Landing", "Tacoma");
            stopwatch.Stop();
            adjMatrixDictPrint = stopwatch.Elapsed;

            

            //ADJACENCY LIST (Dictionary)
            TimeSpan adjDictBuild;
            TimeSpan adjDictPrint;

            var dijkstraAdjList = new DijkstraSpf<string>();
            var adjList = new AdjacencyList<string>(cities);
            buildGraph(adjList, cityEdges);

            Console.WriteLine("Cities Distance Table");
            Console.WriteLine("---------------------");

            stopwatch.Restart();
                dijkstraAdjList.BuildDistanceTable(adjList, 0);
            stopwatch.Stop();
            adjDictBuild = stopwatch.Elapsed;

            dijkstraAdjList.PrintDistanceTable();

            stopwatch.Restart();
                dijkstraAdjList.PrintShortestPath(adjList, "King's Landing", "Tacoma");
            stopwatch.Stop();
            adjDictPrint = stopwatch.Elapsed;

            

            //ADJACENCY LIST (Version 2)
            TimeSpan adjDict2Build;
            TimeSpan adjDict2Print;

            var dijkstraAdjList2 = new DijkstraSpf<string>();
            var adjList2 = new AdjacencyList2<string>(cities);
            buildGraph(adjList2, cityEdges);

            stopwatch.Restart();
                dijkstraAdjList2.BuildDistanceTable(adjList2, 0);
            stopwatch.Stop();
            adjDict2Build = stopwatch.Elapsed;

            dijkstraAdjList2.PrintDistanceTable();

            stopwatch.Restart();
                dijkstraAdjList2.PrintShortestPath(adjList2, "King's Landing", "Tacoma");
            stopwatch.Stop();
            adjDict2Print = stopwatch.Elapsed;

            

            

            Console.WriteLine($"GRAPH TYPE\t\t\tBUILD DT\tPRINT SPF\tTOTAL");
            Console.WriteLine($"Adjacency Matrix\t\t{formatTimespan(adjMatrixBuildTime)}\t{formatTimespan(adjMatrixPrintTime)}\t{formatTimespan(adjMatrixBuildTime + adjMatrixPrintTime)}");
            Console.WriteLine($"Adjacency Matrix w/Dict:\t{formatTimespan(adjMatrixDictBuild)}\t{formatTimespan(adjMatrixDictPrint)}\t{formatTimespan(adjMatrixDictBuild + adjMatrixDictPrint)}");
            Console.WriteLine($"Adjacency List:\t\t\t{formatTimespan(adjDictBuild)}\t{formatTimespan(adjDictPrint)}\t{formatTimespan(adjDictBuild + adjDictPrint)}");
            Console.WriteLine($"Ajacency List 2:\t\t{formatTimespan(adjDict2Build)}\t{formatTimespan(adjDict2Print)}\t{formatTimespan(adjDict2Build + adjDict2Print)}");
            
            Console.WriteLine("\nExited Successfully");
        }

        public static void buildGraph(IGraph<string> graph, List<ValueTuple<int,int,int>> edges)
        {
            foreach(var edge in edges)
            {
                graph.AddEdge(edge.Item1, edge.Item2, edge.Item3);
            }
        }

        public static string formatTimespan(TimeSpan time)
        {
            string newTime = time.ToString("ffffff");

            return newTime.Substring(0, 2).TrimStart('0') + newTime.Substring(2,1) + '.' + newTime.Substring(3, 3) + " ms";

        }


    }
}
