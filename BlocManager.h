#ifndef BLOCMANAGER_H
#define BLOCMANAGER_H

#include <stdbool.h>
#include <assert.h>

//Le nombre total de blocs (=longueur des tableaux BLOC_COLLISION et BLOC_CARACTERE)
extern const int NOMBRE_BLOCS;

//Tableau contenant 1 si le bloc de numéro d'indice est solide
//0 sinon
extern const int BLOC_COLLISION[];

//Tableau contenant le caractere du bloc d'indice
extern const char BLOC_CARACTERE[];

//Renvoie true si le numéro du bloc défini un bloc solide
//false sinon
bool isBlocSolide(int numeroBloc);

#endif
