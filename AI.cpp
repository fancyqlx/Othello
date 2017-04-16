#include "AI.h"
#include "Board.h"


bool AI::move(Board & B){
    B.set_color(color);
    legal_vec = B.legal_squares();
    if(legal_vec.size()){
        while(1)
        {
            cout<<COLOR[color]<<"'s turn. Please input coordinates:X Y"<<endl;
            int x,y;
            cin>>x>>y;
            pair<int,int> square(x,y);
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