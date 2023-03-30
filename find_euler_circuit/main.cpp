#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	char isDirected;
	int n, m; //number of node and the number of edges

	//Ask the user if the graph is directed or undirected
	cout << "Is the graph directe: y/n " << endl;
	cin >> isDirected;

	//Get from the user the number of nodes
	cin >> n;

	//Get from the user the number of edges
	cin >> m;

	//Create the graph
	Graph graph(isDirected, n, m);

	//Add edges to the graph
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(u, v);
	}	

	if(graph.isEulerian())
		cout << "The graph is Eulerian" << endl;
	else
		cout << "The graph is not Eulerian" << endl;

}