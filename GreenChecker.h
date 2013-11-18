#pragma once
#include "CPiece.h"

class GreenChecker : public CPiece {
public:
	// Constructor
	GreenChecker() { setColor(GREEN); setKing(0); setSpec(1); }

	//color symbol output
	char printColor() { return (isKing()) ? 'G' : 'g'; }
};