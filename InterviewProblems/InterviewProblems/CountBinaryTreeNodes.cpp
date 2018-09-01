#include "stdafx.h"
#include "iostream"
#include "BinaryTreeNode.cpp"

using namespace std;

class CountBinaryTreeNodes {

public:

	CountBinaryTreeNodes() {

	}

	int CountNodes(BinaryTreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return 1 + CountNodes(root->left) + CountNodes(root->right);
	}

	int GreatestNode(BinaryTreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int max = root->value;
		int greatestLeft = GreatestNode(root->left);
		int greatestRight = GreatestNode(root->right);
		if (greatestLeft > max) {
			max = greatestLeft;
		}
		if (greatestRight > max) {
			max = greatestRight;
		}
		return max;
	}

	void GreatestNodeAlternative(BinaryTreeNode* root, int* maxUntilNow) {
		if (root == NULL) {
			return;
		}
		if (root->value > *maxUntilNow) {
			*maxUntilNow = root->value;
		}
		GreatestNodeAlternative(root->left, maxUntilNow);
		GreatestNodeAlternative(root->right, maxUntilNow);
	}


	void testMax(BinaryTreeNode* input, int expectedOutput, char* testName) {
		int actualOutput = GreatestNode(input);
		if (actualOutput == expectedOutput) {
			cout << "passed " << testName << endl;
		}
		else {
			cout << "Failed " << testName << endl;
		}
	}

	void testMaxAlternative(BinaryTreeNode* input, int expectedOutput, char* testName) {
		int actualOutput = 0;
		GreatestNodeAlternative(input, &actualOutput);
		if (actualOutput == expectedOutput) {
			cout << "passed " << testName << endl;
		}
		else {
			cout << "Failed " << testName << endl;
		}
	}

	void testCountNodes(BinaryTreeNode* input, int expectedOutput, char* testName) {
		int actualOutput = CountNodes(input);
		if (actualOutput == expectedOutput) {
			cout << "passed " << testName << endl;
		}
		else {
			cout << "Failed " << testName << endl;
		}
	}

	BinaryTreeNode* testCase1() {
		BinaryTreeNode *root = new BinaryTreeNode();
		root->value = 20;
		root->left = new BinaryTreeNode();
		root->right = new BinaryTreeNode();
		root->left->value = 15;
		root->right->value = 25;
		root->left->left = new BinaryTreeNode();
		root->left->right = new BinaryTreeNode();
		root->right->left = new BinaryTreeNode();
		root->right->right = new BinaryTreeNode();
		root->left->left->value =  12;
		root->left->right->value = 18;
		root->right->left->value = 22;
		root->right->right->value = 28;
		return root;
	}

	void run() {

		testCountNodes(testCase1(), 7, "sorted tree count: 7");
		testMax(testCase1(), 28, "max value in tree: 7");
		testMaxAlternative(testCase1(), 28, "max value in tree: 7");

		
		
	}
};


