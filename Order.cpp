#include "Order.h"
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
	cout << "�������� ������ - �� �����";
	for (int i = 0; i < cur_cart.size(); i++)
		cout << i + 1 << ". " << cur_cart[i].getName() << " - " << cur_cart[i].getPrice() << " �.\n";
	cout << "����� ����: " << actual_price << endl;
}

void Order::fillString(string& to_write) {
	for (int i = 0; i < cur_cart.size(); i++) {
		to_write += to_string(i + 1) += ". ";
		to_write += cur_cart[i].getName() += " - ";
		to_write += to_string(cur_cart[i].getPrice()) += " �.\n";
	}
	to_write += "����� ����: ";
	to_write += to_string(actual_price) += "\n���� � ����� �� ������ �������: ";
	to_write += receiveTime() += '\n';
}