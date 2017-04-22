#include "Strategy.h"
#include "Board.h"
#include <cstdlib>
using namespace std;

int Strategy::get_score(const Board & B){
    int size = B.get_size();
    int ** board = B.get_board();
    int** w = new int*[size];
    for(int i=0;i<size;++i) w[i] = new int[size]();
    w[0][0] = 120;
    w[0][1] = w[1][0] = -20;
    w[1][1] = -40;
    w[0][2]=w[2][0]=20;
    w[1][2]=w[2][1]=-5;
    w[2][2]=15;
    w[0][3]=w[3][0]=5;
    w[1][3]=w[3][1]=-5;
    w[2][3]=w[3][2]=w[3][3]=3;
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(w[i][j]!=0){
                w[i][size-j-1]=w[i][j];
                w[size-i-1][j]=w[i][j];
                w[size-i-1][size-j-1] = w[i][j];
            }
            if(w[i][j]==0){
                w[i][j] = rand()%3+1;
            }
        }
    }
    int p_score=0, o_score=0;
    int player=B.get_color(), opp=1-B.get_color();
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(board[i][j]==player) p_score += w[i][j];
            else if(board[i][j]==opp) o_score += w[i][j];
        }
    }
    return (p_score-o_score);
}