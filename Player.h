#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>
#include <vector>
#include "Board.h"
using namespace std;

class Player{
    public:
        /*constructor*/
        Player(int c):color(c){}
        /*player makes a move at the square*/
        virtual bool move(Board &){}

    protected:
        int color;
        vector<pair<int,int> > legal_vec;
};

#endif