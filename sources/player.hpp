#pragma once
namespace ariel
{
}
using namespace ariel;
#include <iostream>
using namespace std;
#include "card.hpp"
#include <vector>

class Player
{
private:
    string name;
    vector<Card> cards;
    int index;
    int countCardsTaken;

public:
    Player() {}
    Player(std ::string name);
    int stacksize();
    int cardesTaken();

    bool isIndexValid(int index);
    int getIndex();
    int getNumInIndex(int index);
    void setIndex(int newIndex);
    void addCardesTaken(int num);

    vector<Card>& getCards();
};