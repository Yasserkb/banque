#include "Devise.h"
#include <iostream>
#include <assert.h>

using namespace std;

Devise::Devise()
{
    this->argent = 0;
    this->symbole = "MAD";
}

Devise::Devise(double argent, string symbl)
{
    if (argent <= 0)
    {
        this->argent = 0;

    }
    else {
        this->argent = argent;
    }
    this->symbole = symbl;
}

bool Devise::operator>(Devise dev)
{
    bool R;
    R = this->argent >= dev.argent;
    return R;
}

bool Devise::operator>=(Devise dev)
{
    bool R;
    R = this->argent >= dev.argent;
    return R;
}

Devise& Devise::operator-=(Devise dev)
{
    this->argent -= dev.argent;
    return *this;
}

Devise& Devise::operator+=(Devise dev)
{
    this->argent += dev.argent;
    return *this;
}

Devise Devise::operator*(double num)
{
    return Devise(this->argent * num, this->symbole);
}

Devise Devise::operator/(double num)
{
    assert(num != 0);
    return Devise(this->argent / num,this->symbole);
}

string Devise::toString() const
{
    return to_string(this->argent) + " " + this->symbole;
}
