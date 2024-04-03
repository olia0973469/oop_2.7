//////////////////////////////////////////////////////////////////////////////
// Money.h
// заголовочний файл Ц визначенн€ класу
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Money
{
	double hr;
	double kop;
public:
	double GetHr() const { return hr; }
	double GetKop() const { return kop; }
	void SetHr(double value) { this->hr = value; }
	void SetKop(double value) { this->kop = value; }

	Money();
	Money(double, double);
	Money(const Money&);

	Money Add(const Money& other) const;
	Money Sub(const Money& other) const;
	double Divide(const Money& other) const;
	Money DivideFraction(double division);
	Money MultFraction(double mult);

	Money& operator =(const Money&);
	Money operator!=(const Money& other) const;
	Money operator<=(const Money& other) const;
	Money operator>(const Money& other) const;
	Money operator>=(const Money& other) const;
	operator string() const;
	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
	friend ostream& operator <<(ostream&, const Money&);
	friend istream& operator >>(istream&, Money&);
};
