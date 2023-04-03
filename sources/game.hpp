
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
    Deck deck;
    Player p1;
    Player p2;
    int lastIndex;
    bool isOver;

public:
    Game() {}
    Game(Player p1, Player p2);
    int playTurn();    // void/int ???
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

    void tempPlayTurn();
    void initialize(Deck &deck);
    void shuffle(Deck& deck);
    bool deal_cards(Deck& deck, vector<Card>& p1_cards, vector<Card>& p2_cards, int num_cards);
};