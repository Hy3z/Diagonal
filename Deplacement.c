#include "Personnage.h"
#include <stdbool.h>
#include <assert.h>


//Le personnage commence par aller en bas � droite
bool direction_bas = true;
bool direction_droite = true;


/*
Num�ro des blocs correspondant aux nom des variables list�es si-dessous
Pour v�rifier la correspondance, consulter le tableau des blocs ou le tableau des d�placements
On utilise #define afin de pouvoir ensuite utiliser ces "variables" en tant que constantes dans des switch
*/
#define VIDE 0
#define CORPS_DEFAUT 1
#define TETE_HAUT_GAUCHE 10
#define TETE_HAUT_DROITE 8
#define TETE_BAS_GAUCHE 11
#define TETE_BAS_DROITE 9

#define CORPS_HAUT_GAUCHE_TO_HAUT_GAUCHE 15
#define CORPS_HAUT_GAUCHE_TO_HAUT_DROITE 17
#define CORPS_HAUT_GAUCHE_TO_BAS_GAUCHE 12
#define CORPS_HAUT_GAUCHE_TO_BAS_DROITE 15

#define CORPS_HAUT_DROITE_TO_HAUT_GAUCHE 16
#define CORPS_HAUT_DROITE_TO_HAUT_DROITE 14
#define CORPS_HAUT_DROITE_TO_BAS_GAUCHE 14
#define CORPS_HAUT_DROITE_TO_BAS_DROITE 12

#define CORPS_BAS_GAUCHE_TO_HAUT_GAUCHE 13
#define CORPS_BAS_GAUCHE_TO_HAUT_DROITE 14
#define CORPS_BAS_GAUCHE_TO_BAS_GAUCHE 14
#define CORPS_BAS_GAUCHE_TO_BAS_DROITE 17

#define CORPS_BAS_DROITE_TO_HAUT_GAUCHE 15
#define CORPS_BAS_DROITE_TO_HAUT_DROITE 13
#define CORPS_BAS_DROITE_TO_BAS_GAUCHE 16
#define CORPS_BAS_DROITE_TO_BAS_DROITE 15


void inverse_horizontal(){
    direction_droite = !direction_droite;
}


void inverse_vertical(){
    direction_bas = !direction_bas;
}


/*
Pr�condition:
    La taille du personnage est un entier naturel non-nul
Postcondition
    La position renvoy�e respecte:
        Le champ (x) est un entier naturel inf�rieur � 100
        Le champ (y) est un entier naturel inf�rieur � 30
*/
position prochaine_position(personnage perso){
    //precondition
    assert(perso.taille > 0);

    position pos = perso.tete -> pos;
    int x = pos.x;
    int y = pos.y;

    //Si le personnage se dirige vers la droite sa valeur en x (abscisse) augmente
    if (direction_droite) {
        pos.x = pos.x + 1;

        //Si le personnage se dirige vers le bas sa valeur en y (ordonn�e) augmente
		if (direction_bas) {
            pos.y = pos.y + 1;
        //Sinon sa valeur en y (ordonn�e) diminue
		} else {
            pos.y = pos.y - 1;
		}

    //Si non sa valeur en x (abscisse) diminue
	} else {
	    pos.x = pos.x - 1;

	    //Si le personnage se dirige vers le bas sa valeur en y (ordonn�e) augmente
		if (direction_bas) {
            pos.y = pos.y + 1;
        //Sinon sa valeur en y (ordonn�e) diminue
		} else {
            pos.y = pos.y - 1;
		}
	}

    //postcondition
    assert(pos.x>=0 && pos.x<100 && pos.y>=0 && pos.y<30);
    return pos;
}


/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int prochain_bloc(personnage perso, int grille[30][100]){
    position prochaine_pos = prochaine_position(perso);
    return grille[prochaine_pos.y][prochaine_pos.x];
}


