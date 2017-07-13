#ifndef STRATEGY_H
#define STRATEGY_H

#include "Board.h"


class Strategy{
    public:
        /*return the score of the current board*/
        int get_score(const Board &);
};

#endif