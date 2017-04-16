Obj = Othello.o Board.o Player.o \
 	Human.o AI.o

Othello: $(Obj)
	g++ $(Obj) -o Othello

$(Obj): Board.h 

.PHONY: clean
clean:
	rm $(Obj) Othello
