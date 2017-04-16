## Othello

### Usage:
run Othello to play a game, and you can add some arguments:
-HH : Human vs Human
-AH : AI vs Human
-AA : AI vs AI
-size= : set the size of square grid, default is 8
-help : print the help information of Othello

### What is Othello:
How to play the Game of Othello, 
an example of an 8x8 square grid: 

Othello is a game between two players on an 8x8 square grid
(64 positions). The two players, represented as black (B)
and white (W), initially occupy the center positions as
indicated below.

   A B C D E F G H
1  . . . . . . . . 
2  . . . . . . . . 
3  . . . . . . . . 
4  . . . W B . . . 
5  . . . B W . . . 
6  . . . . . . . . 
7  . . . . . . . . 
8  . . . . . . . . 

Black moves first, and places a 'B' somewhere on an *empty* location
(indicated by a '.'). There are constraints on where the B may be
placed though (other than 'empty'). Notably, the B must be placed
so that it brackets or sandwiches a contiguous sequence of
opponent pieces. So, a b can be placed at coordinates (3,D), (4,C), (5,F),
or (6,E). When a B is placed that causes a sequence of ws to be bracketed,
the ws that are bracketed are flipped to B (i.e., from the opponent's
color to the current player's color). So, placing a 'B' at (5,F)
leads to the following board:

   A B C D E F G H
1  . . . . . . . . 
2  . . . . . . . . 
3  . . . . . . . . 
4  . . . W B . . . 
5  . . . B B B . . 
6  . . . . . . . . 
7  . . . . . . . . 
8  . . . . . . . . 

White now moves. Any move must bracket at least one B piece,
and after doing so, the Bs in the bracketed sequence are
switched to ws. For the board above, W could be placed on (6,D),
(4,F), or (6,F) -- note that one can bracket pieces along a
diagnoal. If W is placed on (6,F), the resulting board is:

   A B C D E F G H
1  . . . . . . . . 
2  . . . . . . . . 
3  . . . . . . . . 
4  . . . W B . . . 
5  . . . B W B . . 
6  . . . . . W . . 
7  . . . . . . . . 
8  . . . . . . . . 

Play continues until neither player can move. Very often, this
happens when all sqaures are filled, but both players may
be unable to bracket a sequence of opponents' pieces before all
squares are filled, and so the game stops before all squares
are filled. The player with the most squares filled at game's
end, wins.

If one player cannot move (because they cannot bracket an opposing
sequence), but the other player can move, then the former player
must pass until such time that they can move.
===============================================================
