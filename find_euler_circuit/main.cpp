#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	char isDirected;
	int n, m; //number of node and the number of edges
	bool isInputValid = true;

	//Ask the user if the graph is directed or undirected
	cout << "Is the graph directed: y/n " << endl;
	cin >> isDirected;

	//check that is Directed is only 'y' or 'n'
	if(isDirected != 'y' && isDirected != 'n') 
		isInputValid = false;



	//Get from the user the number of nodes
	cin >> n;

	//Get from the user the number of edges
	cin >> m;

	if (n < 1 || m < 1) {
		isInputValid = false;
	}



	//Create the graph
	Graph graph(isDirected, n, m);

	//Add edges to the graph
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		if (u > n || v > n || v < 1 || u < 1) {
			isInputValid = false;
			break;
		}

		graph.addEdge(u, v);

	}	

	if (isInputValid) {
		if (graph.isEulerian()) {
			cout << "The graph is aulerian" << endl;
			graph.getEulerCircuit();
		}
		else {
			cout << "The graph is not aulerian" << endl;
		}
	}
	else {
		cout << "invalid input" << endl;
	}
		


	


	
}