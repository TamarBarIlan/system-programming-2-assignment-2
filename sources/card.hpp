#pragma once
#include <iostream>
using namespace std;

class Card
{
private:
    int number;
    string color;

public:
    Card(int number, string color)
    {
        this->number = number;
        this->color = color;
    }
};