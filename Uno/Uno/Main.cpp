#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int playerCardArrayValue[4][7];
string playerCardNumber[4][7];

int main() {
	int replay = 0;
	int cardsLeft = 7;

	do {
		//Set All Cards as Playable
		for (int i = 0; i < 108; i++)
			playedCards[i] = 0;
		//Randomize first player, choose a first card, and distribute the rest
		firstPlayer();
		firstCard();
		distributeCards();
		//Loop for all players to repeat
		for (int currentPlayer = firstPlayer(); currentPlayer < 4; currentPlayer++) {
			if (currentPlayer == 3) {
				//Display current card, hand, then let user choose a card
				currentCard();
				displayHand(currentPlayer);
				chooseACard();
				if(cardsLeft > 1)
					currentPlayer = 0;
			}
			else {
				//computerGuess();
			}
		}
		//Ask for Repeat Gameplay
		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}