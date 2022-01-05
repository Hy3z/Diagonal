#ifndef NCURSESMANAGER_H
#define NCURSESMANAGER_H


#include <stdbool.h>


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
void affiche(int grille[30][100], const char BLOC_CARACTERE[], int max_x, int max_y);


//Renvoie si une touche est appuyée sur le clavier a cet instant
bool isToucheAppuyee();


//Efface le contenu de la fenêtre NCurses
void effacer();


/*
Affiche le message de fin de partie
Attend qu'une touche soit appuyée et renvoie true si une partie doit se relancer
*/
bool relancerPartie();


#endif

