#include "stdafx.h"
#include "iostream"
#include <vector>
#include <map>
#include <unordered_set>
#include "LinkedListNode.cpp"

using namespace std;

class RemoveDuplicatesUnsortedList {

public:

	RemoveDuplicatesUnsortedList() {


		
	}

	LinkedListNode* testCase1() {
		LinkedListNode *head = new LinkedListNode();
		head->value = 1;
		head->next = new LinkedListNode();
		head->next->value = 1;
		head->next->next = new LinkedListNode();
		head->next->next->value = 2;
		head->next->next->next = new LinkedListNode();
		head->next->next->next->value = 3;
		head->next->next->next->next = NULL;
		return head;
	}

	LinkedListNode* testCase2() {
		LinkedListNode *head = new LinkedListNode();
		head->value = 5;
		head->next = new LinkedListNode();
		head->next->value = 2;
		head->next->next = new LinkedListNode();
		head->next->next->value = -1;
		head->next->next->next = new LinkedListNode();
		head->next->next->next->value = -1;
		head->next->next->next->next = NULL;
		return head;
	}

	LinkedListNode* testCase3() {
		LinkedListNode *head = new LinkedListNode();
		head->value = 1;
		head->next = new LinkedListNode();
		head->next->value = 1;
		head->next->next = new LinkedListNode();
		head->next->next->value = 1;
		head->next->next->next = new LinkedListNode();
		head->next->next->next->value = 1;
		head->next->next->next->next = NULL;
		return head;
	}

	LinkedListNode* testCase4() {
		LinkedListNode *head = NULL;
		return head;
	}
	void removeDuplicates(LinkedListNode *head) {
		
		if (head == NULL) {
			return;
		}

		unordered_set<int> *set = new unordered_set<int>();

		LinkedListNode *node = head;
		set->insert(node->value);

		while (node->next != NULL) {
			if (set->find(node->next->value) == set->end()) {
				set->insert(node->next->value);
				node = node->next;
			}
			else {
				LinkedListNode *tmpN = node->next;
				node->next = node->next->next;
				delete tmpN;
			}
		}
	}

	void eraseFirstNode(LinkedListNode **head) {
		if (head == NULL) {
			return;
		}
		LinkedListNode *tmpN = *head;
		*head = (*head)->next;
		delete tmpN;
	}

	void print(LinkedListNode *head) {
		while (head != NULL) {
			cout << head->value;
			head = head->next;
		}
		cout << endl;
	}

	void run() {


		LinkedListNode *head = testCase2();
		// { 1, 2, 3, 4, 4} = {1, 2 ,3 , 4}
		// { 1, 1, 2, 3} = {1, 2, 3}
		// { 5, 2, -1, -1} = { 5, 2, -1}
		// { 1, 1, 1, 1, 1}
		// { }

		print(head);
		eraseFirstNode(&head);
		print(head);
	}
};


