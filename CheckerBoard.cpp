#pragma once
#include "CheckerBoard.h"
#include <iostream>
#include <string>

using namespace std;

CheckerNode* checkerboard[9][9];
CheckerList checkers;

//Public methods
CheckerBoard::CheckerBoard() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			checkerboard[i][j] = NULL;
		}
	}
	// Add in the checkers
	
	//red checkers
	checkerboard[0][1] = checkers.Append(new RedChecker());
	checkerboard[0][3] = checkers.Append(new RedChecker());
	checkerboard[0][5] = checkers.Append(new RedChecker());
	checkerboard[0][7] = checkers.Append(new RedChecker());
	checkerboard[1][2] = checkers.Append(new RedChecker());
	checkerboard[1][4] = checkers.Append(new RedChecker());
	checkerboard[1][6] = checkers.Append(new RedChecker());
	
	//green checkers
	checkerboard[1][8] = checkers.Append(new GreenChecker());
	checkerboard[3][8] = checkers.Append(new GreenChecker());
	checkerboard[5][8] = checkers.Append(new GreenChecker());
	checkerboard[7][8] = checkers.Append(new GreenChecker());
	checkerboard[2][7] = checkers.Append(new GreenChecker());
	checkerboard[4][7] = checkers.Append(new GreenChecker());
	checkerboard[6][7] = checkers.Append(new GreenChecker());
	
	//black checkers
	checkerboard[8][1] = checkers.Append(new BlackChecker());
	checkerboard[8][3] = checkers.Append(new BlackChecker());
	checkerboard[8][5] = checkers.Append(new BlackChecker());
	checkerboard[8][7] = checkers.Append(new BlackChecker());
	checkerboard[7][2] = checkers.Append(new BlackChecker());
	checkerboard[7][4] = checkers.Append(new BlackChecker());
	checkerboard[7][6] = checkers.Append(new BlackChecker());
	
	red = 7;
	green = 7;
	black = 7;
}

