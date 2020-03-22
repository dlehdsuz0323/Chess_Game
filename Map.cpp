#include "Map.h"
#include "BitImageManager.h"
#include "BitImage.h"
#include "Pieces.h"

//
//Map* Map::inst = nullptr;
//
//Map* Map::GetInstance()
//{
//	if (inst == nullptr)
//		inst = new Map();
//
//	return inst;
//}
Map::Map()
{
}


Map::~Map()
{
}

void Map::Init(void)
{
	for (int i = 0; i < CHESS_BOARD_HIGH; i++)
	{
		for (int j = 0; j < CHESS_BOARD_WIDTH; j++)
		{

			if (i % 2 == 0 && j % 2 == 1)
			{
				iChessMap[i][j] = BROWN_COLOR;
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				iChessMap[i][j] = BROWN_COLOR;
			}
			else 
				iChessMap[i][j] = SKIN_COLOR;
		}
	}
}
	
void Map::Draw(HDC hdc)
{
		for (int i = 0; i < CHESS_BOARD_HIGH; i++)
		{
			for (int j = 0; j < CHESS_BOARD_WIDTH; j++)
			{
				BitImageManager::GetInstance()->Draw(hdc,MAP,iChessMap[i][j] ,i, j);
			}
		}
}

bool Map::SelectedPiecesBitMap(POINT  *SelectPieces)
{
	if (SelectPieces->x <= 480 && SelectPieces->y <= 480)
	{
		SelectPieces->x = SelectPieces->x /= 60;
		SelectPieces->y = SelectPieces->y /= 60;
	}
	else
		return false;

	iChessMap[SelectPieces->x][SelectPieces->y] = PICK;

	return true;
}

