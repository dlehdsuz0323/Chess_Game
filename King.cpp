#include "King.h"

void King::Init(int x, int y, int _iteam)
{
	iPieces = KING;
	iState = LIVE;

	iTeam = _iteam;
	PiecesPos.x = x;
	PiecesPos.y = y;
}

int King::GetPieces()
{
	return iPieces;
}

int King::GetTeam()
{
	return iTeam;
}

int King::GetState()
{
	return iState;
}

POINT * King::GetPoint()
{
	return &PiecesPos;
}

Pieces* King::AdvancementPown()
{
	return 0;
}

bool King::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{
			// 위 아래 좌 우
	if (MousePoint->y - 1  == PiecesPos.y && MousePoint->x  == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y == PiecesPos.y && MousePoint->x - 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y == PiecesPos.y && MousePoint->x + 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}

			// 대각선
	else if (MousePoint->y - 1 == PiecesPos.y && MousePoint->x - 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y - 1 == PiecesPos.y && MousePoint->x + 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x - 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x + 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	return false;
}



bool King::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{
	return false;
}

King::King()
{
}


King::~King()
{
}
