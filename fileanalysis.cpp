#include <iostream>
#include <fstream>
#include <vector>
#define FILE_SAVE _declspec(dllexport)
using namespace std;

extern "C"
{
	FILE_SAVE void SaveProject(char* ProjectName, vector<char>vecccanvas);
}

void SaveProject(char *ProjectName, vector<char>veccanvas)
{
	/*
	���Σ�
	ProjectNameint����������
	veccanvas����������
	*/
	ofstream project;
	project.open(ProjectName); //���ļ�
	for (int i = 0; i < veccanvas.size(); i++)
		project << veccanvas[i];
	project.close();
}