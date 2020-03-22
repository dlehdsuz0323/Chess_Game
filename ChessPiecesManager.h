#pragma once
#include <Windows.h>
#include <vector>	

#include "Global.h"

#include "Pieces.h"
#include "Pown.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"

#include "Map.h"

using namespace std;

class Pown;
class Pieces;
class Map;
class ChessPiecesManager
{
private:
	
	static ChessPiecesManager* inst;

	RECT				ChessPieces;
	POINT				MousePoint;
	POINT				BeforMovingPos;

	Pieces*				BlackPlayerPieces[CHESS_PLAYER_PIECES_MAXNUMBER];
	Pieces*				WhitePlayerPieces[CHESS_PLAYER_PIECES_MAXNUMBER];

	Pown				cWPown[8],		cBPown[8];
	Knight				cWKnight[2],	cBKnight[2];
	Bishop				cWBishop[2],	cBBishop[2];
	Rook				cWRook[2],		cBRook[2];
	King				cWKing,			cBking;
	Queen				cWQueen,		cBQueen;

	bool				bMovedPieces;
	int				    iMoveToNumber;

public:

	static ChessPiecesManager* GetInstance();

	void	  Init(void);
	void	  Draw(HDC hdc);
			  
	Pieces*	  LMouseButtonDown(POINT * SelectPoint, int *iGameState);
	bool	  MovedToMousePos(Pieces*	ChoicePieces, POINT* MousePos, int *iGameState, HWND hWnd, int *iPlayerTurn);
	//bool	  PownAdvancement(Pieces * ChoicePieces);
	

	void	  MovedAblePown(Pieces *ChoicePieces, Pieces* WhitePieces[CHESS_PLAYER_PIECES_MAXNUMBER], Pieces* Blackpieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iPlayerTurn);
	bool	  AttackedbleChessPieces(Pieces *ChoicePieces, Pieces* PlayerDiePieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iChessPiecesNumber, int *iGameState);
	void	  CheckedJumpPieces(Pieces * ChoicePieces, Pieces* PlayerPieces[CHESS_PLAYER_PIECES_MAXNUMBER], int iChessPiecesNumber);

	void	  Release();


	ChessPiecesManager();
	~ChessPiecesManager();
};

