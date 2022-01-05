#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H


#include <stdbool.h>


//Modifie le caractere d'une case (x,y) de la grille par le caract�re (caractere)
void changerCaractere(int x, int y, char caractere);


//Rafraichit l'�cran
void rafraichirEcran();


//Initialise les diff�rents composants de la fen�tre
void initFenetre();


//Ferme la fen�tre
void finFenetre();


/*
Affiche les caract�res de la grille:
    entre (0 et max_x)en abscisse
    entre (0 et max_y) en ordonn�e
*/
void affiche(int grille[30][100], const char BLOC_CARACTERE[], int max_x, int max_y);


//Renvoie si une touche est appuy�e sur le clavier a cet instant
bool isToucheAppuyee();


//Efface le contenu de la fen�tre NCurses
void effacer();


/*
Affiche le message de fin de partie
Attend qu'une touche soit appuy�e et renvoie true si une partie doit se relancer
*/
bool relancerPartie();


#endif

