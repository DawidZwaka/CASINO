#include "blackjack.h"

void Blackjack::resetCards() {
    int i;

    for(i=0;i<13;i++)
        cards[i] = 4;
}

void Blackjack::resetHands() {
    int i;

    for(i=0;i<9;i++){
        Hands[0][i].setByIndex(20);
        Hands[1][i].setByIndex(20);
    }
}

int Blackjack::checkHand(int handIndex) {
    int i, sum = 0;

    for(i=0;i<9;i++){
        if(Hands[handIndex][i].getVal() != -1){
            sum += Hands[handIndex][i].getVal();
        }
    }

    return sum;
}

bool Blackjack::checkHand( int cardIndex, int handIndex ) {
    bool found = false;
    int i;

    for(i=0;i<9;i++) {
        if(Hands[handIndex][i].getVal() == -1)
            break;

        if(Hands[handIndex][i].getIndex() == cardIndex){
            found = true;
            break;
        }
    }

    return found;
}

int Blackjack::getCardIndex(int handIndex) {
    int index = rand()% 13 + 1;

    if(index == 1 && checkHand(index, handIndex))
        index = 0;

    return index;
}

void Blackjack::drawCard(int handIndex) {
    int index = getCardIndex(handIndex), i;

    for(i=0;i<9;i++){
        if(Hands[handIndex][i].getVal() == -1){
           Hands[handIndex][i].setByIndex(index);
            break;
        }
    }
}

float Blackjack::calcChanceToLose() {
    int sum = checkHand(0),
        maxAcceptableVal = 21 - sum,
    A[14] = {2,3,4,5,6,7,8,9,10,10,10,10,11,99}, i, powA = 0;

    if(checkHand(0,0))
        A[13] = 1;

    for(i=0;i<14;i++)
        if(maxAcceptableVal >= A[i])
            powA++;

    return (float)powA/14;
}

void Blackjack::printHand(int handIndex) {
    int i,j, cardVal, cardSign;

    for(i=0;i<7;i++){
        for(j=0;j<9;j++){
            cardVal = Hands[handIndex][j].getVal();
            cardSign = Hands[handIndex][j].getSign();

            if(cardVal != -1){

                switch(char(i+'0')) {
                    case '0':
                    case '6':{
                        printf(" --------- ");
                        break;
                    }
                    case '1': {
                        printf(" |%c      | ", cardSign);
                        break;
                    }
                    case '5': {
                        printf(" |      %c| ", cardSign);
                        break;
                    }
                    case '3': {
                        printf(" |   %c   | ", cardSign);
                        break;
                    }
                    case '2':
                    case '4':{
                        printf(" |       | ");
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}

int Blackjack::calcRes(){
    int res = 0;
    int userPoints = checkHand(1), cpuPoints = checkHand(0);

    if(userPoints == 21)
        res = 1.5*bet;
    if(userPoints == cpuPoints && userPoints <= 21)
        res = 0;
    if(userPoints > 21 || (userPoints < cpuPoints && cpuPoints <= 21))
        res = -bet;
    if((userPoints > cpuPoints && userPoints < 21) || cpuPoints > 21)
        res = bet;


    return res;
}

int Blackjack::play() {
    resetCards();
    resetHands();

    int res;
    bool cpuPass = false, userPass = false;
    char key = '3';

    drawCard(0);
    drawCard(1);

    while(!cpuPass || !userPass) {

        //user turn
        key = '3';
        while(key != '1' && key !='2' && !userPass){
            system("cls");
            cout << "Twoja reka:" << endl;
            printHand(1);
            cout << "Suma: " << checkHand(1) << endl
            << "1.Dobierz " << endl
            << "2.Spasuj" << endl
            << "Twoj wybor: ";

            if(checkHand(1) >= 21){
                userPass = true;
                cpuPass = true;
                key = '2';
            }

            if(!userPass)
                cin >> key;
        }

        switch(key) {
            case '1': {
                drawCard(1);

                if(checkHand(1) >= 21)
                    cpuPass = true;
                break;
            }
            case '2': {
                userPass = true;
                break;
            }
            default: {
                break;
            }
        }

        //cpu turn
        if(calcChanceToLose() > 0.4 && !cpuPass){
            drawCard(0);

            if(checkHand(0) >= 21){
                cpuPass = true;
                userPass = true;
            }
        }else {
            cpuPass = true;
        }
    }

    system("cls");
    res = calcRes();

    if(res > 0)
        cout << "Wygrales, gratulacje!";
    else if(res == 0)
        cout << "Remis!";
    else
        cout << "Niestety przegrales!";

    cout << endl << "Twoj wynik: " << checkHand(1) << endl
    << "Wynik opponenta: " << checkHand(0) << endl
    << "Saldo: " << res << endl;

    return res;
}
