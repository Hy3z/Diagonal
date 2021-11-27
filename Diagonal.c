#include "BlocManager.h"
#include "NCursesManager.h"
#include "Map_Manager.h"
#include "deplacementsjoueur.h"
#include <time.h>
#include <ncurses.h>

//Delai entre 2 déplacements en secondes
const double CLOCK_DELAY = 0.05*CLOCKS_PER_SEC;



int main(){
	int taille_ecran_x = 30 ;
	int taille_ecran_y = 100 ;
	int grille[30][100] ;
	MapVide(grille, 30, 100);
	modif_pos(4,4);
    grille[4][4] = 1;
    initFenetre();
    affiche(grille, BLOC_CARACTERE, 30, 100);
    rafraichirEcran();
    while( !isBlocSolide(prochcase(grille,30, 100))){
    //numero de la case du prochain deplacement)


        /*
        fait des trucs en fonction du numero de la case
        deplace le perso dans la liste
        fait des trucs au pif (animation par exemple)
        */
        if(p.x==3) inverse_horizontale();
        if(p.x==97) inverse_horizontale();

		deplace_joueur(grille,30,100);
        changerCaractere(grille, BLOC_CARACTERE, p.y, p.x);



        clock_t debutAttente = clock();


        while((double)(clock()-debutAttente)<CLOCK_DELAY){
            if(isToucheAppuyee()){
				inverse_verticale();
            }
        }
        rafraichirEcran();
    }
    finFenetre();
    return 0;
}
