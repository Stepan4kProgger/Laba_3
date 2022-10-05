#pragma once
#include "MaterialUnit.h"
using namespace std;

class Order {
	vector<MaterialUnit> cur_cart;
	double actual_price;
public:
	Order();
	~Order();
	void clearCart();
	bool isNotEmpty();
	void addProduct(MaterialUnit&);
	void viewCart();
	void fillString(string&);
};
