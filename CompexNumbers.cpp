#include <iostream>
#include "ComplexNumbers.h"
using namespace std;

Complex::Complex()
	{
		Im = 0;
		Re = 0;
	}
Complex::Complex(double aIm, double aRe)
	{
		Im = aIm;
		Re = aRe;
	}
void Complex::SetComplex(double aIm, double aRe)
	{
		Im = aIm;
		Re = aRe;
	}

Complex Complex::operator + (Complex b)
	{
		Complex Temp;
		Temp.Im = this->Im + b.Im;
		Temp.Re = this->Re + b.Re;
		return Temp;
	}
Complex Complex::operator - (Complex b)
	{
		Complex Temp;
		Temp.Im = this->Im - b.Im;
		Temp.Re = this->Re - b.Re;
		return Temp;
	}
Complex Complex::operator * (Complex b)
	{
		Complex Temp;
		Temp.Im = this->Im * b.Im - this->Re * b.Re;
		Temp.Re = this->Im * b.Re + this->Re * b.Im;
		return Temp;
	}
Complex Complex::operator / (Complex b)
	{
		Complex Temp;
		if (b.Im == 0 || b.Re == 0) return Temp;
		Temp.Im = (this->Im * b.Im + this->Re * b.Re) / (b.Im * b.Im + b.Re * b.Re);
		Temp.Re = (this->Re * b.Im - this->Im * b.Re) / (b.Im * b.Im + b.Re * b.Re);
		return Temp;
	}
void Complex::print()
	{
		cout << Im << " + i * " << Re << endl;
	}
