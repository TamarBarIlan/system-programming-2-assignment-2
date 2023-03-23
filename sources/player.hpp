#include <iostream>
using namespace std;

class player {
private:
    string name;

public:
    player(string name){
        this->name = name;
    }
    int stackSize();
    int cardesTaken();
};