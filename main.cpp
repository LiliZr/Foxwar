#include "animal.hpp"
#include "coordonnees.hpp"
#include "deplacement.hpp"
#include "ensemble.hpp"
#include "grille.hpp"
#include "tools.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
  srand(time(NULL));
  system("mkdir images");
  grille g,g2;
  int l;int r;
  grilleVide(g2);
  grilleVide(g);
  initialiseGrille(g);
  afficherGrille(g);
  compte(g, l ,r);
  cout << endl;
  cout << "Lapins : " << l << endl << "Renards :" << r << endl;
  int n = 0;
  while(l != 0 || r != 0){
    grilleVide(g2);
    deplace(g, g2);
    copieGrille(g2,g);
    afficherGrille(g);
    compte(g, l ,r);
    cout << "\033[1;37m" << "Lapins : " << l << endl << "Renard : " << r << endl;
    sleep(1);
    reint_display();
    string img =  n + ".ppm";
    image(g,n);
    n++;

  }
  cout << "Les lapins et les renards sont tous morts ! " << endl;
  return 0;
}
