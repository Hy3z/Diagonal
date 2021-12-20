#ifndef BLOCMANAGER_H
#define BLOCMANAGER_H

#include <stdbool.h>
#include <assert.h>

const int NOMBRE_BLOCS;

extern const int BLOC_COLLISION[];

extern const char BLOC_CARACTERE[];

bool blocSolide(int numeroBloc);

char blocCaractere(int numeroBloc);


#endif
