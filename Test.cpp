
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
    CHECK((p1.cardesTaken() > 0 || p2.cardesTaken() > 0));
}

TEST_CASE("Checking if after ten turns there are less than 17 cards in the pack")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool flag = false;
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
    CHECK((p1.cardesTaken() > 0 || p2.cardesTaken() > 0));
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

TEST_CASE("Checking if an error is thrown after at most 27 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool flag = false;
    try
    {
        for (int i = 0; i <= 26; i++)
        {
            game.playTurn();
        }
    }
    catch (exception &e)
    {
        flag = true;
    }
    CHECK(flag);
}

TEST_CASE("Checking if an error is thrown if creating a game with player 1")
{
    Player p1("Alice");
    bool flag = false;
    try
    {
        Game game(p1, p1);
    }
    catch (exception &e)
    {
        flag = true;
    }
    CHECK(flag);
}

TEST_CASE("Checking if an error is thrown if another turn is activated after the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool flag = false;
    game.playAll();
    try{
        game.playTurn();
    }
    catch(exception &e){
        flag = true;
    }
    CHECK(flag);
}

TEST_CASE("Checking if an error is thrown if playAll is activated on the same game twice")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool flag = false;
    game.playAll();
    try{
        game.playAll();
    }
    catch(exception &e){
        flag = true;
    }
    CHECK(flag);
}
