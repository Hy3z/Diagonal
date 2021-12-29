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
Précondition:
    La taille du personnage est un entier positif non-nul
    (Implique que la queue du personnage est un pointeur non-nul)
*/
position positionQueue(personnage perso){
    //precondition
	assert(perso.taille > 0);

	return perso.queue -> pos;
}


/*
Précondition:
    La taille du personnage est un entier positif non-nul
    (Implique que la tête du personnage est un pointeur non-nul)
*/
position positionTete(personnage perso){
    //precondition
	assert(perso.taille > 0);

	return perso.tete -> pos;
}


/*
Précondition:
    La taille du personnage est un entier positif non-nul
    (Implique que la queue du personnage est un pointeur non-nul)
PostCondition:
    La taille du personnage est un entier positif non nul
*/
void retirer_queue(personnage* perso){
    //precondition
	assert(perso -> taille > 0);

	//On ne diminue la taille du personnage que si celle-ci est de 2 ou +
	//Sinon le personnage aurait pût faire 0 de taille après la diminution
	if(perso -> taille > 1){
		corps* queue = perso -> queue;

        //La nouvelle queue est le corps suivant la queue actuelle
		perso -> queue = queue -> suivant;

		//On libère l'espace réservé pour la queue actuelle
		free(queue);

		//On diminue la taille du personnage de 1
		perso -> taille = perso -> taille - 1;
	}
}


/*
PostCondition:
    La taille du personnage a augmentée de 1
*/
void ajouter_queue(personnage* perso){

    /*
    On alloue un espace mémoire pour la nouvelle queue
    Si jamais l'allocation a échouée, on réessaye jusqu'à ce que ça fonctionne
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
    La taille du personnage a augmentée de 1
*/
void ajouter_tete(personnage* perso, position positionTete){

    /*
    On alloue un espace mémoire pour la nouvelle tête
    Si jamais l'allocation a échouée, on réessaye jusqu'à ce que ça fonctionne
    */
    corps* nouvelle_tete = NULL;
    while(nouvelle_tete == NULL){
        nouvelle_tete = malloc(sizeof(corps));
    }

    //La position de la nouvelle tête est (positionTete)
    nouvelle_tete -> pos = positionTete;

    //Si le personnage est de taille 0 alors la nouvelle tête devient aussi la nouvelle queue
    if(perso -> taille == 0){
        perso -> queue = nouvelle_tete;
    //Sinon l'ancienne tête pointe vers la nouvelle tête
    }else{
        perso -> tete -> suivant = nouvelle_tete;
    }

    perso -> tete = nouvelle_tete;

    //On augmente la taille du personnage de 1
    perso -> taille = perso -> taille + 1;
}

/*
Précondition:
    L'entier (taille) est un entier positif non-nul
PostCondition:
    La taille du personnage est égale à (taille)
*/
personnage creer(int taille, position positionTete){
    //precondition
    assert(taille > 0);

    //On déclare la variable perso et on rempli ses champs
    personnage perso;
    perso.taille = 0;
    perso.queue = NULL;
    perso.tete = NULL;

    //On ajoute la tête du personnage avec comme position (positionTete)
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

/*
#include <stdio.h>
void afficher_perso(personnage perso){
	corps* actuel = perso.queue;
	printf("Taille = %d \n",perso.taille);
	while(actuel!=NULL){
		printf("(%d %d) ",(actuel -> pos).x , (actuel -> pos).y );
		actuel = actuel -> suivant;
	}
	printf("\n");
}

int main(){
	personnage perso;
	perso.taille = 0;
	perso.queue = NULL;
	perso.tete = NULL;
	ajouter_queue(&perso);
	afficher_perso(perso);
	ajouter_queue(&perso);
	afficher_perso(perso);
	retirer_queue(&perso);
	afficher_perso(perso);
	retirer_queue(&perso);
	afficher_perso(perso);

}*/
