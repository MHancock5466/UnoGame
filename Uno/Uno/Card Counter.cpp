#include <iostream>
#include "Header.h"
using namespace std;

string card[108] = { 
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"+4", "+4", "+4", "+4", "W", "W", "W", "W" };

char cardColor[4] = { 'r', 'g', 'y', 'b' };

void distributeCards() {
	for (int playerNumber = 0; playerNumber < 4; playerNumber++)
		for (int cardNumber = 0; cardNumber < 7; cardNumber++) {
			cardTest = drawCard();
			playerCards[playerNumber][cardNumber] = atoi(card[cardTest].c_str());
			if (cardTest < 25)
				setColor('r');
			else if (cardTest >= 25 && cardTest < 50)
				setColor('g');
			else if (cardTest >= 50 && cardTest < 75)
				setColor('y');
			else
				setColor('b');
			cout << playerCards[playerNumber][cardNumber] << " " << cardTest << endl;
		}
}