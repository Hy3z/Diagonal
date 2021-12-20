#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include "Personnage.h"
#include "NCursesManager.h"
#include <stdbool.h>

extern bool direction_bas;
extern bool direction_droite;
extern personnage perso;

void inverse_horizontal();

void inverse_vertical();

position prochaine_position();

int prochain_bloc(int grille[30][100]);

int valeur_tete();

int valeur_corps(int valeurTeteAvant, int valeurTeteApres);

int corps_vaut_8(int valeurTeteApres);

int corps_vaut_9(int valeurTeteApres);

int corps_vaut_10(int valeurTeteApres);

int corps_vaut_11(int valeurTeteApres);

void deplace(int grille[30][100]);

void initialiser_personnage(int grille[30][100], int taille, int x, int y);

#endif
