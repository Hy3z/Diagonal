#include <ncurses.h>

const char blocCaractere[] = {'!','-'};

void changerCaractere(int grille[][], int x, int y){
    mvaddch(y, x, blocCaractere[grille[y][x]);
}

void rafraichirEcran(){
    refresh();

}

void initEcran(double delai){
    initscr();
    halfdelay(delai);
}

void finEcran(){
    endwin();
}
