#pragma once
#include "CheckerBoard.h"
#include <string>
#include <sstream>

using namespace std;

class Game {
public:
	Game();
	~Game() {}

	void play();
	void getNextMove();
	void alternateTurn();
	bool isGameOver();

private:
	char* playerString(PieceColor color) {
		switch (color) {
		case RED:
			return "Red";
			break;
		case GREEN:
			return "Green";
			break;
		case BLACK:
			return "Black";
			break;
		default:
			return "Error";
			break;
		}
	}

	int validInt() {
		string strInput = "";
		int out;
		while (true)
		{
			getline(cin, strInput);

			// This code converts from string to number safely.
			stringstream myStream(strInput);
			if ((myStream >> out) && (out >= 0 && out <= 8))
				break;
			cout << "Invalid input, please try again" << endl;
		}
		return out;
	}

};