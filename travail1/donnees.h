#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
private:

	

public:

	Donnees();

	Carte PaquetDeCartes[maxCartes];

	Joueur Joueur1;
	Joueur Joueur2;



void InitialiserCartes();

};

