#include "game.h"

int Game::setBet(int b){
    if(b>=getMinBet() && b<=getMaxBet()) {
        bet = b;
        return 0;
    }else {
        return -1;
    }
}

int Game::getBet(){
    return bet;
}

int Game::getMinBet() {
    return minBet;
}

int Game::getMaxBet() {
    return maxBet;
}

void Game::centerText(string text, int fieldWidth) {
    int padLen = (fieldWidth - text.size()) / 2;

    printf("%*s%s%*s", padLen, "", text.c_str(), padLen, "");
}

void Game::printError(string err = "Wystapil blad!"){
    cout << err << endl
    << "Nacisnij dowolny przycisk, aby konntynuowac...";

    cin.ignore();
    cin.clear();
    cin.get();
}

void Game::printMenu(int accountBalance) {
    cout
        << "--------| Menu Gry |-------" << endl
        << "| 1.Zagraj                |" << endl
        << "| 2.Zmien wartosc zakladu |" << endl
        << "| 3.Wroc do menu          |" << endl
        << "---------------------------" << endl
        << "Wartosc zakladu: " << getBet() << endl
        << "Stan konta: " << accountBalance << endl
        << "---------------------------" << endl
        << "Twoj wybor: ";
}

int Game::loop(int maxRes, int &biggestWin) { 

    int res = 0, gameRes = 0, inputBet;
    char key = '4';

    while (key != '3') {
        system("cls");

        printMenu(maxRes + res);

        cin.clear();
        cin >> key;

        switch (key) {
        case '1': {
            system("cls");

            if ((res - getBet()) < -maxRes)
                printError("Za malo pieniedzy na koncie!");
            else {
                gameRes = play();

                if (gameRes > biggestWin)
                    biggestWin = gameRes;

                res += gameRes;

                cin.ignore();
                cin.clear();
                cin.get();
            }

            break;
        }
        case '2': {
            system("cls");

            cout << "Podaj wartosc zakladu z przedzialu od " << getMinBet() << " do " << getMaxBet() << ": ";
            cin >> inputBet;

            if (setBet(inputBet) == -1)
                printError("Wprowadzono liczbe spoza zakresu!");

            break;
        }
        default:
            break;
        };
    }


    return res;
}