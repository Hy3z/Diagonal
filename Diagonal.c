#include "Deplacement.h"
#include "MapManager.h"
#include <time.h>

//Delai entre 2 déplacements en secondes
const double CLOCK_DELAY = 0.05*CLOCKS_PER_SEC;
const int TAILLE = 20;
const int DEPART_X = 1;
const int DEPART_Y = 1;

int main(){
	int grille[30][100] ;

	initialiser_personnage(grille, TAILLE, DEPART_X, DEPART_Y);

	MapVide(grille, 100, 30);

    initFenetre();
    affiche(grille, 100, 30);
    rafraichirEcran();

    while( !blocSolide(prochain_bloc(grille))){
    //numero de la case du prochain deplacement)


        /*
        fait des trucs en fonction du numero de la case
        deplace le perso dans la liste
        fait des trucs au pif (animation par exemple)
        */

        deplace(grille);

        clock_t debutAttente = clock();
        while((double)(clock()-debutAttente)<CLOCK_DELAY){
            if(isToucheAppuyee()){
				inverse_vertical();
            }
        }

        rafraichirEcran();
    }
    finFenetre();
    return 0;
}
