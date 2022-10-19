#pragma once
#include "Humanic.h"
using namespace std;

class MaterialUnit {
	string name;
	double price;
public:
	MaterialUnit();
	void setName(string);
	void setPrice(double);
	string getName();
	double getPrice();
};

class BuildMaterials {
	MaterialUnit* ptr;
	int size;
public:
	BuildMaterials();
	BuildMaterials(bool*);
	~BuildMaterials();
	void viewAll();
	int getSize();
	MaterialUnit operator[](int);
};

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