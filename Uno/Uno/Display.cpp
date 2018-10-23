#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"
using namespace std;

void setColor(string color) {
	if (color == "d")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Red
	else if (color == "g")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
	else if (color == "y")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
	else if (color == "b")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Blue
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  //White
}

void displayHand(int player) {
	int total = 0;
	setColor("w");
	cout << "\nYour Hand: " << endl;
	//Loop for all cards in player hands
	for (int i = 0; i < 108; i++) {
		if (isCardStandard(player, i)) {
			setColor(card[1][playerCardArrayValue[player][i]]);
			cout << playerCardNumber[player][i] << " ";
		}
		else {
			setColor("w");
			cout << playerCardNumber[player][i] << " ";
		}
	}
}

void displayCardCount(int player) {
	int total = 0;
	for (int i = 0; i < 108; i++)
		if (isCardStandard(player, i))
			total += 1;
	if (total > 1)
		cout << "Player " << player + 1 << " has " << total << " cards left." << endl;
	else if (total = 1)
		cout << "Player " << player + 1 << " has " << total << " card left." << endl;
}