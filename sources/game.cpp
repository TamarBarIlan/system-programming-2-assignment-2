#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"

// constructor
Game ::Game(Player p1, Player p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->lastIndex = 0;
    this->isOver = false;

    //Dealing the cards to each player
    initialize(deck);
    shuffle(deck);
    deal_cards(deck, p1.getCards(), p2.getCards(), 16);
}

// Returns -1 if the indexes are invalid or the game is already over
// Returns 0 if the turn was successful
int Game ::playTurn()
{
    if (p1.getIndex() != p2.getIndex() || !(p1.isIndexValid(p1.getIndex()) && p2.isIndexValid(p2.getIndex())))
    {
        return -1;
    }
    int index = p1.getIndex();
    this->lastIndex = index;
    tempPlayTurn();
    return 0;
}

void Game ::tempPlayTurn()
{

    int p1Index = -1;
    int p2Index = -1;
    p1Index = p1.getIndex();
    p2Index = p1.getIndex();

    if (!(p1.isIndexValid(p1Index) && p2.isIndexValid(p2Index)))
    {
        p1.addCardesTaken(26 - this->lastIndex);
        p2.addCardesTaken(26 - this->lastIndex);
        this->isOver = true;
    }
    // p1 win
    if (p1.getNumInIndex(p1Index) > p2.getNumInIndex(p2Index))
    {
        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p1.addCardesTaken((p1.getIndex() - this->lastIndex) * 2);
    }
    // p2 win
    if (p1.getNumInIndex(p1Index) < p2.getNumInIndex(p2Index))
    {
        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p2.addCardesTaken((p2.getIndex() - this->lastIndex) * 2);
    }
    // draw
    else
    {
        p1.setIndex(p1Index + 2);
        p2.setIndex(p2Index + 2);
        tempPlayTurn();
    }
}
void Game ::printLastTurn()
{
}
void Game ::playAll()
{
}
void Game ::printWiner()
{
}
void Game ::printLog()
{
}
void Game ::printStats()
{
}

// Initialize a deck of cards
void Game :: initialize(Deck &deck)
{
    Card card;
    for (int j = 0; j < card.num_suits; j++)
    {
        for (int q = 1; q <= card.num_ranks; q++)
        {
            card.suit = Suit(j);
            card.rank = Rank(q);
            deck.cards.push_back(card);
        }
    }
}

//shuffling a deck of cards
void Game :: shuffle(Deck& deck)
{
    Deck shuffled;
    while(!deck.cards.empty())
    {
        size_t rand_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[rand_index]);
        deck.cards.erase(deck.cards.begin() + rand_index);
    }
    deck = shuffled;
}

//Dealing a deck of cards
bool Game :: deal_cards(Deck& deck, vector<Card>& p1_cards, vector<Card>& p2_cards, int num_cards)
{
    if(deck.cards.size() < 2 * num_cards)
    {
        return false;
    }
    for( int i = 0; i < num_cards; i++)
    {
        p1_cards.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
        p2_cards.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
    }
    return true;
}
