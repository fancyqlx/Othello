#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>
#include "Board.h"
using namespace std;

Board::Board(int size):bsize(size),color(1){
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

Board::Board(const Board& B){
    if(this != &B){
        bsize = B.bsize;
        color = B.color;
        board = new int* [bsize];
        for(int i=0;i<bsize;++i) board[i] = new int[bsize];
        for(int i=0;i<bsize;++i){
            for(int j=0;j<bsize;++j){
                board[i][j] = B.board[i][j];
            }
        }
    }
}

Board::~Board(){
    for(int i=0;i<bsize;++i) delete [] board[i];
}

int Board::count_pieces(int c){
    int nums = 0;
    for(int i=0;i<bsize;++i)
        for(int j=0;j<bsize;++j)
            if(board[i][j] == c)
                ++nums;
    return nums;
}

void Board::set_color(int c){
    color = c;
}

int Board::get_color()const{
    return color;
}

int ** Board::get_board()const{
    return board;
}

int Board::get_size()const{
    return bsize;
}

void Board::set_piece(pair<int,int> square, int c){
    int x = square.first, y = square.second;
    board[x][y] = c;
}

void Board::print_board(){
    cout<<setw(3)<<' ';
    for(int i=0;i<bsize;++i){
        cout<<left<<setw(2)<<char('A'+i);
    }
    cout<<"White:"<<count_pieces(0)
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
    int opt = 1 - color;
    bool flag = false;
    while(x>=0 && x<bsize && y>=0 && y<bsize && board[x][y] == opt){
        x += add_x;
        y += add_y;
        if(x>=0 && x<bsize && y>=0 && y<bsize && board[x][y] == 1-opt) flag = true;
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
            if(board[i][j] == -1 && is_legal(make_pair(i,j))) vec.push_back(make_pair(i,j));
    return vec;
}

void Board::filp(pair<int,int> square, int dir){
    int x = square.first, y = square.second;
    int add_x = DIRECTIONS[dir][0], add_y = DIRECTIONS[dir][1];
    x += add_x;
    y += add_y;
    int opt = 1 - color;
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
    set_piece(square,color);
}

int Board::who_is_winner(){
    return count_pieces(1)>count_pieces(0);
}