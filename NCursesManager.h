#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H

#include <ncurses.h>
#include <stdbool.h>
#include "BlocManager.h"

//Affiche le caractere d'une case de la grille
void changerCaractere(int x, int y, char caractere);

//Rafraichie l'écran
void rafraichirEcran();

//Initialise les différents composants de la fenêtre
void initFenetre();

//Ferme la fenêtre
void finFenetre();

void affiche(int grille[30][100], int max_x, int max_y);

//Renvoie si une touche est appuyée sur le clavier à cet instant
bool isToucheAppuyee();

#endif

