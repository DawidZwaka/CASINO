#pragma once
#include <iostream>
using namespace std;

class Game
{
protected:
	int minBet, maxBet, bet;

public:
    
    int getMinBet();
    int getMaxBet();
    int getBet();
    int setBet(int);
    void centerText(string, int);
    void printError(string);
    void printMenu(int);
    virtual int loop(int, int&);
    virtual int play() = 0;
};

