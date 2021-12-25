#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H


#include <ncurses.h>
#include <stdbool.h>
#include <assert.h>
#include "BlocManager.h"


//Modifie le caractere d'une case (x,y) de la grille par le caractère (caractere)
void changerCaractere(int x, int y, char caractere);


//Rafraichit l'écran
void rafraichirEcran();


//Initialise les différents composants de la fenêtre
void initFenetre();


//Ferme la fenêtre
void finFenetre();


/*
Affiche les caractères de la grille:
    entre (0 et max_x)en abscisse
    entre (0 et max_y) en ordonnée
*/
void affiche(int grille[30][100], int max_x, int max_y);


//Renvoie si une touche est appuyée sur le clavier a cet instant
bool isToucheAppuyee();


#endif

