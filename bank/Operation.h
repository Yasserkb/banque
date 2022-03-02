#pragma once
#include <iostream>
#include <ctime>

using namespace std;
class Operation
{
private:
	time_t t;
	const int id;
	static int count;
	string op;

public:

	Operation(string m);
	void afficher() const;
	~Operation();


};

