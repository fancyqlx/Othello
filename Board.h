#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*eight directions*/
const int DIRECTIONS[8][2] = {{-1,-1},{-1,0},{-1,-1},
                        {0,-1},{0,1},
                        {-1,1},{1,0},{1,1}};

class Board{
    public:
        /*constructor*/
        Board(int size = 8);

        /*count the number of pieces of the color*/
        int count_pieces(int color);

        /*print the current board*/
        void print_board();

        /*start form square, move in a direction, 
        find the existence of the valid square 
        that bracketing opponent pieces */
        bool valid_move(pair<int,int> square, int dir);

        /*to judge whether the location square 
        is legal for the current player*/
        bool is_legal(pair<int,int> square);

        /*find all the legal squares 
        for the current player*/
        vector<pair<int,int> >  legal_squares();

        /*filp opponent pieces in a direction 
        started from square*/
        void filp(pair<int,int> square, int dir);

        /*filp opponent pieces in all the directions 
        started from square*/
        void make_filps(pair<int,int> square);

    private:
        size_t bsize;
        int turns;
        int ** board;
};
#endif