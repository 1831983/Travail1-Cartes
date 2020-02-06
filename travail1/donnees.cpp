#include "donnees.h"

Donnees::Donnees()
{

	InitialiserCartes();

}

void Donnees::InitialiserCartes()
{
	int cpt = 0;

	for (int atout = 1; atout <= 4; atout++)
	{

		for (int valeurCarte = 1; valeurCarte <= 13; valeurCarte++)
		{
			Carte NouvelleCarte;

			if (atout == 1)
			{
		
				NouvelleCarte.InitialiserCarte(valeurCarte, "coeur");
			}

			if (atout == 2)
			{
				NouvelleCarte.InitialiserCarte(valeurCarte, "pique");
			}

			if (atout == 3)
			{
				NouvelleCarte.InitialiserCarte(valeurCarte, "carreau");
			}

			if (atout == 4)
			{
				NouvelleCarte.InitialiserCarte(valeurCarte, "trefle");
			}

			PaquetDeCartes[cpt] = NouvelleCarte;
			cpt++;

		}
	}


}
