poker: poker.o deck.o card.o player.o interface.o analysis.o monte.o
	gcc -Wall -o poker poker.o deck.o card.o player.o interface.o analysis.o monte.o

poker.o: poker.c hedz.h
	gcc -Wall -c poker.c

deck.o: deck.c hedz.h
	gcc -Wall -c deck.c

card.o: card.c hedz.h
	gcc -Wall -c card.c

player.o: player.c hedz.h
	gcc -Wall -c player.c

interface.o: interface.c hedz.h
	gcc -Wall -c interface.c

analysis.o: analysis.c hedz.h
	gcc -Wall -c analysis.c

monte.o: monte.c hedz.h
	gcc -Wall -c monte.c

make clean:
	rm -f *.o
