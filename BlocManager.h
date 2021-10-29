#ifndef BLOCMANAGER_H
#define BLOCMANAGER_H

#include <stdbool.h>

//Liste contenant 1 si le bloc de num�ro d'indice est solide
//0 sinon
#define int BLOC_COLLISION[];

//Liste contenant le caractere du bloc d'indice
#define char BLOC_CARACTERE[];

//Renvoie true si le num�ro du bloc d�fini un bloc solide
//false sinon
bool isBlocSolide(int numeroBloc);

#endif
