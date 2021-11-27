#include <ncurses.h>
#include <stdbool.h>

void changerCaractere(int grille[30][100], const char BLOC_CARACTERE[], int x, int y){
    mvaddch(x, y, BLOC_CARACTERE[grille[x][y]]);
}

void rafraichirEcran(){
    refresh();
}

void initFenetre(){
    initscr();
    noecho();
    curs_set(false);
    nodelay(stdscr,true);
    keypad(stdscr, true);
}

void affiche(int map[30][100], const unsigned char BLOC_CARACTERE[], int x, int y){
	for(int x1=0 ; x1<x ; x1++){
		for(int y1=0 ; y1<y ; y1++){
			changerCaractere(map, BLOC_CARACTERE, x1, y1);
		}
	}
}

void finFenetre(){
    endwin();
}

bool isToucheAppuyee(){
    return getch()!=ERR;
}
