#pragma once
#include "MaterialUnit.h"
using namespace std;

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