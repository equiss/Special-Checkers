#pragma once
#include "Game.h"

using namespace std;

PieceColor playerturn;
CheckerBoard board;

Game::Game() { playerturn = GREEN; }

void Game::play() {

	do {
		getNextMove();
		alternateTurn();
	} while (!isGameOver());
	board.print();
	}

void Game::getNextMove()
{
	bool validMove = false;
	char special = 'n';
	int srcRow;
	int srcCol;
	int destRow;
	int destCol;

	do {
		board.print();

		// Get input and convert to coordinates
		cout << playerString(playerturn) << "'s Move" << endl;
		cout << "Please enter your piece's row: ";
		srcRow = validInt();

		cout << "Please enter your piece's column: ";
		srcCol = validInt();

		cout << "Please enter the piece's destination row: ";
		destRow = validInt();

		cout << "Please enter the piece's destination column: ";
		destCol = validInt();

		if ((playerturn == GREEN) &&
			(board.isLegalMove(srcRow,srcCol,destRow,destCol, playerturn)) &&
			(board.hasSpecial(srcRow,srcCol)) &&
			(!board.isJump(srcRow, srcCol, destRow, destCol)))
		{
			do {
				cout << "Use special? (y/n): ";
				cin >> special;
			} while (special != 'y' && special != 'n');
		}
		if (special == 'y')
		{
			//Attemt to move checker (CheckerBoard takes care of validity checks)
			validMove = board.moveCheckerGreenSpecial(srcRow, srcCol, destRow, destCol, playerturn);
		}
		else
		{
			//Attempt to move checker (CheckerBoard takes care of validity checks)
			validMove = board.moveChecker(srcRow, srcCol, destRow, destCol, playerturn);
		}

		if (!validMove) { cout << "Invalid move! Try again" << endl; }

	} while (!validMove);
}
void Game::alternateTurn() {
	int red = board.getRed();
	int green = board.getGreen();
	int black = board.getBlack();

	playerturn = (PieceColor)((playerturn + 1) % 3);
	if (playerturn == RED && red == 0) { playerturn = (PieceColor)((playerturn + 1) % 3); }
	if (playerturn == GREEN && green == 0) { playerturn = (PieceColor)((playerturn + 1) % 3); }
	if (playerturn == BLACK && black == 0) { playerturn = (PieceColor)((playerturn + 1) % 3); }

}
bool Game::isGameOver() { 
	int red = board.getRed();
	int green = board.getGreen();
	int black = board.getBlack();

	if (red != 0 && green == 0 && black == 0) { 
		cout << "Red Wins!";
		return true;
	}
	if (red == 0 && green != 0 && black == 0) {
		cout << "Green Wins!";
		return true;
	}
	if (red == 0 && green == 0 && black != 0) {
		cout << "Black Wins!";
		return true;
	}
	if (red == 0 && green == 0 && black == 0) {
		cout << "It's a Tie!";
		return true;
	}
	return false;
}