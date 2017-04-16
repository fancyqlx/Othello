#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <cstring>
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Board.h"
using namespace std;

/*print the help information from Readme*/
void help(){
    fstream fin("Readme",fstream::in);
    if(fin){
        string line;
        while(getline(fin,line))
            cout<<line<<endl;
    }
    fin.close();
}

/*Playing game*/
void play_game(int type, int size){
    Board B(size);
    Player * PLAYER[2];
    switch(type){
        case 0:
            PLAYER[0] = new Human(0);
            PLAYER[1] = new Human(1);
            break;
        case 1:
            PLAYER[0] = new AI(0);
            PLAYER[1] = new Human(1);
            break;
        case 2:
            PLAYER[0] = new AI(0);
            PLAYER[1] = new AI(1);
            break;
    }
    /*game start*/
    cout<<"********GAME START!********"<<endl;
    B.print_board();
    int c_play = 1;
    while(1){
        if(PLAYER[c_play]->move(B)){
            c_play = 1 - c_play;
        }else if(!PLAYER[1-c_play]->move(B)){
            break;
        }
    }
    cout<<"********GAME OVER!********"<<endl;
    cout<<COLOR[B.who_is_winner()]<<" is WINNER!"<<endl;
}

int main(int argc, char **argv){
    /*the type of game:
    0: Human vs Human
    1: AI vs Human
    2: AI vs AI
    */
    int type = 0;

    /*default size of grid is 8*/
    int size = 8;

    if(argc == 1){
        /*let user selet game style if no argument provided*/
        cout<<"Pleaes select the type of the game: 1 2 or 3"<<endl;
        cout<<"1: Human vs Human "<<"2: AI vs Human "<<"3: AI vs AI"<<endl;
        cout<<"Input: ";
        cin>>type;
        --type;
        /*game starts*/
        play_game(type,size);
    }
    else if(argc < 6){
        /*check arguments*/
        bool flag = true;
        for(int i=1;i<argc;++i){
            if(strcmp(argv[i],"-HH")==0) type = 0;
            else if(strcmp(argv[i],"-AH")==0) type = 1;
            else if(strcmp(argv[i],"-AA")==0) type = 2;
            else if(strcmp(argv[i],"-help")==0) help();
            else{
                string s = "";
                int j = 0;
                while(j<strlen(argv[i]) && j<6){
                    s += argv[i][j];
                    ++j;
                }
                if(s == "-size="){
                    int num = 0;
                    while(j<strlen(argv[i])){
                        num = num * 10 + argv[i][j];
                        ++j;
                    }
                    if(num <= 26) size = num;
                    else size = 8;
                }
                else{
                    cerr<<"---wrong arguments!---"<<endl;
                    flag = false;
                }
            }
        }
        /*if arguments is right, the game starts*/
        if(flag){
            play_game(type,size);
        }
    }
    else{
        cerr<<"---only five arguments allowed!---"<<endl;
    }
    return 0;
}