#include "Bishop.h"

void Bishop::Init(int x, int y, int _iteam)
{
	iPieces = BISHOP;
	iState = LIVE;

	iTeam = _iteam;
	PiecesPos.x = x;
	PiecesPos.y = y;
}

int Bishop::GetPieces()
{
	return iPieces;
}

int Bishop::GetTeam()
{
	return iTeam;
}

int Bishop::GetState()
{
	return iState;
}

POINT * Bishop::GetPoint()
{
	return &PiecesPos;
}

Pieces* Bishop::AdvancementPown()
{
	return 0;
}

//bool Bishop::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
//{
//	for (int i = 0; i < CHESS_BOARD_HIGH; i++)
//	{
//		if (MousePoint->x - i  == PiecesPos.x && MousePoint->y - i == PiecesPos.y)
//		{
//			PiecesPos.x = MousePoint->x;
//			PiecesPos.y = MousePoint->y;
//			return true;
//		}
//
//		else if (MousePoint->x + i == PiecesPos.x && MousePoint->y - i == PiecesPos.y)
//		{
//			PiecesPos.x = MousePoint->x;
//			PiecesPos.y = MousePoint->y;
//			return true;
//		}
//
//		else if (MousePoint->x - i == PiecesPos.x && MousePoint->y + i == PiecesPos.y)
//		{
//			PiecesPos.x = MousePoint->x;
//			PiecesPos.y = MousePoint->y;
//			return true;
//		}
//
//		else if (MousePoint->x + i == PiecesPos.x && MousePoint->y + i == PiecesPos.y)
//		{
//			PiecesPos.x = MousePoint->x;
//			PiecesPos.y = MousePoint->y;
//			return true;
//		}
//	}
//
//	return 0;
//}

bool Bishop::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{
	if (iDirection == NOT_MOVED)
	{
		BeforMovingPos.x = PiecesPos.x;
		BeforMovingPos.y = PiecesPos.y;
	}

	if (iDirection == NOT_MOVED || iDirection == MOVED)
	{
		if (PiecesPos.x > MousePoint->x && PiecesPos.y > MousePoint->y)
		{
			PiecesPos.x--;
			PiecesPos.y--;
			iDirection = MOVED;
			return true;
		}

		else if (PiecesPos.x < MousePoint->x && PiecesPos.y > MousePoint->y)
		{
			PiecesPos.x++;
			PiecesPos.y--;
			iDirection = MOVED;
			return true;
		}

		else if (PiecesPos.x < MousePoint->x && PiecesPos.y < MousePoint->y)
		{
			PiecesPos.x++;
			PiecesPos.y++;
			iDirection = MOVED;
			return true;
		}

		else if (PiecesPos.x > MousePoint->x && PiecesPos.y < MousePoint->y)
		{
			PiecesPos.x--;
			PiecesPos.y++;
			iDirection = MOVED;
			return true;
		}

		if (iDirection == MOVED)
		{
			if (PiecesPos.x != MousePoint->x || PiecesPos.y != MousePoint->y)
			{
				PiecesPos.x = BeforMovingPos.x;
				PiecesPos.y = BeforMovingPos.y;
			}
		}
	}

	iDirection = NOT_MOVED;
	return false;
}

bool Bishop::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{
	return false;
}


Bishop::Bishop()
{
	iDirection = NOT_MOVED;
}


Bishop::~Bishop()
{
}
