#ifndef COORDONNEES_HPP_INCLUDED
#define COORDONNEES_HPP_INCLUDED

const int TAILLE = 20;
const int T=TAILLE*TAILLE;

struct coord{
    int x,y;
};

struct tab_coord{
    coord tab[T];
    int n;
};

/* _Fonctions coordonnees.cpp_ */
coord creeCoord( int x, int y );
int getX(coord c);
int getY(coord c);
bool egalCoord ( coord c1, coord c2);
coord randomCoord( tab_coord t);
bool coord_valide(coord a);
void ajoute_coord( tab_coord  &t, coord c);
tab_coord retourne_voisins(coord c);
float alea();

#endif
