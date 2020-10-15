#include "card.h"

int Card::setSign(int index){
    int res = 0;
    sign = '0';

    if(index>=2 && index<=9)
        sign = index + '0';
    if(index == 10)
        sign = 'T';
    if(index == 11)
        sign = 'J';
    if(index == 12)
        sign = 'Q';
    if(index == 13)
        sign = 'K';
    if(index == 1 || index == 0)
        sign = 'A';
    if(index == 20)
        sign = 'X';
    if(sign == '0')
        res = -1;

    return res;
}

void Card::setVal(int index){
    if(index>=2 && index<=10)
        val = index;
    if(index>=11 && index<=13)
        val = 10;
    if(index == 1)
        val = 11;
    if(index == 0)
        val = 1;
    if(index == 20)
        val = -1;
}

int Card::getVal(){
    return val;
}

char Card::getSign(){
    return sign;
}

void Card::setByIndex(int index){
    if(setSign(index) == 0)
        setVal(index);
    else
        cout << "Niepoprawny index karty!";
}

int Card::getIndex(){
    return indx;
}
