#pragma once
#include "CPiece.h"
#include "CheckerBoard.h"
//#include <stdlib.h>

class RedChecker : public CPiece {
public:
	// Constructor
	RedChecker() { setColor(RED); setKing(0); setSpec(1); }

	//color symbol output
	char printColor() { return (isKing()) ? 'R' : 'r'; }

};