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

std::list<int> Graph::getEulerCircuit() {
	bool** visited = createVisitedArray();

	int v = -1;

	//use find circuit to find the base circuit
	std::list<int> circuit = findCircuit(0, visited);
	std::list<int> L1;

	//create iterator that point the will point to the first element in the circuit
	std::list<int>::iterator itrList = circuit.begin();
	
	//while the iterator is not the end of the circuit
	while (itrList != circuit.end()) {
		if(hasUnvisitedEdge(visited, *itrList)) {
			v = findUnvisitedEdge(visited, *itrList);
			
			visited[*itrList][v] = true;

			//if the graph is undirected, then we need to mark the edge as visited in the opposite direction
			if (isDirected == 'n') {
				visited[v][*itrList] = true;
			}

			L1 = findCircuit(v, visited);

			circuit.splice(std::next(itrList), L1);
		}

		//go to the next element in the list
		++itrList;
	}

	//print the circuit
	cout << "(";
	for (auto itr = circuit.begin(); itr != circuit.end(); ++itr) {
		cout << (*itr + 1);

		if (std::next(itr) != circuit.end()) {
			cout << ",";
		}

	}
	cout << ")";

	return circuit;
}

//The function find circuit in the graph, and return a list the contains this circuit in the graph, the function get vertex v0 as parameter
std::list<int> Graph::findCircuit(int v0, bool** visited) {
	int v = v0;
	int u = -1;
	std::list<int> circuit;
	circuit.push_back(v);

	while (hasUnvisitedEdge(visited, v)) {
		u = findUnvisitedEdge(visited, v);
		visited[v][u] = true;

		//If the graph undirected, then we need to mark the edge as visited in the opposite direction
		if (isDirected == 'n') {
			visited[u][v] = true;
		}

		circuit.push_back(u);
		v = u;
	}

	return circuit;
}


//The function gets 2d visited array, and find unvisited edge, and return the vertex of the unvisited edge
int Graph::findUnvisitedEdge(bool** visited, int v) {
	for (auto itr = adjList[v].begin(); itr != adjList[v].end(); ++itr) {
		if (!visited[v][*itr]) {
			return *itr;
		}
	}
	return -1;
}

//The function gets 2d visited array, and vertex v, and returns true if the vertex v has an unvisited edge, false otherwise
bool Graph::hasUnvisitedEdge(bool** visited, int v) {
	for (auto itr = adjList[v].begin(); itr != adjList[v].end(); ++itr) {
		if (!visited[v][*itr]) {
			return true;
		}
	}
	return false;
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

	//Travers the adjacency list of the current node
	for (auto itr = adjList[u].begin(); itr != adjList[u].end(); ++itr) {
		if (!visited[*itr]) {
			Visit(visited, *itr);
		}
	}
}

//Function prints all the edges in the graph
void Graph::printGraph() {
	for (int i = 0; i < n; i++) {
		std::cout << i << " : ";
		for (auto itr = adjList[i].begin(); itr != adjList[i].end(); ++itr) {
			std::cout << *itr << " ";
		}
		std::cout << std::endl;
	}
}

//Function iterates over the adjacency list and creates 2d array with the same dimention that will store wheter the node visited of not
bool** Graph::createVisitedArray() {
	bool** visited = new bool* [n];

	//Create the 2d array
	for (int i = 0; i < n; i++) {
		if (adjList[i].size() > 0) {
			visited[i] = new bool[n];
		}
		else {
			visited[i] = nullptr;
		}
	}

	//Initialize all the values with false
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i] != nullptr) {
				visited[i][j] = false;
			}
		}
	}

	return visited;
}