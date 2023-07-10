#pragma once

class Fraction {
private:
	int _numerator;
	int _denominator;

public:
	Fraction() = default;
	Fraction(int numer, int denom) : _numerator(numer), _denominator(denom) {}

	Fraction(const Fraction& other);
	Fraction& operator=(const Fraction& other);

	Fraction(Fraction&& other);
	Fraction& operator=(Fraction&& other);

	Fraction operator*(const Fraction& other) const;
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	int GetNumer();
	int GetDenom();

	bool operator>(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;

	Fraction& operator++();   
	Fraction& operator++(int);
	Fraction& operator--();    
	Fraction& operator--(int);

	explicit operator double() const;
	
	void Simplify();

private:
	int GCD(int a, int b);

	friend istream& operator>>(istream& in, Fraction& fraction);
	friend ostream& operator<<(ostream& print, const Fraction& fraction);
};
//------------------------------------------------------------------------

istream& operator>>(istream& in, Fraction& fraction) {
	in >> fraction._numerator >> fraction._denominator;
	fraction.Simplify();
	return in;
}

ostream& operator<<(ostream& print, const Fraction& fraction) {
	print << fraction._numerator << "/" << fraction._denominator;
	return print;
}

//------------------------------------------------------------------------

Fraction::Fraction(const Fraction& other) {
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
}

Fraction& Fraction::operator=(const Fraction& other) {
	if (this != &other) {
		this->_numerator = other._numerator;
		this->_denominator = other._denominator;
	}
	return *this;
}

//------------------------------------------------------------------------

Fraction::Fraction(Fraction&& other) {
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	other._numerator = NULL;
	other._denominator = NULL;
}

Fraction& Fraction::operator=(Fraction&& other) {
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	other._numerator = NULL;
	other._denominator = NULL;

	return *this;
}

//------------------------------------------------------------------------

Fraction Fraction::operator*(const Fraction& other) const {
	if (other._denominator == 0 || this->_denominator == 0) {
		assert(!"Division by zero!!");
	}
	int numer = _numerator * other._numerator;
	int denom = _denominator * other._denominator;
	return Fraction(numer, denom);
}

Fraction Fraction::operator+(const Fraction& other) const {
	if (other._denominator == 0 || this->_denominator == 0) {
		assert(!"Division by zero!!");
	}
	int numer = (_numerator * other._denominator) + (_denominator * other._numerator);
	int denom = _denominator * other._denominator;
	return Fraction(numer, denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
	if (other._denominator == 0 || this->_denominator == 0) {
		assert(!"Division by zero!!");
	}
	int numer = (_numerator * other._denominator) - (_denominator * other._numerator);
	int denom = _denominator * other._denominator;
	return Fraction(numer, denom);
}

Fraction Fraction::operator/(const Fraction& other) const {
	if (other._numerator == 0 || this->_denominator == 0) {
		assert(!"Division by zero!!");
	}
	int numer = _numerator * other._denominator;
	int denom = _denominator * other._numerator;
	return Fraction(numer, denom);
}

//------------------------------------------------------------------------

int Fraction::GetNumer() {
	return this->_numerator;
}

int Fraction::GetDenom() {
	return this->_denominator;
}

//------------------------------------------------------------------------

bool Fraction::operator>(const Fraction& other) const {
	return (_numerator * other._denominator) > (other._numerator * _denominator);
}

bool Fraction::operator>=(const Fraction& other) const {
	return (_numerator * other._denominator) >= (other._numerator * _denominator);
}

bool Fraction::operator<(const Fraction& other) const {
	return (_numerator * other._denominator) < (other._numerator * _denominator);
}

bool Fraction::operator<=(const Fraction& other) const {
	return (_numerator * other._denominator) <= (other._numerator * _denominator);
}

bool Fraction::operator==(const Fraction& other) const {
	return (_numerator * other._denominator) == (other._numerator * _denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
	return (_numerator * other._denominator) != (other._numerator * _denominator);
}

//------------------------------------------------------------------------

Fraction& Fraction::operator++() {
	_numerator += _denominator;
	return *this;
}

Fraction& Fraction::operator++(int) {
	_numerator += _denominator;
	return *this;
}

Fraction& Fraction::operator--() {
	_numerator -= _denominator;
	return *this;
}

Fraction& Fraction::operator--(int) {
	_numerator -= _denominator;
	return *this;
}

Fraction::operator double() const {
	return (double)_numerator / _denominator;
}

//------------------------------------------------------------------------

void Fraction::Simplify() {
	int gcd = GCD(_numerator, _denominator);
	this->_numerator /= gcd;
	this->_denominator /= gcd;
}

int Fraction::GCD(int a, int b) {
	int gcd{};
	for (int i = 1; i <= a && i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}