#include <libloaderapi.h>
#include <vector>
#include <cstring>
#pragma once

using namespace std;
//动态链接库函数
HINSTANCE hInst = LoadLibrary(L"fileanalysis.dll");

typedef int(*DLLFuncSave)(char* ProjectName, vector<char>veccanvas);
DLLFuncSave SaveProject = (DLLFuncSave)::GetProcAddress(hInst, "SaveProject");

typedef void(*DLLFuncRead)(char temparr[], char* path);
DLLFuncRead ReadProject = (DLLFuncRead)::GetProcAddress(hInst, "ReadProject");

extern char temparr[];
extern char canvas[200][200];
extern int canvascolor[200][200];
extern int xMax, yMax;
int colormap[] = {1, 2, 3, 4, 5, 8, 14, 15};

int charmap(int c)
{
	switch (c)
	{
	case '#':
		return 0;
		break;
	case '@':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '%':
		return 3;
		break;
	case ' ':
		return 4;
		break;
	}
}

int testload()
{
	if (!hInst)
		return 0;
	else
		return 1;
}

char intTochar(int i)
{
	return i + 48;
}

int charToint(char c)
{
	return c - 48;
}

void PrintPic(char* t_canvas, char* t_color)
{
	int X = 0, Y = 0;
	system("cls");
	int x = 0, y = 0, n = 0;

	while (true)
	{
		if (t_canvas[n] == '\0')
			break;
		if (t_canvas[n] == '/')
		{
			n++; y++; x = 0;
			Y = y;
			continue;
		}
		if (t_canvas[n] == '_')
		{
			x++; n++;
			continue;
		}

		SetFontColor(colormap[charToint(t_color[n])]);
		canvascolor[y][x] = charToint(t_color[n]);
		canvas[y][x] = t_canvas[n];
		MoveCursor(x, y);
		printf("%c", t_canvas[n]);
		x++; n++;
		if (x > X)
			X = x;
	}
	xMax = X; yMax = Y;
}

void deleteslash(char* str)
{
	int i = 0;
	for (; str[i] != '\0'; i++)
		str[i] = str[i + 1];
	cout << i;
}

void getname(char* path, char* name)
{
	int i = 0;
	for (; path[i] != '\0'; i++);
	int j = i;
	for (; path[j] != '\\'; j--);
	for (int k = 0; path[k] != '\0'; k++)
		name[k] = path[j + k + 1];
}

//vector<int> getrange(char* arr,int pos = 0)
//{
//	//pos:传入当前指针的位置以提高效率
//	vector <char> vecrange;
//	for (int i = pos; arr[i] != '\0'; i++)
//		vecrange.push_back(arr[i]);
//}