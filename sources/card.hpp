#include <iostream>
using namespace std;

class card {
private:
    int number;
    string color;

public:
    card(int number, string color){
        this->number = number;
        this->color = color;
    }
};