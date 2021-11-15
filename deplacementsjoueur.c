#include <stdbool.h>
#include "deplacementsjoueur.h"
#include <assert.h>


bool deplaceEnhaut;
bool deplaceAdroite;
struct pos {
	int y;
	int x;
};
struct pos p;




int prochcase(int tab[][],int max_x, int max_y, int min_x, int min_y) {
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
	if (p.x < max_x, p.y < max_y, p.x > min_x, p.y > min_y) {
		end -1;
	}
}



void deplace_joueur(int tab[][],int max_x, int max_y, int min_x, int min_y) {
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
	if (p.x < max_x, p.y < max_y, p.x > min_x, p.y > min_y) {
		end -1;
	}	
	tab[p.y][p.x] = 0;
}



void inverse_horizontale() {
	deplaceAdroite != deplaceAdroite;
}
	


struct pos positions() {
	return p;
}
	
	
int modif_pos(int a, int b) {
	p.y = a;
	p.x = b;
}
