#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	char isDirected;
	int n, m; //number of node and the number of edges
	bool isInputValid = true;

	//Get from the user if the graph is directed or not
	isInputValid = Graph::getGraphDirectionInput(isDirected);

	//Get from the user the number of nodes and edges
	if(isInputValid)
		isInputValid = Graph::getGraphSizeInput(n, m);
	
	//Create the graph
	Graph graph(isDirected, n, m);

	if(isInputValid)
		isInputValid = graph.getGraphEdgesInput(m);

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