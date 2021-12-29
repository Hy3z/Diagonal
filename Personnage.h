#ifndef PERSONNAGE_H
#define PERSONNAGE_H


////////////////////////////////////////////////////////////////////////
/*
Structure définissant une position dans la grille
L'entier x représente la position en abcisse
L'entier y représente la position en ordonnée
*/
struct position_struct {
		int x;
		int y;
};
typedef struct position_struct position;


/*
Implémentation d'une liste chaînée

Structure définissant un corps (équivalent à un maillon d'une liste chainée)
La position est la position dans la grille de ce corps
(suivant) est un pointeur vers le corps suivant (équivalent au maillon suivant dans une liste chaînée)
*/
struct corps_struct {
	position pos;
	struct corps_struct* suivant;
};
typedef struct corps_struct corps;


/*
Un personnage est définit comme une liste de corps
Il contient un pointeur vers la queue du personnage (équivalent au premier maillon d'une liste chaînée)
/!\ La queue du personnage n'est pas la queue de la liste

Il contient un pointeur vers la tête du personnage (équivalent au dernier maillon d'une liste chaînée)
/!\ La tête du personnage n'est pas le premier élément de la liste

Il contient un entier qui indique sa taille (équivalent au nombre de maillons de la liste chaînée)
*/
struct personnage_struct {
	corps* queue;
	corps* tete;
	int taille;
};
typedef struct personnage_struct personnage;
////////////////////////////////////////////////////////////////////////


//Renvoie la valeur du champ (pos) de la queue du personnage (perso)
position positionQueue(personnage perso);


//Renvoie la valeur du champ (pos) de la tête du personnage (perso)
position positionTete(personnage perso);


//Supprime la queue du personnage (perso)
void retirer_queue(personnage* perso);


//Ajoute un corps comme nouvelle queue au personnage (perso) avec une position (-1, -1)
void ajouter_queue(personnage* perso);


//Ajoute un corps comme nouvelle tête au personnage (perso) avec une position (positionTete)
void ajouter_tete(personnage* perso, position positionTete);


//Renvoie un personnage de taille (taille) avec tous ses corps en position (-1, -1) et sa tête en position (positionTete)
personnage creer(int taille, position positionTete);


#endif
