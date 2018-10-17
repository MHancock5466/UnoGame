#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

string playerCardNumber[4][7];
int playerCardArrayValue[4][7];

int main() {
	int replay = 0;
	int cardsLeft = 1;
	
	do {
		for (int i = 0; i < 108; i++)
			playedCards[i] = 0;
		firstPlayer();
		distributeCards();
		firstCard();
		for (int currentPlayer = firstPlayer(); currentPlayer < 4; currentPlayer++) {
			if (currentPlayer == 3) {
				currentCard();
				displayHand(currentPlayer);
				chooseACard();
			}
		}
		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}