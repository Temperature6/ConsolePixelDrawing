/*
2020/10/06 19:43-创建工程并完成第一个版本
2020/10/07 13:25-添加空格抬笔的功能
2020/10/07 21:54-修复颜色栏显示信息不全的Bug
2020/11/01 10:05-更改切换画笔的方式，增添了新画笔
*/
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "BetterPrint.h"
using namespace std;

int x = 1, y = 1;
int pen = 0, historypen = 0, up = 0;
int color = 7;
char PenType[5] = { '#', '@', '*', '%', ' ' };
vector <string> ColorType = { "兰  ","绿  ","青  ","红  ","洋红","深灰","黄  ","白  " };
/*
	1 - BLUE 兰1
	2 - GREEN 绿2
	3 - CYAN 青3
	4 - RED 红4
	5 - MAGENTA 洋红5
	8 - DARKGRAY 深灰6
	14 - YELLOW 黄7
	15 - WHITE 白8
*/

void draw(int direction);
void drawattributes(int key);

int main()
{
	printf("开始之前右击窗口左上角，属性——布局——调整大小时对输出的文本换行——取消勾选\n");
	printf("注意：在光标到达窗口边界之前调整窗口大小防止出现问题\n");
	printf("按下#、@、*、%对应的数字按键切换画笔，按下“0”切换为橡皮,按下空格键抬起\\放下画笔\n");
	printf("颜色对应的按键：B-兰 G-绿 C-青 R-红 M-洋红 D-深灰 Y-黄 W-白\n");
	printf("按下回车键开始\n");
	system("title 开始你的绘画吧!");
	if (_getch() != 13)
		exit(1);
	system("cls");
	while (true)
	{
		draw(_getch());
	}
}

void draw(int key)
{
	switch (key) {
	case 72:
		//上
		if (y - 1 <= 0)
			break;
		MoveCursor(x, y - 1);
		if (pen != 5)
			printf("%c", PenType[pen]);
		y--;
		break;
	case 80:
		//下
		MoveCursor(x, y + 1);
		if (pen != 5)
			printf("%c", PenType[pen]);
		y++;
		break;
	case 75:
		//左
		if (x - 1 <= 0)
			break;
		MoveCursor(x - 1, y);
		if (pen != 5)
			printf("%c", PenType[pen]);
		x--;
		break;
	case 77:
		//右
		MoveCursor(x + 1, y);
		if (pen != 5)
			printf("%c", PenType[pen]);
		x++;
		break;
	default:
		drawattributes(key);
		break;
	}
}

void drawattributes(int key)
{
	switch (key)
	{
		//兰
	case 98:
	case 66:
		SetFontColor(1);
		color = 0;
		break;
		//绿
	case 103:
	case 71:
		SetFontColor(2);
		color = 1;
		break;
		//青
	case 99:
	case 67:
		SetFontColor(3);
		color = 2;
		break;
		//红
	case 114:
	case 72:
		SetFontColor(4);
		color = 3;
		break;
		//洋红
	case 109:
	case 77:
		SetFontColor(5);
		color = 4;
		break;
		//深灰
	case 100:
	case 68:
		SetFontColor(8);
		color = 5;
		break;
		//黄
	case 121:
	case 89:
		SetFontColor(14);
		color = 6;
		break;
		//白
	case 119:
	case 87:
		SetFontColor(15);
		color = 7;
		break;
		//抬起/放下画笔
	case 32:
		up++;
		if (up >= 2)
			up -= 2;
		if (up == 1)
		{
			system("title 画笔类型：抬起");
			historypen = pen;
			pen = 5;
		}
		else if (up == 0)
			pen = historypen;
		break;
		//切换画笔
	case 51:
		pen = 0;
		break;
	case 50:
		pen = 1;
		break;
	case 53:
		pen = 3;
		break;
	case 56:
		pen = 2;
		break;
	case 48:
		pen = 4;
		break;
	default:
		break;
	}
	//刷新画笔类型
	switch (pen)
	{
	case 0:
		system("title 画笔类型：#");
		break;
	case 1:
		system("title 画笔类型：@");
		break;
	case 2:
		system("title 画笔类型：*");
		break;
	case 3:
		system("title 画笔类型：%");
		break;
	case 4:
		system("title 画笔类型：橡皮");
		break;
	}
	MoveCursor(0, 0);
	cout << "画笔颜色：" << ColorType[color];
	MoveCursor(x, y);
}
