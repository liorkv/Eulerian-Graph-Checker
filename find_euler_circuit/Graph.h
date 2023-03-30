#pragma once
#include <list>

class Graph {
private:
	char isDirected;
	int n;
	int m;
	std::list<int>* adjList;

public:
	Graph(char isDirected, int n, int m);
	~Graph();

	std::list<int> findCircuit(int v0);

	int findUnvisitedEdge(bool** visited, int v);

	bool hasUnvisitedEdge(bool** visited, int v);

	void addEdge(int u, int v);

	bool isEulerian();

	bool isGraphConnected();

	void Visit(bool* visited, int nodeIndex);

	void logMethodFor_Visit(bool* visited, int nodeIndex);

	void printAdjacencyList(bool* visited);

	void printGraph();

	bool** createVisitedArray();

};