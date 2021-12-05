#define _CRT_SECURE_NO_WARNINGS
#include "students.h"

enum menu {
	EXIT,
	NAME,
	SEX,
	GROUP,
	NUM,
	GRADES,
	DEPART
};

void PrintStudent(Students * st)
{
	cout << "���: " << st->full_name << endl
		<< " ���: " << st->sex << endl
		<< " ����� ������: " << st->group << endl
		<< " ����� � ������: " << st->id << endl
		<< " ������ �� ��������: ";
	for (int i = 0; i < 8; ++i) {
		cout << st->grades[i] << " ";
	}
	cout << endl
		<< " ����� ��������: " << st->depart << endl
		<< " ���� �������� ���������: " << st->date << endl << endl;
}

void SetStudent()
{
	Students st;
	struct tm * timeinfo;
	time_t tstamp;
	string buf = "",
		text = "";

	cout << "������� ��� ��������: " << endl;
	while (InputText(buf)) {
		text += buf + " ";
	}
	st.full_name = text;
	cout << "������� ��� �������� (M/W): " << endl;
	input(st.sex);
	cout << "������� ������ ��������: " << endl;
	input(st.group);
	cout << "������� ����� �������� � ������: " << endl;
	input(st.id);
	cout << "������� ������ �������� �� ������: " << endl;
	for (int i = 0; i < 8; ++i) {
		cin >> st.grades[i];
	}
	cout << "������� ����� �������� (day/evening): " << endl;
	input(st.depart);

	time(&tstamp);
	timeinfo = localtime(&tstamp);
	st.date = asctime(timeinfo);

	bool tmp = true;
	for (int i = 0; i < 8; i++) {
		if (st.grades[i] == 2)
			tmp = false;
	}
	if (tmp) {
		ofstream file("student.txt", ios_base::app);
		if (file.is_open()) {
			file.setf(ios::left);

			file << st.full_name << '\n'
				<< st.group << '\n'
				<< st.id << '\n'
				<< st.sex << '\n'
				<< st.depart << '\n';
			for (int i = 0; i < 8; i++) {
				file << st.grades[i];
				if (i != 7) {
					file << " ";
				}
			}		
			file << '\n' << st.date << '\n';

			cout << "���������� ���������" << endl;
		}
		else {
			cout << "�� ������� ������� ����" << endl;
		}

		file.close();
	}
	else {
		cout << "������ ������� ������ ���� ��������. ���������� � ��� �� ����� ���������." << endl;
		system("pause");
	}
}

bool ChangeStudent(vector<Students>* st)
{
	bool isEmpty = true,
		isChange = false;
	string name = "",
		buf = "";
	struct tm * timeinfo;
	time_t tstamp;

	cout << "������� ��� ��������:" << endl;
	while (InputText(buf)) {
		name += buf + " ";
	}
	
	
	int size = (*st).size();
	for (int i = 0; i < size; ++i) {
		if ((*st)[i].full_name.find(name) != string::npos) {
			isEmpty = false;
			isChange = ChangeStudentMenu(&(*st)[i]);
			if (isChange) {
				time(&tstamp);
				timeinfo = localtime(&tstamp);
				(*st)[i].date = asctime(timeinfo);
			}
			break;
		}
	}
	if (isEmpty) {
		cout << "����� ������� �� ������" << endl;
		return false;
	}
	else return isChange;
}

bool ChangeStudentMenu(Students * st)
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;
	bool isChange = false;
	do
	{
		system("cls");
		cout << "��������:" << endl
			<< "1 - ���" << endl
			<< "2 - ���" << endl
			<< "3 - ����� ������" << endl
			<< "4 - ����� � ������" << endl
			<< "5 - ������" << endl
			<< "6 - ����� ��������" << endl
			<< "0 - �����" << endl;

		input(userChoice);
		
		switch (userChoice)
		{
		case NAME: {
			cout << "������ ��������: " << st->full_name << endl
				<< "����� ��������: ";
			cin >> st->full_name;
			cout << endl;
			isChange |= true;
			break;
		}
		case SEX: {
			cout << "������ ��������: " << st->sex << endl
				<< "����� ��������: ";
			input(st->sex);
			cout << endl;
			isChange |= true;
			break;
		}
		case GROUP: {
			cout << "������ ��������: " << st->group << endl
				<< "����� ��������: ";
			input(st->group);
			cout << endl;
			isChange |= true;
			break;
		}
		case NUM: {
			cout << "������ ��������: " << st->id << endl
				<< "����� ��������: ";
			input(st->id);
			cout << endl;
			isChange |= true;
			break;
		}
		case GRADES: {
			cout << "������ ��������: ";
			for (int i = 0; i < 8; ++i) {
				cout << st->grades[i] << " ";
			}
			cout << "����� ��������: ";
			for (int i = 0; i < 8; ++i) {
				cin >> st->grades[i];
			}
			cout << endl;
			isChange |= true;
			break;
		}
		case DEPART: {
			cout << "������ ��������: " << st->depart << endl
				<< "����� ��������: ";
			input(st->depart);
			cout << endl;
			isChange |= true;
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

	return isChange;
}

void ReadFromFile(vector<Students>* st)
{
	ifstream file("student.txt");
	Students tmpSt;

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, tmpSt.full_name);
			if (tmpSt.full_name != "") {
				file >> tmpSt.group
					>> tmpSt.id
					>> tmpSt.sex
					>> tmpSt.depart;
				for (int i = 0; i < 8; ++i) {
					file >> tmpSt.grades[i];
				}
				getline(file, tmpSt.date);
				getline(file, tmpSt.date);
				st->push_back(tmpSt);
			}
		}
		
	}
	else {
		cout << "�� ������� ������� ����" << endl;
	}

	file.close();
}
