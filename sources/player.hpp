#pragma once
namespace ariel
{
}
using namespace ariel;
#include <iostream>
using namespace std;

class Player
{
private:
    string name;

public:
    Player() {}
    Player(std ::string name)
    {
        this->name = name;
    }
    int stacksize();
    int cardesTaken();
};