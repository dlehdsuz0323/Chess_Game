#include <iostream>

#include "BitImageManager.h"
#include "BitImage.h"

#include "Map.h"

#include "ChessPiecesManager.h"

BitImageManager* BitImageManager::inst = nullptr;

BitImageManager::BitImageManager()
{
}

void BitImageManager::Init(HDC hdc)
{
	char buffer[256];

	//White_Pieces
	for (int i = 0; i < 6; i++)
	{
		BitImage* pNew = new BitImage();
		sprintf_s(buffer, "block_w_%02d.bmp", i);

		pNew->Init(hdc, hWnd, buffer);
		vecWhitePieces.push_back(pNew);
	}

	//Black_Pieces
	for (int i = 0; i < 6; i++)
	{
		BitImage* pNew = new BitImage();
		sprintf_s(buffer, "block_b_%02d.bmp", i);

		pNew->Init(hdc, hWnd, buffer);
		vecBlackPieces.push_back(pNew);
	}

	//Map
	for (int i = 0; i < 3; i++)
	{
		BitImage* pNew = new BitImage();
		sprintf_s(buffer, "block%02d.bmp", i);

		pNew->Init(hdc, hWnd, buffer);
		vecMap.push_back(pNew);
	}
}

void BitImageManager::Draw(HDC hdc, int iBlockType, int pieces, int x, int y)
{
	if (iBlockType == MAP)
	{
		switch (pieces)
		{
		case SKIN_COLOR:
			vecMap[0]->Draw(hdc, x * 60, y * 60);
			break;
		case BROWN_COLOR:
			vecMap[1]->Draw(hdc, x * 60, y * 60);
			break;
		case PICK:
			vecMap[2]->Draw(hdc, x * 60, y * 60);
			break;
		}
	}

	if (iBlockType == WHITE_PIECES)
	{
		switch (pieces)
		{
		case POWN:
			vecWhitePieces[0]->Draw(hdc, x * 60, y * 60);
			break;
		case KNIGHT:
			vecWhitePieces[1]->Draw(hdc, x * 60, y * 60);
			break;
		case BISHOP:
			vecWhitePieces[2]->Draw(hdc, x * 60, y * 60);
			break;
		case ROOK:
			vecWhitePieces[3]->Draw(hdc, x * 60, y * 60);
			break;
		case QUEEN:
			vecWhitePieces[4]->Draw(hdc, x * 60, y * 60);
			break;
		case KING:
			vecWhitePieces[5]->Draw(hdc, x * 60, y * 60);
			break;
		}
	}

	if (iBlockType == BLACK_PIECES)
	{
		switch (pieces)
		{
		case POWN:
			vecBlackPieces[0]->Draw(hdc, x * 60, y * 60);
			break;
		case KNIGHT:
			vecBlackPieces[1]->Draw(hdc, x * 60, y * 60);
			break;
		case BISHOP:
			vecBlackPieces[2]->Draw(hdc, x * 60, y * 60);
			break;
		case ROOK:
			vecBlackPieces[3]->Draw(hdc, x * 60, y * 60);
			break;	
		case QUEEN:
			vecBlackPieces[4]->Draw(hdc, x * 60, y * 60);
			break;
		case KING:
			vecBlackPieces[5]->Draw(hdc, x * 60, y * 60);
			break;
		}
	}
}

void BitImageManager::Release()
{
	for (auto iter = vecWhitePieces.begin(); iter != vecWhitePieces.end(); iter++)
	{
		delete(*iter);
	}

	for (auto iter = vecBlackPieces.begin(); iter != vecBlackPieces.end(); iter++)
	{
		delete(*iter);
	}

	for (auto iter = vecMap.begin(); iter != vecMap.end(); iter++)
	{
		delete(*iter);
	}
}


BitImageManager::~BitImageManager()
{
}
