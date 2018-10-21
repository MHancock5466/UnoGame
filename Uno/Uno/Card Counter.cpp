#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int playedDeckCards[108] = { 0 };
int cardsInHand[4][108] = { 7 };
int cardDrawn;
int colorChoice;
string currentCardString;
string lastPlayedCardColor;
string lastPlayedCardString;

void distributeCards() {
	//Loops distribute cards for 4 players, 7 cards each
	for (int player = 0; player < 4; player++)
		for (int cards = 0; cards < 7; cards++) {
			//Draws card, Redraws if the card is already "played"
			do {
				playerCardArrayValue[player][cards] = drawCard();
			} while (playedDeckCards[playerCardArrayValue[player][cards]] == 1);
			//Sets drawn card as status "played"
			playedDeckCards[playerCardArrayValue[player][cards]] = 1;
			//Gives string of card from array value slot
			playerCardNumber[player][cards] = card[0][playerCardArrayValue[player][cards]];
		}
}

void firstCard() {
	//Draw a card, set as a value
	do {
		cardDrawn = drawCard();
	} while (cardDrawn >= 99);
	//Set the last played card color and string
	lastPlayedCardString = card[0][cardDrawn];
	lastPlayedCardColor = card[1][cardDrawn];
	//Set card status as "played"
	playedDeckCards[cardDrawn] = 1;
}

void currentCard() {
	setColor("w");
	cout << "\nCurrent Card: ";
	setColor(lastPlayedCardColor);
	cout << lastPlayedCardString << endl;
	setColor("w");
}

bool cardIsPlayable(int player, int arrayValue) {
	if (playerCardNumber[player][arrayValue] == lastPlayedCardString || card[1][playerCardArrayValue[player][arrayValue]] == lastPlayedCardColor || playerCardNumber[player][arrayValue] == "+4" || playerCardNumber[player][arrayValue] == "W")
		return true;
	else
		return false;
}

void drawACard(int player) {
	cout << endl;
}

void computerGuess(int player) {
	//Check all cards in possible hand
	for (int i = 0; i < 108; i++) {
		if (cardIsPlayable(player, i)) {
			//Check if card is already played
			if (playerCardNumber[player][i] != "-") {
				lastPlayedCardString = playerCardNumber[player][i];
				lastPlayedCardColor = card[1][playerCardArrayValue[player][i]];
				playerCardNumber[player][i] = "-";
				setColor("w");
				cout << "Player " << player + 1 << " played ";
				setColor(lastPlayedCardColor);
				cout << lastPlayedCardString << endl;
				if (lastPlayedCardString == "+4" || lastPlayedCardString == "W") {
					colorChoice = firstPlayer() + 1;
					if (colorChoice == 1)
						lastPlayedCardColor = "d";
					else if (colorChoice == 2)
						lastPlayedCardColor = "g";
					else if (colorChoice == 3)
						lastPlayedCardColor = "y";
					else
						lastPlayedCardColor = "b";
				}
				i = 110;
			}
		}
		else if (i == 107) {
			setColor("w");
			cout << "Player " << player + 1 << " drew a card." << endl;
			drawACard(player);
		}
	}
}

int chooseACard(int player) {
	setColor("w");
	cout << "\n\nChoose a card slot number (0 to draw a card)\nYour Choice: ";
	cin >> cardDrawn;
	do {
		if (cardDrawn == 0) {
			drawACard(player);
			return 0;
		}
		else if (playerCardNumber[3][cardDrawn - 1] == "-") {
			cout << "Nice try. Choose again: ";
			cin >> cardDrawn;
		}
		else if (cardIsPlayable(3, cardDrawn - 1)) {
			lastPlayedCardString = card[0][playerCardArrayValue[3][cardDrawn - 1]];
			lastPlayedCardColor = card[1][playerCardArrayValue[3][cardDrawn - 1]];
			if (lastPlayedCardString == "+4" || lastPlayedCardString == "W") {
				cout << "\nChoose a color:\n1 - Red\n2 - Green\n3 - Yellow\n4 - Blue\nYourChoice: ";
				cin >> colorChoice;
				if (colorChoice == 1)
					lastPlayedCardColor = "d";
				else if (colorChoice == 2)
					lastPlayedCardColor = "g";
				else if (colorChoice == 3)
					lastPlayedCardColor = "y";
				else
					lastPlayedCardColor = "b";
			}
			colorChoice = 0;
			playerCardNumber[3][cardDrawn - 1] = "-";
			return 0;
		}
		else {
			cout << "\nCheater. Try again: ";
			cin >> cardDrawn;
		}
	} while (playerCardNumber[3][cardDrawn - 1] != lastPlayedCardString || card[1][playerCardArrayValue[3][cardDrawn - 1]] != card[1][playerCardArrayValue[3][cardDrawn]]);
}