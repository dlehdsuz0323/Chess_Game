#pragma once
#include <Windows.h>

#include "Global.h"

class BitImage
{
private:

	HDC MemDC;
	HBITMAP MyBitMap;
	HBITMAP OldBitMap;

public:

	void Init(HDC hdc,HWND hwnd, char *cBlock);
	void Draw(HDC hdc, int x, int y);
	void Release(void);

	BitImage();
	~BitImage();
};

