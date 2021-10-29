#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H

#include <ncurses.h>
#include <stdbool.h>

//Affiche le caractere d'une case de la grille
void changerCaractere(int grille[][], char blocCaractere[], int x, int y);

//Rafraichie l'�cran
void rafraichirEcran();

//Initialise les diff�rents composants de la fen�tre
void initFenetre();

//Ferme la fen�tre
void finFenetre();

//Renvoie si une touche est appuy�e sur le clavier � cet instant
bool isToucheAppuyee();

#endif

