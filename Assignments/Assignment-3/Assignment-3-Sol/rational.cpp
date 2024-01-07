#include "rational.h"
int Rational::totalRationals = 0;
Rational Rational::maxRational;
//DEFAULT CONSTRUCTOR
Rational::Rational() : numerator(0), denominator(1) {}
//PARAMETERIZED CONSTRUCTOR
Rational::Rational(int n, int d)
{
	this->numerator = n;
	this->denominator = d;
}
//CONSTRUCTOR FOR OBJS HAVING ONLY NUMERATOR
Rational::Rational(int numer)
{
	this->numerator = numer;
	this->denominator = 1;
}
//COPY CONSTRUCTOR
Rational::Rational(const Rational& r)
{
	numerator = r.numerator;
	denominator = r.denominator;
}
//DESTRUCTOR
Rational::~Rational()
{
	cout << "                          - - " << endl;
	cout << "I'm a fraction destructor > < " << endl;
	cout << "                          --- " << endl;
}
//SETTERS/GETTERS
void Rational::set_numerator(int nu)
{
	this->numerator = nu;
}
int Rational::get_numerator()const
{
	return numerator;
}
void Rational::set_denominator(int de)
{
	this->denominator = de;
}
int Rational::get_denominator()const
{
	return numerator;
}
//OPERATORS +,-,*,/
Rational Rational::operator+(const Rational& obj)
{

	Rational result;

	result.numerator = this->numerator + obj.numerator;
	result.denominator = this->denominator;  // You should keep the denominator the same

	return result;
}

Rational Rational::operator-(const Rational& obj)
{
	Rational result;

	result.numerator = this->numerator - obj.numerator;
	result.denominator = this->denominator;  // You should keep the denominator the same

	return result;
}

Rational Rational::operator*(const Rational& obj)
{
	Rational result;

	result.numerator = this->numerator * obj.numerator;
	result.denominator = this->denominator * obj.denominator;  // You should keep the denominator the same

	return result;
}

Rational Rational::operator/(const Rational& obj)
{
	Rational result;

	result.numerator = this->numerator / obj.numerator;
	result.denominator = this->denominator / obj.denominator;  // You should keep the denominator the same

	return result;
}
//OPERATORS ==,!=,>,<
bool Rational::operator==(const Rational& obj)
{
	Rational result;
	if (this->numerator == obj.numerator && this->denominator == obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Rational::operator!=(const Rational& obj)
{
	Rational result;
	if (this->numerator != obj.numerator && this->denominator != obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Rational::operator>(const Rational& obj)
{
	Rational result;
	if (this->numerator > obj.numerator && this->denominator > obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Rational::operator<(const Rational& obj)
{
	Rational result;
	if (this->numerator < obj.numerator && this->denominator < obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//OPERATORS >=,<=,++,--
bool Rational::operator>=(const Rational& obj)
{
	Rational result;
	if (this->numerator >= obj.numerator && this->denominator >= obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Rational::operator<=(const Rational& obj)
{
	Rational result;
	if (this->numerator <= obj.numerator && this->denominator <= obj.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Rational Rational::operator++()
{
	this->numerator + denominator;
	return *this;
}
Rational Rational::operator--()
{
	this->numerator -= denominator;
	return *this;
}
//OPERATORS -,+,=
Rational& Rational::operator-()
{
	numerator = -numerator;
	return *this;
}

Rational Rational::operator+() const
{
	return *this;
}
bool Rational::operator!() const
{
	return numerator == 0;
}
Rational& Rational::operator=(const Rational& obj)
{
	if (this != &obj)
	{
		this->numerator = obj.numerator;
		this->denominator = obj.denominator;
	}
	return *this;
}
//OPERATOR +=,-=,,/=
Rational& Rational::operator+=(const Rational& obj)
{
	int newNumerator = (this->numerator * obj.denominator) + (obj.numerator * this->denominator);
	int newDenominator = this->denominator * obj.denominator;
	this->numerator = newNumerator;
	this->denominator = newDenominator;
	return *this;
}
Rational& Rational::operator-=(const Rational& obj)
{
	int newNumerator = (this->numerator * obj.denominator) - (obj.numerator * this->denominator);
	int newDenominator = this->denominator * obj.denominator;
	this->numerator = newNumerator;
	this->denominator = newDenominator;
	return *this;
}
Rational& Rational::operator*=(const Rational& obj)
{
	this->numerator *= obj.numerator;
	this->denominator *= obj.denominator;
	return *this;
}
Rational& Rational::operator/=(const Rational& obj)
{
	this->numerator /= obj.numerator;
	this->denominator /= obj.denominator;
	return *this;
}
void Rational::initializeMaxRational(int n, int d)
{
	maxRational.set_numerator(n);
	maxRational.set_denominator(d);
}
Rational Rational::getMaxRational()
{
	return maxRational;
}

int Rational::getTotalRationals()
{
	return totalRationals;
}
//COUT
ostream& operator<<(ostream& display, const Rational ray)
{
	display << "Numerator: " << ray.numerator << endl;
	display << "Denominator: " << ray.denominator << endl;
	return display;
}
//CIN
istream& operator>>(istream& input, Rational ray)
{
	cout << "Enter the numerator: ";
	input >> ray.numerator;
	cout << "Enter the denominator: ";
	input >> ray.denominator;
	return input;
}