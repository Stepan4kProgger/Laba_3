#pragma once
#include "InputValidation.h"
#include "Exceptional.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>
using namespace std;

const string MAT_DIR = "Materials.txt";
const string CHECK_DIR = "Check.txt";

bool isFileExists(string);
int getRowsAmount(string);