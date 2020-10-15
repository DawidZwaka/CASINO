#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "casino.h"

using namespace std;

void Casino::loadTop100() {
    ifstream in;
    stringstream lineStream;
    string line, name, word;
    int i = 0, j = 0, biggestWin = 0;
    in.open(top100NameFile);

    while (in.good()) {
        getline(in, line, '\n');
        
        lineStream.clear();
        lineStream << line;
        j = 0;

        while (getline(lineStream,word,'*')) {
            if (j == 0)
                name = word;
            if (j == 1)
                biggestWin = stoi(word);

            j++;
        }

        if(line[0] != 0)
            top100[i] = Player(name, biggestWin);

        i++;
    }

    in.close();
}

void Casino::saveTop100() {
    ofstream out;
    string line;
    int i = 0;

    out.open(top100NameFile);

    while (top100[i].getBiggestWin() != 0 && i != 100) {

        out << top100[i].getName() << "*" << top100[i].getBiggestWin();

        if (i != 99)
            out << '\n';

        i++;
    }

    out.close();
}

void Casino::updateTop100(Player player) {
    int i = 0, indexToShift = -1, maxIndex = 99;
    Player tempNext = Player("0",0), temp;

    if (player.getBiggestWin() <= 0)
        return;

    if (top100[0].getBiggestWin() == 0) {
        top100[0] = player;
        return;
    }

    while (i != 100) {
        if (top100[i].getBiggestWin() <= player.getBiggestWin())
            indexToShift = i;

        if (tempNext.getBiggestWin() == 0 && top100[i].getBiggestWin() == 0)
            return;

        if (indexToShift != -1) {
            if (tempNext.getBiggestWin() != 0) {
                temp = top100[i];
                top100[i] = tempNext;
                tempNext = temp;
            }
            else {
                tempNext = top100[i];
                top100[i] = player;
            }

        }

        i++;
    }


}

void Casino::printTop100() {
    int i = 0;

    cout 
        << " Top 100 najwiekszych wygranych " << endl
        << "--------------------------------" << endl;

    while (top100[i].getBiggestWin() != 0 && i != 100) {
        cout << (i+1) << ". " << top100[i].getName() << ", "<< top100[i].getBiggestWin() << " zl" << endl;

        i++;
    }
}

void Casino::printMenu(string name, int accountBalance) {
    system("cls");

    cout
        << "--------| MENU |-------" << endl
        << "| 1.Jednoreki bandyta |" << endl
        << "| 2.Black Jack        |" << endl
        << "| 3.Wyswietl TOP100   |" << endl
        << "| 4.Wyjscie z kasyna  |" << endl
        << "-----------------------" << endl
        << "Imie: " << name << endl
        << "Stan konta: " << accountBalance << endl
        << "-----------------------" << endl
        << "Twoj wybor: ";
}
