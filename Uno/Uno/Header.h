#ifndef Uno
#define Uno

int firstPlayer();
int drawCard();
int computerChoice();
void setColor(int color);
void displayHand(int player);
void distributeCards();
void displayCurrentCard();
void chooseACard();

std::string playerCardNumber[][7];
int playerCardArrayValue[][7];
#endif