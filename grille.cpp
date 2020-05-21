/*Fonctions Grille */

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

#include "grille.hpp"

using namespace std;

/* Nettoie l'affichage */
void reint_display() {
  cout << "\x1B[2J\x1B[H" << endl;
}

/* range un animal dans la grille */
void setAnimal(grille &g, animal a) {
  g.t[getY(coordAnimal(a))][getX(coordAnimal(a))]=a;
}

/*initialise une grille vide*/
void grilleVide(grille &g) {
  for (int i =0; i < TAILLE; i++){
    for (int j =0; j<TAILLE; j++){
      setAnimal(g,creerAnimal(Rien,creeCoord(j,i)));
    }
  }
}

/*initialise une grille aleatoirement*/
void initialiseGrille (grille &g) {
  float r;
  Animal e;
  for (int i =0; i < TAILLE; i++){
    for (int j =0; j<TAILLE; j++){
      r= rand()%100/100.;
      e=Rien;
      if (r< ProbR+ProbL) e=Lapin;
      if (r< ProbR) e=Renard;
      setAnimal(g,creerAnimal(e,creeCoord(j,i)));
    }
  }
}

/*affiche une grille */
void afficherGrille(grille g) {
  for (int i =0; i < TAILLE; i++){
    for (int j =0; j<TAILLE; j++){
      switch (especeAnimal(g.t[i][j])){
        case 0: cout << "\033[1;34m" <<" L "; break;
        case 1: cout << "\033[1;31m" << " R "; break;
        default: cout << "\033[1;37m" << " O ";
      }
    }
    cout<<endl;
  }
}

/*retourne une copie de l animal situe aux coordonnees "c" dans la grille */
animal getAnimal(grille g, coord c) {
  animal a;
  a= g.t[getY(c)][getX(c)];
  return a;
}

/*Copie grille 1 dans grille 2*/
void copieGrille (grille g1, grille &g2) {
  coord c; animal a;
  for (int i =0; i < TAILLE; i++){
    for (int j =0; j<TAILLE; j++){
      c=creeCoord(j,i);
      a= getAnimal(g1, c);
      setAnimal(g2,a);
    }
  }
}

/*Retourne lensemble des cases voisines contenant l espece e */
tab_coord voisinsEspeces(grille g, animal a, Animal e) {
  tab_coord t,v;
  t.n=0;
  v=retourne_voisins(coordAnimal(a));
  for (int i=0; i<v.n ; i++){
    if (especeAnimal(getAnimal(g,v.tab[i]))==e)ajoute_coord(t,v.tab[i]);
  }
  return t;
}
