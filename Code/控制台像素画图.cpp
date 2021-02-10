/*
2020/10/06 19:43-创建工程并完成第一个版本
2020/10/07 13:25-添加空格抬笔的功能
2020/10/07 21:54-修复颜色栏显示信息不全的Bug
2020/11/01 12:05-更改切换画笔的方式，增添了新画笔
2020/12/13 13:07-修复了无法正常打开的Bug
2021/01/02 12:39-添加了按s键保存画图工程的功能，增加了“fileanalysis.dll”用于保存画图工程
2021/01/02 12:58-添加了画布范围
2021/02/08 20:48-修复了之前画作无法保存的问题
2021/02/09 21:30-更改了很多很多
2021/02/10 17:30-修复了很多很多BUG
*/
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include "BetterPrint.h"
#include "function.h"

#define XMAX 200
#define YMAX 200

using namespace std;

int x = 1, y = 1;
int xMax = 1, yMax = 1; //确定画笔画到的最大范围
char pen = '#', historypen, up = 0;
int color = 7;
bool normal = true; //是否为正常进入

char canvas[YMAX][XMAX]; //画布
int canvascolor[YMAX][XMAX]; //像素颜色
char temparr[YMAX * XMAX * 2];
char path[100]; //路径
//读取文件后储存的临时数组
char t_canvas[YMAX * XMAX];
char t_canvascolor[YMAX * XMAX];

//char PenType[5] = { '#', '@', '*', '%', ' ' };
vector <string> ColorType = { "兰  ","绿  ","青  ","红  ","洋红","深灰","黄  ","白  " };
char name[60] = "draw.txt";
char suffix[10] = ".cpd"; //后缀名

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
void Save();
void InputName();

int main(int argc, char* argv[])
{
	if (testload() == 0)
	{
		system("title 错误");
		printf("\n我们无法加载“fileanalysis.dll”\n请检查“fileanalysis.dll”是否与可执行文件位于同一文件夹中\n\n");
		system("pause");
		exit(1);
	}
START:
	int pos = 2; //*2后才是对应的y轴坐标
	//命令行调用(argc>1)
	if (argc > 1)
	{
		cout << argv[1];
		normal = false;
		if (strcmp(argv[1],"/n") == 0) //新建画布
			pos = 2;
		else if (strcmp(argv[1], "/f") == 0) //打开画布
			pos = 3;
		else if (strcmp(argv[1], "/h") == 0) //帮助
			pos = 4;
		else if (strcmp(argv[1], "/g") == 0) //Github仓库
			pos = 5;
	}
	//正常进入(argc=1)
	else if (argc == 1)
	{
	system("cls");
	system("title 欢迎使用");
	printf("\n使用 ↑ ↓ 键选择操作，按下回车确定");
	printf("\n\n\n\t\t新建画布\n\n\t\t打开画布文件\n\n\t\t操作说明\n\n\t\t打开GitHub仓库\n\n\t\t退出");
	MoveCursor(14, 4);
	SetFontColor(4);
	printf(">");
	bool run = true;
	while (run)
	{
		switch (_getch())
		{
		case 72: // 上
			//清空上次
			MoveCursor(14, pos * 2);
			printf(" ");
			pos--;
			if (pos < 2)
				pos = 6;
			MoveCursor(14, pos * 2);
			printf(">");
			break;
		case 80: // 下
			//清空上次
			MoveCursor(14, pos * 2);
			printf(" ");
			pos++;
			if (pos > 6)
				pos = 2;
			MoveCursor(14, pos * 2);
			printf(">");
			break;
		case 13:
			run = false;
			break;
		default:
			break;
		}
	}
	SetFontColor(15);
	}

	//根据选择执行操作
	if (pos == 2)
	{ //新建画布
		InputName();
		strcat_s(name, suffix);
		system("cls");
		while (true)
		{
			draw(_getch());
		}
	}
	else if (pos == 3)
	{ //打开画布文件

		system("cls");
		if (normal)
		{
			printf("\n输入画作文件的相对路径或绝对路径\n(路径中不能含有空格或非法字符或将文件拖动到这里):");
			cin >> path;
			ReadProject(temparr, path);
		}
		else
		{
			if (argv[2][0] == '/')
				deleteslash(argv[2]);
			ReadProject(temparr, argv[2]);
		}
		getname(path, name);

		int n = 0;
		int m = 0;
		while (temparr[n] != '\\')
		{
			t_canvas[n] = temparr[n];
			n++;
		}
		n++;
		while (temparr[n] != '\0')
		{
			t_canvascolor[m] = temparr[n];
			n++; m++;
		}
		PrintPic(t_canvas, t_canvascolor);
		SetFontColor(15);
		MoveCursor(1, 2);

		while (true)
		{
			draw(_getch());
		}
	}
	else if (pos == 4)
	{ //操作说明
		system("cls");
		printf("开始之前右击窗口左上角，属性——布局——调整大小时对输出的文本换行——取消勾选\n\n");
		printf("注意：在光标到达窗口边界之前调整窗口大小防止出现问题\n\n");
		printf("按下#、@、*、%对应的数字按键切换画笔，按下“s”键保存，按下“0”切换为橡皮,按下空格键抬起\\放下画笔\n\n");
		printf("颜色对应的按键：B-兰 G-绿 C-青 R-红 M-洋红 D-深灰 Y-黄 W-白\n\n");
		system("pause");
		goto START;
	}
	else if (pos == 5)
	{ //打开GitHub仓库
		system("cls");
		system("start https://github.com/Temperature6/ConsolePixelDrawing");
		printf("\nGitHub仓库地址：https://github.com/Temperature6/ConsolePixelDrawing \n\n");
		system("pause");
		goto START;
	}
	else if (pos == 6)
	{ //退出
		exit(1);
	}
}

