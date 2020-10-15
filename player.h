#pragma once
#include <iostream>
using namespace std;

class Player {
    int accountBalance, biggestWin;
    string name;

    public:
        Player(string n = "annonymous", int bigWin = 0) {
            accountBalance = (rand()% 5 + 10) * 1000;
            name = n;
            biggestWin = bigWin;
        }

        int getAccountBalance();
        void updateAccountBalance(int);
        string getName();
        int getBiggestWin();
        void setBiggestWin(int);
};
