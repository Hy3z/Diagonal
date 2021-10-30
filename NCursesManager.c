#include <ncurses.h>
#include <stdbool.h>

void changerCaractere(int grille[0][0], const char BLOC_CARACTERE[], int x, int y){
    mvaddch(y, x, BLOC_CARACTERE[grille[y][x]]);
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

void finFenetre(){
    endwin();
}

bool isToucheAppuyee(){
    return getch()!=ERR;
}
