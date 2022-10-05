#include "BuildMaterials.h"
using namespace std;

MaterialUnit strToMatUnit(string input) {
	MaterialUnit temp;
	stringstream sStr(input);
	string buf;
	getline(sStr, buf, '\t');
	temp.setName(buf);
	getline(sStr, buf);
	temp.setPrice(stod(buf));
	return temp;
}

BuildMaterials::BuildMaterials() {}

BuildMaterials::BuildMaterials(bool* non_req_param) : size(0), ptr(nullptr) {
	cout << "BuildMat constructor\n";
	if (!isFileExists(MAT_DIR)) {
		cout << "Файл не найден\n";
		throw 0;
	}
	size = getRowsAmount(MAT_DIR);
	if (size == 0)
		throw Exceptional("Файл пуст\n");
	try {
		ptr = new MaterialUnit[size];
	}
	catch (bad_alloc& except) {
		cout << "Поставь больше оперативки!\n";
		throw;
	}
	ifstream file(MAT_DIR);
	string buf;
	int cursor = 0;
	while (getline(file, buf)) {
		ptr[cursor] = strToMatUnit(buf);
		cursor++;
	}
}

BuildMaterials::~BuildMaterials() {
	delete[] ptr;
}

void BuildMaterials::viewAll() {
	cout << "Название материала - Цена\n\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << ptr[i].getName() << " - " << ptr[i].getPrice() << " р.\n";
	}
	cout << "---\n";
}

int BuildMaterials::getSize() { return size; }

MaterialUnit BuildMaterials::operator[](int index) {
	return ptr[index];
}