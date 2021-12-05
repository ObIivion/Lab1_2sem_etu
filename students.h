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
	string full_name; // Фамилия Имя Отчество
	char sex;         // Пол: M/W
	int group;        // Номер группы
	int id;           // Номер студента в списке 
	int grades[8];    // Оценки за экзамены и диф. зачёты
	string depart;   // Форма обучения
	string date;      // Дата внесения изменнеия в запись (post/update) 
}Students;

void PrintStudent(Students * st);
void SetStudent();
bool ChangeStudent(vector<Students> * st);
bool ChangeStudentMenu(Students * st);
void ReadFromFile(vector<Students> * st);