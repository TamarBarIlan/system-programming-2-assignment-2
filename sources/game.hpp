
#pragma once
namespace ariel
{
}
using namespace ariel;
#include "player.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;

class Game
{
private:
    Player p1;
    Player p2;

public:
    Game() {}
    Game(Player p1, Player p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};