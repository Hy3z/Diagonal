/* Ligne = x , colonne = y */

#include <assert.h>

/* Cr�ation du map vide avec seulement les contours */
void MapVide(int grille[30][100], int x, int y) {
	assert (x > 0 && y > 0) ;

	/* Cr�ations du centre ( vide )  */
	for (int i = 0 ; i < y ; i ++ ) {
		for (int j = 0 ; j < x ; j ++ ) {
			grille[i][j] = 0 ;
		}
	}
	/* Cr�ation des cot�s ( mur ) */
	for (int i = 1 ; i < y ; i ++ ) {
		grille[i][x-1] = 3 ;
		grille[i][0] = 3 ;
	}
	/* Cr�ation des cot�s ( Sol et plafond ) */
	for (int j = 1 ; j < x ; j ++ ) {
		grille[y-1][j] = 2 ;
		grille[0][j] = 2 ;
	}
	/* Cr�ation des coins */
	grille[0][0] = 6 ;
	grille[y-1][x-1] = 7 ;
	grille[y-1][0] = 5 ;
	grille[0][x-1] = 4 ;
}


