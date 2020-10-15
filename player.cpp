#include <iostream>
#include "player.h"

using namespace std;

int Player::getAccountBalance(){
    return accountBalance;
};

void Player::updateAccountBalance(int amount){
    if(accountBalance + amount >= 0)
        accountBalance += amount;
    else
        cout << "Brak Pieniedzy";
};

string Player::getName() {
    return name;
}

int Player::getBiggestWin() {
    return biggestWin;
}

void Player::setBiggestWin(int bigWin) {
    if (bigWin > biggestWin) {
        biggestWin = bigWin;
    }
    else {
        cout << "Nie mozna ustawic najwiekszej wygranej mniejszej niz aktualna wygrana!";

    }
}
