#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*eight directions*/
const int DIRECTIONS[8][2] = {{-1,-1},{-1,0},{-1,-1},
                        {0,-1},{0,1},
                        {-1,1},{1,0},{1,1}};
const char COLOR[2][6] = {"WHITE","BLACK"};

class Board{
    public:
        /*constructor*/
        Board(int size = 8);

        /*count the number of pieces of the color*/
        int count_pieces(int);

        /*set color, means set the current player*/
        void set_color(int c);
        int get_color()const;

        /*get the board*/
        int ** get_board()const;

        /*get the size of board*/
        int get_size()const;

        /*set piece into c*/
        void set_piece(pair<int,int> square, int c);

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

        /*judge whether the game is over*/
        int who_is_winner();

    private:
        size_t bsize;
        int color;
        int ** board;
        int winner;
};
#endif