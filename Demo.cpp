/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main()
{
  
  Player p1("Alice");
  Player p2("Bob");

  Game game(p1, p2);
  
  for (int i = 0; i < 20; i++)
  {
    //cout << "befoer turn: " << i << endl;
    game.playTurn();
    //cout << "p1 wins = " << p1.getNumberOfWins() << endl;
    // cout << "p2 wins = " << p2.getNumberOfWins() << endl; 
  }
  game.printLastTurn();             // print the last turn stats. For example:
                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
  cout << p1.stacksize() << endl;   // prints the amount of cards left. should be 21 but can be less if a draw was played
  //cout << "p1 took " <<p1.cardesTaken() << " cards" << endl;
  //cout << "p2 took " <<p2.cardesTaken() << " cards" << endl; // prints the amount of cards this player has won.
  game.playAll(); 
                 // playes the game untill the end
  game.printWiner();                // prints the name of the winning player
  game.printLog();                  // prints all the turns played one line per turn (same format as game.printLastTurn())
  game.printStats();                // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
}