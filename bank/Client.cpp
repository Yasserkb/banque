#include "Client.h"
int Client::count = 1;

Client::Client(string nomc) : Id(Client::count++)
{
	this->nomProp = nomc;
}

void Client::afficher() const
{
	cout << " NOM Client : " << this->nomProp << endl;
	for (int i = 0; i < comptes.size(); i++)
	{
		comptes[i]->consulterSolde();
	}
}

void Client::ajouterCompte(Compte* compte)
{
	this->comptes.push_back(compte);
}

void Client::afficherOperation() const
{
	cout << "NOM Client  : " << this->nomProp << endl;
	for (int i = 0; i < comptes.size(); i++)
	{
		comptes[i]->consulterSolde();
		comptes[i]->affOperation();
	}
}

void Client::retirerCompteById(int id, Devise d)
{
	for (int i = 0; i < comptes.size(); i++)
	{
		if (comptes[i]->checkId(id))
		{
			comptes[i]->retirerArgent(d);
		}
	}
}

void Client::deposerCompteById(int id, Devise d)
{
	for (int i = 0; i < comptes.size(); i++)
	{
		if (comptes[i]->checkId(id))
		{
			comptes[i]->deposerArgent(d);
		}
	}
}

void Client::transferById(int id, Compte& compte, Devise d)
{
	for (int i = 0; i < comptes.size(); i++)
	{
		if (comptes[i]->checkId(id))
		{
			if (comptes[i]->retirerArgent(d)) {
				compte.deposerArgent(d);
			}
		}
	}
}

Client::~Client()
{
	cout << "destruction du objet Client " << endl;
}
