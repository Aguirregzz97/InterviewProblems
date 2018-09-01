#include "stdafx.h"
#include "iostream"
#include <vector>
#include <map>

using namespace std;

class CountNumbers {

public:

	CountNumbers() {

	}

	void run() {


		// [1, 1, 1, 2, 2, 3]  expectedO: 1: 4, 2: 2, 3: 1    { 1: 3, 2: 2, 3: 1 }  
		// [-1, -1, 2, 3] expectedO: -1: 2, 2: 1, 3: 1



		//[0, 1, 2, 3 ,4, 5, 6, 7, 8, 9, 0, 1 2]

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

		map<int, int>* mapN = new map<int, int>;		
		
		for (int i = 0; i < v->size(); i++) {
			int key = v->at(i);
			if (mapN->find(key) == mapN->end()) {
				mapN->at(key) = 1;
			}
			else {
				mapN->at(key) = mapN->at(key) + 1;
			}
		}

		for (auto i = mapN->begin(); i != mapN->end(); i++) {
			cout << i->first << ":" << i->second << endl;
		}


	}
};


