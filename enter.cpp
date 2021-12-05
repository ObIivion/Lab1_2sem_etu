#include "enter.h"

bool InputText(string & text)
{
	string _buffer; bool error;
	if (cin.peek() == '\n') {
		cin.ignore(cin.rdbuf()->in_avail());
		return false;
	}
	while (true) {
		cin >> _buffer;
		error = (cin.fail() || cin.bad());
		if (error) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Îøèáêà ââîäà! Ïîâòîğèòå, ïîæàëóéñòà" << endl;
			return false;
		}
		else break;
	}
	text = _buffer;
	return true;
}
