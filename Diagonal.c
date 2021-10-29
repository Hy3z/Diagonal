#include <BlocManager.h>
#include <NCursesManager.h>
#include <time.h>

//Delai entre 2 déplacements en secondes
const double DELAI = 0.5;

int main(){
    initFenetre();
    while( !isBlocSolide(numero de la case du prochain deplacement) ){

        /*
        fait des trucs en fonction du numero de la case
        deplace le perso dans la liste
        fait des trucs au pif (animation par exemple)
        */

        changerCaractere(grille, BLOC_CARACTERE, position en x du perso, position en y du perso);



        rafraichirEcran();

        time_t debutAttente = time();
        while(difftime(debutAttente,time())<DELAI){
            if(isToucheAppuyee()){
                //key pressed, changer le sens du perso en hauteur
            }
        }

    }
    finFenetre();
    return 0;
}
