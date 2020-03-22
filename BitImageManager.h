#pragma once
#include <Windows.h>
#include <vector>

#include "Global.h"

using namespace std;


class Map;
class BitImage;
class BitImageManager
{
private:
	BitImageManager();
	static BitImageManager* inst;

	vector <BitImage*>	vecMap;
	vector <BitImage*>	vecWhitePieces;
	vector <BitImage*>	vecBlackPieces;

	HWND				hWnd;

public:
	void Init(HDC hdc);
	void Draw(HDC hdc,int iBlockType, int iPieces, int x, int y);
	void Release();

	static BitImageManager* GetInstance()
	{
		if (inst == nullptr)
			inst = new BitImageManager();

		return inst;
	}
	
	~BitImageManager();
};

