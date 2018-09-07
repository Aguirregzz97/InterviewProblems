#include "stdafx.h"
#include "iostream"
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class AnagramStrings {

public:
	AnagramStrings() {
	}

	bool isAnagram(vector<string> *strings) {
		if (strings->at(0).empty() && strings->at(1).empty()) {
			return true;
		}
		if (strings->at(0).size() != strings->at(1).size()) {
			return false;
		}
		sort(strings->at(0).begin(), strings->at(0).end());
		sort(strings->at(1).begin(), strings->at(1).end());

		if (strings->at(0) == strings->at(1)) {
			return true;
		}
		else {
			return false;
		}

	}

	 vector<string>* testCase1() {
		 vector <string> *strings = new vector <string>();
		 strings->push_back("trianglee"); //{ t, r, i, a, n, g, l, e }
		 strings->push_back("inteegral"); // try to insert (if i can insert something, then it would not be an anagram)
		 return strings;
	}

	 vector<string>* testCase2() {
		 vector <string> *strings = new vector <string>();
		 strings->push_back("mouse"); //{ t, r, i, a, n, g, l, e }
		 strings->push_back("micky"); // try to insert (if i can insert something, then it would not be an anagram)
		 return strings;
	 }

	 vector<string>* testCase3() {
		 vector <string> *strings = new vector <string>();
		 strings->push_back(""); 
		 strings->push_back("");
		 return strings;
	 }

	 vector<string>* testCase4() {
		 vector <string> *strings = new vector <string>();
		 strings->push_back("triangle");
		 strings->push_back("integral");
		 return strings;
	 }

	void run() {
		if(isAnagram(testCase4())) {
			cout << "It is an anagram!" << endl;
		} 
		else {
			cout << "It isnt :(" << endl;
		}


	}
};


