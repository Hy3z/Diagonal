Diagonal: Diagonal.o MapManager.o Deplacement.o NCursesManager.o BlocManager.o Personnage.o
	gcc Diagonal.o MapManager.o Deplacement.o NCursesManager.o BlocManager.o Personnage.o -o Diagonal -IC:\MinGW\include\ncurses -lncurses

Diagonal.o: Diagonal.c MapManager.h Deplacement.h
	gcc -c Diagonal.c -IC:\MinGW\include\ncurses -lncurses

BlocManager.o: BlocManager.c
	gcc -c BlocManager.c -IC:\MinGW\include\ncurses -lncurses

NCursesManager.o: NCursesManager.c BlocManager.h
	gcc -c NCursesManager.c -IC:\MinGW\include\ncurses -lncurses

MapManager.o: MapManager.c
	gcc -c MapManager.c
	
Deplacement.o: Deplacement.c NCursesManager.h Personnage.h
	gcc -c Deplacement.c -IC:\MinGW\include\ncurses -lncurses

Personnage.o: Personnage.c
	gcc -c Personnage.c



clean:
	rm -f *.o
	rm -f Diagonal
