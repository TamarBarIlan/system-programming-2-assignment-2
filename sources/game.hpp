#include <iostream>
using namespace std;

class game {
private:   
    player p1;
    player p2;

public:
    game(player p1, player p2){
        this->p1 = p1;
        this->p2 = p2;
    }
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};