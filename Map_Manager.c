/* Map Manager 
 * Int Map [][] contient la map
 * int taille ecran x
 * int taille ecran y
 * fonctions qui font des trucs sur la liste de la map */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <ncurses.h>

/* Différents Objets de la map ( Futur Boost ou 'particules' ) */
const int VIDE = 0 ;
const int MUR = 1 ;
const int SOL = 2 ;
const int COIN = 3 ;
const int BLOCK = 4 ;

/* Map avec sa taille, Besoin de malloc potentiellement pour changer la taille selon l'utilisateur
Celle ci est réprésentée par un tableau 2D rempli d'entiers selon les constantes d'au-dessus */
int map[30][100] ; 
int taille_ecran_x = 30 ;
int taille_ecran_y = 100;


/* Exemple map[][] {
 * { MUR , MUR , MUR },
 * { VIDE , BOOST , VIDE },
 * { MUR , MUR , MUR }
 * }
 */
 
/* Ligne = x , colonne = y */

/* Création du map vide avec seulement les contours */
void MapVide(int map[30][100], int x, int y) {
	assert (x > 0 && y > 0) ;
	
	/* Créations du centre ( vide )  */
	for (int i = 0 ; i < x ; i ++ ) {
		for (int j = 0 ; j < y ; j ++ ) {
			map[i][j] = VIDE ;
		}
	}
	/* Création des cotés ( mur ) */
	for (int i = 1 ; i < x ; i ++ ) {
		map[i][y-1] = MUR ;
		map[i][0] = MUR ;
	}
	/* Création des cotés ( Sol et plafond ) */
	for (int j = 1 ; j < y ; j ++ ) {
		map[x-1][j] = SOL ;
		map[0][j] = SOL ;
	}
	/* Création des coins */
	map[0][0] = COIN ;
	map[x-1][y-1] = COIN ;
	map[x-1][0] = COIN ;
	map[0][y-1] = COIN ;
	
	return ;
}

/* Fonction pour crée des structures ( Pour le moment : mur ou sol/plafond 		Futur : Diagonal ? 
 * Elle prend pour argument la map, 
 * l'objet choisi donc MUR, SOL, ect. 
 * pour le moment on prend la taille de la map/écran, cela peut être changé selon comment on choisi la taille de la map. 
 * puis la taille de l'objet */
void SetUpStructure (int map[30][100], int obj , int x , int y , int t) {
	assert ( x > 0 && y > 0 && t > 0 ) ;
	x -= 1 ;	// On ne souhaite pas modifié le contour
	y -= 1 ; 	// de même
	
	if (obj == SOL) {						// Si l'objet voulu est un SOL
		assert ( y+t < taille_ecran_y ) ;	// Pour le moment : Empécher un dépassement du contour et de la map.
		for (int i = 0 ; i < t ; i ++ ) {	// Création du sol de taille t
			if ( map[x][y+i] == VIDE ) {	// On remplace seulement le VIDE par le SOL
				map[x][y+i] = SOL ;
			}
			else if (map[x][y+i] == MUR) {	// Si il y a déjà un MUR on place alors un COIN
				map[x][y+i] = COIN ;
			}
		}									// Si c'est déjà un SOL par besoin de changer
	} 	
	
	
	else if (obj == MUR) {					// De même pour le MUR
		assert ( x + t  < taille_ecran_x ) ; 
		for (int i = 0 ; i < t ; i ++ ) {
			if ( map[x+i][y] == VIDE ) {
				map[x+i][y] = MUR ;
			}
			else if (map[x+i][y] == SOL) {
				map[x+i][y] = COIN ;
			}
		}
	}
	return ;
}

/* Fonction pour dessiner les coins selon leur situation
 * C'est à dire on pose un MUR à coté d'un SOL, cela donne un COIN ( dans ce cas un ANGLE DROIT ) 
 * Cette fonction donc prend en argument la map, et un emplacement précis, avec les coordonées x et y */
