#include <ncurses.h>
#include <stdbool.h>
#include "BlocManager.h"

void changerCaractere(int x, int y, char caractere){
    mvaddch(y, x, caractere);
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

void affiche(int grille[30][100], int max_x, int max_y){
    for(int y=0 ; y<max_y ; y++){
        for(int x=0 ; x<max_x ; x++){
			changerCaractere(x, y, blocCaractere(grille[y][x]));
		}
	}
}

void finFenetre(){
    endwin();
}

bool isToucheAppuyee(){
    return getch()!=ERR;
}
