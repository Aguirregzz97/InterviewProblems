#include "stdafx.h"
#include "iostream"
#include <vector>
#include <unordered_set>

using namespace std;

class OptimumSubstring {

public:

	OptimumSubstring() {

	}


	string smallerSubstringAlg(string base, string alp) {

		if (alp == "") {
			return "";
		}


		unordered_set<char>* set = new unordered_set<char>();  
		for (int i = 0; i < alp.size(); i++) {
			set->insert(alp[i]);
		}

		int first = 0;
		int last = 0;
		int smallestFirst = 0;
		int smallestLast = 0;
		int smallestYet = 10000;
		
		bool isFirst = true;
		for (int i = 0; i < base.size(); i++) {				// "sgfkwvfjs"  "wvs"
			for (int j = i; j < base.size(); j++) {
				if (set->find(base[j]) != set->end()) {
					if (isFirst) {				
						first = j;
						isFirst = false;
					}
					set->erase(base[j]);
					if (set->empty()) {
						last = j;
					}
				}
			}
			if (!set->empty()) {
				continue;
			}
			isFirst = true;
			for (int i = 0; i < alp.size(); i++) {
				set->insert(alp[i]);
			}
			if (last - first < smallestYet) {
				smallestFirst = first;
				smallestLast = last;
				smallestYet = last - first;
			}
		}

		string result;
		for (int i = smallestFirst; i < smallestLast + 1; i++) {
			result += base[i];
		}

		return result;

	}

	void testLargeString(string base, string alp, string expectedOutput) {
		string result = smallerSubstringAlg(base, alp);
		if (result == expectedOutput) {
			cout << "succes";
		}
		else {
			cout << "Le fail";
		}

	}

	string testCaseLarge() {
		return "sgfkwvfjs";
	}

	string testCaseSmall() {
		return "a";
	}


	void run() {

		//Given a string and a smaller alphabet, create the optimal substring that has all the alph

		// "andres" "sda" = "andres"
		// "andres" "a" = "a"
		// "a" "a" = "a"
		// "sgfkwvfjs" "wvs" = "wvfjs"
		// "wwvs" "wvs" = "wvs"

		testLargeString(testCaseSmall(), "a", "a");


	}
};


