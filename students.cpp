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
	cout << "ФИО: " << st->full_name << endl
		<< " Пол: " << st->sex << endl
		<< " Номер группы: " << st->group << endl
		<< " Номер в списке: " << st->id << endl
		<< " Оценки за экзамены: ";
	for (int i = 0; i < 8; ++i) {
		cout << st->grades[i] << " ";
	}
	cout << endl
		<< " Форма обучения: " << st->depart << endl
		<< " Дата внесения изменений: " << st->date << endl << endl;
}

void SetStudent()
{
	Students st;
	struct tm * timeinfo;
	time_t tstamp;
	string buf = "",
		text = "";

	cout << "Введите ФИО студента: " << endl;
	while (InputText(buf)) {
		text += buf + " ";
	}
	st.full_name = text;
	cout << "Введите пол студента (M/W): " << endl;
	input(st.sex);
	cout << "Введите группу студента: " << endl;
	input(st.group);
	cout << "Введите номер студента в группе: " << endl;
	input(st.id);
	cout << "Введите оценки студента за сессию: " << endl;
	for (int i = 0; i < 8; ++i) {
		cin >> st.grades[i];
	}
	cout << "Введите форму обучения (day/evening): " << endl;
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

			cout << "Сохранение завершено" << endl;
		}
		else {
			cout << "Не удалось открыть файл" << endl;
		}

		file.close();
	}
	else {
		cout << "Данный студент должен быть отчислен. Информация о нем не будет сохранена." << endl;
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

	cout << "Введите ФИО студента:" << endl;
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
		cout << "Такой студент не найден" << endl;
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
		cout << "Изменить:" << endl
			<< "1 - ФИО" << endl
			<< "2 - Пол" << endl
			<< "3 - Номер группы" << endl
			<< "4 - Номер в списке" << endl
			<< "5 - Оценки" << endl
			<< "6 - Форма обучения" << endl
			<< "0 - Выход" << endl;

		input(userChoice);
		
		switch (userChoice)
		{
		case NAME: {
			cout << "Старое значение: " << st->full_name << endl
				<< "Новое значение: ";
			cin >> st->full_name;
			cout << endl;
			isChange |= true;
			break;
		}
		case SEX: {
			cout << "Старое значение: " << st->sex << endl
				<< "Новое значение: ";
			input(st->sex);
			cout << endl;
			isChange |= true;
			break;
		}
		case GROUP: {
			cout << "Старое значение: " << st->group << endl
				<< "Новое значение: ";
			input(st->group);
			cout << endl;
			isChange |= true;
			break;
		}
		case NUM: {
			cout << "Старое значение: " << st->id << endl
				<< "Новое значение: ";
			input(st->id);
			cout << endl;
			isChange |= true;
			break;
		}
		case GRADES: {
			cout << "Старое значение: ";
			for (int i = 0; i < 8; ++i) {
				cout << st->grades[i] << " ";
			}
			cout << "Новое значение: ";
			for (int i = 0; i < 8; ++i) {
				cin >> st->grades[i];
			}
			cout << endl;
			isChange |= true;
			break;
		}
		case DEPART: {
			cout << "Старое значение: " << st->depart << endl
				<< "Новое значение: ";
			input(st->depart);
			cout << endl;
			isChange |= true;
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
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();
}
