#include "Order.h"
Order::Order() : actual_price(0) { cout << "Order constr\n"; }
Order::~Order() { cout << "Order destr\n"; }

void Order::clearCart() {
	actual_price = 0;
	cur_cart.clear();
	cout << "Корзина очищена!\n";
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
		throw Exceptional("Корзина ещё пуста\n");
	cout << "Название товара - На сумму";
	for (int i = 0; i < cur_cart.size(); i++)
		cout << i + 1 << ". " << cur_cart[i].getName() << " - " << cur_cart[i].getPrice() << " р.\n";
	cout << "Общий итог: " << actual_price << endl;
}

void Order::fillString(string& to_write) {
	for (int i = 0; i < cur_cart.size(); i++) {
		to_write += to_string(i + 1) += ". ";
		to_write += cur_cart[i].getName() += " - ";
		to_write += to_string(cur_cart[i].getPrice()) += " р.\n";
	}
	to_write += "Общий итог: ";
	to_write += to_string(actual_price) += "\nДата и время на момент покупки: ";
	to_write += receiveTime() += '\n';
}