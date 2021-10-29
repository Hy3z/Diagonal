#include <CaseManager.h>
#include <GraphismeManager.h>
#include <time.h>

const double delai = 0.5;

int main(){
    initEcran(delai);
    while( !blocSolide(numero de la case du prochain deplacement) ){

        /*
        fait des trucs en fonction du numero de la case
        deplace le perso dans la liste
        fait des trucs au pif (animation par exemple)
        */

        changerCaractere(la grille, position en x du perso, position en y du perso);



        rafraichirEcran();


        int pressedKey = getch();
        if(pressedKey!=ERR){

        }
    }
    finEcran();
//test

}
