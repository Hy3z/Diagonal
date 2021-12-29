#ifndef MAPMANAGER_H
#define MAPMANAGER_H


/*
Remplie les cases de (grille) d'indice:
    [[0, x-1]] en abcisse
    [[0, y-1]] en ordonn�
par du vide et pose �galement les blocs de contours
*/
void mapVide(int grille[30][100], int x, int y) ;


/*
Modifie les cases de (grille) en fonction du num�ro (niveau) du niveau que l'on shouhaite cr�er
Pour l'instant il n'y a qu'un seul niveau
*/
void creerNiveau(int niveau, int grille[30][100]);


//Modifie les cases de (grille) pour cr�er le niveau 1
void creerNiveau1(int grille[30][100]);


/*
Place des blocs al�atoirement dans la carte pour chaque colonne avec un bloc par colonne
Les num�ros des colonnes sont compris entre min_x et max_x inclus
Les blocs peuvent se placer sur les lignes entre min_y et max_y inclus
*/
void blocAleatoire(int grille[30][100], int min_x, int min_y, int max_x, int max_y);


#endif

