#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <assert.h>
#include <stdlib.h>

#include <stdio.h>

struct position_struct {
		int x;
		int y;
};
typedef struct position_struct position;

struct corps_struct {
	position pos;
	struct corps_struct* suivant;
};
typedef struct corps_struct corps;

struct personnage_struct {
	corps* queue;
	corps* tete;
	int taille;
};
typedef struct personnage_struct personnage;

position positionQueue(personnage perso);

position positionTete(personnage perso);

int taille(personnage perso);

void ajouter_queue(personnage* perso);

personnage creer(int taille, position pos);

void retirer_queue(personnage* perso);

void ajouter_tete(personnage* perso, position positionTete);

#endif
