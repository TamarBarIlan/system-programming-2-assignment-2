
#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include <stdio.h>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;

TEST_CASE("Checking whether at the beginning of the game each player has 26 cards")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Checking if at the end of the game the players have 0 cards")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Checking if at the end of the game the sum of the cards is 52")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playAll();
    if (p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52)
    {
        res = true;
    }
    else
    {
        res = false;
    }
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
    CHECK(p1.stacksize() + p2.stacksize() == 0);
}

TEST_CASE("Checking if after one turn the sum of the cards is 52")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    game.playTurn();
    if (p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52)
    {
        res = true;
    }
    else
    {
        res = false;
    }
    CHECK(res);
}

TEST_CASE("Checking if after turn 1 there are less than 26 cards in the pack")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
}

TEST_CASE("Checking if after ten turns there are less than 17 cards in the pack")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 10; i++)
    {
        game.playTurn();
        if (p1.stacksize() == 0 && p2.stacksize() == 0)
        {
            i = 10;
        }
    }
    CHECK(p1.stacksize() < 17);
    CHECK(p2.stacksize() < 17);
}

TEST_CASE("Checking if after at most 26 turns the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 26; i++)
    {
        game.playTurn();
        if (p1.stacksize() == 0 && p2.stacksize() == 0)
        {
            i = 10;
        }
    }
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}




