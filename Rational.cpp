//Orion Guan
//April 11th, 2017
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

	void simplify()
	{
		int gcd = gcd_recursive(numerator, denominator);
		numerator /= gcd; 
		denominator /= gcd;
		if (denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
		}
	}

	int gcd_recursive(int a, int b)
	{
		if (b) return gcd_recursive(b, a % b);
		else return a;
	}

public:
	Rational(int numerator, int denominator)
	{
		if (denominator)
		{
			this->numerator = numerator;
			this->denominator = denominator;
			simplify();
		}
		else
		{
			cout << "Divide by zero detected, returning 0." << endl;
			this->numerator = 0;
			this->denominator = 1;
		}
	}

	void add(Rational addend)
	{
		numerator = numerator * addend.denominator + addend.numerator * denominator;
		denominator *= addend.denominator;
		simplify();
	}

	void subtract(Rational subtrahend)
	{
		numerator *= -1;
		add(subtrahend);
		numerator *= -1;
	}

	void multiply(Rational multiplier)
	{
		numerator *= multiplier.numerator;
		denominator *= multiplier.denominator;
		simplify();
	}

	void divide(Rational divisor)
	{
		if (!divisor.numerator)
		{
			cout << "Divide by zero cancelled." << endl;
			return;
		}
		if (!numerator)
		{
			return;
		}
		int temp = denominator;
		denominator = numerator;
		numerator = temp;
		multiply(divisor);
		temp = denominator;
		denominator = numerator;
		numerator = temp;
	}

	void printRadical()
	{
		cout << toString(numerator) << '/' << toString(denominator) << endl;
	}

	void printDouble()
	{
		cout << toString(numerator/(double)denominator) << endl;
	}

	string toString(int integer) //this version of std doesn't have to_string
	{
		stringstream ss;
		ss << integer;
		return ss.str();
	}

	string toString(double doubleExpression)
	{
		stringstream ss;
		ss << doubleExpression;
		return ss.str();
	}
};