//2020/10/6 19:43
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "BetterPrint.h"
using namespace std;

int x = 1, y = 1;
int pen = 0, historypen = 0, up = 0;
int color = 7;
char PenType[4] = { '#', '@', '*', ' ' };
vector <string> ColorType = { "��","��","��","��","���","���","��","��" };
/*
	1 - BLUE ��1
	2 - GREEN ��2
	3 - CYAN ��3
	4 - RED ��4
	5 - MAGENTA ���5
	8 - DARKGRAY ���6
	14 - YELLOW ��7
	15 - WHITE ��8
*/

void draw(int direction);
void drawattributes(int key);

int main()
{
	printf("��ʼ֮ǰ�һ��������Ͻǣ����ԡ������֡���������Сʱ��������ı����С���ȡ����ѡ\n");
	printf("ע�⣺�ڹ�굽�ﴰ�ڱ߽�֮ǰ�������ڴ�С��ֹ��������\n");
	printf("���¡�P���л�����ģʽ,���¿ո��̧��\\���»���\n");
	printf("��ɫ��Ӧ�İ�����B-�� G-�� C-�� R-�� M-��� D-��� Y-�� W-��\n");
	printf("���»س�����ʼ\n");
	system("title ��ʼ��Ļ滭��!");
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
		//��
		if (y - 1 <= 0)
			break;
		MoveCursor(x, y - 1);
		if (pen != 5)
			printf("%c", PenType[pen]);
		y--;
		break;
	case 80:
		//��
		MoveCursor(x, y + 1);
		if (pen != 5)
			printf("%c", PenType[pen]);
		y++;
		break;
	case 75:
		//��
		if (x - 1 <= 0)
			break;
		MoveCursor(x - 1, y);
		if (pen != 5)
			printf("%c", PenType[pen]);
		x--;
		break;
	case 77:
		//��
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
		//��
		case 98:
		case 66:
			SetFontColor(1);
			color = 0;
			break;
		//��
		case 103:
		case 71:
			SetFontColor(2);
			color = 1;
			break;
		//��
		case 99:
		case 67:
			SetFontColor(3);
			color = 2;
			break;
		//��
		case 114:
		case 72:
			SetFontColor(4);
			color = 3;
			break;
		//���
		case 109:
		case 77:
			SetFontColor(5);
			color = 4;
			break;
		//���
		case 100:
		case 68:
			SetFontColor(8);
			color = 5;
			break;
		//��
		case 121:
		case 89:
			SetFontColor(14);
			color = 6;
			break;
		//��
		case 119:
		case 87:
			SetFontColor(15);
			color = 7;
			break;
		//̧��/���»���
		case 32:
			up++;
			if (up >= 2)
				up -= 2;
			if (up == 1)
			{
				system("title �������ͣ�̧��");
				historypen = pen;
				pen = 5;
			}
			else if (up == 0)
				pen = historypen - 1;
		//�л�����
		case 112:
		case 80:
			pen++;
			switch (pen)
			{
			case 4:
				pen -= 4;
			case 0:
				system("title �������ͣ�#");
				break;
			case 1:
				system("title �������ͣ�@");
				break;
			case 2:
				system("title �������ͣ�*");
				break;
			case 3:
				system("title �������ͣ���Ƥ");
				break;
			}
		default:
			break;
	}
	MoveCursor(0, 0);
	cout << "������ɫ��" << ColorType[color];
	MoveCursor(x, y);
}