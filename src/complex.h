#pragma once

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class complex
{
private:
	double real, imag;
public:
	complex(double r = 0, double i = 0);
	void setVals(double r, double i);
	string print();
	complex operator + (complex const &other);
	complex operator - (complex const &other);
	complex operator * (complex const &other);
	double magnitude();
	//complex();
	//~complex();
};

bool accept(complex c, int n);