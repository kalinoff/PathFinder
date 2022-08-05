#pragma once
#include <map>
#include <list>
#include <vector>
#include <iostream>
 
struct Graph {

	std::map<int, std::list<int>> adjList; 
	
	//Fill the adjacency list by pair of int, int values
	void addEdge(int firstNode, int secondNode);

	//Fill the adjacency list by initializer_list of int values
	void addEdgesByList(int node, std::initializer_list<int> edgesList);


	//Init graph by numpad values withoud diagonal connections
	void initNumPadGraph();

	//Init graph by numpad values with diagonal connections
	void initNumPadGraphDiagonal(); 


	void printAdjList();
	

	//Init DFS-like recursive algorithm, then print paths
	void findPaths(int startNode, int finishNode);

	//Recirsive part of DFS-like algorithm
	void recursiveFind(int& node, const int& finishNode, std::map<int, bool>& visited,
		std::vector<int> sequence, std::vector<std::vector<int>>& pathSet);

};