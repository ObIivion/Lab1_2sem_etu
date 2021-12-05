#pragma once
#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>
#include<ctime>
#include"enter.h"

using namespace std;
typedef struct Students
{
	string full_name; // ������� ��� ��������
	char sex;         // ���: M/W
	int group;        // ����� ������
	int id;           // ����� �������� � ������ 
	int grades[8];    // ������ �� �������� � ���. ������
	string depart;   // ����� ��������
	string date;      // ���� �������� ��������� � ������ (post/update) 
}Students;

void PrintStudent(Students * st);
void SetStudent();
bool ChangeStudent(vector<Students> * st);
bool ChangeStudentMenu(Students * st);
void ReadFromFile(vector<Students> * st);