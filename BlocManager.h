#ifndef BLOCMANAGER_H
#define BLOCMANAGER_H


#include <stdbool.h>


/*
Definition:
    Un bloc est représenté par un nombre (allant de 0 à NOMBRE_BLOCS - 1)
    On associe à ce bloc une collision (1 = le joueur peut entrer en collision avec ce bloc, 0 sinon)
    On associe à ce bloc un caractere (de type char)
    A chaque case la grille de jeu on associe un bloc
*/


//Constante utilisée pour definir le nombre de blocs implementés
const int NOMBRE_BLOCS;


/*
Tableau contenant des nombres (0 ou 1) definissant si le bloc de numéro d'indice correspondant a une collision
Exemple:
    Le bloc de numéro 0 a une collision si:
    BLOC_COLLISION[0] == 1
*/
extern const int BLOC_COLLISION[];


/*
Tableau contenant des caracteres definissant le caractère du bloc
Exemple:
    Le bloc de numéro 0 a le caractère:
    BLOC_CARACTERE[0]
*/
extern const char BLOC_CARACTERE[];


/*
Renvoie true si le bloc de numéro (numeroBloc) a une collision
Renvoie false sinon
*/
bool blocSolide(int numeroBloc);


//Renvoie le caractere (de type char) associé au bloc de numéro (numeroBloc)
char blocCaractere(int numeroBloc);


#endif
