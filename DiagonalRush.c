#include "Deplacement.h"
#include "MapManager.h"
#include "NCursesManager.h"
#include "BlocManager.h"
#include <time.h>
#include <stdio.h>


//Delai entre 2 d�placements en seconde
double secondes_delai;

//Delai entre 2 d�placements en nombre de ticks de processeur
double tick_delai;

//Taille de base du personnage
const int BASE_TAILLE = 20;

//Position de d�part en abscisse (DEPART_X) et en ordonn�e (DEPART_Y) du personnage
const int DEPART_X = 1;
const int DEPART_Y = 1;


//Variable contenant le personnage
personnage perso;


//Fonction �x�cutant les diff�rentes fonction de test des blocs de code (rien � tester pour NCursesManager)
int testDiagonalRush(){
    printf("==============D�but des tests==============");
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


//Fonction d�marrant le jeu, avec en param�tre le d�lai et la niveau � charger
void diagonalRush(float secondes_delai, int niveau){

    //Le delai en ticks est le delai en secondes multipli� par le nombre de ticks par seconde
    double tick_delai = CLOCKS_PER_SEC*secondes_delai;


    //On cr�e notre grille de jeu qui est un tableau 2 dimension
	int grille[30][100];


    //On initialise le personnage avec la fonction (initialiser_personnage) d�clar�e dans "Deplacement.h"
	perso = initialiser_personnage(grille, BASE_TAILLE, DEPART_X, DEPART_Y);


    //On cr�er le niveau 1 avec la fonction (creerNiveau) d�clar�e dans "MapManager.h"
	creerNiveau(niveau, grille);


	//On initialise la fen�tre avec la fonction (initFenetre) d�clar�e dans "NCursesManager.h"
    initFenetre();


    //On affiche la grille avec la fonction (affiche) d�clar�e dans "NCursesManager.h"
    //On raffra�chit l'�cran avec la fonction (rafraichirEcran) d�clar�e dans "NCursesManager.h"
    affiche(grille, BLOC_CARACTERE, 100, 30);
    rafraichirEcran();


    //La seule condition de fin de partie est la collision avec un bloc solide
    while( !blocSolide(prochain_bloc(perso, grille))){


        //Recup�re les ancienne position de la queue et de la t�te afin de mettre � jour les graphismes
        position ancienneTetePosition = positionTete(perso);
        position ancienneQueuePosition = positionQueue(perso);

        //Deplace la personnage avec la fonction (deplace) d�clar�e dans "Deplacement.h"
        deplace(&perso, grille);

        //R�cup�re la nouvelle position de la t�te afin de mettre � jour les graphismesi
        position nouvelleTetePosition = positionTete(perso);


        //On met � jour le caract�re de la nouvelle t�te
        changerCaractere(nouvelleTetePosition.x,
                         nouvelleTetePosition.y,
                         blocCaractere(grille[nouvelleTetePosition.y][nouvelleTetePosition.x]));

        /*
        Les queues cr��es par la fonction (creer) de "Personnage.h" ont pour coordonn�es (-1, -1)
        On test donc les coordonn�es de cette queue pour savoir si il y a quelque chose � mettre � jour dans les graphismes
        */
        if(ancienneQueuePosition.x >= 0 && ancienneQueuePosition.y >= 0){
            changerCaractere(ancienneQueuePosition.x,
                             ancienneQueuePosition.y,
                             blocCaractere(grille[ancienneQueuePosition.y][ancienneQueuePosition.x]));
        }

        //On met � jour le caract�re de l'ancienne t�te
        changerCaractere(ancienneTetePosition.x,
                         ancienneTetePosition.y,
                         blocCaractere(grille[ancienneTetePosition.y][ancienneTetePosition.x]));


        //Valeur de temps en nombre de ticks de processeur, d�but de l'attente
        clock_t debutAttente = clock();

        /*
        On attend tant que la diff�rence de nombre de ticks processeur entre le d�but de l'attente et actuellement est inf�rieure au nombre de ticks que l'on doit attendre

        Invariant de boucle: (partie enti�re de (tick_delai))
        Variant de boucle: (partie enti�re de (tick_delai - (clock() - debutAttente)))
        */
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
}


int main(){
    //testDiagonalRush();
    diagonalRush(0.1, 1);
    return 0;
}
