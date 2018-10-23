#include <string>
using namespace std;
#ifndef Uno
#define Uno

//Random Class
int firstPlayer();
int drawCard();

//Display Class
void setColor(string color);
void displayHand(int player);
void displayCardCount(int player);

//Card Counter Class
void distributeCards();
void firstCard();
void currentCard();
int chooseACard(int player);
void computerGuess(int player);
bool isCardStandard(int player, int i);
int didPlayerWin(int player);

//Public Variables for Use
extern int reversed;
extern int skip;
int playerCardArrayValue[][108];
int playedDeckCards[];
string playerCardNumber[][108];
const string card[2][108] = {
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "S", "S", "R", "R", "+2", "+2",
	"+4", "+4", "+4", "+4", "W", "W", "W", "W",
	"d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d", "d",
	"g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g", "g",
	"y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y", "y",
	"b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b",
	"c", "c", "c", "c", "c", "c", "c", "c" };

#endif