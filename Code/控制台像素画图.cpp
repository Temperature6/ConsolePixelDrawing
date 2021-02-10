/*
2020/10/06 19:43-�������̲���ɵ�һ���汾
2020/10/07 13:25-��ӿո�̧�ʵĹ���
2020/10/07 21:54-�޸���ɫ����ʾ��Ϣ��ȫ��Bug
2020/11/01 12:05-�����л����ʵķ�ʽ���������»���
2020/12/13 13:07-�޸����޷������򿪵�Bug
2021/01/02 12:39-����˰�s�����滭ͼ���̵Ĺ��ܣ������ˡ�fileanalysis.dll�����ڱ��滭ͼ����
2021/01/02 12:58-����˻�����Χ
2021/02/08 20:48-�޸���֮ǰ�����޷����������
2021/02/09 21:30-�����˺ܶ�ܶ�
2021/02/10 17:30-�޸��˺ܶ�ܶ�BUG
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
int xMax = 1, yMax = 1; //ȷ�����ʻ��������Χ
char pen = '#', historypen, up = 0;
int color = 7;
bool normal = true; //�Ƿ�Ϊ��������

char canvas[YMAX][XMAX]; //����
int canvascolor[YMAX][XMAX]; //������ɫ
char temparr[YMAX * XMAX * 2];
char path[100]; //·��
//��ȡ�ļ��󴢴����ʱ����
char t_canvas[YMAX * XMAX];
char t_canvascolor[YMAX * XMAX];

//char PenType[5] = { '#', '@', '*', '%', ' ' };
vector <string> ColorType = { "��  ","��  ","��  ","��  ","���","���","��  ","��  " };
char name[60] = "draw.txt";
char suffix[10] = ".cpd"; //��׺��

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
void Save();
void InputName();

int main(int argc, char* argv[])
{
	if (testload() == 0)
	{
		system("title ����");
		printf("\n�����޷����ء�fileanalysis.dll��\n���顰fileanalysis.dll���Ƿ����ִ���ļ�λ��ͬһ�ļ�����\n\n");
		system("pause");
		exit(1);
	}
START:
	int pos = 2; //*2����Ƕ�Ӧ��y������
	//�����е���(argc>1)
	if (argc > 1)
	{
		cout << argv[1];
		normal = false;
		if (strcmp(argv[1],"/n") == 0) //�½�����
			pos = 2;
		else if (strcmp(argv[1], "/f") == 0) //�򿪻���
			pos = 3;
		else if (strcmp(argv[1], "/h") == 0) //����
			pos = 4;
		else if (strcmp(argv[1], "/g") == 0) //Github�ֿ�
			pos = 5;
	}
	//��������(argc=1)
	else if (argc == 1)
	{
	system("cls");
	system("title ��ӭʹ��");
	printf("\nʹ�� �� �� ��ѡ����������»س�ȷ��");
	printf("\n\n\n\t\t�½�����\n\n\t\t�򿪻����ļ�\n\n\t\t����˵��\n\n\t\t��GitHub�ֿ�\n\n\t\t�˳�");
	MoveCursor(14, 4);
	SetFontColor(4);
	printf(">");
	bool run = true;
	while (run)
	{
		switch (_getch())
		{
		case 72: // ��
			//����ϴ�
			MoveCursor(14, pos * 2);
			printf(" ");
			pos--;
			if (pos < 2)
				pos = 6;
			MoveCursor(14, pos * 2);
			printf(">");
			break;
		case 80: // ��
			//����ϴ�
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

	//����ѡ��ִ�в���
	if (pos == 2)
	{ //�½�����
		InputName();
		strcat_s(name, suffix);
		system("cls");
		while (true)
		{
			draw(_getch());
		}
	}
	else if (pos == 3)
	{ //�򿪻����ļ�

		system("cls");
		if (normal)
		{
			printf("\n���뻭���ļ������·�������·��\n(·���в��ܺ��пո��Ƿ��ַ����ļ��϶�������):");
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
	{ //����˵��
		system("cls");
		printf("��ʼ֮ǰ�һ��������Ͻǣ����ԡ������֡���������Сʱ��������ı����С���ȡ����ѡ\n\n");
		printf("ע�⣺�ڹ�굽�ﴰ�ڱ߽�֮ǰ�������ڴ�С��ֹ��������\n\n");
		printf("����#��@��*��%��Ӧ�����ְ����л����ʣ����¡�s�������棬���¡�0���л�Ϊ��Ƥ,���¿ո��̧��\\���»���\n\n");
		printf("��ɫ��Ӧ�İ�����B-�� G-�� C-�� R-�� M-��� D-��� Y-�� W-��\n\n");
		system("pause");
		goto START;
	}
	else if (pos == 5)
	{ //��GitHub�ֿ�
		system("cls");
		system("start https://github.com/Temperature6/ConsolePixelDrawing");
		printf("\nGitHub�ֿ��ַ��https://github.com/Temperature6/ConsolePixelDrawing \n\n");
		system("pause");
		goto START;
	}
	else if (pos == 6)
	{ //�˳�
		exit(1);
	}
}

void draw(int key)
{
	switch (key) {
	case 72:
		//��
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
		//��
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
		//��
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
		//��
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
			system("title �������ͣ�̧��"); //̧����/
			historypen = pen;
			pen = '/';
		}
		else if (up == 0)
			pen = historypen;
		break;
	//�л�����
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
	//���滭ͼ����
	case 83:
	case 115:
		system("title ���ڱ��滭ͼ����...");
		Save();
		system("title ����ɹ�");
		Sleep(1000);
	default:
		break;
	}
	//ˢ�»�������
	switch (pen)
	{
	
	case '#':
		system("title �������ͣ�#");
		break;
	case '@':
		system("title �������ͣ�@");
		break;
	case '*':
		system("title �������ͣ�*");
		break;
	case '%':
		system("title �������ͣ�%");
		break;
	case ' ':
		system("title �������ͣ���Ƥ");
		break;
	}
	MoveCursor(0, 0);
	cout << "������ɫ��" << ColorType[color];
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
	printf("\n�����뻭��������(50���ַ�����):");
	cin >> name;
}