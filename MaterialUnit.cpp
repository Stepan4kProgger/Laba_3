#include "MaterialUnit.h"
using namespace std;

MaterialUnit::MaterialUnit() { cout << '|'; }
void MaterialUnit::setName(string name) { this->name = name; }
void MaterialUnit::setPrice(double price) { this->price = price; }
string MaterialUnit::getName() { return name; }
double MaterialUnit::getPrice() { return price; }