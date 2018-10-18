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
int currentCardChoice;
int cardDrawn;
string currentCardVar;
string lastPlayedCard;

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
	cardDrawn = drawCard();
	currentCardVar = card[cardDrawn];
	playedCards[cardDrawn] = 1;
	lastPlayedCard = currentCardVar;
	setColor(cardDrawn);
}

void currentCard() {
	cout << "Current Card: ";
	setColor();
	cout << lastPlayedCard << endl;
}

void chooseACard() {	
	cout << "\nChoose a card\nYour Choice: ";
	cin >> currentCardChoice;
	do {
		if (playerCardNumber[3][currentCardChoice - 1] == lastPlayedCard) {
			cout << "Accepted" << endl;
			currentCardVar = card[playerCardArrayValue[3][currentCardChoice]];
			lastPlayedCard = currentCardVar;
		}
		else {
			cout << "Invalid" << endl;
			cin >> currentCardChoice;
		}
	} while (true);
}