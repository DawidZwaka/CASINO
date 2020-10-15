#include <iostream>

using namespace std;

class Card {
    char sign;
    int val, indx;
    int setSign(int);
    void setVal(int);

    public:
    Card(int index = 20) {
        setByIndex(20);
        indx = index;
    }

    int getVal();
    char getSign();
    void setByIndex(int);
    int getIndex();
};
