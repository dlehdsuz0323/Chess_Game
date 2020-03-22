#include "BitImage.h"



BitImage::BitImage()
{
}


BitImage::~BitImage()
{
}

void BitImage::Init(HDC hdc,HWND hwnd, char *cBlock)
{
	MemDC = CreateCompatibleDC(hdc);
	MyBitMap = (HBITMAP)LoadImage(NULL, cBlock,
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (MyBitMap == NULL)
	{
		MessageBox(hwnd, "이미지 로드 실패", "이미지 로드 실패", MB_OK);
	}
	OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);

}

void BitImage::Draw(HDC hdc, int x, int y)
{
	TransparentBlt(hdc, x, y, 60, 60, MemDC, 0, 0, 125, 125, RGB(255, 0, 255));
}

void BitImage::Release(void)
{
	DeleteObject(MemDC);
	DeleteObject(MyBitMap);
	DeleteObject(OldBitMap);
}
