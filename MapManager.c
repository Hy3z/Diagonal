#include <assert.h>
#include <time.h>
#include <stdlib.h>


/*
Numéro des blocs correspondant aux nom des variables listées si-dessous
Pour vérifier la correspondance, consulter le tableau des blocs
*/
int VIDE = 0;
int MUR_HORIZONTAL = 2;
int MUR_VERTICAL = 3;
int COIN_HAUT_GAUCHE = 4;
int COIN_HAUT_DROIT = 5;
int COIN_BAS_GAUCHE = 6;
int COIN_BAS_DROIT = 7;
int MUR_BLOC = 18;



/*
Préconditions:
    x est un entier naturel non-nul
    y est un entier naturel non-nul
Postcondition:
    (
    Pour tout x0 appartenant à [[0, x-1]] ,
    Pour tout y0 appartenant à [[0, y-1]]
    ):
        grille[y0][x0] est un entier naturel compris entre 0 et NOMBRE_BLOCS-1 (définit dans BlocManager.c)
*/
void grilleVide(int grille[30][100], int x, int y) {

    //precondition
	assert (x > 0 && y > 0) ;


	/*
	On remplit la sous grille de vide

	Invariant de boucle: (y)
	Variant de boucle: (y-i)
	*/
	for (int i = 0 ; i < y ; i ++ ) {
        /*
        Invariant de boucle: (x)
        Variant de boucle: (x-j)
        */
		for (int j = 0 ; j < x ; j ++ ) {
			grille[i][j] = VIDE ;
		}
	}


	/*
	On inscrit dans la grille les côtés gauche et droit de murs verticaux (piliers)

    Invariant de boucle: (y)
    Variant de boucle: (y-i)
    */
	for (int i = 1 ; i < y ; i ++ ) {
		grille[i][x-1] = MUR_VERTICAL ;
		grille[i][0] = MUR_VERTICAL ;
	}


	/*
	On inscrit dans la grille les côtés haut et bas de murs horizontaux (sol & plafond)

	Invariant de boucle: (x)
    Variant de boucle: (x-j)
    */
	for (int j = 1 ; j < x ; j ++ ) {
		grille[y-1][j] = MUR_HORIZONTAL ;
		grille[0][j] = MUR_HORIZONTAL ;
	}


	//On pose dans chaque coin le bloc qui lui correspond
	grille[0][0] = COIN_HAUT_GAUCHE;
	grille[y-1][x-1] = COIN_BAS_DROIT;
	grille[y-1][0] = COIN_BAS_GAUCHE ;
	grille[0][x-1] = COIN_HAUT_DROIT ;
}


/*
Précondition:
    (min_x) est un entier naturel
    (min_y) est un entier naturel
    (max_x) est un entier naturel inférieur à 100
    (max_y) est un entier naturel inférieur à 30
*/
void blocAleatoire(int grille[30][100], int min_x, int min_y, int max_x, int max_y){
    //precondition
    assert(min_x>=0 && min_y>=0 && max_x>=0 && max_y>=0 && max_x<100 && max_y<30);

    //Initialise la fonction (rand)
    srand(time(NULL));

    /*
    Pour chaque colonne entre min_x et max_x

    Invariant de boucle: (max_x)
    Variant de boucle: (max_x + 1 - x)
    */
    for(int x=min_x ; x<=max_x ; x++){

        //(rand) renvoie un entier aléatoire entre 0 et une constante RAND_MAX
        int random_y = rand();

        //La variable (random_y) contient alors un entier entre 0 et (max_y - min_y)
        random_y = random_y % (max_y - min_y +1);

        //La variable (random_y) contient alors un entier entre min_y et max_y
        random_y = random_y + min_y;

        grille[random_y][x] = MUR_BLOC;
    }
}


void creerNiveau1(int grille[30][100]){
    grilleVide(grille, 100, 30);

    //Les blocs apparaîtront entre la colonne 10 et la colonne 98
    blocAleatoire(grille, 10, 2, 98, 28);
}


/*
Précondition:
    (niveau) est un entier naturel non-nul
*/
void creerNiveau(int niveau, int grille[30][100]){
    //precondition
    assert(niveau > 0);

    switch (niveau){
    case 1:
        creerNiveau1(grille);
        break;
    default:
        creerNiveau1(grille);
        break;
    }
}


//Jeu de test
#include <stdio.h>
void testMapManager(int NOMBRE_BLOCS){
    printf("\n");
    printf("==============MapManager==============");
    printf("\n");

    int grille[30][100];
    grilleVide(grille, 100,  30);
    for(int x=0; x<100; x++){
        for(int y=0; y<30; y++){
            //Test postcondition de la fonction grilleVide
            assert(grille[y][x] >= 0 && grille[y][x] <= NOMBRE_BLOCS - 1);
        }
    }
    printf("grilleVide valide \n");
}
