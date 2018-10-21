#include <iostream>
#include <random>
#include "Header.h"
using namespace std;

//Generators work by randomly choosing a seed value, then using said seed to generate a list of numbers between the set limits
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