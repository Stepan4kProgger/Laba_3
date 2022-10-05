#pragma once
#include "Common.h"
using namespace std;

class Entity {
	string name;
	bool is_juristic;
public:
	Entity();
	~Entity();
	void setName(string);
	void setFace(bool);
	string getName();
	bool getFace();
};