void draw(int key)
{
	switch (key) {
	case 72:
		//上
		if (y - 1 <= 1)
			break;
		MoveCursor(x, y - 1);
		if (pen != '/')
		{
			printf("%c", pen);
			canvas[y - 1][x] = pen;
			if (pen != ' ')
				canvascolor[y - 1][x] = color;
		}
		y--;
		break;
	case 80:
		//下
		if (y + 1 > 100)
			break;
		MoveCursor(x, y + 1);
		if (pen != '/')
		{
			printf("%c", pen);
			canvas[y + 1][x] = pen;
			if (pen != ' ')
				canvascolor[y + 1][x] = color;
			if (y > yMax)
				yMax = y;
		}
		y++;
		break;
	case 75:
		//左
		if (x - 1 <= 0)
			break;
		MoveCursor(x - 1, y);
		if (pen != '/')
		{
			printf("%c", pen);
			canvas[y][x - 1] = pen;
			if (pen != ' ')
				canvascolor[y][x - 1] = color;
		}
		x--;
		break;
	case 77:
		//右
		if (x + 1 > 100)
			break;
		MoveCursor(x + 1, y);
		if (pen != '/')
		{
			printf("%c", pen);
			canvas[y][x + 1] = pen;
			if (pen != ' ')
				canvascolor[y][x + 1] = color;
			if (x > xMax)
				xMax = x;
		}
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
			system("title 画笔类型：抬起"); //抬起用/
			historypen = pen;
			pen = '/';
		}
		else if (up == 0)
			pen = historypen;
		break;
	//切换画笔
	case 51:
		pen = '#';
		break;
	case 50:
		pen = '@';
		break;
	case 53:
		pen = '%';
		break;
	case 56:
		pen = '*';
		break;
	case 48:
		pen = ' ';
		break;
	//保存画图工程
	case 83:
	case 115:
		system("title 正在保存画图工程...");
		Save();
		system("title 保存成功");
		Sleep(1000);
	default:
		break;
	}
	//刷新画笔类型
	switch (pen)
	{
	
	case '#':
		system("title 画笔类型：#");
		break;
	case '@':
		system("title 画笔类型：@");
		break;
	case '*':
		system("title 画笔类型：*");
		break;
	case '%':
		system("title 画笔类型：%");
		break;
	case ' ':
		system("title 画笔类型：橡皮");
		break;
	}
	MoveCursor(0, 0);
	cout << "画笔颜色：" << ColorType[color];
	MoveCursor(x, y);
}

void Save()
{
	vector <char> tempvec;
	for (int i = 0; i < yMax + 2; i++)
	{
		for (int j = 0; j < xMax + 2; j++)
			tempvec.push_back(canvas[i][j]);
		tempvec.push_back('/');
	}
	for (int k = 0; k < tempvec.size(); k++)
	{
		if (tempvec[k] == '\0')
			tempvec[k] = '_';
		if (tempvec[k] == ' ')
			tempvec[k] = '_';
	}

	tempvec.push_back('\\');
	for (int i = 0; i < yMax + 2; i++)
	{
		for (int j = 0; j < xMax + 2; j++)
			tempvec.push_back(intTochar(canvascolor[i][j]));
		tempvec.push_back('/');
	}
	tempvec.push_back('<');
	SaveProject(name, tempvec);
}

void InputName()
{
	system("cls");
	printf("\n请输入画作的名称(50个字符以内):");
	cin >> name;
}