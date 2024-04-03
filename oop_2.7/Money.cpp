//////////////////////////////////////////////////////////////////////////////
// Money.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include "Money.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Money::Money()
{}

Money::Money(double x, double y)
{
	hr = x;
	kop = y;
}

Money::Money(const Money& a)
{
	*this = a;
}

Money Money::Add(const Money& other) const
{
	Money result;
	result.SetHr(this->hr + other.hr);
	result.SetKop(this->kop + other.kop);
	return result;
}

Money Money::Sub(const Money& other) const
{
	Money result;
	result.SetHr(this->hr - other.hr);
	result.SetKop(this->kop - other.kop);

	if (result.kop >= 100)
	{
		result.hr -= result.kop / 100;
		result.kop = 100;
	}

	return result;
}

double Money::Divide(const Money& other) const
{
	if (other.hr == 0 || other.kop == 0)
	{
		cout << "Error: Division by zero" << endl;
		return 0.0;
	}

	double totalThis = hr - (static_cast<double>(kop) / 100);
	double totalOther = other.hr - (static_cast<double>(other.kop) / 100);

	return totalThis / totalOther;
}

Money Money::DivideFraction(double division)
{
	if (division == 0.0)
	{
		cerr << "Error.\n";
		exit(1);
	}

	Money result;
	result.hr = this->hr / division;
	result.kop = this->kop / division;

	return result;
}

Money Money::MultFraction(double mult)
{
	Money result;
	result.SetHr (this->hr * mult);
	result.SetKop (this->kop * mult);
	return result;
}

Money& Money::operator =(const Money& r)
{
	hr = r.hr;
	kop = r.kop;
	return *this;
}

Money Money::operator!=(const Money& other) const
{
	Money result;
	result.hr = (hr != other.hr) ? hr : 0;
	result.kop = (kop != other.kop) ? kop : 0;
	return result;
}

Money Money::operator<=(const Money& other) const
{
	Money result;
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis < totalOther) 
	{
		result.hr = hr;
		result.kop = kop;
	}
	return result;
}

Money Money::operator>(const Money& other) const
{
	Money result;

	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis > totalOther) 
	{
		result.hr = hr;
		result.kop = kop;
	}

	return result;
}

Money Money::operator>=(const Money& other) const 
{
	Money result;
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis >= totalOther) 
	{
		result = *this;
	}
	return result;
}

Money::operator string() const
{
	stringstream ss;
	ss << "(" << hr << " UAH , Kop " << kop << ")";
	return ss.str();
}

Money& Money::operator ++()
{
	++hr;
	return *this;
}

Money& Money::operator --()
{
	--hr;
	return *this;
}

Money Money::operator ++(int)
{
	Money tmp = *this;
	++kop;
	return tmp;
}

Money Money::operator --(int)
{
	Money tmp = *this;
	--kop;
	return tmp;
}

ostream& operator <<(ostream& out, const Money& x)
{
		out << string(x);
	return out;
}

istream& operator >>(istream& in, Money& x)
{
	cout << " Hryvni: "; in >> x.hr;
	cout << " Kopijky: "; in >> x.kop;
	return in;
}
