#ifndef DEPLACEMENT_JOUEUR_H
#define DEPLACEMENT_JOUEUR_H
#include <stdbool.h>

struct pos {
	int y;
	int x;
};
struct pos p;


/*fonction qui renvoie le numéro de la prochaine case */
int prochcase(int tab[30][100],int max_x, int max_y);


/*fonction déplaçant la valeur du joueur dans la nouvelle position */
void deplace_joueur(int tab[30][100],int max_x, int max_y);


/*fonction inversant la direction */
void inverse();

void inverse_horizontale();

void inverse_verticale();



/*fonction renvoyant les positions x et y */
struct pos positions();


/*fonction pour modifier manuellement les positions */
void modif_pos(int a, int b);

#endif
