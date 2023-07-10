#include <iostream>
#include <cassert>

using namespace std;

#include"Fraction.h"

int main() {
	/*Fraction f1, f2;
	cin >> f1;
	cin >> f2;

	cout << f1 << endl;
	cout << f2 << endl;*/

	/*cout << f1 + f2 << endl;
	cout << f1 - f2 << endl;
	cout << f1 / f2 << endl;
	cout << f1 * f2 << endl;*/

	/*cout << (f1 > f2) << endl;
	cout << (f1 < f2) << endl;
	cout << (f1 >= f2) << endl;
	cout << (f1 <= f2) << endl;
	cout << (f1 == f2) << endl;
	cout << (f1 != f2) << endl;*/

	/*cout << f1++ << endl;
	cout << ++f2 << endl;

	cout << --f1 << endl;
	cout << f2-- << endl;*/

	/*Fraction f1(3, 9);

	double frac = (double)f1;
	cout << frac << endl;
	cout << typeid(frac).name() << endl;*/

	Fraction f1(3, 7);
	Fraction f2(f1);
	cout << f1 << endl << f2 << endl;

	Fraction f3 = move(f1);
	cout << f1 << endl << f3 << endl;
	cout << endl;

	Fraction f4(5, 9);
	Fraction f5;
	f5 = f4;
	cout << f4 << endl << f5 << endl;

	Fraction f6;
	f6 = move(f5);
	cout << f5 << endl << f6 << endl;

	return 0;
}