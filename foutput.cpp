#include "foutput.h"

using namespace std;

void PrintAll(vector<Students> * st)
{
	cout << "��� �������� � �����:" << endl;
	int size = (*st).size();
	for (int i = 0; i < size; ++i) {
		PrintStudent(&(*st)[i]);
	}
}

void PrintGroup(vector<Students>* st)
{
	int group;
	cout << "������� ����� ������:" << endl;
	input(group);

	int size = (*st).size();
	for (int i = 0; i < size; ++i) {
		if ((*st)[i].group == group) {
			PrintStudent(&(*st)[i]);
		}
	}
}

void PrintTOP(vector<Students>* st)
{
	int size = (*st).size();
	int top[3] = { -1, -1, -1 };
	double max = 0;
	cout << "���-3 ��������� �� �������� �����:" << endl;
	for (int j = 0; j < 3; ++j) {
		max = 0;
		for (int i = 0; i < size; ++i) {
			if (max < average((*st)[i].grades) && i != top[0] && i != top[1] && i != top[2]) {
				max = average((*st)[i].grades);
				top[j] = i;
			}
		}
	}
	
	for (int i = 0; i < 3; ++i) {
		if (top[i] >= 0) {
			cout << "���-" << i << ":" << endl;
			PrintStudent(&(*st)[top[i]]);
		}
	}
}

double average(int * grd)
{
	double sum = 0.0;
	for (int i = 0; i < 8; ++i) {
		sum += grd[i];
	}
	return (sum/8);
}

void PrintCountInSex(vector<Students>* st)
{
	int size = (*st).size();
	int mCount = 0,
		wCount = 0;
	for (int i = 0; i < size; ++i) {
		if ((*st)[i].sex == 'M' || (*st)[i].sex == 'm') {
			mCount += 1;
		}
		else if((*st)[i].sex == 'F' || (*st)[i].sex == 'f'){
			wCount += 1;
		}
	}
	cout << "���������� ��������� �������� ����: " << mCount << endl
		<< "���������� ��������� �������� ����: " << wCount << endl;
}

void PrintScholar(vector<Students>* st)
{
	int size = (*st).size();
	bool flag = true;
	int count = 0;

	for (int i = 0; i < size; ++i) {
		if ((*st)[i].depart.find("day") != string::npos) {
			flag = true;
			for (int k = 0; k < 8; ++k) {
				if ((*st)[i].grades[k] == 3) {
					flag = false;
					break;
				}
			}
			if (flag) {
				count += 1;
			}
		}
	}

	cout << "���������� ��������� �� ����������: " << count << endl;

}

void PrintNoScholarAB(vector<Students>* st)
{
	int size = (*st).size();
	bool flag = true;

	cout << "��������, �� ���������� ���������:" << endl;
	for (int i = 0; i < size; ++i) {
		flag = true;
		for (int k = 0; k < 8; ++k) {
			if ((*st)[i].grades[k] == 3) {
				flag = false;
				break;
			}
		}
		if (!flag || (*st)[i].depart.find("evening") != string::npos) {
			PrintStudent(&(*st)[i]);
		}
	}

	cout << "��������, �������� �� �������:" << endl;
	for (int i = 0; i < size; ++i) {
		flag = true;
		for (int k = 0; k < 8; ++k) {
			if ((*st)[i].grades[k] != 5) {
				flag = false;
				break;
			}
		}
		if (flag) {
			PrintStudent(&(*st)[i]);
		}
	}
	cout << "��������, �������� �� ������ � �������:" << endl;
	for (int i = 0; i < size; ++i) {
		flag = true;
		for (int k = 0; k < 8; ++k) {
			if ((*st)[i].grades[k] != 5 || (*st)[i].grades[k] != 4) {
				flag = false;
				break;
			}
		}
		if (flag) {
			PrintStudent(&(*st)[i]);
		}
	}
}

void PrintNumS(vector<Students>* st)
{
	int num;
	cout << "������� ����� ��������:" << endl;
	input(num);

	int size = (*st).size();
	for (int i = 0; i < size; ++i) {
		if ((*st)[i].id == num) {
			PrintStudent(&(*st)[i]);
		}
	}
}

void PrintInDay(vector<Students>* st)
{
	string dateMonth = "",
		dateDay = "";
	cout << "������� ����:" << endl;
	cin >> dateDay;
	cout << "������� ����� (������: Dec):" << endl;
	cin >> dateMonth;

	cout << "������ � ������ ����:" << endl;

	int size = (*st).size();
	for (int i = 0; i < size; ++i) {
		if ((*st)[i].date.find(" " + dateDay + " ") != string::npos && (*st)[i].date.find(" " + dateMonth + " ") != string::npos) {
			PrintStudent(&(*st)[i]);
		}
	}
	char hour[2] = "";
	int pos = 0;
	cout << "������ �� �������:" << endl;
	for (int i = 0; i < size; ++i) {
		pos = (*st)[i].date.find(':');
		hour[0] = (*st)[i].date[pos - 2];
		hour[1] = (*st)[i].date[pos - 1];
		if (atoi(hour) < 12) {
			PrintStudent(&(*st)[i]);
		}
	}
	cout << "������ ����� �������:" << endl;
	for (int i = 0; i < size; ++i) {
		pos = (*st)[i].date.find(':');
		hour[0] = (*st)[i].date[pos - 2];
		hour[1] = (*st)[i].date[pos - 1];
		if (atoi(hour) > 12) {
			PrintStudent(&(*st)[i]);
		}
	}
}
