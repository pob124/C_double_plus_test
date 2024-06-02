#include <iostream>
#include "complex.h"
using namespace std;
Complex::Complex() {

	real = 0;
	imagine = 0;
}
Complex::Complex(double r, double i) {
	real = r;
	imagine = i;
}
Complex add(Complex a, Complex b) {
	Complex temp;
	temp.real = a.real + b.real;
	temp.imagine = a.imagine + b.imagine;
	return temp;
}
void print(string s1, Complex c1){
	
	cout << s1 << " " << c1.real << " + " << c1.imagine << endl;

}
Complex Complex::operator+ (Complex op2) {
	Complex temp;
	temp.real = real + op2.real;
	temp.imagine = imagine + op2.imagine;
	return temp;

}
bool Complex::operator==(Complex op2) {
	if (real == op2.real && imagine == op2.imagine) return true;
	else return false;

}
Complex& Complex::operator++() { //전위
	real += 1;
	imagine += 1;
	return *this;
}
Complex Complex::operator++(int x) { //후위
	Complex temp;
	temp = *this;
	real += 1;
	imagine += 1;
	return temp;
}