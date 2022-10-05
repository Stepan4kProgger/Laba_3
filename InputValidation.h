#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using std::cin;
using std::cout;
using std::string;

int intInput(string name = "�����", int min_val = 0, int max_val = 10000, int exceptional = 0) { //������� {name}:
	cout << "������� " << name << ":\n";
	int obj;
	while (!(cin >> obj) || obj < min_val || obj > max_val) {
		if (cin && obj == exceptional)
			break;
		cin.clear();
		cin.ignore(10, '\n');
		cout << "������! ����������, ��������� ������� �����, ����������� �����\n";
	}
	cin.ignore(10, '\n');
	return obj;
}

string strInput(string name = "������") { //������� {name}:
	cin.clear();
	cout << "������� " << name << ":\n";
	string value;
	getline(cin, value);
	return value;
}

bool boolInput(string name) { //������� �������, ����� �������, {name}...
	cout << "������� �������, ����� �������, " << name
		<< "\n1 - ��\n����� ������ ������� - ���\n";
	if (_getch() == '1') {
		cout << "�������: ��\n";
		return true;
	}
	cout << "�������: ���\n";
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