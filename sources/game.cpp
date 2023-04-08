#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"
#include <vector>

// constructor
Game ::Game(Player& p1, Player& p2)
    : p1(p1), p2(p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->lastIndex = 0;
    this->isOver = false;
    Deck deck;
    //Dealing the cards to each player
    initialize(deck);
    shuffle(deck);
    deal_cards(deck, p1.getCards(), p2.getCards(), 26);
    
    cout << "p1: " << endl;
    for (int i = 0; i < 26; i++)
    {
        size_t inx = static_cast<size_t>(i);
        cout << "p1 rank = " << p1.getCards().at(inx).rank << " p1 suit = " << p1.getCards().at(inx).suit << endl;
    }
    cout << "p2: " << endl;
    for (int i = 0; i < 26; i++)
    {
        size_t inx = static_cast<size_t>(i);
        cout << "p2 rank = " << p2.getCards().at(inx).rank << " p2 suit = " << p2.getCards().at(inx).suit << endl;
    }
}

// Returns -1 if the indexes are invalid or the game is already over
// Returns 0 if the turn was successful
int Game ::playTurn()
{
    if (this->isOver || p1.getIndex() != p2.getIndex() || !(p1.isIndexValid(p1.getIndex()) && p2.isIndexValid(p2.getIndex())))
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
    cout << "start tempPlayTurn" << endl;

    int p1Index = -1;
    int p2Index = -1;
    p1Index = p1.getIndex();
    p2Index = p2.getIndex();

    if (!(p1.isIndexValid(p1Index) && p2.isIndexValid(p2Index)))
    {
        p1.addCardesTaken(26 - this->lastIndex);
        p2.addCardesTaken(26 - this->lastIndex);
        this->isOver = true;
    }
    // p1 win
    else if (p1.getNumInIndex(p1Index) > p2.getNumInIndex(p2Index))
    {
        cout << "in the case that p1 win" << endl;
        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p1.addCardesTaken((p1.getIndex() - this->lastIndex) * 2);
    }
    // p2 win
    else if (p1.getNumInIndex(p1Index) < p2.getNumInIndex(p2Index))
    {
        cout << "in the case that p2 win" << endl;
        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p2.addCardesTaken((p2.getIndex() - this->lastIndex) * 2);
    }
    // draw
    else
    {
        cout << "in draw case " << endl;
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

void Game::shuffle(Deck& deck) {
    // Use a random number generator to shuffle the deck
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.cards.begin(), deck.cards.end(), gen);
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

void Game :: print_deck(const Deck& deck)
{
    for(Card c : deck.cards)
    {
        print_card(c);
    }
}

void  Game :: print_card(const Card& card)
{
    cout << "Rank = " << card.rank << ", Suit = " << card.suit << endl;
}
