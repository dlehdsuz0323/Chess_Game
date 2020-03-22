#pragma once
#include <Windows.h>
#include "Global.h"

class BitImage;
class Pieces
{
protected:
	int		iPieces;											
	int		iState;												
	int		iTeam;
	POINT	PiecesPos;
	RECT    ChessPieces;

	bool	 MovePown;


public:

	virtual void	 Init(int x, int y, int iteam);
	virtual int		 GetPieces();
	virtual int		 GetTeam();
	virtual int		 GetState();
	virtual POINT*   GetPoint();
	virtual inline void	 SetDie()
	{
		iState = DEAD;
	}

	inline void MovedPownReset()
	{
		MovePown = false;
	}

	virtual Pieces*	 PownAdvanceMent(Pieces * ChoicePieces);

	virtual bool	 MovedToMousePoint(POINT * MousePoint, int *iIncreasePos) = 0;
	virtual bool	 AttackingToPieces(POINT* MousePoint , Pieces* PiecesKind) = 0;



	Pieces();
	~Pieces();
};
