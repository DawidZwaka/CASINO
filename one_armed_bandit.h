#pragma once
#include "game.h"

class OneArmedBandit: public Game {
    int amountOfCylinders;
    int amountOfSymbols;
    int *result;
    int calcRes();
    void printResScreen(int);

    public:
    OneArmedBandit(int c = 3, int s = 7, int b = 100, int minb = 50, int maxb = 5000 ) {
        amountOfCylinders = c;
        amountOfSymbols = s;
        bet = b;
        minBet = minb;
        maxBet = maxb;
        result = new int [amountOfCylinders];
    }
    ~OneArmedBandit() {
        delete [] result;
    }

    int play();
};
