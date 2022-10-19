#include "BuildMaterials.h"
#include <iomanip>
using namespace std;

MaterialUnit::MaterialUnit() { cout << '|'; }
void MaterialUnit::setName(string name) { this->name = name; }
void MaterialUnit::setPrice(double price) { this->price = price; }
string MaterialUnit::getName() { return name; }
double MaterialUnit::getPrice() { return price; }

MaterialUnit strToMatUnit(string input) {
	MaterialUnit temp;
	stringstream sStr(input);
	string buf;
	getline(sStr, buf, '\t');
	temp.setName(buf);
	getline(sStr, buf, '\t');
	temp.setPrice(stod(buf));
	return temp;
}

BuildMaterials::BuildMaterials() {}

BuildMaterials::BuildMaterials(bool* non_req_param) : size(0), ptr(nullptr) {
	cout << "BuildMat constructor\n";
	if (!isFileExists(MAT_DIR)) {
		cout << "���� �� ������\n";
		throw 0;
	}
	size = getRowsAmount(MAT_DIR);
	if (size == 0)
		throw Exceptional("���� ����\n");
	int choose = intInput("�� 0, ���� �� �� ������ ������� �������������� �������� � ������������", INT_MIN, INT_MAX);
	if (choose == 0)
		throw Exceptional("� ��\n");
	try {
		ptr = new MaterialUnit[size];
	}
	catch (bad_alloc& except) {
		cout << "������� ������ ����������!\n";
		throw;
	}
	cout << "������ ������������� ������ MatUnit";
	ifstream file(MAT_DIR);
	string buf;
	int cursor = 0;
	while (getline(file, buf)) {
		ptr[cursor] = strToMatUnit(buf);
		cursor++;
	}
}

BuildMaterials::~BuildMaterials() {
	cout << "BuildMats destr\n";
	delete[] ptr;
}

void BuildMaterials::viewAll() {
	cout << "�������� ��������� - ����\n\n";
	for (int i = 0; i < size; i++) {
		stringstream ss;
		ss << fixed << setprecision(2) << ptr[i].getPrice();
		cout << i + 1 << ". " << ptr[i].getName() << " - " << ss.str() << " �.\n";
	}
	cout << "---\n";
}

int BuildMaterials::getSize() { return size; }

MaterialUnit BuildMaterials::operator[](int index) {
	return ptr[index];
}

Order::Order() : actual_price(0) { cout << "Order constr\n"; }
Order::~Order() { cout << "Order destr\n"; }

void Order::clearCart() {
	actual_price = 0;
	cur_cart.clear();
	cout << "������� �������!\n";
}

bool Order::isNotEmpty() {
	return cur_cart.size();
}

void Order::addProduct(MaterialUnit& unit) {
	cur_cart.push_back(unit);
	actual_price += unit.getPrice();
}

void Order::viewCart() {
	if (actual_price == 0)
		throw Exceptional("������� ��� �����\n");
	cout << "�������� ������ - �� �����\n";
	for (int i = 0; i < cur_cart.size(); i++) {
		stringstream ss;
		ss << fixed << setprecision(2) << cur_cart[i].getPrice();
		cout << i + 1 << ". " << cur_cart[i].getName() << " - " << ss.str() << " �.\n";
	}
	cout << "����� ����: " << actual_price << endl;
}

void Order::fillString(string& to_write) {
	for (int i = 0; i < cur_cart.size(); i++) {
		to_write += to_string(i + 1) += ". ";
		to_write += cur_cart[i].getName() += " - ";
		stringstream ss;
		ss << fixed << setprecision(2) << cur_cart[i].getPrice();
		to_write += ss.str() += " �.\n";
	}
	to_write += "����� ����: ";
	to_write += to_string(actual_price) += "\n���� � ����� �� ������ �������: ";
	to_write += receiveTime() += '\n';
}
