#pragma once

#include <Windows.h> 

#include "Pieces.h"
#include "Global.h"

class Pown : public Pieces
{
	Pieces*  AdvancementPieces;


public:

	 void	 Init(int x, int y, int _iteam);
	 int		 GetPieces();
	 int		 GetTeam(void);
	 int		 GetState(void);
	 POINT*   GetPoint(void);

	Pieces*			 AdvancementPown(void);

	Pieces*	 PownAdvanceMent(Pieces * ChoicePieces);
	bool			 MovedToMousePoint(POINT * MousePoint, int *iIncreasePos);
	bool	 AttackingToPieces(POINT* MousePoint, Pieces* PiecesKind);

	inline bool MovedPown(void)
	{
		MovePown = true;
	}

	Pown();
	~Pown();
};

