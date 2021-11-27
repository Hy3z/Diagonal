Diagonal: Diagonal.o BlocManager.o NCursesManager.o Map_Manager.o deplacementsjoueur.o
	gcc Diagonal.o BlocManager.o NCursesManager.o Map_Manager.o deplacementsjoueur.o -IC:\MinGW\include\ncurses -lncurses -o Diagonal

Diagonal.o: Diagonal.c BlocManager.h NCursesManager.h Map_Manager.h deplacementsjoueur.h
	gcc -c Diagonal.c -IC:\MinGW\include\ncurses -lncurses

BlocManager.o: BlocManager.c
	gcc -c BlocManager.c -IC:\MinGW\include\ncurses -lncurses

NCursesManager.o: NCursesManager.c
	gcc -c NCursesManager.c -IC:\MinGW\include\ncurses -lncurses

Map_Manager.o: Map_Manager.c
	gcc -c Map_Manager.c -IC:\MinGW\include\ncurses -lncurses
	
deplacementsjoueur.o: deplacementsjoueur.c
	gcc -c deplacementsjoueur.c -IC:\MinGW\include\ncurses -lncurses

clean:
	rm -f *.o
	rm -f Diagonal
