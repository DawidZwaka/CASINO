#include <iostream>
#include <time.h>
#include <string>
#include "game.h"
#include "one_armed_bandit.h"
#include "blackjack.h"
#include "player.h"

using namespace std;

int simpleGameLoop(Game *wsk, int maxRes) {
	
	int res = 0, inputBet;
    char key = '4';

    while(key != '3'){
        system("cls");

        cout
        << "---| Jednoreki bandyta |---" << endl
        << "| 1.Zagraj                |" << endl
        << "| 2.Zmien wartosc zakladu |" << endl
        << "| 3.Wroc do menu          |" << endl
        << "---------------------------" << endl
        << "Wartosc zakladu: " << wsk->getBet() << endl
        << "Stan konta: " << (maxRes+res) << endl
        << "---------------------------" << endl
        << "Twoj wybor: ";

        cin.clear();
        cin >> key;

        switch(key){
            case '1': {
                system("cls");

                if((res - wsk->getBet()) < -maxRes )
                    wsk->printError("Za malo pieniedzy na koncie!");
                    else {
                        res += wsk->play();

                        cin.ignore();
                        cin.clear();
                        cin.get();
                    }

                break;
            }
            case '2': {
                system("cls");

                cout << "Podaj wartosc zakladu z przedzialu od " << wsk->getMinBet() << " do " << wsk->getMaxBet() << ": ";
                cin >> inputBet;

                if(wsk->setBet(inputBet) == -1)
                    wsk->printError("Wprowadzono liczbe spoza zakresu!");

                break;
            }
            default:
                break;
        };
    }


    return res;
}

void printMenu(string name, int accountBalance){
    system("cls");

    cout
    << "--------| MENU |-------" << endl
    << "| 1.Jednoreki bandyta |" << endl
    << "| 2.Black Jack        |" << endl
    << "| 3.Oczko             |" << endl
    << "| 4.Wyswietl TOP100   |" << endl
    << "| 5.Wyjscie z kasyna  |" << endl
    << "-----------------------" << endl
    << "Imie: " << name << endl
    << "Stan konta: " << accountBalance << endl
    << "-----------------------" << endl
    << "Twoj wybor: ";
};

int main ()
{
    srand(time (NULL));
    char key = '6';
    int playerMoney, balanceDiff = 0;

    Player newPlayer("Dawid");
    
	//Game *game;
    //OneArmedBandit smallBandit;
    //Blackjack blackjackTable;

    while(key != '5'){
        playerMoney = newPlayer.getAccountBalance();

        printMenu(newPlayer.getName(), playerMoney);

        cin.clear();
        cin >> key;

        switch(key) {
            case '1': {
            	//game = &smallBandit;
            	
                //balanceDiff = simpleGameLoop(game,playerMoney);
                break;
            }
            case '2': {
                //game = &blackjackTable;
            	
                //balanceDiff = simpleGameLoop(game,playerMoney);
                break;
            }
            case '3': {

                break;
            }
            case '4': {

                break;
            }
            default: {

                break;
            }
        }

        if(balanceDiff != 0){
            newPlayer.updateAccountBalance(balanceDiff);
            balanceDiff = 0;
        }
    }

  return 0;
}

