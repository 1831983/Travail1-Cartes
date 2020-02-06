#include "joueur.h"

Joueur::Joueur()
{
	nom = "";
	nombreDeVictoire = 0;
	nombreDeDefaite = 0;

	for (int i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}



Carte* Joueur::getCarte(int indiceTableau)
{
	return mainDuJoueur[indiceTableau];
}


string Joueur::getNom() const
{
	return nom;
}

int Joueur::getNombreDeVictoire()const
{
	return nombreDeVictoire;
}

int Joueur::getNombreDeDefaite() const
{
	return nombreDeDefaite;
}
void Joueur::setNom(string inNom)
{
	nom = inNom;
}

void Joueur::AjouterVictoire()
{
	nombreDeVictoire++;
}

void Joueur::AjouterDefaite()
{
	nombreDeDefaite++;
}

void Joueur::RetirerCartes()
{
	for (int i = 0; i < maxCartesAJouer ; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}
