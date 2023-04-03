#include "player.hpp"
#define CARDS_FOR_PLAYER 26

Player ::Player(std ::string name)
{
    this->name = name;
    this->index = 0;
    this->countCardsTaken = 0;
}

int Player ::stacksize()
{
    if (this->index < 26 && this->index >= 0)
    {
        return (CARDS_FOR_PLAYER - this->index);
    }
    return -1;
}
int Player ::cardesTaken()
{
    return this->countCardsTaken;
}

bool Player ::isIndexValid(int index)
{
    if (index >= 0 && index < 26)
    {
        return true;
    }
    return false;
}

int Player ::getIndex()
{
    return this->index;
}

int Player ::getNumInIndex(int index)
{
    if (isIndexValid(index))
    {
        this->cards[index];
    }
    return -1;
}

void Player ::setIndex(int newIndex)
{
    this->index = newIndex;
}

void Player ::addCardesTaken(int num)
{
    this->countCardsTaken += num;
}

vector<Card> &Player ::getCards()
{
    return this->cards;
}