void Coin( int map[30][100] , int x , int y ) {
	bool Droite ; // Il y a t'il un objet à droite ?
	bool Gauche ; // IL y a t'il un objet à gauche ?
	bool Dessus ; // IL y a t'il un objet au dessus ?
	bool Dessous ; // IL y a t'il un objet en dessous ?
	
	if ( map[x-1][y] == MUR || map[x-1][y] == COIN) { 	// On vérifie au dessus
		Dessus = true ;
	}
	else {
		Dessus = false ;
	}
	if ( map[x+1][y] == MUR || map[x+1][y] == COIN) {	// On vérifie en dessous
		Dessous = true ;								// Il y a un objet en dessous
	}
	else {
		Dessous = false ; 								// Il n'y a pas d'objet en dessous
	}
	if ( map[x][y+1] == SOL || map[x][y+1] == COIN) {	// On vérifie à droite
		Droite = true ;								
	}
	else {
		Droite = false ;
	}
	if ( map[x][y-1] == SOL || map[x][y-1] == COIN) {	// On vérifie à gauche
		Gauche = true ;
	}
	else {
		Gauche = false ; 
	}

	if ( Dessus == true) {								// Vérification de chaque possibilités : 
		if ( Dessous == true) {							// Il y a un au dessus et en dessous 
			if ( Droite == true) {						// IL y a un objet au dessus, en dessous, et à droite ect.
				if ( Gauche == true) {
					mvaddch( x , y , ACS_PLUS) ;
				}
				else {
					mvaddch( x , y , ACS_LTEE) ;
				}
			}
			else {
				if ( Gauche == true) {
					mvaddch( x , y , ACS_RTEE) ;
				}
				else {
					mvaddch( x , y , ACS_HLINE) ;	// Il y a un objet au dessus, en dessous, mais ni à droite ni à gauche
				}
			}
		}
		else {
			if ( Droite == true) {
				if ( Gauche == true) {
					mvaddch( x , y , ACS_BTEE) ;
				}
				else {
					mvaddch( x , y , ACS_LLCORNER) ;
				}
			}
			else { 
				if ( Gauche == true) {
					mvaddch( x , y , ACS_LRCORNER) ;	// Il y a un objet au dessus mais pas en dessous, il y a aussi un objet à
				}										// gauche mais pas à droite.
			}
		}
	}
	else { 
		if ( Dessous == true) {
			
			if ( Droite == true) {
				if ( Gauche == true) {
					mvaddch( x , y , ACS_TTEE) ;
				}
				else {
					mvaddch( x , y , ACS_ULCORNER) ;
				}
			}
			else {
				if ( Gauche == true ) {
					mvaddch( x , y , ACS_URCORNER) ;
				}
			}
		}
		else {
			mvaddch( x , y , ACS_HLINE) ;
		}
	}
}

/* Fonction qui affiche le contour ( Peut être rajouter dans la fonction AfficheMap juste après mais plus simple et plus lisible comme ça */ 
void AfficheContour(int map[30][100] , int x , int y ){
	assert (x > 0 && y > 0) ;
	mvaddch( 0 , 0 , ACS_ULCORNER) ;	// On ajoute les coins 
	mvaddch( x , y , ACS_LRCORNER) ;
	mvaddch( x , 0 , ACS_LLCORNER) ;
	mvaddch( 0 , y , ACS_URCORNER) ;
	
	for (int i = 1 ; i < x ; i ++ ) {	// On fait les cotés ( MURS ) 
		mvaddch (i , y , ACS_VLINE ) ;	// MURS de droite
		mvaddch (i , 0 , ACS_VLINE ) ;	// MURS de gauche
	}
	for (int j = 1 ; j < y ; j ++ ) {	// On fait le SOL et le plafond
		mvaddch (x , j , ACS_HLINE ) ;	// SOL
		mvaddch (0 , j , ACS_HLINE ) ;	// Plafond
	}
	return ;
}

/* Fonction qui affiche la map de façon plus lisible pour l'homme (avec des caractère et non des chiffres */
void AfficheMap( int map[30][100] , int x  , int y  ) {
	AfficheContour(map,x,y) ;	// On affiche le contours (plus simple mais peut être rajouter comme dit précédemment 
	x -= 1 ;	// Pour ne pas aller jusqu'au contours ( peut être réglé peut être selon comment est géré la taille de la map )
	y -= 1 ; 
	for (int i = 1 ; i < x ; i ++ ) {	// On parcours toutes les lignes
		for (int j = 1 ; j < y ; j ++ ) {	// On parcours toutes les colonnes
			if (map[i][j] == SOL) {			// Si c'est un sol on va au coordonnée et on place le caractère correspondant
				mvaddch( i , j , ACS_HLINE ) ; 
			}
			else if (map[i][j] == MUR) {	// De même pour le MUR
				mvaddch( i , j , ACS_VLINE ) ;
			}
			else if (map[i][j] == COIN) {	// De même pour le COIN
				Coin( map , i , j ) ;		// On utilise la fonction précédent pour connaître la situation du COIN 
			}								// et placé le bon caractère selon le type de COIN
			else if (map[i][j] == BLOCK) {	// Autre possibilité ( à enlever ) 
				mvaddch( i , j , ACS_BLOCK) ;
			}
		}
	}
	return ;
} 
						

/* Pose un objet, à finir, et développer si il y a le temps et si voulu / idée */
void PoseObjet( int obj , int map[30][100] , int x ,int y ) {
	map[x][y] = obj ;
	AfficheMap(map, 30 , 100 ) ;
	refresh() ;
	return ;
}


/* Test des différentes fonctions (TEMPORAIRE, A ENLEVER)*/
int main() {
	taille_ecran_x = 30 ;
	taille_ecran_y = 100 ;
	MapVide(map, 30, 100);
	SetUpStructure(map, MUR , 5 , 50 , 20)  ;
	SetUpStructure(map, SOL , 10 , 5 , 60) ; 
	initscr();
	AfficheMap(map , 30 , 100 ) ;
	refresh() ;
	getch() ;
	SetUpStructure(map, MUR , 3 , 5 , 20) ;
	SetUpStructure(map, SOL, 22 , 5 , 60) ;
	refresh() ; 
	AfficheMap(map , 30 , 100 ) ;
	PoseObjet(BLOCK, map, 20 , 20 ) ;
	getch() ;
	endwin() ;
	
	return 0 ;
}


