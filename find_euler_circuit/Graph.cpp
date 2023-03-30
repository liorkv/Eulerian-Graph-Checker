#include <iostream>
#include "Graph.h"
using namespace std;

//Constructor, initialize the graph
Graph::Graph(char isDirected, int n, int m) {
	this->isDirected = isDirected;
	this->n = n;
	this->m = m;
	adjList = new std::list<int>[n];
}

Graph::~Graph() {

}

//Add new edge to the graph, If the graph is undirected, add the edge to both vertices
void Graph::addEdge(int u, int v) {

	adjList[u-1].push_back(v-1);
	if (isDirected == 'n') {
		adjList[v-1].push_back(u-1);
	}
}

bool Graph::isEulerian() {
	//Check if the graph is connected graph
	bool isGraphConnectedResult = isGraphConnected();

	//If the graph is not connected then return false, because it is not possible to find an Eulerian circuit in a disconnected graph
	if (!isGraphConnectedResult) {
		return false;
	}

	//If the graph is connected, and if the graph is undirected check if all the nodes have even degree
	if (isDirected == 'n') {
		for (int i = 0; i < n; i++) {
			if (adjList[i].size() % 2 != 0) {
				return false;
			}
		}
	}
	//If the graph is connected, and if the graph is directed check if all the nodes have the same in-degree and out-degree
	else {
		int inDegree = 0;
		int outDegree = 0;
		for (int i = 0; i < n; i++) {
			inDegree = adjList[i].size();
			outDegree = 0;
			for (int j = 0; j < n; j++) {
				for (auto itr = adjList[j].begin(); itr != adjList[j].end(); ++itr) {
					if (*itr == i) {
						outDegree++;
					}
				}
			}
			if (inDegree != outDegree) {
				return false;
			}
		}
	}


	return true;
}

//The function return true if the graph is connected, false otherwise
bool Graph::isGraphConnected() {
	//Create a visited array
	bool* isNodeVisited = new bool[n];

	//Initialize the visited array with false
	for (int i = 0; i < n; i++) {
		isNodeVisited[i] = false;
	}

	//Call the Visit function to check if the graph is connected
	Visit(isNodeVisited, 0);

	//Check if all the nodes are visited
	for (int i = 0; i < n; i++) {
		if (!isNodeVisited[i]) {
			return false;
		}
	}

	return true;
}

void Graph::Visit(bool* visited, int u) {
	visited[u] = true;
	logMethodFor_Visit(visited, u);

	//Travers the adjacency list of the current node
	for (auto itr = adjList[u].begin(); itr != adjList[u].end(); ++itr) {
		if (!visited[*itr]) {
			Visit(visited, *itr);
		}
	}
}

//FOR TESTING PURPOSE ONLY
void Graph::logMethodFor_Visit(bool* visited, int nodeIndex) {
	//Print all node that are connected to the current node
	cout << "Current node is: " << nodeIndex << endl;
	cout << "It is connected to:";
	for (auto itr = adjList[nodeIndex].begin(); itr != adjList[nodeIndex].end(); ++itr) {
		cout << *itr << " ";
	}

	cout << endl;

	//Print the status of the visited array
	cout << "Visited array: " << endl;
	printAdjacencyList(visited);
}
//////////////////////////////////////////////

void Graph::printAdjacencyList(bool* visited) {
	//for every node print if it 's visited or not
	for (int i = 0; i < n; i++) {
		std::cout << i << " : ";
		if (visited[i]) {
			std::cout << "visited" << std::endl;
		}
		else {
			std::cout << "not visited" << std::endl;
		}
	}
}