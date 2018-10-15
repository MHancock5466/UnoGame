#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Header.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void setColor(char color) {
	switch (color) {
	case 'r':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Red
		break;
	case 'g':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
		break;
	case 'y':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
		break;
	case 'b':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Blue
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  //White
	}
}

void displayHand(int player) {
	cout << "\nYour Hand: " << endl;
	for (int i = 0; i < 7; i++) {
		cout << playerCards[player][i] << endl;
	}
}