void CheckerBoard::print() {

	//checkers.Print();

	const int width = 4;
	const int height = 3;
	for (int i = (9 * height) - 1; i >= 0; i--)
	{
		int rowsquare = i / height;
		//side border with numbering
		if (i % 3 == 1) {
			cout << '-' << (char)('0' + 8 - rowsquare) << '-';
		}
		else {
			cout << "---";
		}
		//print checker board
		for (int j = 0; j < 9 * width; ++j) {
			int colsquare = j / width;
			if (((i % 3) == 1) && ((j % 4) == 1 || (j % 4) == 2) && checkerboard[8 - rowsquare][colsquare] != NULL) {
				if ((j % 4) == 1) {
					CPiece* temp = checkerboard[8 - rowsquare][colsquare]->cPiece();
					cout << temp->printColor();
				}
				else {
					CPiece* temp = checkerboard[8 - rowsquare][colsquare]->cPiece();
					cout << temp->printSpecialStatus();
				}
			}
			else {
				if ((rowsquare + colsquare) % 2 == 1) {
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}

	// Print the bottom border with numbers
	for (int iRow = 0; iRow < height; ++iRow) {
		if (iRow % 3 == 1) {
			cout << "---";
			for (int i = 0; i < 9 * width; ++i) {
				int colsquare = i / width;
				if ((i % 4) == 1) {
					cout << (colsquare);
				}
				else {
					cout << '-';
				}
			}
			cout << endl;
		}
		else {
			for (int i = 1; i < 9 * width; ++i) {
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool CheckerBoard::isLegalMove(int srcRow, int srcCol, int destRow, int destCol, PieceColor player) 
{
	if ((checkerboard[srcRow][srcCol] != NULL) &&
		(destRow >= 0 && destRow <= 8) &&
		(destCol >= 0 && destCol <= 8))
	{
		CheckerNode* dest = checkerboard[destRow][destCol];
		CheckerNode* src = checkerboard[srcRow][srcCol];

		if (src->cPiece()->getColor() != player) { return false; }

		if (dest == NULL)
		{
			if (src->cPiece()->isKing() == 0)
			{
				return isLegalColorMove(srcRow, srcCol, destRow, destCol);
			}
			else
			{
				//Move one (empty)space, any direction
				if ((abs(destRow - srcRow) <= 1) && (abs(destCol - srcCol) <= 1))
				{
					return true;
				}
				//Jump to bottom right				
				else if (((destRow == srcRow + 2) && (destCol == srcCol + 2)) && checkerboard[destRow - 1][destCol - 1] != 0)
				{
					return true;
				}
				//Jump to top right
				else if (((destRow == srcRow - 2) && (destCol == srcCol + 2)) && checkerboard[destRow + 1][destCol - 1] != 0)
				{
					return true;
				}
				//Jump to middle(row) right
				else if (((destRow == srcRow) && (destCol == srcCol + 2)) && checkerboard[destRow][destCol - 1] != 0)
				{
					return true;
				}
				//Jump to bottom middle(col)
				else if (((destRow == srcRow + 2) && (destCol == srcCol)) && checkerboard[destRow - 1][destCol] != 0)
				{
					return true;
				}
				//Jump to top middle(col)
				else if (((destRow == srcRow - 2) && (destCol == srcCol)) && checkerboard[destRow + 1][destCol] != 0)
				{
					return true;
				}
				//Jump to bottom left
				else if (((destRow == srcRow + 2) && (destCol == srcCol - 2)) && checkerboard[destRow - 1][destCol + 1] != 0)
				{
					return true;
				}
				//Jump to middle(row) left
				else if (((destRow == srcRow) && (destCol == srcCol - 2)) && checkerboard[destRow][destCol + 1] != 0)
				{
					return true;
				}
				//Jump to top left
				else if (((destRow == srcRow - 2) && (destCol == srcCol - 2)) && checkerboard[destRow + 1][destCol + 1] != 0)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool CheckerBoard::isJump(int srcRow, int srcCol, int destRow, int destCol)
{
	return ((abs(srcRow - destRow) == 2) || (abs(srcCol - destCol) == 2)) ? true : false;
}

bool CheckerBoard::moveChecker(int srcRow, int srcCol, int destRow, int destCol, PieceColor player)
{
	if (isLegalMove(srcRow, srcCol, destRow, destCol, player))
	{
		if (isJump(srcRow, srcCol, destRow, destCol)) { return moveCheckerJump(srcRow, srcCol, destRow, destCol); }
	
		//CheckerNode* dest = checkerboard[destRow][destCol];
		//CheckerNode* src = checkerboard[srcRow][srcCol];

		checkerboard[destRow][destCol] = checkerboard[srcRow][srcCol];
		checkerboard[srcRow][srcCol] = NULL;

		makeKing(destRow, destCol);
		
		return true;
	}
	return false;
}

bool CheckerBoard::moveCheckerGreenSpecial(int srcRow, int srcCol, int destRow, int destCol, PieceColor player) 
{
	if (isLegalMove(srcRow, srcCol, destRow, destCol, player))
	{
		if (isJump(srcRow, srcCol, destRow, destCol)) { return false; }

		checkerboard[destRow][destCol] = checkerboard[srcRow][srcCol];
		checkerboard[srcRow][srcCol] = checkers.Append(new GreenChecker());
		green++;

		CheckerNode* oldgreen = checkerboard[destRow][destCol];
		CheckerNode* newgreen = checkerboard[srcRow][srcCol];
		oldgreen->cPiece()->useSpecial();
		newgreen->cPiece()->useSpecial();

		makeKing(destRow, destCol);
		makeKing(srcRow, srcCol);

		return true;
	}
	return false;
}

bool CheckerBoard::hasSpecial(int srcRow, int srcCol) {
	CheckerNode* src = checkerboard[srcRow][srcCol];
	return src->cPiece()->hasSpec();
}

//Private methods
bool CheckerBoard::isLegalColorMove(int srcRow, int srcCol, int destRow, int destCol)
{
	CheckerNode* srcnode = checkerboard[srcRow][srcCol];
	PieceColor color = srcnode->cPiece()->getColor();

	switch (color)
	{
	case RED:
		if ((destRow == srcRow + 1) && (abs(destCol - srcCol) == 1))
		{
			return true;
		}
		if ((destRow == srcRow + 2) && (destCol == srcCol + 2))
		{
			CheckerNode* temp = checkerboard[srcRow + 1][srcCol + 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != RED) return true;
			}
		}
		if ((destRow == srcRow + 2) && (destCol == srcCol - 2))
		{
			CheckerNode* temp = checkerboard[srcRow + 1][srcCol - 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != RED) return true;
			}
		}
		return false;	
	case GREEN:
		if ((destCol == srcCol - 1) && (abs(destRow - srcRow) == 1))
		{
			return true;
		}
		if ((destCol == srcCol - 2) && (destRow == srcRow + 2))
		{
			CheckerNode* temp = checkerboard[srcRow + 1][srcCol - 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != GREEN) return true;
			}
		}
		if ((destCol == srcCol - 2) && (destRow == srcRow - 2))
		{
			CheckerNode* temp = checkerboard[srcRow - 1][srcCol - 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != GREEN) return true;
			}
		}
		return false;
	case BLACK:
		if ((destRow == srcRow - 1) && (abs(destCol - srcCol) == 1))
		{
			return true;
		}
		if ((destRow == srcRow - 2) && (destCol == srcCol + 2))
		{
			CheckerNode* temp = checkerboard[srcRow - 1][srcCol + 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != BLACK) return true;
			}
		}
		if ((destRow == srcRow - 2) && (destCol == srcCol - 2))
		{
			CheckerNode* temp = checkerboard[srcRow - 1][srcCol - 1];
			if (temp != NULL && temp != 0)
			{
				CPiece* tempPiece = temp->cPiece();
				if (tempPiece->getColor() != BLACK) return true;
			}
		}
		return false;
	}
}
bool CheckerBoard::moveCheckerJump(int srcRow, int srcCol, int destRow, int destCol)
{
	CheckerNode* src = checkerboard[srcRow][srcCol];
	CheckerNode* jumped = NULL;
	int jumpRow = srcRow;
	int jumpCol = srcCol;

	if (destRow == srcRow - 2) { jumpRow = srcRow - 1; }
	if (destRow == srcRow + 2) { jumpRow = srcRow + 1; }
	if (destCol == srcCol - 2) { jumpCol = srcCol - 1; }
	if (destCol == srcCol + 2) { jumpCol = srcCol + 1; }

	jumped = checkerboard[jumpRow][jumpCol];

	PieceColor jumpedColor = jumped->cPiece()->getColor();

	if (jumpedColor == BLACK)
	{
		if (rand() % 2 == 0)
		{
			checkerboard[jumpRow][jumpCol] = NULL;
			checkerboard[srcRow][srcCol] = NULL;
			black--;
			(src->cPiece()->getColor() == RED) ? red-- : green--;
			checkers.Delete(jumped->cPiece());
			checkers.Delete(src->cPiece());
			
			return true;
		}
	}
	if ((jumpedColor == RED) && jumped->cPiece()->hasSpec() )
	{
		checkerboard[destRow][destCol] = checkerboard[srcRow][srcCol];
		checkerboard[srcRow][srcCol] = NULL;
		jumped->cPiece()->useSpecial();
		makeKing(destRow, destCol);
		return true;
	}

	checkerboard[destRow][destCol] = checkerboard[srcRow][srcCol];
	checkerboard[srcRow][srcCol] = NULL;
	checkerboard[jumpRow][jumpCol] = NULL;
	checkers.Delete(jumped->cPiece());
	makeKing(destRow, destCol);
	if (jumpedColor == RED) { red--; }
	if (jumpedColor == GREEN) { green--; }
	if (jumpedColor == BLACK) { black--; }
	return true;
}
void CheckerBoard::makeKing(int destRow, int destCol) {
	
	CheckerNode* dest = checkerboard[destRow][destCol];
	PieceColor col = dest->cPiece()->getColor();
	
	if ((col == GREEN && destCol == 0) || 
		(col == RED && destRow == 8) ||
		(col == BLACK && destRow == 0))
	{
		dest->cPiece()->promote();
		return;
	}
}