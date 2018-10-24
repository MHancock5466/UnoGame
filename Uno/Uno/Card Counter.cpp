#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int playedDeckCards[108] = { 0 };
int cardsInHand[4][108] = { 7 };
int cardsDrawn[4] = { 0 };
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

void drawCards(int player, string lastCard) {
		do {
			playerCardArrayValue[player][7 + cardsDrawn[player]] = drawCard();
		} while (playedDeckCards[playerCardArrayValue[player][7 + cardsDrawn[player]]] == 1);
		playedDeckCards[playerCardArrayValue[player][7 + cardsDrawn[player]]] = 1;
		playerCardNumber[player][7 + cardsDrawn[player]] = card[0][playerCardArrayValue[player][7 + cardsDrawn[player]]];
	cardsDrawn[player] += 1;
}

void reverseGame() {
	if (reversed == 1)
		reversed = -1;
	else if (reversed == -1)
		reversed = 1;
}

bool cardIsPlayable(int player, int arrayValue) {
	if (playerCardNumber[player][arrayValue] == lastPlayedCardString || card[1][playerCardArrayValue[player][arrayValue]] == lastPlayedCardColor || playerCardNumber[player][arrayValue] == "+4" || playerCardNumber[player][arrayValue] == "W")
		return true;
	else
		return false;
}

void isCardSpecial(string cardString, int player) {
	int playerAffected = 0;
	//Set player that is affected by the draw card or skip card
	if (reversed == 1) {
		if (player < 3)
			playerAffected = player + 1;
		else
			playerAffected = 0;
	}
	else {
		if (player > 0)
			playerAffected = player - 1;
		else
			playerAffected = 3;
	}
	if (lastPlayedCardString == "+4" || lastPlayedCardString == "W") {
		if (player == 3) {
			cout << "\nChoose a color:\n1 - Red\n2 - Green\n3 - Yellow\n4 - Blue\nYour Choice: ";
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
		else {
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
		
	}
	if (lastPlayedCardString == "+4" || lastPlayedCardString == "+2") {
		if (lastPlayedCardString == "+2") {
			drawCards(playerAffected, cardString);
			drawCards(playerAffected, cardString);
		}
		else {
			drawCards(playerAffected, cardString);
			drawCards(playerAffected, cardString);
			drawCards(playerAffected, cardString);
			drawCards(playerAffected, cardString);
		}
	}
		
	else if (lastPlayedCardString == "R")
		reverseGame();
	else if (lastPlayedCardString == "S") {
		skip = 1;
	}
}

bool isCardStandard(int player, int i) {
	if (playerCardNumber[player][i] == "0" || playerCardNumber[player][i] == "1" || playerCardNumber[player][i] == "2" || playerCardNumber[player][i] == "3" || playerCardNumber[player][i] == "4" || playerCardNumber[player][i] == "5" || playerCardNumber[player][i] == "6" || playerCardNumber[player][i] == "7" || playerCardNumber[player][i] == "8" || playerCardNumber[player][i] == "9" || playerCardNumber[player][i] == "S" || playerCardNumber[player][i] == "R" || playerCardNumber[player][i] == "+2" || playerCardNumber[player][i] == "+4" || playerCardNumber[player][i] == "W")
		return true;
	else
		return false;
}

void computerGuess(int player) {
	//Check all cards in possible hand
	for (int i = 0; i < 108; i++) {
		if (cardIsPlayable(player, i)) {
			//Check if card is already played
			if (isCardStandard(player, i)) {
				lastPlayedCardString = playerCardNumber[player][i];
				lastPlayedCardColor = card[1][playerCardArrayValue[player][i]];
				isCardSpecial(lastPlayedCardString, player);
				playerCardNumber[player][i] = "-";
				setColor("w");
				cout << "Player " << player + 1 << " played ";
				setColor(lastPlayedCardColor);
				cout << lastPlayedCardString << endl;
				i = 108;
			}
		}
		else if (i == 107) {
			setColor("w");
			cout << "Player " << player + 1 << " drew a card." << endl;
			drawCards(player, "+1");
		}
	}
}

int chooseACard(int player) {
	setColor("w");
	cout << "\n\nChoose a card slot number (0 to draw a card)\nYour Choice: ";
	cin >> cardDrawn;
	do {
		if (cardDrawn == 0) {
			drawCards(player, "+1");
			cout << "Player 4 drew a card." << endl;
			return 0;
		}
		else if (playerCardNumber[3][cardDrawn - 1] == "-") {
			cout << "Nice try. Choose again: ";
			cin >> cardDrawn;
		}
		else if (cardIsPlayable(3, cardDrawn - 1)) {
			lastPlayedCardString = card[0][playerCardArrayValue[3][cardDrawn - 1]];
			lastPlayedCardColor = card[1][playerCardArrayValue[3][cardDrawn - 1]];
			isCardSpecial(lastPlayedCardString, player);
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

int didPlayerWin(int player) {
	int total = 0;
	for (int i = 0; i < 108; i++)
		if (isCardStandard(player, i))
			total += 1;
	if (total == 0) {
		cout << "Player " << player + 1 << " has " << total << " cards left. Player " << player + 1 << " has won." << endl;
		return 10;
	}
	else
		return player;
}