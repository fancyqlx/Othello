#include "AI.h"
#include "Board.h"
#include <limits>
#include "Strategy.h"
#include <utility>
#include <cstdio>
using namespace std;


bool AI::move(Board & B){
    //cout<<"AI is moving..."<<endl;
    B.set_color(color);
    legal_vec = B.legal_squares();
    Board b = B;
    if(legal_vec.size()){
        while(1)
        {
            int alpha = numeric_limits<int>::min();
            int beta = numeric_limits<int>::max();
            int r_score = numeric_limits<int>::min();
            int level = 8;
            pair<int,int> square;
            for(vector<pair<int,int> >::iterator it=legal_vec.begin();it!=legal_vec.end();++it){
                if(alpha<=beta){
                    int score = alpha_beta(level-1,b,1-max,*it,alpha, beta);
                    if(score>alpha) alpha = score;
                    if(score>r_score){
                        r_score = score;
                        square = make_pair(it->first,it->second);
                    }
                }
                else{ break;}
            }
            B.print_board();
            getchar();
            cout<<COLOR[color]<<"'s turn. It puts the piece in:"
            <<square.first<<' '<<char('A'+square.second)<<endl;
            if(B.is_legal(square)){
                B.make_filps(square);
                B.print_board();
                break;
            }
        }
        return true;
    }
    return false;
}

int AI::evaluate(const Board & B){
    Strategy Sty;
    return Sty.get_score(B);
}

int AI::alpha_beta(int level, Board B, int max_min, pair<int,int> square, int alpha, int beta){
    //cout<<"alpha-beta searching: level "<<level<<endl;
    //cout<<square.first<<" "<<char('A'+square.second)<<endl;
    B.make_filps(square);
    if(level==0) return evaluate(B);
    int r_score = 0;
    if(max_min==max){
        B.set_color(color);
        r_score = numeric_limits<int>::min();
    }
    else{
        B.set_color(1-color);
        r_score = numeric_limits<int>::max();
    }
    vector<pair<int,int> > vec = B.legal_squares();
    for(vector<pair<int,int> >::iterator it=vec.begin();it!=vec.end();++it){
        if(alpha<=beta){
            int score = alpha_beta(level-1,B,1-max_min,*it, alpha, beta);
            if(max_min==max){
                if(score>alpha) alpha = score;
                if(score>r_score) r_score = score;
            }
            else{
                if(score<beta) beta = score;
                if(score<r_score) r_score = score;
            }
        }
        else{
            if(max_min==max) return (alpha<beta?alpha:beta);
            else return (alpha>beta?alpha:beta);
        }
    }
    return r_score;
}