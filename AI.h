#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Board.h"
#include <limits>
using namespace std;

class AI:public Player{
    public:
        /*constructor*/
        AI(int c):Player(c),max(c){}
        /*player makes a move at the square*/
        bool move(Board &);
        int evaluate(const Board &);
        int alpha_beta(int,Board,int,pair<int,int>,int,int);
    private:
        int max;
};

#endif