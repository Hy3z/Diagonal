#include <assert.h>


/*
Num�ro des blocs correspondant aux nom des variables list�es si-dessous
Pour v�rifier la correspondance, consulter le tableau des blocs
*/
int VIDE = 0;
int MUR_HORIZONTAL = 2;
int MUR_VERTICAL = 3;
int COIN_HAUT_GAUCHE = 4;
int COIN_HAUT_DROIT = 5;
int COIN_BAS_GAUCHE = 6;
int COIN_BAS_DROIT = 7;


/*
Pr�conditions:
    x est un entier naturel non-nul
    y est un entier naturel non-nul
Postcondition:
    (
    Pour tout x0 appartenant � [[0, x-1]] ,
    Pour tout y0 appartenant � [[0, y-1]]
    ):
        grille[y0][x0] est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager.c)
*/
void mapVide(int grille[30][100], int x, int y) {

    //precondition
	assert (x > 0 && y > 0) ;


	//On remplit la sous grille de vide
	for (int i = 0 ; i < y ; i ++ ) {
		for (int j = 0 ; j < x ; j ++ ) {
			grille[i][j] = VIDE ;
		}
	}


	//On inscrit dans la grille les c�t�s gauche et droit de murs verticaux (piliers)
	for (int i = 1 ; i < y ; i ++ ) {
		grille[i][x-1] = MUR_VERTICAL ;
		grille[i][0] = MUR_VERTICAL ;
	}


	//On inscrit dans la grille les c�t�s haut et bas de murs horizontaux (sol & plafond)
	for (int j = 1 ; j < x ; j ++ ) {
		grille[y-1][j] = MUR_HORIZONTAL ;
		grille[0][j] = MUR_HORIZONTAL ;
	}


	//On pose dans chaque coin le bloc qui lui correspond
	grille[0][0] = COIN_HAUT_GAUCHE;
	grille[y-1][x-1] = COIN_BAS_DROIT;
	grille[y-1][0] = COIN_BAS_GAUCHE ;
	grille[0][x-1] = COIN_HAUT_DROIT ;
}


void creerNiveau1(int grille[30][100]){
    mapVide(grille, 100, 30);
}


/*Pr�condition:
    (x) est un entier naturel
    (y) est un entier naturel
*/
void blocAleatoire(int grille[30][100], int x, int y){
    //precondition
    assert(x>=0 && y>=0);
}


/*Pr�condition:
    (niveau) est un entier naturel non-nul
*/
void creerNiveau(int niveau, int grille[30][100]){
    //precondition
    assert(niveau > 0);

    switch (niveau){
    case 1:
        creerNiveau1(grille);
        break;
    default:
        creerNiveau1(grille);
        break;
    }
}
