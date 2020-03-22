#include "Rook.h"



void Rook::Init(int x, int y, int _iteam)
{
	iPieces = ROOK;
	iState = LIVE;

	iTeam = _iteam;
	PiecesPos.x = x;
	PiecesPos.y = y;
}

int Rook::GetPieces()
{
	return iPieces;
}

int Rook::GetTeam()
{
	return iTeam;
}

int Rook::GetState()
{
	return iState;
}

POINT * Rook::GetPoint()
{
	return &PiecesPos;
}

Pieces* Rook::AdvancementPown()
{
	return 0;
}

bool Rook::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{	
	if (PiecesPos.x > MousePoint->x && PiecesPos.y == MousePoint->y)
	{
		PiecesPos.x -= 1;
		return true;
	}

	else if (PiecesPos.x < MousePoint->x && PiecesPos.y == MousePoint->y)
	{
		PiecesPos.x += 1;
		return true;
	}

	else if (PiecesPos.y > MousePoint->y && PiecesPos.x == MousePoint->x)
	{
		PiecesPos.y -= 1;
		return true;
	}

	else if (PiecesPos.y < MousePoint->y && PiecesPos.x == MousePoint->x)
	{
		PiecesPos.y += 1;
		return true;
	}

	return false;
}

bool Rook::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{

	return false;
}

Rook::Rook()
{
}


Rook::~Rook()
{
}
