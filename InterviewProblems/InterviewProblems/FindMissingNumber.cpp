#include "stdafx.h"
#include "iostream"
#include <vector>
#include <unordered_set>

using namespace std;

class FindMisssingNumber {

public:

	FindMisssingNumber() {


	}

	int findUsingOther() {

	}

	int findUsingFormula(vector<int> *vec) {
		int sumVec = 0;
		unordered_set<int> *set = new unordered_set<int>();
		for (int i = 0; i < vec->size(); i++) {
			if (vec->at(i) <= 0) return -1;
			if (set->find(vec->at(i)) == set->end()) {
				set->insert(vec->at(i));
			}
			else {
				return -2;
			}
			sumVec += vec->at(i);
		}
		int sizePlusOne = vec->size() + 1;
		int sumFor = (sizePlusOne * (sizePlusOne + 1)) / 2;
		return sumFor - sumVec;
	}

	void test(vector<int>* input, int expectedOutput, char* testName) {
		int actualOutput = findUsingFormula(input);
		if (actualOutput == expectedOutput) {
			cout << "passed " << testName << endl;
		} else {
			cout << "Failed " << testName << endl;
		}
	}

	vector<int>* testCase1() {
		vector<int>* vec = new vector<int>();
		vec->push_back(3);
		vec->push_back(1);
		return vec;
	}

	vector<int>* testCase2() {
		vector<int>* vec = new vector<int>();
		return vec;
	}

	vector<int>* testCase3() {
		vector<int>* vec = new vector<int>();
		vec->push_back(5);
		vec->push_back(1);
		vec->push_back(2);
		vec->push_back(3);
		vec->push_back(4);
		return vec;
	}


	vector<int>* testCase4() {
		vector<int>* vec = new vector<int>();
		vec->push_back(-8);
		vec->push_back(1);
		vec->push_back(2);
		vec->push_back(5);
		return vec;
	}

	vector<int>* testCase5() {
		vector<int>* vec = new vector<int>();
		vec->push_back(1);
		vec->push_back(2);
		vec->push_back(1);
		return vec;
	}

	void run() {
		// [1, 2 ,3, 5]  =  4
		// [2, 3, 4, 5] = 1
		// [] = 1
		// [1, 3] = 2
		// [2, 3] = 1
		// [1, 2, 3, 4] = 5
		// [1] = 2
		// [2, 4, 3, 5] = 1
		// [-8, 1, 2, 5] = -1        solve by adding an if in the same for
		// [ 1, 2, 1 ] = -2          maybe unordered_set(), it is still 0(1) to find

		test(testCase1(), 2, "2 numbers");
		test(testCase2(), 1, "Empty");
		test(testCase3(), 6, "5 numbers");
		test(testCase4(), -1, "negative in vector");
		test(testCase5(), -2, "repeated in vector");


	}
};


