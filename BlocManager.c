#include <stdbool.h>
#include <assert.h>


/*Nombre total de blocs impl�ment�s
On utilise #define afin de pouvoir d�finir la dimension des tableaux suivants
*/
#define NOMBRE_BLOCS 19


//On d�finit la constante BLOC_COLLISION
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
    1,
    1
};


//On d�finit la constante BLOC_CARACTERE
const char BLOC_CARACTERE[NOMBRE_BLOCS] = {
	' ',
	'*',
	'=',
	'|',

	'+',
	'+',
	'+',
	'+',

	'1',
	'2',
	'3',
	'4',
	
	'^',
	'v',

	'/',
	'\\',
	'>',
	'<',

	'#'
};


/*
Pr�condition:
    (numeroBloc) est un entier compris entre 0 et NOMBRE_BLOCS-1
*/
bool blocSolide(int numeroBloc){
    //precondition
    assert(numeroBloc>=0 && numeroBloc<NOMBRE_BLOCS);

    return BLOC_COLLISION[numeroBloc] == 1;
}


/*
Pr�condition:
    (numeroBloc) est un entier compris entre 0 et NOMBRE_BLOCS-1
*/
char blocCaractere(int numeroBloc){
    //precondition
	assert(numeroBloc>=0 && numeroBloc<NOMBRE_BLOCS);

	return BLOC_CARACTERE[numeroBloc];
}


int obtenirNOMBRE_BLOCS(){
    return NOMBRE_BLOCS;
}


/*
Jeu de test
Renvoie la collision/caract�re en fonction du num�ro de bloc
R�sultats � comparer avec le tableau des blocs pour v�rifier
*/
#include <stdio.h>
void testBlocManager(){
    printf("\n");
    printf("==============BlocManager==============");
    printf("\n");

    printf("Collision des blocs suivants: \n");
	for(int x=0 ; x<NOMBRE_BLOCS; x++){
        printf("%d = %d \n", x , blocSolide(x));
	}

	printf("\n");

	printf("Caractere des blocs suivants: \n");
	for(int x=0 ; x<NOMBRE_BLOCS; x++){
        printf("%d = %c \n", x , blocCaractere(x));
	}
}

