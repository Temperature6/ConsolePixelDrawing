#pragma once
#include <Windows.h>

void SetFontColor(int color)
{
	/*
	0 - BLACK ºÚ

	1 - BLUE À¼ 2 - GREEN ÂÌ

	3 - CYAN Çà 4 - RED ºì

	5 - MAGENTA Ñóºì 6 - BROWN ×Ø

	7 - LIGHTGRAY µ­»Ò 8 - DARKGRAY Éî»Ò

	9 - LIGHTBLUE µ­À¼ 10 - LIGHTGREEN µ­ÂÌ

	11 - LIGHTCYAN µ­Çà 12 - LIGHTRED µ­ºì

	13 - LIGHTMAGENTA µ­Ñóºì 14 - YELLOW »Æ

	15 - WHITE °×
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MoveCursor(int startX, int startY)
{
	HANDLE hd;
	COORD pos;
	pos.X = startX;
	pos.Y = startY;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hd, pos);
}