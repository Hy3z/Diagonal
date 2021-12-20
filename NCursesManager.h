#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H

#include <ncurses.h>
#include <stdbool.h>
#include "BlocManager.h"

//Affiche le caractere d'une case de la grille
void changerCaractere(int x, int y, char caractere);

//Rafraichie l'�cran
void rafraichirEcran();

//Initialise les diff�rents composants de la fen�tre
void initFenetre();

//Ferme la fen�tre
void finFenetre();

void affiche(int grille[30][100], int max_x, int max_y);

//Renvoie si une touche est appuy�e sur le clavier � cet instant
bool isToucheAppuyee();

#endif

