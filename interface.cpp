#include "interface.h"
#include<iostream>
#include<locale.h>
#include"enter.h"
#include"students.h"
#include<vector>
#include"foutput.h"

using namespace std;

//именнованный массив для выбора пункта меню
enum menu {
	EXIT,
	ENTER,
	PRINT
};
//именнованный массив для выбора пункта подменю
enum taskmenu {
	RETURN,
	CHANGE,
	ALL,
	GROUP,
	TOP,
	SEX,
	SCHOLAR,
	NOSCHOLAR,
	NUMS,
	INDAY
};

//функция для вывода и взаимодействия с меню
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "Лабораторная работа №1" << endl
			<< "1 - Добавить студента" << endl
			<< "2 - Просмотреть записи" << endl
			<< "0 - Выход" << endl;

		input(userChoice);

		switch (userChoice)
		{
		case ENTER: {
			system("cls");
			SetStudent();
			break;
		}
		case PRINT: {
			system("cls");
			MenuTask();
			break;
		}
		case EXIT: break;
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//функция для вывода и взимоействия с пунктами подменю
void MenuTask()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	bool flagIsGhange = false;

	vector<Students> * st = new vector<Students>;
	ReadFromFile(st);

	do
	{
		system("cls");
		cout << "1 - Изменить запись" << endl
			<< "2 - Вывести всех студентов" << endl
			<< "3 - Вывести студентов группы N" << endl
			<< "4 - ТОП-3 студентов" << endl
			<< "5 - Количество студентов женского и мужского пола" << endl
			<< "6 - Стипендиаты (очная ф.о. и без троек)" << endl
			<< "7 - Студенты без стипендии; отличники; хорошисты" << endl
			<< "8 - Студент под номером k в группе" << endl
			<< "9 - Записи в конкретный день; до полудня; после полудня" << endl
			<< "0 - Назад" << endl;
		input(userChoice);
		
		switch (userChoice)
		{
			
		case CHANGE: {
			flagIsGhange |=	ChangeStudent(st);
			break;
		}
					 
		case ALL: {
			PrintAll(st);
			system("pause");
			break;
		}
		case GROUP: {
			PrintGroup(st);
			system("pause");
			break;
		}
		case TOP: {
			PrintTOP(st);
			system("pause");
			break;
		}
		case SEX: {
			PrintCountInSex(st);
			system("pause");
			break;
		}
		case SCHOLAR: {
			PrintScholar(st);
			system("pause");
			break;
		}
		case NOSCHOLAR: {
			PrintNoScholarAB(st);
			system("pause");
			break;
		}
		case NUMS: {
			PrintNumS(st);
			system("pause");
			break;
		}
		case INDAY: {
			PrintInDay(st);
			system("pause");
			break;
		}
		//вернуться в главное меню
		case RETURN: {
			userChoice = 0;
			break;
		}
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}
	} while (userChoice != RETURN);

	if (flagIsGhange) {
		ofstream file("student.txt", ios_base::out | ios_base::trunc);
		if (file.is_open()) {
			file.setf(ios::left);
			int size = (*st).size();
			for (int i = 0; i < size; ++i) {
				file << (*st)[i].full_name << '\n'
					<< (*st)[i].group << '\n'
					<< (*st)[i].id << '\n'
					<< (*st)[i].sex << '\n'
					<< (*st)[i].depart << '\n';
				for (int j = 0; j < 8; j++)
					file << (*st)[i].grades[j] << " ";
				file << '\n' << (*st)[i].date;
			}
		}
		else {
			cout << "Не удалось внести изменения в файл" << endl;
			system("pause");
		}
		file.close();
	}
}