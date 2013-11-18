#pragma once
#include "CPiece.h"
#include "RedChecker.h"
#include "GreenChecker.h"
#include "BlackChecker.h"

using namespace std;

// CheckerNode class
class CheckerNode {
	CPiece* checker;
	CheckerNode* next;

public:
	CheckerNode() {};
	void setChecker(CPiece* achecker) { checker = achecker; };
	void SetNext(CheckerNode* aNext) { next = aNext; };
	CPiece* cPiece() { return checker; };
	CheckerNode* Next() { return next; };
};

// CheckerList class
class CheckerList {
	CheckerNode *head;
public:
	CheckerList() { head = NULL; };
	void Print();
	CheckerNode* Append(CPiece* checker);
	void Delete(CPiece* checker);
};