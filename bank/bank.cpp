#include <iostream>
#include "Compte.h"
#include "Client.h"
#include "Operation.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include "ComptePayant.h"
#include "Devise.h"

int main()
{
    Client P("Charlse");

	P.afficher();

	CompteCourant* cc = new CompteCourant(Devise(10000, "MAD"), Devise(2000, "MAD"));
	CompteEpargne* ce = new CompteEpargne(Devise(10000, "MAD"));
	ComptePayant* cp = new ComptePayant(Devise(10000, "MAD"));
	CompteCourant ct(Devise(10000, "MAD"), Devise(2000, "MAD"));

	P.ajouterCompte(cc);
	P.ajouterCompte(ce);
	P.ajouterCompte(cp);

	P.afficher();
	
		Devise d(1000, "MAD");

	//retirer
	P.retirerCompteById(1, d);
	P.retirerCompteById(2, d);
	P.retirerCompteById(3, d);

	cout << endl << "apres le retrait" << endl;

	P.afficher();

	//deposer
	P.deposerCompteById(1, d);
	P.deposerCompteById(2, d);
	P.deposerCompteById(3, d);

	cout << endl << "apres le deposition " << endl;

	P.afficher();


	//transferer 
	P.transferById(1, ct, d);
	P.transferById(2, ct, d);
	P.transferById(3, ct, d);

	cout << endl << "apres le transfer " << endl;

	P.afficher();
	ct.consulterSolde();

	//il ne peut pas retirer car  il veut retire un somme superieur a le decouvert
	Devise d4(3000, "MAD");
	P.retirerCompteById(1, d4);

	

}