/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int valeur_tete(){
    if (direction_droite) {
		if (direction_bas) {
			return TETE_BAS_DROITE;
		} else {
			return TETE_HAUT_DROITE;
		}
	} else {
		if (direction_bas) {
			return TETE_BAS_GAUCHE;
		} else {
			return TETE_HAUT_GAUCHE;
		}
	}
}


/*
Pr�condition:
    (taille) est un entier naturel positif non-nul
    (x) est un entier naturel
    (y) est un entier naturel

*/
personnage initialiser_personnage(int grille[30][100], int taille, int x, int y){
    //precondition
    assert(taille > 0 && x>=0 && y>=0);

    position pos;
	pos.x=x;
	pos.y=y;

    //Creer le personnage avec la fonction (creer) d�clar�e dans "Personnage.h"
	personnage perso = creer(taille, pos);

	//Initialise dans la grille la valeur de bloc du personnage
    grille[y][x] = valeur_tete();

    return perso;
}


//////////////////////////////////////////////////////////////////////////////////////////
/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int corps_direction_haut_droite(int valeurTeteApres){
	switch (valeurTeteApres){
	case TETE_HAUT_DROITE:
		return CORPS_HAUT_DROITE_TO_HAUT_DROITE;
	case TETE_BAS_DROITE:
		return CORPS_HAUT_DROITE_TO_BAS_DROITE;
	case TETE_HAUT_GAUCHE:
		return CORPS_HAUT_DROITE_TO_HAUT_GAUCHE;
	case TETE_BAS_GAUCHE:
		return CORPS_HAUT_DROITE_TO_BAS_GAUCHE;
	default:
		return CORPS_DEFAUT;
	}
}

/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int corps_direction_bas_droite(int valeurTeteApres){
	switch (valeurTeteApres){
	case TETE_HAUT_DROITE:
		return CORPS_BAS_DROITE_TO_HAUT_DROITE;
	case TETE_BAS_DROITE:
		return CORPS_BAS_DROITE_TO_BAS_DROITE;
	case TETE_HAUT_GAUCHE:
		return CORPS_BAS_DROITE_TO_HAUT_GAUCHE;
	case TETE_BAS_GAUCHE:
		return CORPS_BAS_DROITE_TO_BAS_GAUCHE;
	default:
		return CORPS_DEFAUT;
	}
}

/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int corps_direction_haut_gauche(int valeurTeteApres){
	switch (valeurTeteApres){
	case TETE_HAUT_DROITE:
		return CORPS_HAUT_GAUCHE_TO_HAUT_DROITE;
	case TETE_BAS_DROITE:
		return CORPS_HAUT_GAUCHE_TO_BAS_DROITE;
	case TETE_HAUT_GAUCHE:
		return CORPS_HAUT_GAUCHE_TO_HAUT_GAUCHE;
	case TETE_BAS_GAUCHE:
		return CORPS_HAUT_GAUCHE_TO_BAS_GAUCHE;
	default:
		return CORPS_DEFAUT;
	}
}

/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int corps_direction_bas_gauche(int valeurTeteApres){
	switch (valeurTeteApres){
	case TETE_HAUT_DROITE:
		return CORPS_BAS_GAUCHE_TO_HAUT_DROITE;
	case TETE_BAS_DROITE:
		return CORPS_BAS_GAUCHE_TO_BAS_DROITE;
	case TETE_HAUT_GAUCHE:
		return CORPS_BAS_GAUCHE_TO_HAUT_GAUCHE;
	case TETE_BAS_GAUCHE:
		return CORPS_BAS_GAUCHE_TO_BAS_GAUCHE;
	default:
		return CORPS_DEFAUT;
	}
}

