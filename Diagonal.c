#include "Deplacement.h"
#include "MapManager.h"
#include <time.h>

//Delai entre 2 d�placements en seconde
double secondes_delai  = 0.05;

//Delai entre 2 d�placements en nombre de ticks de processeur
double tick_delai;

//Taille de base du personnage
const int BASE_TAILLE = 20;

//Position de d�part en abscisse (DEPART_X) et en ordonn�e (DEPART_Y) du personnage
const int DEPART_X = 1;
const int DEPART_Y = 1;


int main(){
    //Le delai en ticks est le delai en secondes multipli� par le nombre de ticks par seconde
    double tick_delai = CLOCKS_PER_SEC*secondes_delai;


    //On cr�e notre grille de jeu qui est un tableau 2 dimension
	int grille[30][100];


    //On initialise le personnage avec la fonction (initialiser_personnage) d�clar�e dans "Deplacement.h"
	initialiser_personnage(grille, BASE_TAILLE, DEPART_X, DEPART_Y);


    //On cr�er le niveau 1 avec la fonction (creerNiveau) d�clar�e dans "MapManager.h"
	creerNiveau(1, grille);


	//On initialise la fen�tre avec la fonction (initFenetre) d�clar�e dans "MapManager.h"
    initFenetre();


    //On affiche la grille avec la fonction (affiche) d�clar�e dans "MapManager.h"
    //On raffra�chit l'�cran avec la fonction (rafraichirEcran) d�clar�e dans "NCursesManager.h"
    affiche(grille, 100, 30);
    rafraichirEcran();


    //La seule condition de fin de partie est la collision avec un bloc solide
    while( !blocSolide(prochain_bloc(grille))){


        /*
        fait des trucs en fonction du numero de la case
        fait des trucs au pif (animation par exemple)
        */


        //Deplace la personnage avec la fonction (deplace) d�clar�e dans "Deplacement.h"
        //Cette fonction modifie aussi le graphismes avec ncurses (sans raffraichir l'�cran)
        deplace(grille);


        //Valeur de temps en nombre de ticks de processeur
        clock_t debutAttente = clock();

        //On attend tant que le diff�rence de nombre de ticks processeur entre le d�but de l'attente et actuellement est inf�rieur au nombre de ticks que l'on doit attendre
        while((double)(clock()-debutAttente)<tick_delai){

            //Si jamais une touche est appuy�e durant ce d�lai, on inverse le deplacement vertical du personnage
            if(isToucheAppuyee()){
				inverse_vertical();
            }
        }


        //Raffraichit l'�cran pour afficher le d�placement du personnage
        rafraichirEcran();
    }

    //Le jeu est termin�, on ferme la fen�tre
    finFenetre();
    return 0;
}
