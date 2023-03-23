#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include <stdio.h>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;



TEST_CASE("Checking whether at the beginning of the game each player has 26 cards"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    if(p1.stacksize() == 26 && p2.stacksize() == 26){
        res = true;
    }else{
        res = false;
    }
    CHECK(res);
}

TEST_CASE("Checking if at the end of the game the players have 0 cards"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playAll();
    if(p1.stackSize() == 0 && p2.stackSize() == 0){
        res = true;
    } else {
        res = false;
    }
    CHECK(res);
}

TEST_CASE("Checking if at the end of the game the sum of the cards is 52"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playAll();
    if(p1.stackSize() + p1.cardesTaken() + p2.stackSize() + p2.cardesTaken() == 52){
        res = true;
    } else {
        res = false;
    }
    CHECK(res);
}

TEST_CASE("Checking if after one turn the sum of the cards is 52"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playTurn();
    if(p1.stackSize() + p1.cardesTaken() + p2.stackSize() + p2.cardesTaken() == 52){
        res = true;
    } else {
        res = false;
    }
    CHECK(res);
}


