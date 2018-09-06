#include "stdafx.h"
#include "iostream"
#include <vector>

using namespace std;

class GraphNode {

public:
	vector <GraphNode*> *connections;
	int value;

	GraphNode(int value) {
		this->value = value;
		this->connections = new vector<GraphNode*>();
	}
};


