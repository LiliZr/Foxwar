#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include "coordonnees.hpp"

//Pour les Renards
const int FoodInit = 5;
const int FoodLapin = 5;
const int FoodReprod = 8;
const int MaxFood = 10;
const float ProbBirthRenard = 0.05;
//Pour les Lapins
const float ProbBirthLapin = 0.30;
const int MinFreeBirthLapin = 4;

enum Animal{Lapin, Renard, Rien};

struct animal{
    Animal genre;
    coord c;
    int nourriture;
    int age;
};

/* _Fonctions animal.cpp_ */
animal creerAnimal( Animal g, coord c);
coord coordAnimal( animal a);
Animal especeAnimal( animal a);
int nourritureAnimal(animal a);
bool estVide ( animal a);
void changeCoordAnimal (animal &a, coord c);
void mangeRenard (animal &a);
void faimRenard (animal &a);
bool mortAnimal(animal a);
bool seReproduitAnimal(animal a, int nombreCaseVide);

#endif
