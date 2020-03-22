#pragma once
#include <Windows.h>

#include "Map.h"
#include "Pieces.h"
#include "Global.h"
#include "ChessPiecesManager.h"

class Map;
class BitImageManager;
class ChessPiecesManager;
class GameManager
{
private:


	static GameManager* inst;


	Map						cChessMap;
	Pieces*					SelectPieces;
	POINT 					MousePos;
	int						iGameState;
	int						iPlayerTurn;

public:

	void Init(HDC hdc);
	void Draw(HDC hdc);

	void Update(HDC hdc);
	void Release(void);
	void Input(int x, int y, HWND hWnd);

	static GameManager* GetInstance()
	{
		if (inst == nullptr)
			inst = new GameManager();

		return inst;
	}
	GameManager();
	~GameManager();
};

