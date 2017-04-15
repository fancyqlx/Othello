#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>
#include "Board.h"
using namespace std;

Board::Board(int size):bsize(size),turns(1){
    board = new int* [bsize];
    for(int i=0;i<bsize;++i) board[i] = new int[bsize];
    for(int i=0;i<bsize;++i)
        for(int j=0;j<bsize;++j)
            board[i][j] = -1;
    /*0 represents white piece*/
    board[bsize/2-1][bsize/2-1] = board[bsize/2][bsize/2] = 0;
    /*1 represents black piece*/
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
    string s = "   ";
    for(int i=0;i<bsize;++i){
        s += i + '0';
        s += " ";
    }
    cout<<s<<"White:"<<count_pieces(0)
    <<' '<<"Black:"<<count_pieces(1)<<endl;
    for(int i=0;i<bsize;++i){
        cout<<left<<setw(3)<<i;
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

bool Board::valid_move(pair<int,int> square, int dir){
    int x = square.first, y = square.second;
    int add_x = DIRECTIONS[dir][0], add_y = DIRECTIONS[dir][1];
    x += add_x;
    y += add_y;
    int opt = 1 - turns;
    bool flag = false;
    while(x>=0 && x<bsize && y>=0 && y<bsize && board[x][y] == opt){
        x += add_x;
        y += add_y;
        if(board[x][y] == 1-opt) flag = true;
    }
    return flag;
}

bool Board::is_legal(pair<int,int> square){
    bool flag = false;
    for(int i=0;i<8;++i)
        flag |= valid_move(square,i);
    return flag;
}

vector<pair<int,int> > Board::legal_squares(){
    vector<pair<int,int> > vec;
    for(int i=0;i<bsize;++i)
        for(int j=0;j<bsize;++j)
            if(is_legal(make_pair(i,j))) vec.push_back(make_pair(i,j));
    return vec;
}

void Board::filp(pair<int,int> square, int dir){
    int x = square.first, y = square.second;
    int add_x = DIRECTIONS[dir][0], add_y = DIRECTIONS[dir][1];
    x += add_x;
    y += add_y;
    int opt = 1 - turns;
    if(valid_move(square,dir)){
        while(board[x][y] == opt){
            board[x][y] = 1 - opt;
            x += add_x;
            y += add_y;
        }
    }
}

void Board::make_filps(pair<int,int> square){
    for(int i=0;i<8;++i)
        filp(square,i);
}