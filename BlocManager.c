#include <stdbool.h>

int BLOC_COLLISION[] = {
    0,1
};

char BLOC_CARACTERE[] = {
    '!','-'
};

bool isBlocSolide(int numeroBloc){
    return BLOC_COLLISION[numeroBloc] == 1;
}
