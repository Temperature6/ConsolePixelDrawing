#include <iostream>
#include <fstream>
#include <vector>
#define FILE_SAVE _declspec(dllexport)
#define FILE_READ _declspec(dllexport)
using namespace std;

extern "C"
{
	FILE_SAVE void SaveProject(char* ProjectName, vector<char>vecccanvas);
	FILE_READ void ReadProject(char temparr[], char* path);
}

void SaveProject(char *ProjectName, vector<char>veccanvas)
{
	/*
	���Σ�
	ProjectNameint����������
	veccanvas����������
	*/
	char str_x[4];
	char str_y[4];
	ofstream project;
	project.open(ProjectName); //���ļ�
	for (int i = 0; i < veccanvas.size(); i++)
		project << veccanvas[i];
	/*sprintf_s(str_x, "%d", xmax);
	sprintf_s(str_y, "%d", ymax);
	project << "<" << str_x << "," << str_y << ">";*/
	project.close();
}

void ReadProject(char temparr[], char* path)
{
	ifstream file;
	file.open(path);
	file >> temparr;
	return;
}