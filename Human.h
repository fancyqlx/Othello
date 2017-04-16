#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
using namespace std;

class Human: public Player{
    public:
        /*constructor*/
        Human(int c):Player(c){}
        /*player makes a move at the square*/
        bool move(Board &);
};

#endif