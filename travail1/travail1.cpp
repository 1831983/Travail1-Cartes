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
void AfficherLesJoueurs();
void Jouer();
 int DemanderNombreDeCartes();
void MelangerCartes();
void DistribuerLesCartes(int MaxCarteADistribuer);
 int AfficherLesCartes(int MaxCarteADistribuer, Joueur InJoueur);
 void AfficherGagnant(int TotalJoueur1, int TotalJoueur2);
 void AfficherGrandGagnant();




int main() 
{
	InitialiserJoueurs(&leJeu.Joueur1, &leJeu.Joueur2);

	char fini = 'n';
	srand((unsigned)time(NULL));
	
	while (fini=='n' || fini=='N')
	{
		Jouer();
	//   Jouer(); // Jouer plus haut que cout
	cout << "\nTermine (n/o) ? ";
	cin >> fini;	

	AfficherGrandGagnant();
	}
}

//While -» rentre un chiffre entre 1 et 26




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





void Jouer() 
{
	int MaxCarteADistribuer = 0;
	int TotalJoueur1 = 0;
	int TotalJoueur2 = 0;


	ClrScr();

	AfficherLesJoueurs();
	MaxCarteADistribuer = DemanderNombreDeCartes();
	MelangerCartes();

	DistribuerLesCartes(MaxCarteADistribuer);

	TotalJoueur1 = AfficherLesCartes(MaxCarteADistribuer, leJeu.Joueur1);
	TotalJoueur2 = AfficherLesCartes(MaxCarteADistribuer, leJeu.Joueur2);

	AfficherGagnant(TotalJoueur1, TotalJoueur2);

	leJeu.Joueur1.RetirerCartes();
	leJeu.Joueur2.RetirerCartes();

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

int AfficherLesCartes(int MaxCarteADistribuer, Joueur InJoueur)
{
	int Total = 0;

	cout << InJoueur.getNom() << "\n\n";
	cout << "Voici les cartes de votre main :\n";

	for (int i = 0; i < MaxCarteADistribuer; i++)
	{
		
		cout << InJoueur.getCarte(i)->GetValeur() << " " << InJoueur.getCarte(i)->GetAtout() << "\n";
		Total += InJoueur.getCarte(i)->GetValeur();

	}

	cout << "Total : " << Total << "\n\n";

	return Total;

}

void AfficherGagnant(int TotalJoueur1, int TotalJoueur2)
{

	if (TotalJoueur1 > TotalJoueur2)
	{

		cout << leJeu.Joueur1.getNom() << "  gagne la partie ! \n\n";
		leJeu.Joueur1.AjouterVictoire();
		leJeu.Joueur2.AjouterDefaite();


	}
	else if (TotalJoueur1 == TotalJoueur2)
	{
		cout << "\nEgalite !! \n\n";
	}
	else
	{
		cout << leJeu.Joueur2.getNom() << "  gagne la partie ! \n\n";
		leJeu.Joueur2.AjouterVictoire();
		leJeu.Joueur1.AjouterDefaite();
	}

}

void AfficherGrandGagnant()
{
	ClrScr();

	cout << "Les joueurs etaient : " << leJeu.Joueur1.getNom() << " et " << leJeu.Joueur2.getNom() << "\n\n";

	cout << "Voici les stats du joueur  " << leJeu.Joueur1.getNom() << ": \n\n";
	cout << "Nombre de victoires : " << leJeu.Joueur1.getNombreDeVictoire() << "\n\n";
	cout << "Nombre de defaites : " << leJeu.Joueur1.getNombreDeDefaite()  << "\n\n\n";

	cout << "Voici les stats du joueur  " << leJeu.Joueur2.getNom() << ": \n\n";
	cout << "Nombre de victoires : " << leJeu.Joueur2.getNombreDeVictoire() << "\n\n";
	cout << "Nombre de defaites : " << leJeu.Joueur2.getNombreDeDefaite() << "\n\n\n";

	if (leJeu.Joueur1.getNombreDeVictoire() > leJeu.Joueur2.getNombreDeVictoire())
	{
		cout << "Le grand gagnant de la partie est : " << leJeu.Joueur1.getNom() << "\n";
	}

	else if (leJeu.Joueur1.getNombreDeVictoire() == leJeu.Joueur2.getNombreDeVictoire())
	{
		cout << "Egalite entre : " << leJeu.Joueur1.getNom() << " et " << leJeu.Joueur2.getNom();
	}
	else
	{
		cout << "Le grand gagnant de la partie est : " << leJeu.Joueur2.getNom() << "\n";
	}

	


}
