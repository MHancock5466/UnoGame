#include <string>
using namespace std;
#ifndef Uno

#define Uno

int firstPlayer();
int drawCard();
int computerChoice();

void setColor(int color);
void displayHand(int player);

void distributeCards();
void firstCard();
void currentCard();
void chooseACard();

string playerCardNumber[][7];
int playerCardArrayValue[][7];
int playedCards[];
#endif