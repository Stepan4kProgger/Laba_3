#define _CRT_SECURE_NO_WARNINGS
#include "BuildMaterials.h"
#include "Order.h"
#include "Employee.h"
using namespace std;

/*9. Разработать набор классов (минимум 5 классов, связи между
классами: агрегация, композиция, наследование) по предметной области
«Магазин стройматериалов». Функционал программы должен
позволить собрать заказ. Сгенерировать минимум пять типов
исключительных ситуаций. Реализовать перенаправление исключительных
ситуаций. Сгенерировать минимум одну исключительную ситуацию с
оператором new. Создать исключительную ситуацию в конструкторе и
продемонстрировать вызов конструкторов и деструкторов. Задать
собственную функцию завершения. Создать собственный (пользовательский)
класс исключения, сгенерировать исключение этого типа и обработать его. */

void addProd(BuildMaterials& build_mat, Order& cur_order) {
	Exceptional ex("Ввод прерван\n");
	MaterialUnit unit;
	cout << "В любой момент вы можете ввести 0 для отмены\n";
	int cursor = intInput("порядковый номер товара из списка выше\n", 0, build_mat.getSize());
	if (cursor-- == 0)
		throw ex;
	unit.setName(build_mat[cursor].getName());
	int amount = intInput("целочисленное количество товара\n");
	if (amount == 0)
		throw ex;
	unit.setPrice(build_mat[cursor].getPrice() * amount);
	cur_order.addProduct(unit);
	cout << "Успешно добавлено:\n" << unit.getName() << "\nНа сумму: " << unit.getPrice() << " р.\n";
}

void completeOrder(Order& ord) {
	if (!ord.isNotEmpty())
		throw Exceptional("Корзина пуста, выберите хоть что-нибудь\n");
	Exceptional ex("Оформление прервано\n");
	cout << "Вы можете в любой момент ввести 0 для отмены\n";
	Entity buyer;
	buyer.setName(strInput("имя покупателя"));
	if (buyer.getName() == "0")
		throw ex;
	buyer.setFace(boolInput("является ли покупатель юридическим лицом"));
	Employee empl;
	empl.setName(strInput("имя продавца"));
	if (empl.getName() == "0")
		throw ex;
	empl.setInitials(strInput("инициалы продавца"));
	if (empl.getInitials() == "0")
		throw ex;
	ord.viewCart();
	if (boolInput("уверенны ли вы в том, что хотите оформить заказ\n"));
	string to_write = "-=-Товарный-чек-=-\nТовар - Сумма\n";
	ord.fillString(to_write);
	to_write += "-=-Успешно-оплачено-=-\n";
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
		cout << "Выберите дальнейшее действие:\n\n"
			<< "\t1 - Добавить в заказ товар\n"
			<< "\t2 - Посмотреть текущий заказ\n"
			<< "\t3 - Оформить и получить заказ\n";
		if (cur_order.isNotEmpty())
			cout << "\t4 - Очистить корзину\n";
		cout << "\tESC - Отменить заказ\n";
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
	cout << "Завершение работы программы...\n";
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
		cout << "Работа магазина невозможна\n";
		system("pause");
		return -1;
	}
	bool state = true;
	while (state) {
		cout << "Выберите действие нажатием клавиши:\n"
			<< "\n\t1 - Собрать заказ\n"
			<< "\tESC - Выйти\n";
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