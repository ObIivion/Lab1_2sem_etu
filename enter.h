#pragma once

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool InputText(string & text);

template <typename NUM> void input(NUM & arg);

template <typename NUM> inline void input(NUM & arg)
{
	NUM _buffer; bool error;

	while (true) {
		cin >> _buffer;
		error = (cin.fail() || cin.bad());
		if (error) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка ввода! Повторите, пожалуйста" << endl;
		}
		else break;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	arg = _buffer;
}