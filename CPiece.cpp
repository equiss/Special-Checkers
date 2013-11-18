#pragma once
#include "CPiece.h"

	
char CPiece::printSpecialStatus() {
	return (special == 1) ? 'S' : ' ';
}