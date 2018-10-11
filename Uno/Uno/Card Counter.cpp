#include <iostream>
#include <chrono>
#include <thread>
#include "Header.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void cardArray() {
	string card[108] = { 
		"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
		"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
		"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
		"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
		"+4", "+4", "+4", "+4", "W", "W", "W", "W" };

	char cardColor[4] = { 'r', 'g', 'y', 'b' };
}

void distributeCards() {
	

	for (int playerNumber = 0; playerNumber < 4; playerNumber++)
		for (int cardNumber = 0; cardNumber < 7; cardNumber++) {
			sleep_for(seconds(1));
			playerCards[playerNumber][cardNumber] = drawCard();
		}
}