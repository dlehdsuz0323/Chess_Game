#include "Pieces.h"

Pieces* Pieces::PownAdvanceMent(Pieces * ChoicePieces)
{
	return false;
}

Pieces::Pieces()
{
}


Pieces::~Pieces()
{
}

void Pieces::Init(int x, int y, int iteam)
{
}

int Pieces::GetPieces()
{
	return iPieces;
}

int Pieces::GetTeam()
{
	return iTeam;
}

int Pieces::GetState()
{
	return iState;
}

POINT * Pieces::GetPoint()
{
	return &PiecesPos;
}
