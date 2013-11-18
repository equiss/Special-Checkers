#pragma once
//#include "CheckerBoard.h"


enum PieceColor {
	RED,
	GREEN,
	BLACK
};

class CPiece {
public:

	//Getters and Setters
	void setColor(PieceColor col) { color = col; }
	void setKing(bool ki) { king = ki;  }
	void setSpec(bool spe) { special = spe; }

	PieceColor getColor() { return color; }
	bool hasSpec() { return special; }
	bool isKing() { return king; }
	void promote() { king = 1; }
	void useSpecial() { special = 0; }

	//Char getters for board out
	virtual char printColor() = 0;
	char printSpecialStatus();

protected:
	PieceColor color;
	bool king;
	bool special;

};
