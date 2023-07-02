CC=clang
CFLAGS=-Wall -std=c17
LDLIBS=-lncurses
OBJ=main.c graphique.c echiquier.c


huitdame: $(OBJ)
	$(CC)  -o  $@  $^ $(LDLIBS)

echiquier:  echiquier.c echiquier.h
	$(CC)  $(CFLAGS) -c  -o  $@  $< 

graphique: graphique.c graphique.h
	$(CC)  $(CFLAGS) -c  -o  $@  $< 


clean:
	rm -f *.o