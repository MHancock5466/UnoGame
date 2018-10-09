#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
using namespace std;

int firstPlayer() {
	srand(time(NULL));
	int choosePlayer = rand() % 4 + 1;
	return choosePlayer;
}

int drawCard() {
	srand(time(NULL));
	int randomCard = rand() % 108 + 1;
	return randomCard;
}

int computerChoice() {
	srand(time(NULL));
	int randomChoice = rand() % 7 + 1;
	return randomChoice;
}