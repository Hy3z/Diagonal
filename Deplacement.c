#include "Personnage.h"
#include <stdbool.h>
#include <assert.h>


//Le personnage commence par aller en bas à droite
bool direction_bas = true;
bool direction_droite = true;


/*
Numéro des blocs correspondant aux nom des variables listées si-dessous
Pour vérifier la correspondance, consulter le tableau des blocs ou le tableau des déplacements
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
Précondition:
    La taille du personnage est un entier naturel non-nul
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

        //Si le personnage se dirige vers le bas sa valeur en y (ordonée) augmente
		if (direction_bas) {
            pos.y = pos.y + 1;
        //Sinon sa valeur en y (ordonée) diminue
		} else {
            pos.y = pos.y - 1;
		}

    //Si non sa valeur en x (abscisse) diminue
	} else {
	    pos.x = pos.x - 1;

	    //Si le personnage se dirige vers le bas sa valeur en y (ordonée) augmente
		if (direction_bas) {
            pos.y = pos.y + 1;
        //Sinon sa valeur en y (ordonée) diminue
		} else {
            pos.y = pos.y - 1;
		}
	}

    return pos;
}


/*
Postcondition:
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
*/
int prochain_bloc(personnage perso, int grille[30][100]){
    position prochaine_pos = prochaine_position(perso);
    return grille[prochaine_pos.y][prochaine_pos.x];
}


/*
Postcondition:
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
Précondition:
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

    //Creer le personnage avec la fonction (creer) déclarée dans "Personnage.h"
	personnage perso = creer(taille, pos);

	//Initialise dans la grille la valeur de bloc du personnage
    grille[y][x] = valeur_tete();

    return perso;
}


//////////////////////////////////////////////////////////////////////////////////////////
/*
Postcondition:
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
    L'entier renvoyé est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager)
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
    //Récupère les ancienne positions
    position ancienne_queue_position = (perso -> queue) -> pos;
    position ancienne_tete_position = (perso -> tete) -> pos;

    //Récupère la prochaine position de la tete
    position prochaine_position_tete = prochaine_position(*perso);

    //Ajoute la nouvelle tête et retire la queue
    ajouter_tete(perso, prochaine_position_tete);
    retirer_queue(perso);

    //Récupère la valeur de la nouvelle tete, modifie la grille
    int valeur_prochaine_tete = valeur_tete();
    grille[prochaine_position_tete.y][prochaine_position_tete.x] = valeur_prochaine_tete;

    /*
    Remplace dans la grille la queue par du vide
    Si cette queue a pour position (-1,-1), alors c'est une queue créée par la fonction (creer) déclarée dans "Personnage.h"
    */
    if(ancienne_queue_position.x >= 0 && ancienne_queue_position.y >= 0){
        grille[ancienne_queue_position.y][ancienne_queue_position.x] = VIDE;
    }

    //Récupère la nouvelle valeur de l'ancienne tete, modifie la grille
    int valeur_ancienne_tete = valeur_corps(grille[ancienne_tete_position.y][ancienne_tete_position.x], valeur_prochaine_tete);
    grille[ancienne_tete_position.y][ancienne_tete_position.x] = valeur_ancienne_tete;

    /*
    La grille allant de 0 à 99 en abscisse, on test si le personnage est contre le bord de la grille
    Si il va vers la gauche et se trouve à un bloc de sortir de la grille, on dirige le personnage vers la droite
    Si il va vers la droite et se trouve à un bloc de sortir de la grille, on dirige le personnage vers la gauche
    */
    if((prochaine_position_tete.x <=1 && !direction_droite) || (prochaine_position_tete.x >=98 && direction_droite)){
        inverse_horizontal();
    }
}
