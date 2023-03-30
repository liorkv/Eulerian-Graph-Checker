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

	void addEdge(int u, int v);

	bool isEulerian();

	bool isGraphConnected();

	void DFS(bool* visited);

	void Visit(bool* visited, int nodeIndex);

	void logMethodFor_Visit(bool* visited, int nodeIndex);

	void printAdjacencyList(bool* visited);

};