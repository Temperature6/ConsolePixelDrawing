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
	传参：
	ProjectNameint：工程名字
	veccanvas：画布向量
	*/
	ofstream project;
	project.open(ProjectName); //打开文件
	for (int i = 0; i < veccanvas.size(); i++)
		project << veccanvas[i];
	project.close();
}

void ReadProject(char temparr[], char* path)
{
	ifstream file;
	file.open(path);
	file >> temparr;
	return;
}