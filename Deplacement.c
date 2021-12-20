#include "Personnage.h"
#include "NCursesManager.h"
#include <stdbool.h>

bool direction_bas = true;
bool direction_droite = true;
personnage perso;

void inverse_horizontal(){
    direction_droite = !direction_droite;
}

void inverse_vertical(){
    direction_bas = !direction_bas;
}

position prochaine_position(){
    position pos = perso.tete -> pos;
    int x = pos.x;
    int y = pos.y;
    if (direction_droite) {
		if (direction_bas) {
            pos.x = pos.x + 1;
            pos.y = pos.y + 1;
		} else {
		    pos.x = pos.x + 1;
            pos.y = pos.y - 1;
		}
	} else {
		if (direction_bas) {
            pos.x = pos.x - 1;
            pos.y = pos.y + 1;
		} else {
		    pos.x = pos.x - 1;
            pos.y = pos.y - 1;
		}
	}
    return pos;
}

int prochain_bloc(int grille[30][100]){
    position prochaine_pos = prochaine_position();
    return grille[prochaine_pos.y][prochaine_pos.x];
}

void initialiser_personnage(int grille[30][100], int taille, int x, int y){
    position pos;
	pos.x=x;
	pos.y=y;
	perso = creer(taille, pos);
    grille[y][x] = 9;
}

int valeur_tete(){
    if (direction_droite) {
		if (direction_bas) {
			return 9;
		} else {
			return 8;
		}
	} else {
		if (direction_bas) {
			return 11;
		} else {
			return 10;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int corps_vaut_8(int valeurTeteApres){
	switch (valeurTeteApres){
	case 8:
		return 14;
	case 9:
		return 12;
	case 10:
		return 16;
	case 11:
		return 14;
	default:
		return 1;
	}
}

int corps_vaut_9(int valeurTeteApres){
	switch (valeurTeteApres){
	case 8:
		return 13;
	case 9:
		return 15;
	case 10:
		return 15;
	case 11:
		return 16;
	default:
		return 1;
	}
}

int corps_vaut_10(int valeurTeteApres){
	switch (valeurTeteApres){
	case 8:
		return 17;
	case 9:
		return 15;
	case 10:
		return 15;
	case 11:
		return 12;
	default:
		return 1;
	}
}

int corps_vaut_11(int valeurTeteApres){
	switch (valeurTeteApres){
	case 8:
		return 14;
	case 9:
		return 17;
	case 10:
		return 13;
	case 11:
		return 14;
	default:
		return 1;
	}
}

int valeur_corps(int valeurTeteAvant, int valeurTeteApres){
	switch (valeurTeteAvant){
	case 8:
	    return corps_vaut_8(valeurTeteApres);
	case 9:
		 return corps_vaut_9(valeurTeteApres);
	case 10:
		 return corps_vaut_10(valeurTeteApres);
	case 11:
		 return corps_vaut_11(valeurTeteApres);
	default:
		return 1;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void deplace(int grille[30][100]){
    //recupere les ancienne positions
    position ancienne_queue_position = perso.queue -> pos;
    position ancienne_tete_position = perso.tete -> pos;

    //il touche les murs


    //recupere la prochaine position de la tete
    position prochaine_position_tete = prochaine_position();

    //ajoute la nouvelle tete et retire la queue
    ajouter_tete(&perso, prochaine_position_tete);
    retirer_queue(&perso);

    //recupere la valeur de la nouvelle tete, modifie la grille et update les graphisles
    int valeur_prochaine_tete = valeur_tete();
    grille[prochaine_position_tete.y][prochaine_position_tete.x] = valeur_prochaine_tete;
    changerCaractere(prochaine_position_tete.x,
                     prochaine_position_tete.y,
                     blocCaractere(valeur_prochaine_tete));

    //remplace dans la grille la queue par du vide et update les graphismes
    if(ancienne_queue_position.x >= 0 && ancienne_queue_position.y >= 0){
        grille[ancienne_queue_position.y][ancienne_queue_position.x] = 0;
        changerCaractere(ancienne_queue_position.x,
                         ancienne_queue_position.y,
                         blocCaractere(0));
    }
    //si c'est une nouvelle queue alors sa position est -1 -1
    //il n'y a donc rien a modifier

    //recupere la nouvelle valeur de l'ancienne tete, modifie la grille et update les graphismes
    int valeur_ancienne_tete = valeur_corps(grille[ancienne_tete_position.y][ancienne_tete_position.x], valeur_prochaine_tete);
    grille[ancienne_tete_position.y][ancienne_tete_position.x] = valeur_ancienne_tete;
    changerCaractere(ancienne_tete_position.x,
                     ancienne_tete_position.y,
                     blocCaractere(valeur_ancienne_tete));

    if(prochaine_position_tete.x <=1 || prochaine_position_tete.x >=98){
        inverse_horizontal();
    }
}
