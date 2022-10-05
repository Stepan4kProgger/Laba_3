#pragma once
#include "Common.h"
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