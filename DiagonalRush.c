#include "Deplacement.h"
#include "MapManager.h"
#include "NCursesManager.h"
#include "BlocManager.h"
#include <time.h>
#include <stdio.h>


//Delai entre 2 déplacements en seconde
double secondes_delai;

//Delai entre 2 déplacements en nombre de ticks de processeur
double tick_delai;

//Taille de base du personnage
const int BASE_TAILLE = 20;

//Position de départ en abscisse (DEPART_X) et en ordonnée (DEPART_Y) du personnage
const int DEPART_X = 1;
const int DEPART_Y = 1;


//Variable contenant le personnage
personnage perso;


//Fonction éxécutant les différentes fonction de test des blocs de code (rien à tester pour NCursesManager)
int testDiagonalRush(){
    printf("==============Début des tests==============");
    printf("\n");

    testBlocManager();

    testPersonnage();

    testMapManager(obtenirNOMBRE_BLOCS());

    int grille[30][100];
    grilleVide(grille,100,30);
    testDeplacement(grille, obtenirNOMBRE_BLOCS());

    printf("\n");
    printf("==============Fin des tests==============");
    printf("\n");
}


//Fonction démarrant le jeu, avec en paramètre le délai et la niveau à charger
void diagonalRush(float secondes_delai, int niveau){

    //Le delai en ticks est le delai en secondes multiplié par le nombre de ticks par seconde
    double tick_delai = CLOCKS_PER_SEC*secondes_delai;


    //On crée notre grille de jeu qui est un tableau 2 dimension
	int grille[30][100];


    //On initialise le personnage avec la fonction (initialiser_personnage) déclarée dans "Deplacement.h"
	perso = initialiser_personnage(grille, BASE_TAILLE, DEPART_X, DEPART_Y);


    //On créer le niveau 1 avec la fonction (creerNiveau) déclarée dans "MapManager.h"
	creerNiveau(niveau, grille);


	//On initialise la fenêtre avec la fonction (initFenetre) déclarée dans "NCursesManager.h"
    initFenetre();


    //On affiche la grille avec la fonction (affiche) déclarée dans "NCursesManager.h"
    //On raffraîchit l'écran avec la fonction (rafraichirEcran) déclarée dans "NCursesManager.h"
    affiche(grille, BLOC_CARACTERE, 100, 30);
    rafraichirEcran();


    //La seule condition de fin de partie est la collision avec un bloc solide
    while( !blocSolide(prochain_bloc(perso, grille))){


        //Recupère les ancienne position de la queue et de la tête afin de mettre à jour les graphismes
        position ancienneTetePosition = positionTete(perso);
        position ancienneQueuePosition = positionQueue(perso);

        //Deplace la personnage avec la fonction (deplace) déclarée dans "Deplacement.h"
        deplace(&perso, grille);

        //Récupère la nouvelle position de la tête afin de mettre à jour les graphismesi
        position nouvelleTetePosition = positionTete(perso);


        //On met à jour le caractère de la nouvelle tête
        changerCaractere(nouvelleTetePosition.x,
                         nouvelleTetePosition.y,
                         blocCaractere(grille[nouvelleTetePosition.y][nouvelleTetePosition.x]));

        /*
        Les queues créées par la fonction (creer) de "Personnage.h" ont pour coordonnées (-1, -1)
        On test donc les coordonnées de cette queue pour savoir si il y a quelque chose à mettre à jour dans les graphismes
        */
        if(ancienneQueuePosition.x >= 0 && ancienneQueuePosition.y >= 0){
            changerCaractere(ancienneQueuePosition.x,
                             ancienneQueuePosition.y,
                             blocCaractere(grille[ancienneQueuePosition.y][ancienneQueuePosition.x]));
        }

        //On met à jour le caractère de l'ancienne tête
        changerCaractere(ancienneTetePosition.x,
                         ancienneTetePosition.y,
                         blocCaractere(grille[ancienneTetePosition.y][ancienneTetePosition.x]));


        //Valeur de temps en nombre de ticks de processeur, début de l'attente
        clock_t debutAttente = clock();

        /*
        On attend tant que la différence de nombre de ticks processeur entre le début de l'attente et actuellement est inférieure au nombre de ticks que l'on doit attendre

        Invariant de boucle: (partie entière de (tick_delai))
        Variant de boucle: (partie entière de (tick_delai - (clock() - debutAttente)))
        */
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
}


int main(){
    //testDiagonalRush();
    diagonalRush(0.1, 1);
    return 0;
}
