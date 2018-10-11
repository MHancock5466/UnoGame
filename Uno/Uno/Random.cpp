#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
#include <random>
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

int random() {
	int randomNum;
	std::default_random_engine generator;
	generator.seed(randomNum);
	std::uniform_int_distribution<int> distribution(0, 9);//note the min and max parameters are inclusive here
	while (true)
	{
		cout << distribution(generator) << endl;
	}
	cout<< 
}