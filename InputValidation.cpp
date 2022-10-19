#include "InputValidation.h"

int intInput(string name, int min_val, int max_val, int exceptional) { //Введите {name}:
	cout << "Введите " << name << ":\n";
	int obj;
	while (!(cin >> obj) || obj < min_val || obj > max_val) {
		if (cin && obj == exceptional)
			break;
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Ошибка! Пожалуйста, корректно введите целое, запрошенное число\n";
	}
	cin.ignore(10, '\n');
	return obj;
}

string strInput(string name = "строку") { //Введите {name}:
	cin.clear();
	cout << "Введите " << name << ":\n";
	string value;
	getline(cin, value);
	return value;
}

bool boolInput(string name) { //Нажмите клавишу, чтобы выбрать, {name}...
	cout << "Нажмите клавишу, чтобы выбрать, " << name
		<< "\n1 - Да\nЛюбая другая клавиша - Нет\n";
	if (_getch() == '1') {
		cout << "Выбрано: Да\n";
		return true;
	}
	cout << "Выбрано: Нет\n";
	return false;
}

string receiveTime() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[20];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", timeinfo);
	string str(buffer);
	return str;
}