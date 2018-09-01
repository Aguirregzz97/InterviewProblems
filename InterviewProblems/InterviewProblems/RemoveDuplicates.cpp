#include "stdafx.h"
#include "iostream"
#include <vector>
#include <unordered_set>

using namespace std;

class RemoveDuplicates {

public:

	RemoveDuplicates() {

	}

	void run() {
		// Given an array of numbers, count the numbers and output each of their total counts
		// Example: [1, 2, 3, 1, 1, 1]  {1, 2, 3}
		// Expected output: [ 1, 2, 3 ]

		vector<int> *v = new vector<int>();
		for (int i = 0; i < 10; i++) {
			v->push_back(i);
		}
		for (int i = 0; i < 3; i++) {
			v->push_back(i);
		}

		for (int i = 0; i < v->size(); i++) {
			int x = v->at(i);
			cout << x << " ";
		}
		cout << endl << endl;

		unordered_set<int> *set = new unordered_set<int>();
		for (int i = 0; i < v->size(); i++) {
			if (set->find(v->at(i)) == set->end()) {
				set->insert(v->at(i));
			}
		}

		for (auto it = set->begin(); it != set->end(); it++) {
			cout << *it;
		}
	}
};


