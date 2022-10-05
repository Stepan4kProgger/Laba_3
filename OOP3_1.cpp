#define _CRT_SECURE_NO_WARNINGS
#include "BuildMaterials.h"
#include "Order.h"
#include "Employee.h"
using namespace std;

/*9. ����������� ����� ������� (������� 5 �������, ����� �����
��������: ���������, ����������, ������������) �� ���������� �������
�������� ���������������. ���������� ��������� ������
��������� ������� �����. ������������� ������� ���� �����
�������������� ��������. ����������� ��������������� ��������������
��������. ������������� ������� ���� �������������� �������� �
���������� new. ������� �������������� �������� � ������������ �
������������������ ����� ������������� � ������������. ������
����������� ������� ����������. ������� ����������� (����������������)
����� ����������, ������������� ���������� ����� ���� � ���������� ���. */

void addProd(BuildMaterials& build_mat, Order& cur_order) {
	Exceptional ex("���� �������\n");
	MaterialUnit unit;
	cout << "� ����� ������ �� ������ ������ 0 ��� ������\n";
	int cursor = intInput("���������� ����� ������ �� ������ ����\n", 0, build_mat.getSize());
	if (cursor-- == 0)
		throw ex;
	unit.setName(build_mat[cursor].getName());
	int amount = intInput("������������� ���������� ������\n");
	if (amount == 0)
		throw ex;
	unit.setPrice(build_mat[cursor].getPrice() * amount);
	cur_order.addProduct(unit);
	cout << "������� ���������:\n" << unit.getName() << "\n�� �����: " << unit.getPrice() << " �.\n";
}

void completeOrder(Order& ord) {
	if (!ord.isNotEmpty())
		throw Exceptional("������� �����, �������� ���� ���-������\n");
	Exceptional ex("���������� ��������\n");
	cout << "�� ������ � ����� ������ ������ 0 ��� ������\n";
	Entity buyer;
	buyer.setName(strInput("��� ����������"));
	if (buyer.getName() == "0")
		throw ex;
	buyer.setFace(boolInput("�������� �� ���������� ����������� �����"));
	Employee empl;
	empl.setName(strInput("��� ��������"));
	if (empl.getName() == "0")
		throw ex;
	empl.setInitials(strInput("�������� ��������"));
	if (empl.getInitials() == "0")
		throw ex;
	ord.viewCart();
	if (boolInput("�������� �� �� � ���, ��� ������ �������� �����\n"));
	string to_write = "-=-��������-���-=-\n����� - �����\n";
	ord.fillString(to_write);
	to_write += "-=-�������-��������-=-\n";
	ofstream check(CHECK_DIR); check.close(); check.open("Check.txt");
	check << to_write;
	check.close();
	system("cls");
	cout << to_write;
	system("pause");
}

void makeOrder(BuildMaterials& build_mat) {
	bool state = true;
	Order cur_order;
	while (state) {
		system("cls");
		cout << "�������� ���������� ��������:\n\n"
			<< "\t1 - �������� � ����� �����\n"
			<< "\t2 - ���������� ������� �����\n"
			<< "\t3 - �������� � �������� �����\n";
		if (cur_order.isNotEmpty())
			cout << "\t4 - �������� �������\n";
		cout << "\tESC - �������� �����\n";
		int input = _getch();
		switch (input) {
		case '1':
			try { addProd(build_mat, cur_order); }
			catch (Exceptional& ex) {
				cout << ex.what();
			}
			break;
		case '2':
			try { cur_order.viewCart(); }
			catch (Exceptional& ex) {
				cout << ex.what();
			}
			break;
		case '3': {
			bool not_done = true;
			try { completeOrder(cur_order); not_done = false; }
			catch (Exceptional& ex) {
				cout << ex.what();
			}
			state = not_done;
		}
			break;
		case '4':
			if (cur_order.isNotEmpty())
				break;
			cur_order.clearCart();
			break;
		case 27:
			state = false;
		}
		if (state)
			system("pause");
	}
}

void myOwnExit() {
	cout << "���������� ������ ���������...\n";
	exit(0);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BuildMaterials build_m;
	try {
		BuildMaterials temp(NULL);
		build_m = temp;
	}
	catch (...) {
		cout << "������ �������� ����������\n";
		system("pause");
		return -1;
	}
	bool state = true;
	while (state) {
		cout << "�������� �������� �������� �������:\n"
			<< "\n\t1 - ������� �����\n"
			<< "\tESC - �����\n";
		int input = _getch();
		switch (input) {
		case '1':
			makeOrder(build_m);
			break;
		case 27:
			state = false;
			break;
		}
		if (state) {
			system("pause");
			system("cls");
		}
	}
	myOwnExit();
}