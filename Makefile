Diagonal: Diagonal.o MapManager.o Deplacement.o NCursesManager.o BlocManager.o Personnage.o
	gcc Diagonal.o MapManager.o Deplacement.o NCursesManager.o BlocManager.o Personnage.o -o Diagonal -lncurses

Diagonal.o: Diagonal.c MapManager.h Deplacement.h NCursesManager.h BlocManager.h
	gcc -c Diagonal.c

BlocManager.o: BlocManager.c
	gcc -c BlocManager.c

NCursesManager.o: NCursesManager.c
	gcc -c NCursesManager.c -lncurses

MapManager.o: MapManager.c
	gcc -c MapManager.c
	
Deplacement.o: Deplacement.c Personnage.h
	gcc -c Deplacement.c

Personnage.o: Personnage.c
	gcc -c Personnage.c

clean:
	rm -f *.o
	rm -f Diagonal
