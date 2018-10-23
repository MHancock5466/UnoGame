#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Header.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int skip;
int reversed;
int playerCardArrayValue[4][108];
string playerCardNumber[4][108];

int main() {
	int replay = 0;
	int total;
	skip = 0;
	reversed = 1;

	do {
		//Set All Cards as Playable
		for (int i = 0; i < 108; i++)
			playedDeckCards[i] = 0;

		//Randomize first player, choose a first card, and distribute the rest
		int firstPlayerInt = firstPlayer();
		firstCard();
		distributeCards();
		setColor("w");
		cout << "You are player 4." << endl;
		cout << "The random first player is player " << firstPlayerInt + 1 << endl;
		sleep_for(seconds(2));

		//Loop for all players to repeat their turns
		for (int currentPlayer = firstPlayerInt; currentPlayer < 4; currentPlayer += reversed) {
			setColor("w");
			cout << "\n\n\nIt is player " << currentPlayer + 1 << "'s turn. " << endl;
			displayCardCount(currentPlayer);
			currentCard();
			if (currentPlayer == 3) {
				//Display current card, hand, then let user choose a card
				displayHand(currentPlayer);
				chooseACard(currentPlayer);
				currentPlayer = didPlayerWin(currentPlayer);
				if (reversed == 1 && currentPlayer == 3)
					currentPlayer = -1;
			}
			else {
				//Computer plays possible card, elsewise they draw
				computerGuess(currentPlayer);
				currentPlayer = didPlayerWin(currentPlayer);
				sleep_for(seconds(3));
				if (reversed == -1 && currentPlayer == 0)
					currentPlayer = 4;
			}
			
			//Check for skip action, ensure reversed allows skip still
			if (skip == 1) {
				if (reversed == 1) {
					if (currentPlayer == 0)
						currentPlayer = 1;
					else if (currentPlayer == 1)
						currentPlayer = 2;
					else if (currentPlayer == 2)
						currentPlayer = -1;
					else
						currentPlayer = 0;
				}
				else if (reversed = -1) {
					if (currentPlayer == 0)
						currentPlayer = 4;
					else if (currentPlayer == 1)
						currentPlayer = 0;
					else if (currentPlayer == 2)
						currentPlayer = 1;
					else
						currentPlayer = 2;
				}
			}
			skip = 0;
			//Check for cards remaining
		}
		//Ask for Repeat Gameplay
		setColor("w");
		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}