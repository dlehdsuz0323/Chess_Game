#include "Pown.h"
#include "Queen.h"
#include "BitImageManager.h"

void Pown::Init(int x, int y, int _iteam)
{
	iPieces			= POWN;
	iState			= LIVE;

	iTeam			= _iteam;
	PiecesPos.x		= x;
	PiecesPos.y		= y;

	MovePown		= false;
}


int Pown::GetPieces()
{
	return iPieces;
}

int Pown::GetState()
{
	return iState;
}

Pieces* Pown::AdvancementPown(void)
{
	Queen* pNew = new Queen();
	if (this->GetTeam() == WHITE_PIECES)
	{
		pNew->Init(PiecesPos.x, PiecesPos.y, WHITE_PIECES);
		AdvancementPieces = pNew;
		return AdvancementPieces;
	}

	else if (this->GetTeam() == BLACK_PIECES)
	{
		pNew->Init(PiecesPos.x, PiecesPos.y, BLACK_PIECES);
		AdvancementPieces = pNew;
		return AdvancementPieces;
	}

	return nullptr;
}

int Pown::GetTeam()
{
	return iTeam;
}

POINT * Pown::GetPoint()
{
	return &PiecesPos;
}

Pieces* Pown::PownAdvanceMent(Pieces * ChoicePieces)
{
	Pieces * PownAdvancement;

	if (ChoicePieces->GetPieces() == POWN &&
		ChoicePieces->GetTeam() == WHITE_PIECES &&
		ChoicePieces->GetPoint()->y == 0)
	{
		ChoicePieces = AdvancementPown();
	}

	if (ChoicePieces->GetPieces() == POWN &&
		ChoicePieces->GetTeam() == BLACK_PIECES &&
		ChoicePieces->GetPoint()->y == 7)
	{
		ChoicePieces = AdvancementPown();
	}

	return ChoicePieces;
}

bool Pown::MovedToMousePoint(POINT * MousePoint, int *iIncreasePos)
{
	if (iTeam == BLACK_PIECES)
	{
		if (MovePown == false)
		{
			if (MousePoint->y - 2 == PiecesPos.y && MousePoint->x == PiecesPos.x)
			{
				PiecesPos.x;
				PiecesPos.y += 2;
				MovePown = true;
				return false;
			}
		}

		if (MousePoint->y - 1 == PiecesPos.y && MousePoint->x == PiecesPos.x)
		{
			PiecesPos.x;
			PiecesPos.y += 1;
			MovePown = true;
			return false;
		}

		if (PiecesPos.x == MousePoint->x - 1 && PiecesPos.y == MousePoint->y - 1)
		{
			PiecesPos.x += 1;
			PiecesPos.y += 1;
			MovePown = true;
			return true;
		}

		if (PiecesPos.x == MousePoint->x + 1 && PiecesPos.y == MousePoint->y - 1)
		{
			PiecesPos.x -= 1;
			PiecesPos.y += 1;
			MovePown = true;
			return true;
		}
	}

	if (iTeam == WHITE_PIECES)
	{
		if (MovePown == false)
		{
			if (MousePoint->y + 2 == PiecesPos.y && MousePoint->x == PiecesPos.x)
			{
				PiecesPos.x;
				PiecesPos.y -= 2;
				MovePown = true;
				return false;
			}
		}

		if (MousePoint->y + 1 == PiecesPos.y && MousePoint->x == PiecesPos.x)
		{
			PiecesPos.x;
			PiecesPos.y -= 1;
			MovePown = true;
			return false;
		}

		if (PiecesPos.x == MousePoint->x - 1 && PiecesPos.y == MousePoint->y + 1)
		{
			PiecesPos.x += 1;
			PiecesPos.y -= 1;
			MovePown = true;
			return true;
		}

		if (PiecesPos.x == MousePoint->x + 1 && PiecesPos.y == MousePoint->y + 1)
		{
			PiecesPos.x -= 1;
			PiecesPos.y -= 1;
			MovePown = true;
			return true;
		}
	}

	return false;
}

bool Pown::AttackingToPieces(POINT * MousePoint, Pieces * PiecesKind)
{
	return false;
}


Pown::Pown()
{

}


Pown::~Pown()
{
	delete AdvancementPieces;
}
