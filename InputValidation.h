#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using std::cin;
using std::cout;
using std::string;

int intInput(string name = "число", int min_val = 0, int max_val = 10000, int exceptional = 0);
string strInput(string);
bool boolInput(string);
string receiveTime();