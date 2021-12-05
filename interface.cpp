#include "interface.h"
#include<iostream>
#include<locale.h>
#include"enter.h"
#include"students.h"
#include<vector>
#include"foutput.h"

using namespace std;

//������������ ������ ��� ������ ������ ����
enum menu {
	EXIT,
	ENTER,
	PRINT
};
//������������ ������ ��� ������ ������ �������
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

//������� ��� ������ � �������������� � ����
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "������������ ������ �1" << endl
			<< "1 - �������� ��������" << endl
			<< "2 - ����������� ������" << endl
			<< "0 - �����" << endl;

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
			cout << "������� ���������� ��������!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//������� ��� ������ � ������������ � �������� �������
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
		cout << "1 - �������� ������" << endl
			<< "2 - ������� ���� ���������" << endl
			<< "3 - ������� ��������� ������ N" << endl
			<< "4 - ���-3 ���������" << endl
			<< "5 - ���������� ��������� �������� � �������� ����" << endl
			<< "6 - ����������� (����� �.�. � ��� �����)" << endl
			<< "7 - �������� ��� ���������; ���������; ���������" << endl
			<< "8 - ������� ��� ������� k � ������" << endl
			<< "9 - ������ � ���������� ����; �� �������; ����� �������" << endl
			<< "0 - �����" << endl;
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
		//��������� � ������� ����
		case RETURN: {
			userChoice = 0;
			break;
		}
		default: {
			cout << "������� ���������� ��������!" << endl;
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
			cout << "�� ������� ������ ��������� � ����" << endl;
			system("pause");
		}
		file.close();
	}
}