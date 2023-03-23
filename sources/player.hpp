#include <iostream>
using namespace std;

class player {
private:
    string name;

public:
    player(string name){
        this->name = name;
        this->sunOfCards = 0;
        this->sunOfVinCards = 0;
    }
    int stackSize();
    int cardesTaken();
};