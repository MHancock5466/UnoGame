#include <iostream>
#include "Header.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main() {
	int replay = 0;
	do {
		int playerCards[4][7];
		
		for (int i = 0; i < 4; i++)
			for (int x = 0; x < 7; x++) {
				sleep_for(seconds(1));
				playerCards[i][x] = drawCard();
				cout << playerCards[i][x] << endl;
			}

		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 2);

	system("pause");
	return 0;
}