#include <stdbool.h>
#include <assert.h>

//#include <stdio.h>

#define NOMBRE_BLOCS 18

const int BLOC_COLLISION[NOMBRE_BLOCS] = {
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1
};

const char BLOC_CARACTERE[NOMBRE_BLOCS] = {
		' ',
		'*',
		'=',
		'|',

		'+',
		'+',
		'+',
		'+',

		'*',
		'*',
		'*',
		'*',
		'^',

		'/',

		'/',
		'\\',

		'\\',
		'/'
};


bool blocSolide(int numeroBloc){
    assert(numeroBloc>=0 && numeroBloc<NOMBRE_BLOCS);
    return BLOC_COLLISION[numeroBloc] == 1;
}

char blocCaractere(int numeroBloc){
	assert(numeroBloc>=0 && numeroBloc<NOMBRE_BLOCS);
	return BLOC_CARACTERE[numeroBloc];
}

/*int main(){
	printf("%d \n",blocSolide(2));
	printf("%c \n",blocCaractere(2));
}*/

