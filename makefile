Obj = Board.o

Othello: $(Obj)
	g++ $(Obj) -o Othello

$(Obj): Board.h

.PHONY: clean
clean:
	rm $(Obj) Othello
