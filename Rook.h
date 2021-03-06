#pragma once

#include <Windows.h> 

#include "Pieces.h"
#include "Global.h"

class Rook: public Pieces
{
private:

	int		 iPieces;
	int		 iState;
	int		 iTeam;
	POINT	 PiecesPos;

public:

	virtual void	 Init(int x, int y, int _iteam);

	virtual int		 GetPieces();
	virtual int		 GetTeam();
	virtual int		 GetState();
	virtual POINT*   GetPoint();
	virtual Pieces*		 AdvancementPown();
	virtual inline void	 SetDie()
	{
		iState = DEAD;
	}

	virtual bool	 MovedToMousePoint(POINT * MousePoint, int *iIncreasePos);
	virtual bool	 AttackingToPieces(POINT* MousePoint, Pieces* PiecesKind);

	Rook();
	~Rook();
};

