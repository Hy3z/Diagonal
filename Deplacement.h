#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H


#include "Personnage.h"
#include "NCursesManager.h"
#include <stdbool.h>
#include <assert.h>


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


//Variable contenant le personnage
extern personnage perso;


//Inverse le deplacement horizontal
void inverse_horizontal();

//Inverse le deplacement vertical
void inverse_vertical();


//Renvoie un type position contenant les coordonnées du prochain déplacement du personnage
position prochaine_position();


//Renvoie le numéro inscrit dans la case où le personnage se trouvera à son prochain déplacement
int prochain_bloc(int grille[30][100]);


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
Deplace le personnage dans la grille
Met à jour les graphismes de l'ancienne et nouvelle tête
*/
void deplace(int grille[30][100]);


//Créer le personnage de taille (taille) aux coordonnées (x,y)
void initialiser_personnage(int grille[30][100], int taille, int x, int y);


#endif
