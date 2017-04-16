#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Board.h"
using namespace std;

class AI:public Player{
    public:
        /*constructor*/
        AI(int c):Player(c){}
        /*player makes a move at the square*/
        bool move(Board &);
};

#endif