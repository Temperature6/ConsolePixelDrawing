/*
2020/10/06 19:43-�������̲���ɵ�һ���汾
2020/10/07 13:25-��ӿո�̧�ʵĹ���
2020/10/07 21:54-�޸���ɫ����ʾ��Ϣ��ȫ��Bug
2020/11/01 10:05-�����л����ʵķ�ʽ���������»���
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
vector <string> ColorType = { "��  ","��  ","��  ","��  ","���","���","��  ","��  " };
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
	printf("����#��@��*��%��Ӧ�����ְ����л����ʣ����¡�0���л�Ϊ��Ƥ,���¿ո��̧��\\���»���\n");
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
			pen = historypen;
		break;
		//�л�����
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
	//ˢ�»�������
	switch (pen)
	{
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
		system("title �������ͣ�%");
		break;
	case 4:
		system("title �������ͣ���Ƥ");
		break;
	}
	MoveCursor(0, 0);
	cout << "������ɫ��" << ColorType[color];
	MoveCursor(x, y);
}
