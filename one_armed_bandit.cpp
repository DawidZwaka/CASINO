#include "one_armed_bandit.h"
#include <string>

int OneArmedBandit::calcRes() {
    int i, win = true, prev = -1, res;

    for(i=0;i<amountOfCylinders;i++){
        if(prev == -1)
            prev = i;
        else {
            win = (result[prev] == result[i])? true : false;
            prev = i;

            if(win == false)
                break;
        }
    }

    if(win){
        res = (result[1]+1)*2*bet;
    }else
        res = -bet;

    return res;
}

void OneArmedBandit::printResScreen(int res){
    int i, j;

    for(i=0;i<6;i++){
        if(i == 1){
            printf("|");
            centerText("bandit", amountOfCylinders*3.9);
            printf(" |");
        }
        if(i == 5)
        {
            printf("|");
            centerText(res<getMinBet()? "lose": "win", amountOfCylinders*3.8);
            printf(" |\n");

            printf("|");
            centerText(to_string(res), amountOfCylinders*3.8);
            printf(" |\n");
        }

        for(j=0;j<amountOfCylinders;j++)
            switch(char(i + '0')){
                case '0':
                case '2':
                case '4':
                case '5':{
                    if(j == 0)
                        printf("-");

                    printf("----");

                    break;
                }
                case '3': {
                    if(j == 0)
                        printf("|");

                    printf(" %d |", result[j]);

                    break;
                }
            }
        cout << endl;
    }

}

int OneArmedBandit::play(){
    int i, res;

    for(i=0;i<amountOfCylinders;i++)
        result[i] = rand()%(amountOfSymbols-1) + 0;

    res = calcRes();
    printResScreen(res);

    return res;
};
