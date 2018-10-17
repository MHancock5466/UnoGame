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
string currentCardVar;
string lastPlayedCard;

void distributeCards() {
	for (int playerNumber = 0; playerNumber < 4; playerNumber++)
		for (int cardNumber = 0; cardNumber < 7; cardNumber++) {
			playerCardArrayValue[playerNumber][cardNumber] = drawCard();
			while (playedCards[playerCardArrayValue[playerNumber][cardNumber]] == 1)
				playerCardArrayValue[playerNumber][cardNumber] = drawCard();
			playedCards[playerCardArrayValue[playerNumber][cardNumber]] = 1;
			playerCardNumber[playerNumber][cardNumber] = card[playerCardArrayValue[playerNumber][cardNumber]];
		}
}

void chooseACard() {
	cout << "\nChoose a card\nYour Choice: ";
	cin >> currentCardChoice;
	if (playerCardNumber[3][currentCardChoice] == lastPlayedCard)
		cout << "Good";
}

void firstCard() {
	int cardDrawn;
	cardDrawn = drawCard();
	currentCardVar = card[cardDrawn];
	while (playedCards[cardDrawn] == 1) {
		cardDrawn = drawCard();
		currentCardVar = card[cardDrawn];
	}
	playedCards[cardDrawn] = 1;
}

void currentCard() {
	cout << "Current Card: ";
	setColor(playerCardArrayValue[3][currentCardChoice]);
	cout << currentCardVar << endl;
	setColor(-1);
	lastPlayedCard = currentCardVar;
}