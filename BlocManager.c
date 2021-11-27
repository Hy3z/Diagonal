#include <stdbool.h>
#include <assert.h>
#include <ncurses.h>

#define NOMBRE_BLOCS 8
const int BLOC_COLLISION[NOMBRE_BLOCS] = {
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1
};

unsigned char BLOC_CARACTERE[NOMBRE_BLOCS] = {
    ' ',
    '*',
    '─',
    '│',
    '┌',
    '┐',
    '└',
    '┘'
};

bool isBlocSolide(int numeroBloc){
    assert(numeroBloc>=0 && numeroBloc<NOMBRE_BLOCS);
    return BLOC_COLLISION[numeroBloc] == 1;
}
