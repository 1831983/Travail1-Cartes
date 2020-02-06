#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;

class Joueur
{
private:

	string nom;

	int nombreDeVictoire;
	int nombreDeDefaite;

	Carte* mainDuJoueur[26];
	

public:

	Joueur();

	Carte* getCarte(int indiceTableau);
	



	string getNom() const;

	int getNombreDeVictoire() const;
	int getNombreDeDefaite() const;

	

	void setNom(string inNom);
	void AjouterVictoire();
	void AjouterDefaite();
	void RetirerCartes();

};
#endif