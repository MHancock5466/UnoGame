#include <iostream>
#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>
using namespace std;

int firstPlayer() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(0, 3);
	return dist(gen);
}

int drawCard() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 108);
	return dist(gen);
}

int computerChoice() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 7);
	return dist(gen);
}