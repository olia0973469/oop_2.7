//////////////////////////////////////////////////////////////////////////////
// Source.cpp
// головний файл проекту – функція main

#include <iostream>
#include <string>
#include "Goods.h"
#include "Money.h"

using namespace std;

int main()
{
	Goods z;
	Money t;
	string c;
	int d, n1 = 1, n2 = 5;
	cout << " Name = "; cin >> c;
	z.SetName(c);
	cout << " Price = "; cin >> d;
	z.SetPrice(d);
	cout << " Quantity = "; cin >> d;
	z.SetQuantity(d);
	cout << " N = "; cin >> d;
	z.SetNo(d);
	cout << " Date = "; cin >> d;
	z.SetDate(d);
	cout << "g: "; cin >> z;
	cout << z << endl;

	cout << " CangePrice = " << endl;
	z.ChangePrice(n1, n2);

	return 0;
}
