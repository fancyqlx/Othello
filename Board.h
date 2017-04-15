#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <utility>
using namespace std;

class Board{
    public:
        /*constructor*/
        Board():bsize(8),turns(1){}

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
        pair<int,int> * legal_squares();

        /*filp opponent pieces in a direction 
        started from square*/
        void filp(pair<int,int> index, int dir);

        /*filp opponent pieces in all the directions 
        started from square*/
        void make_filps(pair<int,int> square, int * dirs);

    private:
        size_t bsize;
        int turns;
        int ** board;
};

#endif