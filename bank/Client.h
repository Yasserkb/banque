#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Compte.h"
#include "Devise.h"

using namespace std;


class Client
{
private:
	string nomProp;
	const int Id;
	static int count;
	vector<Compte*> comptes = vector<Compte*>();

public:

	Client(string nomc);
	void afficher() const;
	void ajouterCompte(Compte* compte);
	void afficherOperation() const;
	void retirerCompteById(int id, Devise d);
	void deposerCompteById(int id, Devise d);
	void transferById(int id, Compte& compte, Devise d);
	~Client();
};