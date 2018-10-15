#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "Header.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int playerCards[4][7];

int main() {
	int replay = 0;
	int cardsLeft = 1;
	
	do {
		for (int i = 0; i < 20; i++)
			cout << random();
		
		/*firstPlayer();
		distributeCards();
		for (int currentPlayer = firstPlayer(); currentPlayer <= 4; currentPlayer++) {
			if (currentPlayer == 1)
				displayHand(currentPlayer);
			else if (currentPlayer == 4)
				currentPlayer = 0;
		}*/
		
		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}