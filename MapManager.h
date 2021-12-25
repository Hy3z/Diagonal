#ifndef MAPMANAGER_H
#define MAPMANAGER_H


#include <assert.h>


/*
Remplie les cases de (grille) d'indice:
    [[0, x-1]] en abcisse
    [[0, y-1]] en ordonné
par du vide et pose également les blocs de contour
*/
void mapVide(int grille[30][100], int x, int y) ;


/*
Modifie les cases de (grille) en fonction du numéro (niveau) du niveau que l'on shouhaite créer
Pour l'instant il n'y a qu'un seul niveau
*/
void creerNiveau(int niveau, int grille[30][100]);


//Modifie les cases de (grille) pour créer le niveau 1
void creerNiveau1(int grille[30][100]);


//Place des blocs aléatoirement dans la carte pour chaque colonne
void blocAleatoire(int grille[30][100], int x, int y);


#endif

