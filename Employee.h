#pragma once
#include "Entity.h"
using namespace std;

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