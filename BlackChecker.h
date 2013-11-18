#pragma once
#include "CPiece.h"
//#include "CheckerBoard.h"
//#include <stdlib.h>

class BlackChecker : public CPiece {
public:
	// Constructor
	BlackChecker() { setColor(BLACK); setKing(0); setSpec(1); }

	//color symbol output
	char printColor() { return (isKing()) ? 'B' : 'b'; }

};