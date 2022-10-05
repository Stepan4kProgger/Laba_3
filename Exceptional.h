#pragma once
#include <exception>
using namespace std;

class Exceptional : public exception {
public:
	Exceptional(const char*);
};
