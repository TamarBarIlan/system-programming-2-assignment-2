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

int Player::getNumInIndex(int index)
{
    if (isIndexValid(index) && !cards.empty())
    {

        return static_cast<int>(this->cards[static_cast<std::vector<Card>::size_type>(index)].rank);
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

vector<Card>& Player ::getCards()
{
    return this->cards;
}

string Player :: getName()
{
    return name;
}

void Player :: printCardInIndex(int index)
{
    size_t ind = static_cast<size_t>(index);
    Card card = cards.at(ind);
    string rankString;
    switch(card.rank)
    {
        case ACE:
            rankString = "Ace";
            break;
        case TWO:
            rankString = "2";
            break;
        case THREE:
            rankString = "3";
            break;
        case FOUR:
            rankString = "4";
            break;
        case FIVE:
            rankString = "5";
            break;
        case SIX:
            rankString = "6";
            break;
        case SEVEN:
            rankString = "7";
            break;
        case EIGHT:
            rankString = "8";
            break;
        case NINE:
            rankString = "9";
            break;
        case TEN:
            rankString = "10";
            break;
        case JACK:
            rankString = "Jack";
            break;
        case QUEEN:
            rankString = "Queen";
            break;
        case KING:
            rankString = "King";
            break;
        default:
            rankString = "Unknown Rank";
            break;
    }
    
    string suitString;
    switch(card.suit)
    {
        case SPADES:
            suitString = "Spades";
            break;
        case HEARTS:
            suitString = "Hearts";
            break;
        case DIAMONDS:
            suitString = "Diamonds";
            break;
        case CLUBS:
            suitString = "Clubs";
            break;
        default:
            suitString = "Unknown Suit";
            break;
    }
    //Alice played Queen of Hearts Bob played 5 of Spades. Alice wins
    cout << name << " played " << rankString << " of " << suitString;
}