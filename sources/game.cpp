#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"
#include <vector>

// constructor
Game ::Game(Player &p1, Player &p2)
    : p1(p1), p2(p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->lastIndex = -1;
    this->isOver = false;
    Deck deck;
    // Dealing the cards to each player
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
        this->isOver = true;
        return -1;
    }

    int index = p1.getIndex();
    //cout << "p1.getIndex() = " << p1.getIndex() << endl;
    //cout << "in playTurn() isover = " << isOver << endl;
    this->lastIndex = index;
    tempPlayTurn(index, 0);
    return 0;
}

// The function plays one turn
// If ifPrint == 1 then the function prints the turn
void Game ::tempPlayTurn(int index, int ifPrint)
{
    // cout << "start tempPlayTurn. ifPrint = " << ifPrint << endl;
    // cout << "index = " << index << endl;
    //cout << "in A isover = " << isOver << endl;
    //cout << "in tempPlayTurn() the index = " << index << endl;

    int p1Index = -1;
    int p2Index = -1;
    p1Index = index;
    p2Index = index;


    if (p1.getIndex() >= p1.getCards().size() || p2.getIndex() >= p2.getCards().size())
    {
        p1.addCardesTaken(26 - this->lastIndex);
        p2.addCardesTaken(26 - this->lastIndex);
        this->isOver = true;
        return;
    }
    // p1 win
    else if (p1.getNumInIndex(p1Index) > p2.getNumInIndex(p2Index))
    {
        if (ifPrint == 1)
        {
            //cout << "in the case that p1 win isover = " << isOver << endl;
            // cout << "in the case that p1 win" << endl;
            p1.printCardInIndex(p1Index);
            cout << " ";
            p2.printCardInIndex(p2Index);
            cout << ". " << p1.getName() << " wins." << endl;
        }

        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p1.addCardesTaken((p1.getIndex() - this->lastIndex) * 2);
    }
    // p2 win
    else if (p1.getNumInIndex(p1Index) < p2.getNumInIndex(p2Index))
    {
        //cout << "in the case that p2 win isover = " << isOver << endl;
        // cout << "in the case that p2 win" << endl;
        if (ifPrint == 1)
        {
            p1.printCardInIndex(p1Index);
            cout << " ";
            p2.printCardInIndex(p2Index);
            cout << ". " << p2.getName() << " wins." << endl;
        }
        p1.setIndex(p1Index + 1);
        p2.setIndex(p2Index + 1);
        p2.addCardesTaken((p2.getIndex() - this->lastIndex) * 2);
    }
    // draw
    else
    {
        //cout << "in draw case isover = " << isOver << endl;
        // cout << "in draw case " << endl;
        if (ifPrint == 1)
        {
            p1.printCardInIndex(p1Index);
            cout << " ";
            p2.printCardInIndex(p2Index);
            cout << ". "
                 << " draw." << endl;
        }

        p1.setIndex(p1Index + 2);
        p2.setIndex(p2Index + 2);
        tempPlayTurn(p1.getIndex(), ifPrint);
    }
}
void Game ::printLastTurn()
{
    if (lastIndex == -1)
    {
        cout << "They haven't played yet";
    }
    else
    {
        Player p1Temp = p1;
        Player p2Temp = p2;
        // cout << "lastIndex = " << lastIndex << endl;
        tempPlayTurn(lastIndex, 1);
        p1 = p1Temp;
        p2 = p2Temp;
    }
}
void Game ::playAll()
{
    while (!isOver)
    {
        //cout << "in playAll() isover = " << isOver << endl;
        playTurn();
    }
}
void Game ::printWiner()
{
    if (isOver)
    {
        if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout << p1.getName() << " wins" << endl;
        }
        else if (p1.cardesTaken() < p2.cardesTaken())
        {
            cout << p2.getName() << " wins" << endl;
        }
        else
        {
            cout << "draw!" << endl;
        }
    }
}
void Game ::printLog()
{
    bool flag = false;
    if(this->isOver)
    {
        flag = true;
        isOver = false;
    }
    
    int index = p1.getIndex();
    p1.setIndex(0);
    p2.setIndex(0);
    p1.addCardesTaken(-p1.cardesTaken());
    p2.addCardesTaken(-p2.cardesTaken());
    while (p1.getIndex() != index )
    {
        cout << "turn number " << p1.getIndex() + 1 << " :" << endl; 
        tempPlayTurn(p1.getIndex(), 1);
    }
    if(flag)
    {
        isOver = true;
    }
}
void Game ::printStats()
{
}

// Initialize a deck of cards
void Game ::initialize(Deck &deck)
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

void Game::shuffle(Deck &deck)
{
    // Use a random number generator to shuffle the deck
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.cards.begin(), deck.cards.end(), gen);
}

// Dealing a deck of cards
bool Game ::deal_cards(Deck &deck, vector<Card> &p1_cards, vector<Card> &p2_cards, int num_cards)
{
    if (deck.cards.size() < 2 * num_cards)
    {
        return false;
    }
    for (int i = 0; i < num_cards; i++)
    {
        p1_cards.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
        p2_cards.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
    }
    return true;
}

void Game ::print_deck(const Deck &deck)
{
    for (Card c : deck.cards)
    {
        print_card(c);
    }
}

void Game ::print_card(const Card &card)
{
    cout << "Rank = " << card.rank << ", Suit = " << card.suit << endl;
}