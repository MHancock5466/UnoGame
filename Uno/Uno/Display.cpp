#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

void setColor(char color) {
	switch (color) {
	case 'r':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;
	case 'g':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		break;
	case 'y':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		break;
	case 'b':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		break;
	}
}