#include <iostream>
#include <utility>
#include <string>
#include "Board.h"
using namespace std;

Board::Board:bsize(8),turns(1){
    board = new int[bsize];
    for(int i=0;i<bsize;++i) board[i] = new int[bsize];
    for(int i=0;i<bsize;++i)
        for(int j=0;j<bsize;++j)
            board[i][j] = -1;
    /*0 represents white piece*/
    board[bsize/2-1][bsize/2-1] = board[bsize/2][bsize/2] = 0;
    /*1 represents black peice*/
    board[bsize/2-1][bsize/2] = board[bsize/2][bsize/2-1] = 1;
}

int Board::count_pieces(int color){
    int nums = 0;
    for(int i=0;i<bsize;++i)
        for(int j=0;j<bsize;++j)
            if(board[i][j] == color)
                ++nums;
    return nums;
}

void Board::print_board(){
    string = s = "  ";
    for(int i=0;i<bsize;++i)
        s += (i + '0') + ' ';
    cout<<s<<"White:"<<count_pieces(0)
    <<' '<<"Black:"<<count_pieces(1)<<endl;
    for(int i=0;i<bsize;++i){
        cout<<i<<' ';
        for(int j=0;j<bsize;++j){
            switch(board[i][j]){
                case -1:
                    cout<<'.'<<' ';
                    break;
                case 0:
                    cout<<'W'<<' ';
                    break;
                case 1:
                    cout<<'B'<<' ';
                    break;
            }
        }
        cout<<endl;
    }
}
