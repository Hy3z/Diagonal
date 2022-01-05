#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H


#include "Personnage.h"
#include <stdbool.h>


/*
Indique si le personnage se deplace vers le bas (true)
Sinon vers le haut (false)
*/
extern bool direction_bas;

/*
Indique si le personnage se deplace vers la droite (true)
Sinon vers la gauche (false)
*/
extern bool direction_droite;


//Inverse le deplacement horizontal
void inverse_horizontal();

//Inverse le deplacement vertical
void inverse_vertical();


//Renvoie un type position contenant les coordonnées du prochain déplacement du personnage
position prochaine_position(personnage perso);


//Renvoie le numéro inscrit dans la case où le personnage se trouvera à son prochain déplacement
int prochain_bloc(personnage perso, int grille[30][100]);


//Renvoie la valeur que devrait prendre le bloc de la tête en fonction de son orientation
int valeur_tete();


//Renvoie la valeur que devrait prendre le bloc de la l'ancienne tête en fonction de son orientation et de celle de la tête actuelle
int valeur_corps(int valeurTeteAvant, int valeurTeteApres);

//Sous fonctions de (valeur_corps) permettant de déterminer la valeur du corps
int corps_vaut_8(int valeurTeteApres);
int corps_vaut_9(int valeurTeteApres);
int corps_vaut_10(int valeurTeteApres);
int corps_vaut_11(int valeurTeteApres);


/*
Déplace le personnage en:
    - Modifiant les valeurs dans la grille
    - Modifiant la liste chaînée perso
*/
void deplace(personnage* perso, int grille[30][100]);


//Créer le personnage de taille (taille) aux coordonnées (x,y)
personnage initialiser_personnage(int grille[30][100], int taille, int x, int y);


//Permet de changer manuellement la direction du personnage
void mettreDirection(bool bas, bool droite);


//Effectue les tests pour Deplacement
void testDeplacement();


#endif