/*
Postcondition:
    L'entier renvoy� est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (d�finit dans BlocManager)
*/
int valeur_corps(int valeurTeteAvant, int valeurTeteApres){
	switch (valeurTeteAvant){
	case TETE_HAUT_DROITE:
	    return corps_direction_haut_droite(valeurTeteApres);
	case TETE_BAS_DROITE:
		 return corps_direction_bas_droite(valeurTeteApres);
	case TETE_HAUT_GAUCHE:
		 return corps_direction_haut_gauche(valeurTeteApres);
	case TETE_BAS_GAUCHE:
		 return corps_direction_bas_gauche(valeurTeteApres);
	default:
		return CORPS_DEFAUT;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////


void deplace(personnage* perso, int grille[30][100]){
    //R�cup�re les ancienne positions
    position ancienne_queue_position = (perso -> queue) -> pos;
    position ancienne_tete_position = (perso -> tete) -> pos;

    //R�cup�re la prochaine position de la tete
    position prochaine_position_tete = prochaine_position(*perso);

    //Ajoute la nouvelle t�te et retire la queue
    ajouter_tete(perso, prochaine_position_tete);
    retirer_queue(perso);

    //R�cup�re la valeur de la nouvelle tete, modifie la grille
    int valeur_prochaine_tete = valeur_tete();
    grille[prochaine_position_tete.y][prochaine_position_tete.x] = valeur_prochaine_tete;

    /*
    Remplace dans la grille la queue par du vide
    Si cette queue a pour position (-1,-1), alors c'est une queue cr��e par la fonction (creer) d�clar�e dans "Personnage.h"
    */
    if(ancienne_queue_position.x >= 0 && ancienne_queue_position.y >= 0){
        grille[ancienne_queue_position.y][ancienne_queue_position.x] = VIDE;
    }

    //R�cup�re la nouvelle valeur de l'ancienne tete, modifie la grille
    int valeur_ancienne_tete = valeur_corps(grille[ancienne_tete_position.y][ancienne_tete_position.x], valeur_prochaine_tete);
    grille[ancienne_tete_position.y][ancienne_tete_position.x] = valeur_ancienne_tete;

    /*
    La grille allant de 0 � 99 en abscisse, on test si le personnage est contre le bord de la grille
    Si il va vers la gauche et se trouve � un bloc de sortir de la grille, on dirige le personnage vers la droite
    Si il va vers la droite et se trouve � un bloc de sortir de la grille, on dirige le personnage vers la gauche
    */
    if((prochaine_position_tete.x <=1 && !direction_droite) || (prochaine_position_tete.x >=98 && direction_droite)){
        inverse_horizontal();
    }
}


//Jeu de test
#include <stdio.h>
void testDeplacement(int grille[30][100], int NOMBRE_BLOCS){
    printf("\n");
    printf("==============Deplacement==============");
    printf("\n");

    /*
    Ici on fait les test pour une position de personnage, une taille, une direction d�finies
    On pourrait faire varier la position et direction mais il faudrait �valuer 12,000 cas diff�rents
    */
    int TAILLE_INITIALE = 2;
    int X_INITIAL = 1;
    int Y_INITIAL = 1;
    personnage perso = initialiser_personnage(grille, TAILLE_INITIALE, X_INITIAL, Y_INITIAL);
    afficher_perso(perso);

    int prochainBloc = prochain_bloc(perso, grille);
    //postcondition de prochain_bloc()
    assert(prochainBloc >= 0 && prochainBloc <= NOMBRE_BLOCS - 1);

    int valeurTeteAvant = valeur_tete();
    //postcondition de valeur_tete()
    assert(valeurTeteAvant >=0 && valeurTeteAvant <= NOMBRE_BLOCS - 1);

    deplace(&perso, grille);
    afficher_perso(perso);

    int valeurTeteApres = valeur_tete();
    //postcondition de valeur_tete()
    assert(valeurTeteApres >=0 && valeurTeteApres <= NOMBRE_BLOCS - 1);

    int valeurCorps = valeur_corps(valeurTeteAvant, valeurTeteApres);
    //postcondition de valeur_corps()
    assert(valeurCorps >=0 && valeurCorps<= NOMBRE_BLOCS - 1);


}
