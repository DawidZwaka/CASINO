#pragma once
#include "game.h"
#include "card.h"

class Blackjack: public Game{
    int *cards;
    // Hands[0] - CPU hand, Hands[1] - user hand
    Card **Hands;
    void resetCards();
    void resetHands();
    int checkHand(int);
    bool checkHand(int,int);
    int getCardIndex(int);
    void drawCard(int);
    float calcChanceToLose();
    void printHand(int);
    int calcRes();

    public:
    Blackjack(int b = 100, int minb = 30, int maxb = 3000) {
        bet = b;
        minBet = minb;
        maxBet = maxb;

        cards = new int [13];
        Hands = new Card * [2];

        Hands[0] = new Card [9];
        Hands[1] = new Card [9];

        resetCards();
        resetHands();
    }
    ~Blackjack() {
        delete [] cards;
        delete [] Hands[0];
        delete [] Hands[1];
        delete [] Hands;
    }

    int play();
};
