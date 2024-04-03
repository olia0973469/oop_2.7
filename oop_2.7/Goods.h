//////////////////////////////////////////////////////////////////////////////
// Goods.h
// заголовочний файл Ц визначенн€ класу
#pragma once
#include <iostream>
#include "Money.h"
using namespace std;
class Goods
{
	string name;
	int price, quantity, no, date;

	Money money;
public:
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	Goods& operator =(const Goods& r);
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}
	Goods();
	Goods(string, double, double);
	Goods(const Goods&);
	Money Add();
	Money Sub();
	double Divide(int, int);
	Money DivideFraction();
	operator string() const;
	void ChangePrice(double newPriceHr, double newPriceKop);
	void PlusQuantity(int amount);
	void MinusQuantity(int amount);
	Money Cost() const;
	Goods& operator ++();
	Goods& operator --();
	Goods operator ++(int);
	Goods operator --(int);
	friend ostream& operator <<(ostream& out, const Goods& x);
	friend istream& operator >>(istream& in, Goods& x);
};
