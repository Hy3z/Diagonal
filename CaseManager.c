#include <stdbool.h>

const int blocCollision[] = {0,1};

bool blocSolide(int numeroBloc){
    return blocCollision[numeroBloc] == 1;
}
