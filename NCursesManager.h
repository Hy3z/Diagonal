#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H

#include <ncurses.h>
#include <stdbool.h>

//Affiche le caractere d'une case de la grille
void changerCaractere(int grille[][], char blocCaractere[], int x, int y);

//Rafraichie l'écran
void rafraichirEcran();

//Initialise les différents composants de la fenêtre
void initFenetre();

//Ferme la fenêtre
void finFenetre();

//Renvoie si une touche est appuyée sur le clavier à cet instant
bool isToucheAppuyee();

#endif

