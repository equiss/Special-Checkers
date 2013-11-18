#pragma once
#include "CheckerList.h"
#include <iostream>

/**
* Debugging function
* Print the contents of the CheckerList
*/
void CheckerList::Print() {

	// Temp pointer
	CheckerNode *tmp = head;

	// No CheckerNodes
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	// One CheckerNode in the CheckerList
	if (tmp->Next() == NULL) {
		cout << tmp->cPiece()->printColor();
		cout << " --> ";
		cout << "NULL" << endl;
	}
	else {
		// Parse and print the CheckerList
		do {
			cout << tmp->cPiece()->printColor();
			cout << " --> ";
			tmp = tmp->Next();
		} while (tmp != NULL);

		cout << "NULL" << endl;
	}
}

/**
* Append a CheckerNode to the linked CheckerList
*/
CheckerNode* CheckerList::Append(CPiece* checker) {

	// Create a new CheckerNode
	CheckerNode* newCheckerNode = new CheckerNode();
	newCheckerNode->setChecker(checker);
	newCheckerNode->SetNext(NULL);

	// Create a temp pointer
	CheckerNode *tmp = head;

	if (tmp != NULL) {
		// CheckerNodes already present in the CheckerList
		// Parse to end of CheckerList
		while (tmp->Next() != NULL) {
			tmp = tmp->Next();
		}

		// Point the last CheckerNode to the new CheckerNode
		tmp->SetNext(newCheckerNode);
	}
	else {
		// First CheckerNode in the CheckerList
		head = newCheckerNode;
	}

	return newCheckerNode;
}

/**
* Delete a CheckerNode from the CheckerList
*/
void CheckerList::Delete(CPiece* checker) {

	// Create a temp pointer
	CheckerNode *tmp = head;

	// No CheckerNodes
	if (tmp == NULL)
		return;

	// Last CheckerNode of the CheckerList
	if (tmp->Next() == NULL) {
		delete tmp;
		head = NULL;
	}
	else {
		// Parse thru the CheckerNodes
		CheckerNode *prev = NULL;
		do {
			if (tmp->cPiece() == checker) break;
			prev = tmp;
			tmp = tmp->Next();
		} while (tmp != NULL);

		// Adjust the pointers
		prev->SetNext(tmp->Next());

		// Delete the current CheckerNode
		delete tmp;
	}
}