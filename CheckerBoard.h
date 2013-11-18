#pragma once
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <assert.h>
#include "CheckerList.h"

using namespace std;

class CheckerBoard {
public:
	//constructor
	CheckerBoard();

	//console output of the board
	void print();

	//move-checking (general check and king)
	bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol, PieceColor player);
	bool isJump(int srcRow, int srcCol, int destRow, int destCol);

	//checker move
	bool moveChecker(int srcRow, int srcCol, int destRow, int destCol, PieceColor player);
	bool moveCheckerGreenSpecial(int srcRow, int srcCol, int destRow, int destCol, PieceColor player);

	//count methods
	int getRed() { return red; }
	int getGreen() { return green; }
	int getBlack() { return black; }

	//check for special
	bool hasSpecial(int srcRow, int srcCol);


private:
	int red, green, black;
	void setRed(){ red = 0; }
	void setGreen(){ green = 0; }
	void setBlack(){ black = 0; }

	//move-checking cont (color specific movements)
	bool isLegalColorMove(int srcRow, int srcCol, int destRow, int destCol);

	//checker jumping
	bool moveCheckerJump(int srcRow, int srcCol, int destRow, int destCol);

	//check after move for king
	void makeKing(int destRow, int destCol);

};