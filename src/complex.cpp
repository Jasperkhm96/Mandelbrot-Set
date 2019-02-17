#include "complex.h"

complex::complex(double r, double i) {
	real = r;
	imag = i;
}
void complex::setVals(double r, double i) {
	real = r;
	imag = i;
}
string complex::print() {
	return to_string(real) + " + " + to_string(imag) + "i";
}

complex complex::operator + (complex const &other) {
	return complex(real + other.real, imag + other.imag);
}
complex complex::operator - (complex const &other) {
	return complex(real - other.real, imag - other.imag);
}
complex complex::operator * (complex const &other) {
	return complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
}
double complex::magnitude() {
	return sqrt(pow(real, 2) + pow(imag, 2));
}

bool accept(complex c, int n) {
	/*Decide whether or not complex c param is in mandelbrot set*/
	complex z(0, 0);
	for (int i = 0; i < n; i++) {
		z = (z*z) + c;
		if (z.magnitude() > 2) {
			return false;
		}
	}
	return true;
}