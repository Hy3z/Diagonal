#include <assert.h>
#include <stdlib.h>

#include <stdio.h>

/*struct position_struct {
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
typedef struct personnage_struct personnage;*/


////////////////////////////////////////////////////////////////////////
//SI ON PEUT ENLEVER CA C COOL
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

int taille(personnage perso){
	return perso.taille;
}

position positionQueue(personnage perso){
	assert(taille(perso)>0);
	return perso.queue -> pos;
}

position positionTete(personnage perso){
	assert(taille(perso)>0);
	return perso.tete -> pos;
}

void retirer_queue(personnage* perso){
	assert(perso -> taille > 0);
	if(perso -> taille > 1){
		corps* queue = perso -> queue;
		perso -> queue = queue -> suivant;
		free(queue);
		perso -> taille = perso -> taille - 1;
		//FAUT LUI UPDATE GRAPHISME QUEUE
	}
}

void ajouter_queue(personnage* perso){
	corps* nouvelle_queue = malloc(sizeof(corps));

	position nouvelle_position;
	nouvelle_position.x = -1;
	nouvelle_position.y = -1;

	nouvelle_queue -> pos = nouvelle_position;
	nouvelle_queue -> suivant = perso -> queue;
	perso -> queue = nouvelle_queue;
	perso -> taille = perso -> taille + 1;
}

void ajouter_tete(personnage* perso, position positionTete){
    corps* nouvelle_tete = malloc(sizeof(corps));

    nouvelle_tete -> pos = positionTete;
    if(perso -> taille == 0){
        perso -> queue = nouvelle_tete;
    }else{
        perso -> tete -> suivant = nouvelle_tete;
    }
    perso -> tete = nouvelle_tete;
    perso -> taille = perso -> taille + 1;
}

personnage creer(int taille, position pos){
    personnage perso;
    perso.taille = 0;
    perso.queue = NULL;
    perso.tete = NULL;

    ajouter_tete(&perso, pos);
    for(int x=0 ; x<taille - 1 ; x++){
        ajouter_queue(&perso);
    }
    return perso;
}

/*void afficher_perso(personnage perso){
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
