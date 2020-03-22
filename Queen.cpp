#include "Queen.h"

void Queen::Init(int x, int y, int _iteam)
{
	iPieces = QUEEN;
	iState = LIVE;

	iTeam = _iteam;
	PiecesPos.x = x;
	PiecesPos.y = y;
}

int Queen::GetPieces()
{
	return iPieces;
}

int Queen::GetTeam()
{
	return iTeam;
}

int Queen::GetState()
{
	return iState;
}

POINT * Queen::GetPoint()
{
	return &PiecesPos;
}

Pieces* Queen::AdvancementPown()
{

	return 0;
}

void Queen::MovedToDirection()
{

}

bool Queen::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{
	// CROSS

	if (iDirection == NONE)
	{
		BeforMovingPos.x = PiecesPos.x;
		BeforMovingPos.y = PiecesPos.y;
	}

	if (iDirection == NONE || iDirection == DIAGONAL)
	{
		if (PiecesPos.x > MousePoint->x && PiecesPos.y > MousePoint->y)
		{
			PiecesPos.x--;
			PiecesPos.y--;

			iDirection = DIAGONAL;
			return true;
		}

		else if (PiecesPos.x < MousePoint->x && PiecesPos.y > MousePoint->y)
		{
			PiecesPos.x++;
			PiecesPos.y--;

			iDirection = DIAGONAL;
			return true;
		}

		else if (PiecesPos.x < MousePoint->x && PiecesPos.y < MousePoint->y)
		{
			PiecesPos.x++;
			PiecesPos.y++;

			iDirection = DIAGONAL;
			return true;
		}

		else if (PiecesPos.x > MousePoint->x && PiecesPos.y < MousePoint->y)
		{
			PiecesPos.x--;
			PiecesPos.y++;

			iDirection = DIAGONAL;
			return true;
		}

	}

	if (iDirection == DIAGONAL)
	{
		if (PiecesPos.x != MousePoint->x || PiecesPos.y != MousePoint->y)
		{
			PiecesPos.x = BeforMovingPos.x;
			PiecesPos.y = BeforMovingPos.y;
		}
	}


	//STRAIGHT

	if (iDirection == NONE || iDirection == STRAIGHT)
	{
		if (PiecesPos.x > MousePoint->x && PiecesPos.y == MousePoint->y)
		{
			PiecesPos.x -= 1;

			iDirection = STRAIGHT;
			return true;
		}

		else if (PiecesPos.x < MousePoint->x && PiecesPos.y == MousePoint->y)
		{
			PiecesPos.x += 1;

			iDirection = STRAIGHT;
			return true;
		}

		else if (PiecesPos.y > MousePoint->y && PiecesPos.x == MousePoint->x)
		{
			PiecesPos.y -= 1;

			iDirection = STRAIGHT;
			return true;
		}

		else if (PiecesPos.y < MousePoint->y && PiecesPos.x == MousePoint->x)
		{
			PiecesPos.y += 1;

			iDirection = STRAIGHT;
			return true;
		}
	}

	iDirection = NONE;
	return false;
}

bool Queen::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{
	return false;
}


Queen::Queen()
{
	iDirection = NONE;
}


Queen::~Queen()
{
}
