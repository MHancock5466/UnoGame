#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"
using namespace std;

void setColor(int color) {
	if (color >=0 && color < 25)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Red
	else if (color >= 25 && color < 50)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
	else if (color >= 50 && color < 75)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
	else if (color >= 75 && color < 100)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Blue
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  //White
}

void displayHand(int player) {
	setColor(-1);
	cout << "\nYour Hand: " << endl;
	//Loop for all seven cards in player hands
	for (int i = 0; i < 7; i++) {
		setColor(playerCardArrayValue[player][i]);
		cout << playerCardNumber[player][i] << " ";
		if (i == 6)
			setColor(-1);
	}
}