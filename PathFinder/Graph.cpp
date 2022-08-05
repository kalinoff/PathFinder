#include "Graph.h"

void Graph::addEdge(int firstNode, int secondNode) {
	
	adjList[firstNode].push_back(secondNode);
	adjList[secondNode].push_back(firstNode);

}

void Graph::addEdgesByList(int node, std::initializer_list<int> edgesList) {
	
	adjList[node] = edgesList;

}

void Graph::initNumPadGraph() {

	this->addEdgesByList(1, { 2, 4 });
	this->addEdgesByList(2, { 1, 3, 5 });
	this->addEdgesByList(3, { 2, 6 });
	this->addEdgesByList(4, { 1, 5, 7 });
	this->addEdgesByList(5, { 2, 4, 6, 8 });
	this->addEdgesByList(6, { 3, 5, 9 });
	this->addEdgesByList(7, { 4, 8 });
	this->addEdgesByList(8, { 5, 7, 9 });
	this->addEdgesByList(9, { 6, 8 });

}

void Graph::initNumPadGraphDiagonal() {

	this->addEdgesByList(1, { 2, 4, 5 });
	this->addEdgesByList(2, { 1, 3, 4, 5, 6 });
	this->addEdgesByList(3, { 2, 5, 6 });
	this->addEdgesByList(4, { 1, 2, 5, 7, 8 });
	this->addEdgesByList(5, { 1, 2, 3, 4, 6, 7, 8, 9 });
	this->addEdgesByList(6, { 2, 3, 5, 8, 9 });
	this->addEdgesByList(7, { 4, 5, 8 });
	this->addEdgesByList(8, { 4, 5, 6, 7, 9 });
	this->addEdgesByList(9, { 5, 6, 8 });

}

void Graph::printAdjList() {

	for (auto node : adjList) {
		
		std::cout << node.first << " -> ";

		for (auto edgeTo : adjList[node.first])
			std::cout << edgeTo << " ";

		std::cout << "\n";

	}

	std::cout << std::endl;

}

void Graph::findPaths(int startNode, int finishNode) {

	std::vector<std::vector<int>> pathsSet;
	std::vector<int> sequence;
	std::map<int, bool> visited;

	recursiveFind(startNode, finishNode, visited, sequence, pathsSet);

	int numOfPath = 0;

	for (auto path : pathsSet) {

		++numOfPath;

		std::cout << numOfPath << ": ";

		for (auto node : path)
			std::cout << node << " ";

		std::cout << "\n";

	}

	std::cout << std::endl;

}

void Graph::recursiveFind(int& node, const int& finishNode, std::map<int, bool>& visited,
	std::vector<int> sequence, std::vector<std::vector<int>>& pathSet) {

	visited[node] = true;

	sequence.push_back(node);

	if (node == finishNode) {

		pathSet.push_back(sequence);

	}
	else
	{
		for (auto nbr : adjList[node]) {

			if (!visited[nbr]) {

				recursiveFind(nbr, finishNode, visited, sequence, pathSet);

			}
		}
	}

	visited[node] = false;

}
