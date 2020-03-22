#pragma once
#include <Windows.h> 

#include "Global.h"
#include "Pieces.h"


enum QUEENDIRECTION
{
	NONE,
	STRAIGHT,
	DIAGONAL
};

class Queen: public Pieces
{
private:

	int		 iPieces;
	int		 iState;
	int		 iTeam;
	int		 iDirection;
	POINT	 PiecesPos;
	POINT	 BeforMovingPos;
public:
	
	virtual void	 Init(int x, int y, int _iteam);

	virtual int			GetPieces();
	virtual int			 GetTeam();
	virtual int			 GetState();
	virtual POINT*	     GetPoint();
	virtual Pieces*		 AdvancementPown();
	virtual inline void	 SetDie()
	{
		iState = DEAD;
	}

	void			 MovedToDirection();
	virtual bool	 MovedToMousePoint(POINT * MousePoint, int *iIncreasePos);
	virtual bool	 AttackingToPieces(POINT* MousePoint, Pieces* PiecesKind);

	Queen();
	~Queen();
};

