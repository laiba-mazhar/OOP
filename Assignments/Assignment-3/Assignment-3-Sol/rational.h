#pragma once
#include<iostream>
using namespace std;
class Rational
{
private:
	int numerator;
	int denominator;
	static int totalRationals;
	static Rational maxRational;
public:
	Rational();
	Rational(int n, int d);
	Rational(int numer);
	Rational(const Rational& r);
	~Rational();
	void set_numerator(int nu);
	int get_numerator()const;
	void set_denominator(int de);
	int get_denominator()const;
	Rational operator+(const Rational& obj);
	Rational operator-(const Rational& obj);
	Rational operator*(const Rational& obj);
	Rational operator/(const Rational& obj);
	bool operator==(const Rational& obj);
	bool operator!=(const Rational& obj);
	bool operator>(const Rational& obj);
	bool operator<(const Rational& obj);
	bool operator>=(const Rational& obj);
	bool operator<=(const Rational& obj);
	Rational operator++();
	Rational operator--();
	Rational& operator-();
	Rational operator+() const;
	bool operator!() const;
	Rational& operator=(const Rational& obj);
	Rational& operator+=(const Rational& obj);
	Rational& operator-=(const Rational& obj);
	Rational& operator*=(const Rational& obj);
	Rational& operator/=(const Rational& obj);
	static void initializeMaxRational(int n, int d);
	static Rational getMaxRational();
	static int getTotalRationals();
	friend ostream& operator<<(ostream& obj, const Rational ray);
	friend istream& operator>>(istream& obj, const Rational ray);
};