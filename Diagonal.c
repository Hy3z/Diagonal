#include "Deplacement.h"
#include "MapManager.h"
#include <time.h>

//Delai entre 2 déplacements en seconde
double secondes_delai  = 0.05;

//Delai entre 2 déplacements en nombre de ticks de processeur
double tick_delai;

//Taille de base du personnage
const int BASE_TAILLE = 20;

//Position de départ en abscisse (DEPART_X) et en ordonnée (DEPART_Y) du personnage
const int DEPART_X = 1;
const int DEPART_Y = 1;


int main(){
    //Le delai en ticks est le delai en secondes multiplié par le nombre de ticks par seconde
    double tick_delai = CLOCKS_PER_SEC*secondes_delai;


    //On crée notre grille de jeu qui est un tableau 2 dimension
	int grille[30][100];


    //On initialise le personnage avec la fonction (initialiser_personnage) déclarée dans "Deplacement.h"
	initialiser_personnage(grille, BASE_TAILLE, DEPART_X, DEPART_Y);


    //On créer le niveau 1 avec la fonction (creerNiveau) déclarée dans "MapManager.h"
	creerNiveau(1, grille);


	//On initialise la fenêtre avec la fonction (initFenetre) déclarée dans "MapManager.h"
    initFenetre();


    //On affiche la grille avec la fonction (affiche) déclarée dans "MapManager.h"
    //On raffraîchit l'écran avec la fonction (rafraichirEcran) déclarée dans "NCursesManager.h"
    affiche(grille, 100, 30);
    rafraichirEcran();


    //La seule condition de fin de partie est la collision avec un bloc solide
    while( !blocSolide(prochain_bloc(grille))){


        /*
        fait des trucs en fonction du numero de la case
        fait des trucs au pif (animation par exemple)
        */


        //Deplace la personnage avec la fonction (deplace) déclarée dans "Deplacement.h"
        //Cette fonction modifie aussi le graphismes avec ncurses (sans raffraichir l'écran)
        deplace(grille);


        //Valeur de temps en nombre de ticks de processeur
        clock_t debutAttente = clock();

        //On attend tant que le différence de nombre de ticks processeur entre le début de l'attente et actuellement est inférieur au nombre de ticks que l'on doit attendre
        while((double)(clock()-debutAttente)<tick_delai){

            //Si jamais une touche est appuyée durant ce délai, on inverse le deplacement vertical du personnage
            if(isToucheAppuyee()){
				inverse_vertical();
            }
        }


        //Raffraichit l'écran pour afficher le déplacement du personnage
        rafraichirEcran();
    }

    //Le jeu est terminé, on ferme la fenêtre
    finFenetre();
    return 0;
}
