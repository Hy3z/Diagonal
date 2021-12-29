#ifndef PERSONNAGE_H
#define PERSONNAGE_H


////////////////////////////////////////////////////////////////////////
/*
Structure d�finissant une position dans la grille
L'entier x repr�sente la position en abcisse
L'entier y repr�sente la position en ordonn�e
*/
struct position_struct {
		int x;
		int y;
};
typedef struct position_struct position;


/*
Impl�mentation d'une liste cha�n�e

Structure d�finissant un corps (�quivalent � un maillon d'une liste chain�e)
La position est la position dans la grille de ce corps
(suivant) est un pointeur vers le corps suivant (�quivalent au maillon suivant dans une liste cha�n�e)
*/
struct corps_struct {
	position pos;
	struct corps_struct* suivant;
};
typedef struct corps_struct corps;


/*
Un personnage est d�finit comme une liste de corps
Il contient un pointeur vers la queue du personnage (�quivalent au premier maillon d'une liste cha�n�e)
/!\ La queue du personnage n'est pas la queue de la liste

Il contient un pointeur vers la t�te du personnage (�quivalent au dernier maillon d'une liste cha�n�e)
/!\ La t�te du personnage n'est pas le premier �l�ment de la liste

Il contient un entier qui indique sa taille (�quivalent au nombre de maillons de la liste cha�n�e)
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


//Renvoie la valeur du champ (pos) de la t�te du personnage (perso)
position positionTete(personnage perso);


//Supprime la queue du personnage (perso)
void retirer_queue(personnage* perso);


//Ajoute un corps comme nouvelle queue au personnage (perso) avec une position (-1, -1)
void ajouter_queue(personnage* perso);


//Ajoute un corps comme nouvelle t�te au personnage (perso) avec une position (positionTete)
void ajouter_tete(personnage* perso, position positionTete);


//Renvoie un personnage de taille (taille) avec tous ses corps en position (-1, -1) et sa t�te en position (positionTete)
personnage creer(int taille, position positionTete);


#endif
