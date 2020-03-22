#pragma once
#include <Windows.h>

#include "Global.h"

class Pieces;
class BitImage;
class Map
{
private:

	//static Map* inst;

	int		iChessMap[CHESS_BOARD_HIGH][CHESS_BOARD_WIDTH];

	POINT	MousePoint;
	RECT	ChessTile;
	HWND	_hWnd;

public:

//	static Map* GetInstance();

	void Init(void);
	void Draw(HDC hdc);
	bool SelectedPiecesBitMap(POINT *SelectPieces);
	Map();
	~Map();
};

