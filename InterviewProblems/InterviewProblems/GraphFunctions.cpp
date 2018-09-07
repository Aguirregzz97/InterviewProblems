#include "stdafx.h"
#include "iostream"
#include <vector>
#include "GraphNode.cpp"
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

class GraphFunctions {

public:

	GraphFunctions() {

	}

	//encontrar celebridad, nodo al que mas nodos apuntan
	//depth first sum totals
	//shortest path btween 2 nodes


	GraphNode* findCelebrity(GraphNode* root) {
		unordered_set<GraphNode*> *seen = new unordered_set<GraphNode*>();
		map<GraphNode*, int> *mp = new map<GraphNode*, int>();
		stack<GraphNode*> *s = new stack<GraphNode*>();
		s->push(root);
		seen->insert(root);
		mp->insert(pair<GraphNode*, int>(root, 0));
		int mostFamous = 0;
		GraphNode *mostFamousN = new GraphNode(10);
		while (s->size() > 0) {
			GraphNode* current = s->top();
			s->pop();
			for (int i = 0; i < current->connections->size(); i++) {
				if (seen->find(current->connections->at(i)) == seen->end()) {
					s->push(current->connections->at(i));
					mp->insert(pair<GraphNode*, int>(current->connections->at(i), 0));
					seen->insert(current->connections->at(i));
				}
				if (mp->find(current->connections->at(i)) != mp->end()) {
					mp->at(current->connections->at(i)) = mp->at(current->connections->at(i))++;
					if (mp->at(current->connections->at(i)) > mostFamous) {
						mostFamous = mp->at(current->connections->at(i));
						mostFamousN = current->connections->at(i);
					}
				}
			}
		}
		cout << mostFamous << endl;
		return mostFamousN;
	}

	int calculateSumRecPrivate(GraphNode *root, unordered_set<GraphNode*> *seen) {
		if (root == NULL) {
			return 0;
		}
		int total = root->value;
		seen->insert(root);
		for (int i = 0; i < root->connections->size(); i++) {
			GraphNode *current = root->connections->at(i);
			if (seen->find(current) == seen->end()) {
				seen->insert(current);
				total += calculateSumRecPrivate(current, seen);
			}
		}
		return total;
	}

	int calculateSumIter(GraphNode *root) {
		unordered_set <GraphNode *> *seen = new unordered_set<GraphNode *>();
		stack <GraphNode*> *s = new stack <GraphNode*>();
		s->push(root);
		seen->insert(root);
		int total = 0;
		while (s->size() > 0) {
			GraphNode* current = s->top();
			s->pop();
			total += current->value;
			for (int i = 0; i < current->connections->size(); i++) {
				if (seen->find(current->connections->at(i)) == seen->end()) {
					s->push(current->connections->at(i));
					seen->insert(current->connections->at(i));
				}
			}
		}
		return total;
	}

	int calculateSumRec(GraphNode *root) {
		unordered_set <GraphNode*> *seen = new unordered_set <GraphNode*>();
		return calculateSumRecPrivate(root, seen);
	}

	GraphNode* testCase1() {
		GraphNode* root = new GraphNode(50);
		GraphNode* root2 = new GraphNode(60);
		GraphNode* root3 = new GraphNode(80);
		GraphNode* root4 = new GraphNode(30);
		GraphNode* root5 = new GraphNode(20);
		GraphNode* root6 = new GraphNode(100);

		root->connections->push_back(root2);
		root->connections->push_back(root3);
		root->connections->push_back(root4);
		root->connections->push_back(root6);

		root2->connections->push_back(root4);
		root2->connections->push_back(root3);
		root2->connections->push_back(root5);

		root3->connections->push_back(root5);
		root3->connections->push_back(root6);
		root3->connections->push_back(root2);

		root4->connections->push_back(root6);
		root4->connections->push_back(root4);
		root4->connections->push_back(root);

		root5->connections->push_back(root);
		root5->connections->push_back(root3);
		root5->connections->push_back(root6);

		root6->connections->push_back(root4);
		root6->connections->push_back(root5);
		root6->connections->push_back(root);
		return root;
	}

	void run() {
		cout << findCelebrity(testCase1())->value;
	}
};


