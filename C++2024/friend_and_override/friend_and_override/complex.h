
#ifndef COMPLEXNUMBER
#define COMPLEXNUMBER

#include <iostream>
#include <string>
using namespace std;
class Complex {

	private:
		double real;
		double imagine;
	public:
		Complex();
		Complex(double r, double i);
		friend Complex add(Complex a, Complex b);
		friend void print(string s1, Complex c1);
		Complex operator+ (Complex op2);
		bool operator==(Complex op2);
		Complex& operator++ ();
		Complex operator++ (int x);
};
#endif