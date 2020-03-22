#include "Map.h"
#include "GameManager.h"
#include "BitImageManager.h"
#include "ChessPiecesManager.h"

GameManager* GameManager::inst = nullptr;

ChessPiecesManager* ChessPiecesManager::GetInstance()
{
	if (inst == nullptr)
		inst = new ChessPiecesManager();

	return inst;
}

void GameManager::Init(HDC hdc)
{
	BitImageManager::GetInstance()->Init(hdc);
	ChessPiecesManager::GetInstance()->Init();
	cChessMap.Init();
}

void GameManager::Draw(HDC hdc)
{
	cChessMap.Draw(hdc);

	if (iGameState == PIECES_SELECT)
	{
		TextOut(hdc, 10, 500, TEXT("MOVED_PIECES"), 12);
	}
	else if (iGameState == PLAY_GAME)
	{
		TextOut(hdc, 10, 500, TEXT("SELECT_PIECES"), 13);
	}

	if (iPlayerTurn == WHITE_PLAYER_TURN)
	{
		TextOut(hdc, 10, 550, TEXT("WHITE PLAYER"), 12);
	}

	else if (iPlayerTurn == BLACK_PLAYER_TURN)
	{
		TextOut(hdc, 10, 550, TEXT("BLACK PLAYER"), 12);
	}

	ChessPiecesManager::GetInstance()->Draw(hdc);	
}

void GameManager::Update(HDC hdc)
{

}

void GameManager::Release(void)
{
	BitImageManager::GetInstance()->Release();
}

void GameManager::Input(int x, int y, HWND hWnd)
{
	MousePos.x = x;
	MousePos.y = y;

	if (iGameState == PLAY_GAME)
	{
		SelectPieces = ChessPiecesManager::GetInstance()->LMouseButtonDown(&MousePos, &iGameState);
	}

	else if (iGameState == PIECES_SELECT)
	{
	//	MessageBox(hWnd, "iGameState", "PIECES_SELECT", MB_OK);
		ChessPiecesManager::GetInstance()->MovedToMousePos(SelectPieces, &MousePos, &iGameState, hWnd, &iPlayerTurn);
		cChessMap.Init();

		if (iPlayerTurn == WHITE_PLAYER_TURN)
		{
			iPlayerTurn = BLACK_PLAYER_TURN;
			//iPlayerTurn = WHITE_PLAYER_TURN;
		}
		
		else if (iPlayerTurn == BLACK_PLAYER_TURN)
		{
			iPlayerTurn = WHITE_PLAYER_TURN;
		}
	}

	if (iGameState == PIECES_SELECT)
	{
		cChessMap.SelectedPiecesBitMap(&MousePos);
	}
	else if (iGameState == PLAY_GAME)
	{
		cChessMap.Init();
	}

	if (iGameState == GAME_OVER)
	{
		MessageBox(hWnd, "Game_Over", "Game_Over", MB_OK);
	}
}



GameManager::GameManager()
{
	iGameState = PLAY_GAME;
	iPlayerTurn = WHITE_PLAYER_TURN;
}
GameManager::~GameManager()
{
}