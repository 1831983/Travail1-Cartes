#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs(Joueur* Joueur1, Joueur* Joueur2);
void Jouer();
int DemanderNombreDeCartes();
void MelangerCartes();
void DistribuerLesCartes(int MaxCarteADistribuer);
void AfficherLesCartes();


int main() 
{
	InitialiserJoueurs(&leJeu.Joueur1, &leJeu.Joueur2);

	char fini = 'n';
	srand((unsigned)time(NULL));
	
	while (fini=='n' || fini=='N')
	{
		Jouer();
		
		
	//   Jouer(); // Jouer plus haut que cout
	//cout << "\nTermine (n/o) ? ";
	//cin >> fini;		
	}
}

void Jouer() 
{
	int MaxCartesADistribuer = 0;

	ClrScr();

	
	//AfficherLesJoueurs();
	MaxCartesADistribuer = DemanderNombreDeCartes();
	MelangerCartes();

	DistribuerLesCartes(MaxCartesADistribuer);
	
}

void InitialiserJoueurs(Joueur* Joueur1, Joueur* Joueur2)
{
	ClrScr();

	string nomJoueur1;
	string nomJoueur2;

	cout << "Joueur1, entrez votre nom :";
	cin >> nomJoueur1;
	Joueur1->setNom(nomJoueur1);

	cout << "Joueur2, entrez votre nom :";
	cin >> nomJoueur2;
	Joueur2->setNom(nomJoueur2);

}

void AfficherLesJoueurs()
{
	cout << "\nJoueur 1 :\n" << leJeu.Joueur1.getNom() << "\n";
	cout << "\nJoueur 2 : \n" << leJeu.Joueur2.getNom() << "\n";
}

void MelangerCartes()
{
	srand(time(NULL));

	unsigned int NombreAleatoire1 = 0;
	unsigned int NombreAleatoire2 = 0;
	Carte Tempo;

	for (int i = 0; i < 3000; i++)
	{

	NombreAleatoire1 = rand() % maxCartes;
	NombreAleatoire2 = rand() % maxCartes;

	 Tempo = leJeu.PaquetDeCartes[NombreAleatoire1];
	leJeu.PaquetDeCartes[NombreAleatoire1] = leJeu.PaquetDeCartes[NombreAleatoire2] ;
	leJeu.PaquetDeCartes[NombreAleatoire2]= Tempo;

	}


	//Afficher les cartes mélangées

	//for (int i = 0; i < maxCartes; i++)
	//{
	//	cout << leJeu.PaquetDeCartes[i].GetValeur() << "  " << leJeu.PaquetDeCartes[i].GetAtout() << "\n";
	//
	//}



}

int DemanderNombreDeCartes()
{

int MaxCarteADistribuer = 0;


	cout << "\nCombien de cartes a distribuer ? (Max 26)\n";
	cin >> MaxCarteADistribuer;
	cout << "Nombre de cartes a distribuer :\n" << MaxCarteADistribuer << "\n\n";
	
	return MaxCarteADistribuer;

		//if (MaxCarteADistribuer > 26)
		//{
		//	cout << "Erreur, Maximum de cartes a distribuer : 26";
		//	Jouer();
}




void DistribuerLesCartes(int MaxCarteADistribuer)
{
	bool ok = true;
	
	
	for (int i = 0; i <= MaxCarteADistribuer*2 ; i++)
	{
		if (ok == true)
		{
			leJeu.Joueur1.AjouterCartes(&leJeu.PaquetDeCartes[i]);
			ok = false;
		}
	
		else
		{
			leJeu.Joueur2.AjouterCartes(&leJeu.PaquetDeCartes[i]);
			ok = true;
		}
		
	}

}

void AfficherLesCartes(int MaxCarteADistribuer)
{
	for (int i = 0; i <= MaxCarteADistribuer; i++)
	{

		cout << leJeu.Joueur1.getCarte(i)->GetValeur() << " " << leJeu.Joueur1.getCarte(i)->GetAtout();

	}


}
