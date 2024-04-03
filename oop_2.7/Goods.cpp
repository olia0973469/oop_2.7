//////////////////////////////////////////////////////////////////////////////
// Goods.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include <iostream>
#include <sstream>
#include "Goods.h"

using namespace std;

Goods::Goods()
{}

Goods::Goods(string a, double x, double y)
	: name(a), money(x, y)
{}

Goods::Goods(const Goods& a)
{
	*this = a;
}

void Goods::ChangePrice(double newPriceHr, double newPriceKop)
{
	money.SetHr(newPriceHr);
	money.SetKop(newPriceKop);
}

void Goods::PlusQuantity(int amount)
{
	quantity += amount;
}

void Goods::MinusQuantity(int amount)
{
	quantity -= amount;
	if (quantity < 0)
		quantity = 0;
}

Money Goods::Cost() const
{
	double total = money.GetHr() + (money.GetKop() / 100);
	total *= quantity;

	Money result;
	result.SetHr(floor(total));
	result.SetKop((total - floor(total)) * 100);

	return result;
}

Goods& Goods::operator =(const Goods& r)
{
	name = r.name;
	money = r.money;
	return *this;
}

Goods::operator string() const
{
	stringstream ss;
	ss << name << " " << endl;
	ss << price << endl;
	ss << quantity << endl;
	ss << no << endl;
	ss << date << endl;
	ss << money << endl;
	return ss.str();
}

Goods& Goods::operator ++()
{
	++money;
	return *this;
}

Goods& Goods::operator --()
{
	--money;
	return *this;
}

Goods Goods::operator ++(int)
{
	Goods tmp = *this;
	this->money++;
	return tmp;
}

Goods Goods::operator --(int)
{
	Goods tmp = *this;
	this->money--;
		return tmp;
}

ostream& operator <<(ostream& out, const Goods& x)
{
	out << string(x);
	return out;
}

istream& operator >>(istream& in, Goods& x)
{
	cout << " name: "; in >> x.name;
	in >> x.money;
	return in;
}
