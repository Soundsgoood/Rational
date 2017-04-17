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

	//reduces fraction to lowest terms
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

	//identifies the lowest common denominator
	int gcd_recursive(int a, int b)
	{
		if (b) return gcd_recursive(b, a % b);
		else return a;
	}

public:
	//constructs a simplified fraction
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
	
	//adds an addend fraction to this fraction
	void add(Rational addend)
	{
		numerator = numerator * addend.denominator + addend.numerator * denominator;
		denominator *= addend.denominator;
		simplify();
	}

	//subtracts a subtrahend fraction from this fraction
	void subtract(Rational subtrahend)
	{
		numerator *= -1;
		add(subtrahend);
		numerator *= -1;
	}

	//multiplies a multiplier fraction from this fraction
	void multiply(Rational multiplier)
	{
		numerator *= multiplier.numerator;
		denominator *= multiplier.denominator;
		simplify();
	}
	
	//divides a divisor fraction from this fraction
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

	//prints the fraction in a/b form
	void printRadical()
	{
		cout << toString(numerator) << '/' << toString(denominator) << endl;
	}

	//prints the fraction in floating point form
	void printDouble()
	{
		cout << toString(numerator/(double)denominator) << endl;
	}

	//converts an integer to a string
	string toString(int integer) //this version of std doesn't have to_string
	{
		stringstream ss;
		ss << integer;
		return ss.str();
	}

	//converts a double to a string
	string toString(double doubleExpression)
	{
		stringstream ss;
		ss << doubleExpression;
		return ss.str();
	}
};
