Diagonal: Diagonal.o BlocManager.o NCursesManager.o
	gcc Diagonal.o BlocManager.o NCursesManager.o -IC:\MinGW\include\ncurses -lncurses -o Diagonal

Diagonal.o: Diagonal.c BlocManager.h NCursesManager.h
	gcc -c Diagonal.c -IC:\MinGW\include\ncurses -lncurses

BlocManager.o: BlocManager.c
	gcc -c BlocManager.c

NCursesManager.o: NCursesManager.c
	gcc -c NCursesManager.c -IC:\MinGW\include\ncurses -lncurses

clean:
	rm -f *.o
	rm -f Diagonal
