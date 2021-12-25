#include <ncurses.h>
#include <stdbool.h>
#include <assert.h>
#include "BlocManager.h"


/*
La fonction mvaddch de ncurses prend la valeur en ordonnée en 1er argument et la valeur en abscisse en 2eme

Précondition:
    (x) est un entier naturel
    (y) est un entier naturel
*/
void changerCaractere(int x, int y, char caractere){
    //précondition
    assert(x>=0 && y>=0);

    mvaddch(y, x, caractere);
}

//Appelle la fonction refresh de ncurses qui raffrachît les caractères affichés sur l'écran
void rafraichirEcran(){
    refresh();
}


void initFenetre(){
    //Initialise la fênetre ncurses
    initscr();

    //Indique au clavier que relacher une touche n'est pas la même action que l'appuyer
    noecho();

    //Masque le curseur en jeu
    curs_set(0);

    //Indique à ncurses de ne pas attendre, lors de l'appel de la fonction (getch), qu'une touche soit appuyée
    nodelay(stdscr,true);

    //Indique à ncurses que toutes les touches du clavier peuvent être enfoncées lors du jeu
    keypad(stdscr, true);
}


/*
Préconditions:
    (max_x) est un entier naturel
    (max_y) est un entier naturel
*/
void affiche(int grille[30][100], int max_x, int max_y){
    //precondition
    assert(max_x >= 0 && max_y >= 0);

    for(int y=0 ; y<max_y ; y++){
        for(int x=0 ; x<max_x ; x++){
			changerCaractere(x, y, blocCaractere(grille[y][x]));
		}
	}
}


void finFenetre(){
    //Ferme la fênetre de ncurses
    endwin();
}


bool isToucheAppuyee(){
    //getch renvoit une valeur lorsque une touche vient d'être enfoncée
    return getch()!=ERR;
}
