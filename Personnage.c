#include <assert.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////////////////
struct position_struct {
		int x;
		int y;
};
typedef struct position_struct position;

struct corps_struct {
	position pos;
	struct corps_struct* suivant;
};
typedef struct corps_struct corps;

struct personnage_struct {
	corps* queue;
	corps* tete;
	int taille;
};
typedef struct personnage_struct personnage;
////////////////////////////////////////////////////////////////////////////////////


/*
Pr�condition:
    La taille du personnage est un entier positif non-nul
    (Implique que la queue du personnage est un pointeur non-nul)
*/
position positionQueue(personnage perso){
    //precondition
	assert(perso.taille > 0);

	return perso.queue -> pos;
}


/*
Pr�condition:
    La taille du personnage est un entier positif non-nul
    (Implique que la t�te du personnage est un pointeur non-nul)
*/
position positionTete(personnage perso){
    //precondition
	assert(perso.taille > 0);

	return perso.tete -> pos;
}


/*
Pr�condition:
    La taille du personnage est un entier positif non-nul
    (Implique que la queue du personnage est un pointeur non-nul)
PostCondition:
    La taille du personnage est un entier positif non nul
*/
void retirer_queue(personnage* perso){
    //precondition
	assert(perso -> taille > 0);

	//On ne diminue la taille du personnage que si celle-ci est de 2 ou +
	//Sinon le personnage aurait p�t faire 0 de taille apr�s la diminution
	if(perso -> taille > 1){
		corps* queue = perso -> queue;

        //La nouvelle queue est le corps suivant la queue actuelle
		perso -> queue = queue -> suivant;

		//On lib�re l'espace r�serv� pour la queue actuelle
		free(queue);

		//On diminue la taille du personnage de 1
		perso -> taille = perso -> taille - 1;
	}
}


/*
PostCondition:
    La taille du personnage a augment�e de 1
*/
void ajouter_queue(personnage* perso){

    /*
    On alloue un espace m�moire pour la nouvelle queue
    Si jamais l'allocation a �chou�e, on r�essaye jusqu'� ce que �a fonctionne
    */
    corps* nouvelle_queue = NULL;;
    while(nouvelle_queue == NULL){
        nouvelle_queue = malloc(sizeof(corps));
    }

    //La position de la nouvelle queue est (-1, -1)
	position nouvelle_position;
	nouvelle_position.x = -1;
	nouvelle_position.y = -1;
	nouvelle_queue -> pos = nouvelle_position;

	//La nouvelle queue pointe vers l'ancienne
	nouvelle_queue -> suivant = perso -> queue;

	perso -> queue = nouvelle_queue;

	//On augmente la taille du personnage de 1
	perso -> taille = perso -> taille + 1;
}


/*
PostCondition:
    La taille du personnage a augment�e de 1
*/
void ajouter_tete(personnage* perso, position positionTete){

    /*
    On alloue un espace m�moire pour la nouvelle t�te
    Si jamais l'allocation a �chou�e, on r�essaye jusqu'� ce que �a fonctionne
    */
    corps* nouvelle_tete = NULL;
    while(nouvelle_tete == NULL){
        nouvelle_tete = malloc(sizeof(corps));
    }

    //La t�te n'a pas de suivant par d�finition
    nouvelle_tete -> suivant = NULL;

    //La position de la nouvelle t�te est (positionTete)
    nouvelle_tete -> pos = positionTete;

    //Si le personnage est de taille 0 alors la nouvelle t�te devient aussi la nouvelle queue
    if(perso -> taille == 0){
        perso -> queue = nouvelle_tete;
    //Sinon l'ancienne t�te pointe vers la nouvelle t�te
    }else{
        perso -> tete -> suivant = nouvelle_tete;
    }

    perso -> tete = nouvelle_tete;

    //On augmente la taille du personnage de 1
    perso -> taille = perso -> taille + 1;
}

/*
Pr�condition:
    L'entier (taille) est un entier positif non-nul
PostCondition:
    La taille du personnage est �gale � (taille)
*/
personnage creer(int taille, position positionTete){
    //precondition
    assert(taille > 0);

    //On d�clare la variable perso et on rempli ses champs
    personnage perso;
    perso.taille = 0;
    perso.queue = NULL;
    perso.tete = NULL;

    //On ajoute la t�te du personnage avec comme position (positionTete)
    ajouter_tete(&perso, positionTete);

    /*
    On ajoute (taille - 1) queue(s)

    Invariant de boucle: (taille)
    Variant de boucle: (taille-1-x)
    */
    for(int x=0 ; x<taille - 1 ; x++){
        ajouter_queue(&perso);
    }

    return perso;
}


void detruire_personnage(personnage perso){
    //On commence de la queue
    corps* actuel = perso.queue;

    //A chaque fois que le corps n'est pas null -> il y a de l'espace � lib�rer
    while(actuel != NULL){
        corps* suivant = actuel -> suivant;
        free(actuel);

        //On traite ensuite le maillon suivant
        actuel = suivant;
    }
}


//Jeu de test
#include <stdio.h>
void afficher_perso(personnage perso){
	corps* actuel = perso.queue;
	while(actuel!=NULL){
		printf("(%d %d) ",(actuel -> pos).x , (actuel -> pos).y );
		actuel = actuel -> suivant;
	}
	printf("\n");
}

/*
V�rifie les posconditions de chaque fonction
Affiche � chaque op�ration la structure du personnage � comparer avec la th�orie
*/
void testPersonnage(){
    printf("\n");
    printf("==============Personnage==============");
    printf("\n");

    int X_INITIAL = 1;
    int Y_INITIAL = 1;
    position POS_INITIALE;
    POS_INITIALE.x = X_INITIAL;
    POS_INITIALE.y = Y_INITIAL;

    int TAILLE_INITIALE = 2;

	personnage perso = creer(TAILLE_INITIALE, POS_INITIALE);
    assert(perso.taille == TAILLE_INITIALE);
    printf("Creation personnage taille %d: ", TAILLE_INITIALE);
    afficher_perso(perso);

	ajouter_queue(&perso);
	assert(perso.taille == TAILLE_INITIALE+1);
	printf("Ajout d'une queue: ");
	afficher_perso(perso);

	retirer_queue(&perso);
	assert(perso.taille == TAILLE_INITIALE);
	printf("Suppression d'une queue: ");
	afficher_perso(perso);


    int NOUVEAU_X = 2;
    int NOUVEAU_Y = 2;
    position NOUVELLE_POS;
    NOUVELLE_POS.x = NOUVEAU_X;
    NOUVELLE_POS.y = NOUVEAU_Y;
	ajouter_tete(&perso, NOUVELLE_POS);
	assert(perso.taille == TAILLE_INITIALE + 1);
	printf("Ajout d'une tete: ");
	afficher_perso(perso);
}
