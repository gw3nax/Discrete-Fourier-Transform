#include <iostream>
using namespace std;

class Complex
{
private:
	double Re;
	double Im;
public:
	Complex();
	Complex(double aIm, double aRe);
	void SetComplex(double aIm, double aRe);
	Complex operator + (Complex b);
	Complex operator - (Complex b);
	Complex operator * (Complex b);
	Complex operator / (Complex b);
	void print();
};