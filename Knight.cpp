#include "Knight.h"

void Knight::Init(int x, int y, int _iteam)
{
	iPieces = KNIGHT;
	iState = LIVE;

	iTeam = _iteam;
	PiecesPos.x = x;
	PiecesPos.y = y;
}

int Knight::GetPieces()
{
	return iPieces;
}

int Knight::GetTeam()
{
	return iTeam;
}

int Knight::GetState()
{
	return iState;
}

POINT * Knight::GetPoint()
{
	return &PiecesPos;
}

Pieces* Knight::AdvancementPown()
{
	return 0;
}

bool Knight::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{
			// Y축 이동 후 대각선
	if (MousePoint->y - 2 == PiecesPos.y && MousePoint->x + 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y - 2 == PiecesPos.y && MousePoint->x - 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 2 == PiecesPos.y && MousePoint->x + 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 2 == PiecesPos.y && MousePoint->x - 1 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}

			// X축 이동 후 대각선
	else if (MousePoint->y - 1 == PiecesPos.y && MousePoint->x - 2 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x - 2 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y - 1 == PiecesPos.y && MousePoint->x + 2 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}
	else if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x + 2 == PiecesPos.x)
	{
		PiecesPos.y = MousePoint->y;
		PiecesPos.x = MousePoint->x;
		return true;
	}

	return false;
}

bool Knight::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{
	return false;
}

Knight::Knight()
{
}


Knight::~Knight()
{
}
