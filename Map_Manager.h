#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H
#include <stdbool.h>

/* Codes numériques pour désigner le vide, les murs, sols, coin, ect.
const int VIDE ;
const int MUR ;
const int SOL ;
const int COIN ;
const int BLOCK ; */

/* La map sera représentée par le type int map[][] */

/* Fonction pour créer d'une map vide avec seulement les contours */
void MapVide(int map[30][100], int x, int y) ;

/* Fonction pour créer les différentes structures 	*/
void SetUpStructure (int map[30][100], int obj , int x , int y , int t) ;

/* Fonction pour dessiner les coins selon leur situation*/
void Coin( int map[30][100] , int x , int y ) ;

/* Fonction pour afficher le contour */
void AfficheContour(int map[30][100] , int x , int y ) ;

/* Fonction pour afficher la map*/
void AfficheMap( int map[30][100] , int x  , int y  ) ;

/* Fonction permettant de poser un objet */
void PoseObjet( int obj , int map[30][100] , int x ,int y ) ;

#endif

