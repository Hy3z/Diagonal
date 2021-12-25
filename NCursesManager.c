#include <ncurses.h>
#include <stdbool.h>
#include <assert.h>
#include "BlocManager.h"


/*
La fonction mvaddch de ncurses prend la valeur en ordonn�e en 1er argument et la valeur en abscisse en 2eme

Pr�condition:
    (x) est un entier naturel
    (y) est un entier naturel
*/
void changerCaractere(int x, int y, char caractere){
    //pr�condition
    assert(x>=0 && y>=0);

    mvaddch(y, x, caractere);
}

//Appelle la fonction refresh de ncurses qui raffrach�t les caract�res affich�s sur l'�cran
void rafraichirEcran(){
    refresh();
}


void initFenetre(){
    //Initialise la f�netre ncurses
    initscr();

    //Indique au clavier que relacher une touche n'est pas la m�me action que l'appuyer
    noecho();

    //Masque le curseur en jeu
    curs_set(0);

    //Indique � ncurses de ne pas attendre, lors de l'appel de la fonction (getch), qu'une touche soit appuy�e
    nodelay(stdscr,true);

    //Indique � ncurses que toutes les touches du clavier peuvent �tre enfonc�es lors du jeu
    keypad(stdscr, true);
}


/*
Pr�conditions:
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
    //Ferme la f�netre de ncurses
    endwin();
}


bool isToucheAppuyee(){
    //getch renvoit une valeur lorsque une touche vient d'�tre enfonc�e
    return getch()!=ERR;
}
