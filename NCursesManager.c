#include <ncurses.h>
#include <stdbool.h>
#include <assert.h>


const int TOUCHE_FIN_PARTIE = KEY_DC;


/*
Pr�condition:
    (x) est un entier naturel
    (y) est un entier naturel
*/
void changerCaractere(int x, int y, char caractere){
    //pr�condition
    assert(x>=0 && y>=0);

    //La fonction mvaddch de ncurses prend la valeur en ordonn�e en 1er argument et la valeur en abscisse en 2eme
    mvaddch(y, x, caractere);
}


//Appelle la fonction refresh de ncurses qui raffrach�t les caract�res affich�s sur l'�cran
void rafraichirEcran(){
    refresh();
}


void initFenetre(){
    //Initialise la f�netre ncurses
    initscr();

    //Indique au clavier que relacher une touche n'est pas la m�me action que l'appuyer
    noecho();

    //Masque le curseur en jeu
    curs_set(0);

    //Indique � ncurses de ne pas attendre, lors de l'appel de la fonction (getch), qu'une touche soit appuy�e
    nodelay(stdscr,true);

    //Indique � ncurses que toutes les touches du clavier peuvent �tre enfonc�es lors du jeu
    keypad(stdscr, true);
}


/*
Pr�conditions:
    (max_x) est un entier naturel
    (max_y) est un entier naturel
*/
void affiche(int grille[30][100], const char BLOC_CARACTERE[], int max_x, int max_y){
    //precondition
    assert(max_x >= 0 && max_y >= 0);

    for(int y=0 ; y<max_y ; y++){
        for(int x=0 ; x<max_x ; x++){
			changerCaractere(x, y, BLOC_CARACTERE[grille[y][x]]);
		}
	}
}


void finFenetre(){
    //Ferme la f�netre de ncurses
    endwin();
}


bool isToucheAppuyee(){
    //getch renvoit une valeur lorsque une touche vient d'�tre enfonc�e
    return getch()!=ERR;
}


void effacer(){
    clear();
}


bool relancerPartie(){
    //Affiche le message de fin de partie
    mvprintw(13, 30, " Game Over! ");
    mvprintw(14, 30, " Appuyez sur une touche pour relancer ");
    mvprintw(15, 30, " Ou appuyez sur 'suppr' pour quitter ");
    rafraichirEcran();

    //On attend que le joueur appuie sur une touche
    nodelay(stdscr,false);
    int toucheAppuyee = getch();

    //On r�active le mode nodelay pour la partie suivante
    nodelay(stdscr,true);

    //Si la touche appuyee n'est pas celle de fin de partie, c'est � dire qu'on va relancer une partie, on renvoit true
    return toucheAppuyee != TOUCHE_FIN_PARTIE;
}
