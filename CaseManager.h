#ifndef CASEMANAGER_H
#define CASEMANAGER_H

#include<stdbool.h>

//Liste contenant 1 si le bloc de num�ro d'indice est solide
//0 sinon
const int blocCollision[];

//Renvoie true si le num�ro du bloc d�fini un bloc solide
//false sinon
bool blocSolide(int numeroBloc);

#endif
