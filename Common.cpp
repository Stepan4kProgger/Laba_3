#include "Common.h"
using namespace std;

bool isFileExists(string dir) {
	ifstream file(dir);
	return file.is_open();
}

int getRowsAmount(string dir) {
	ifstream file(dir);
	string buf;
	int amount = 0;
	while (getline(file, buf)) {
		amount++;
	}
	file.close();
	return amount;
}
