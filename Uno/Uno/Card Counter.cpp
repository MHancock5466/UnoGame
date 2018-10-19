#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int playedCards[108] = { 0 };
string card[108] = { 
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"+4", "+4", "+4", "+4", "W", "W", "W", "W" };
int cardDrawnArrayValue;
string currentCardString;
string lastPlayedCardString;

void distributeCards() {
	//Loops distribute cards for 4 players, 7 cards each
	for (int playerNumber = 0; playerNumber < 4; playerNumber++)
		for (int cardNumber = 0; cardNumber < 7; cardNumber++) {
			//Draws card, Redraws if the card is already "played"
			do {
				playerCardArrayValue[playerNumber][cardNumber] = drawCard();
			} while (playedCards[playerCardArrayValue[playerNumber][cardNumber]] == 1);
			//Sets drawn card as status "played"
			playedCards[playerCardArrayValue[playerNumber][cardNumber]] = 1;
			//Gives string array value of card from array value slot
			playerCardNumber[playerNumber][cardNumber] = card[playerCardArrayValue[playerNumber][cardNumber]];
		}
}

void firstCard() {
	cardDrawnArrayValue = drawCard();
	currentCardString = card[cardDrawnArrayValue];
	playedCards[cardDrawnArrayValue] = 1;
	lastPlayedCardString = currentCardString;
	setColor(cardDrawnArrayValue);
}

void currentCard() {
	setColor(-1);
	cout << "Current Card: ";
	setColor(cardDrawnArrayValue);
	cout << lastPlayedCardString << endl;
}

bool cardIsPlayable(int arrayValue) {
	if ((playerCardNumber[3][arrayValue - 1] == lastPlayedCardString)) //|| ((cardDrawnArrayValue < 25 && cardDrawnArrayValue >= 0)	&& ))
		return true;
	else
		return false;
}

int chooseACard() {	
	cout << "\nChoose a card\nYour Choice: ";
	cin >> cardDrawnArrayValue;
	do {
		if (cardIsPlayable(cardDrawnArrayValue)) {
			cout << "Accepted" << endl;
			currentCardString = card[playerCardArrayValue[3][cardDrawnArrayValue - 1]];

			lastPlayedCardString = currentCardString;
			playerCardNumber[3][cardDrawnArrayValue - 1] = -1;
			return 0;
		}
		else {
			cout << "Invalid" << endl;
			cin >> cardDrawnArrayValue;
			return 0;
		}
	} while (playerCardNumber[3][cardDrawnArrayValue - 1] != lastPlayedCardString);
}

