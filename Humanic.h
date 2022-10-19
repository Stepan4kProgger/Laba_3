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

class Employee : public Entity {
	string post;
	string initials;
public:
	Employee();
	~Employee();
	void setPost(string);
	void setInitials(string);
	string getPost();
	string getInitials();
};