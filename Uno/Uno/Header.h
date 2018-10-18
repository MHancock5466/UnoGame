#include <string>
using namespace std;
#ifndef Uno
#define Uno
//Random Class
int firstPlayer();
int drawCard();
int computerChoice();
//Display Class
void setColor(int color);
void displayHand(int player);
//Card Counter Class
void distributeCards();
void firstCard();
void currentCard();
void chooseACard();
//Public Variables for Use
string playerCardNumber[][7];
int playerCardArrayValue[][7];
int playedCards[];
#endif