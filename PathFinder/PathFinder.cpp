#include "Graph.h"

int main()
{
	Graph graph;
	graph.initNumPadGraph(); //Init numpad graph
	graph.printAdjList();

	Graph diagGraph;
	diagGraph.initNumPadGraphDiagonal(); //Init numpad graph with diagonal connections
	diagGraph.printAdjList();


	std::cout << "Paths from 1 to 5 without diagonal connections: " << std::endl; 
 	graph.findPaths(1, 5);


	std::cout << "Paths from 1 to 6 with diagonal connections: " << std::endl; 
	diagGraph.findPaths(1, 6);

}

