#include <stdbool.h>
#include "deplacementsjoueur.h"
#include <assert.h>



bool deplaceEnhaut = true;
bool deplaceAdroite = true;
struct pos p;




int prochcase(int tab[30][100],int max_x, int max_y) {
	if (deplaceAdroite) {
		if (deplaceEnhaut) {
			return tab[p.y + 1][p.x + 1];
		} else {
			return tab[p.y - 1][p.x + 1];
		}
	} else {
		if (deplaceEnhaut) {
			return tab[p.y + 1][p.x - 1];
		} else {
			return tab[p.y - 1][p.x - 1];
		}
	}
	if (p.x > max_x, p.y > max_y, p.x < 0, p.y < 0) {
		assert(0<1);
		//end -1;
	}
}



void deplace_joueur(int tab[30][100],int max_x, int max_y) {
    int oldx = p.x;
    int oldy = p.y;
	if (deplaceAdroite) {
		if (deplaceEnhaut) {
			tab[p.y + 1][p.x + 1] = tab[p.y][p.x];
			p.y += 1,p.x += 1;
		} else {
			tab[p.y - 1][p.x + 1] = tab[p.y][p.x];
			p.y -= 1, p.x += 1;
		}
	} else {
		if (deplaceEnhaut) {
			tab[p.y + 1][p.x - 1] = tab[p.y][p.x];
			p.y += 1, p.x -= 1;
		} else {
			tab[p.y - 1][p.x - 1] = tab[p.y][p.x];
			p.y -= 1, p.x -= 1;
		}
	}
	if (p.x > max_x, p.y > max_y, p.x < 0, p.y < 0) {
		assert(0<1);
		//end -1;
	}
	tab[oldy][oldx] = 0;
}



void inverse_horizontale() {
	deplaceAdroite = !deplaceAdroite;
}

void inverse_verticale() {
	deplaceEnhaut = !deplaceEnhaut;
}

struct pos positions() {
	return p;
}


void modif_pos(int a, int b) {
	p.y = a;
	p.x = b;
}
