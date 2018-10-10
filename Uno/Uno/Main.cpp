#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	int replay = 0;
	do {
		firstPlayer();


		cout << "Would you like to play again?\n1 - Yes\n2 - No" << endl;
		cin >> replay;
	} while (replay != 1);

	system("pause");
	return 0;
}