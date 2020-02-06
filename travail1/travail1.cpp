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

int main() 
{

	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs(&leJeu.Joueur1, &leJeu.Joueur2);
	while (fini=='n' || fini=='N')
	{
		Jouer(); 
		cout << leJeu.Joueur1.getNom();
		cout << leJeu.Joueur2.getNom();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
}

void Jouer() 
{
	
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
