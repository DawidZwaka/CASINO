#include <iostream>
#include <time.h>
#include <string>
#include <locale>
#include "casino.h"
#include "player.h"
#include "game.h"
#include "one_armed_bandit.h"
#include "blackjack.h"

using namespace std;

string getNameFromInput() {
    string name;
    int i;
    bool isAlphaNum = false;

    while (!isAlphaNum) {
        isAlphaNum = true;
        i = 0;

        system("cls");
        cout << "Podaj nazwe gracza, aby wejsc do kasyna: ";

        cin >> name;

        while (i < name.length()) {
            if (!isalnum(name[i])) {
                isAlphaNum = false;

                cout << "Niepoprawna nazwa uzytkownika!" << endl
                    << "Nacisnij dowolny klawiszy, aby konntynuowac...";
                
                cin.ignore();
                cin.clear();
                cin.get();
                break;
            }

            i++;
        }
    }

    return name;
}

int main()
{
    srand(time(NULL));
    string name = ".";
    char key = '6';
    int playerMoney, balanceDiff = 0, biggestWin = 0;

    Casino newCasino;

    name = getNameFromInput();

    Player newPlayer(name);

    Game *game;
    OneArmedBandit smallBandit;
    Blackjack blackjackTable;

    while (key != '4') {
        playerMoney = newPlayer.getAccountBalance();

        newCasino.printMenu(newPlayer.getName(), playerMoney);

        cin.clear();
        cin >> key;

        switch (key) {
        case '1': {
            game = &smallBandit;

            balanceDiff = game->loop(playerMoney, biggestWin);
            break;
        }
        case '2': {
            game = &blackjackTable;

            balanceDiff = game->loop(playerMoney, biggestWin);
            break;
        }
        case '3': {
            system("cls");

            newCasino.printTop100();

            cin.ignore();
            cin.clear();
            cin.get();

            break;
        }
        case '4': {
            newCasino.saveTop100();
            break;
        }
        default: {
            break;
        }
        }

        if (balanceDiff != 0) {
            newPlayer.updateAccountBalance(balanceDiff);
            balanceDiff = 0;
        }

        if (biggestWin > newPlayer.getBiggestWin()) {
            newPlayer.setBiggestWin(biggestWin);

            newCasino.updateTop100(newPlayer);
        }
    }

    return 0;
}