#include "stdafx.h"
#include "iostream"
#include <vector>
#include <time.h>


using namespace std;

class FillMatrixWith0 {

public:
	FillMatrixWith0() {
	}

	/*
		1 0 1 0 1		0 0 0 0 0
		1 1 1 1 1  =	1 0 1 0 0
		1 1 1 1 0		0 0 0 0 0

		[1, 0, 1]   [0, 1, 0, 1, 1]
	*/

	vector<vector<int>*>* fillAlgorithm(vector<vector<int>*>* mat) {

		print(mat);

		vector<int> *rowsZ = new vector<int>();
		rowsZ->resize(mat->size());
		vector<int> *columnsZ = new vector<int>();
		columnsZ->resize(mat->at(0)->size());

		for (int i = 0; i < mat->size(); i++) {
			for (int j = 0; j < mat->at(i)->size(); j++) {
				if (mat->at(i)->at(j) == 0) {
					rowsZ->at(i) = 1;
					columnsZ->at(j) = 1;
				}
			}
		}

		for (int i = 0; i < mat->size(); i++) {
			for (int j = 0; j < mat->at(i)->size(); j++) {
				if (rowsZ->at(i) == 1 || columnsZ->at(j) == 1) {
					mat->at(i)->at(j) = 0;
				}
			}
		}

		print(mat);

		return mat;


	}


	vector<vector<int>*>* testCase1() {
		srand(time(NULL));
		vector<vector<int>*> *mat = new vector<vector<int>*>();

		for (int i = 0; i < 10; i++) {
			vector<int> *tmp = new vector<int>();
			for (int j = 0; j < 10; j++) {
				tmp->push_back(rand() % 10);
			}
			mat->push_back(tmp);
		}
		return mat;
	}

	void print(vector<vector<int>*>* mat) {
		for (int i = 0; i < mat->size(); i++) {
			for (int j = 0; j < mat->at(i)->size(); j++) {
				cout << mat->at(i)->at(j) << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	void run() {
		
		fillAlgorithm(testCase1());


	}
};


