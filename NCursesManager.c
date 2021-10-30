#include <ncurses.h>
#include <stdbool.h>

void changerCaractere(int grille[][], char blocCaractere[], int x, int y){
    mvaddch(y, x, blocCaractere[grille[y][x]]);
}

void rafraichirEcran(){
    refresh();
}

void initFenetre(){
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr,true);
    keypad(stdsrc, true);
}

void finFenetre(){
    endwin();
}

bool isToucheAppuyee(){
    return getch()!=ERR;
}
