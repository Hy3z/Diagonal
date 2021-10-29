#ifndef CASEMANAGER_H
#define CASEMANAGER_H

#include<stdbool.h>

//Liste contenant 1 si le bloc de numéro d'indice est solide
//0 sinon
const int blocCollision[];

//Renvoie true si le numéro du bloc défini un bloc solide
//false sinon
bool blocSolide(int numeroBloc);

#endif
