#include <iostream>
#include "ComplexNumbers.h"
#include <iomanip>
using namespace std;

ComplexNum::ComplexNum()
	{
		Im = 0;
		Re = 0;
	}
ComplexNum::ComplexNum(double aIm, double aRe)
	{
		Im = aIm;
		Re = aRe;
	}
void ComplexNum::SetComplexNum(double aIm, double aRe)
	{
		this->Im = aIm;
		this->Re = aRe;
	}
void ComplexNum::SetComplexNum()
{
	double a = 0, r = 0;
	cout << "Ââåäèòå a è b äëÿ êîìïëåêñíîãî ÷èñëà: ";
	cin >> a >> r;
	this->Im = a;
	this->Re = r;
}
ComplexNum ComplexNum::ÑonjugateNumber()
{
	ComplexNum *Temp = new ComplexNum();
	Temp->Im = this->Im;
	Temp->Re = (-1) * this->Re;
	return *Temp;
}
ComplexNum ComplexNum::operator + (ComplexNum b)
	{
		ComplexNum* Temp = new ComplexNum();
		Temp->Im = this->Im + b.Im;
		Temp->Re = this->Re + b.Re;
		return *Temp;
	}
ComplexNum ComplexNum::operator = (ComplexNum b)
{
	this->Im = b.Im;
	this->Re = b.Re;
	return *this;
}
ComplexNum ComplexNum::operator - (ComplexNum b)
	{
		ComplexNum* Temp = new ComplexNum();
		Temp->Im = this->Im - b.Im;
		Temp->Re = this->Re - b.Re;
		return *Temp;
	}
bool ComplexNum::operator == (ComplexNum b)
{
	if (this->Im == b.Im && this->Re == b.Re)
	{
		return true;
	}
	return false;
}
ComplexNum ComplexNum::operator * (ComplexNum b)
	{
		ComplexNum* Temp = new ComplexNum();
		Temp->Im = this->Im * b.Im - this->Re * b.Re;
		Temp->Re = this->Im * b.Re + this->Re * b.Im;
		return *Temp;
	}

ComplexNum ComplexNum::operator * (int num)
{
	ComplexNum* Temp = new ComplexNum();
	Temp->Im = this->Im * num;
	Temp->Re = this->Re * num;
	return *Temp;
}
double ComplexNum::GetRe()
{
	return this->Re;
}
double ComplexNum::GetIm()
{
	return this->Im;
}
ComplexNum ComplexNum::operator / (ComplexNum b)
	{
		ComplexNum* Temp = new ComplexNum();
		if (b.Im == 0 || b.Re == 0) return *Temp;
		Temp->Im = (this->Im * b.Im + this->Re * b.Re) / (b.Im * b.Im + b.Re * b.Re);
		Temp->Re = (this->Re * b.Im - this->Im * b.Re) / (b.Im * b.Im + b.Re * b.Re);
		return *Temp;
	}
ComplexNum ComplexNum::operator / (int num)
{
	ComplexNum* Temp = new ComplexNum();
	Temp->Im = this->Im / num;
	Temp->Re = this->Re / num;
	return *Temp;
}
void ComplexNum::print()
	{
	int width = 1;
	if (abs(this->Re) < 1e-6)
	{
		cout << setw(9) << fixed << setprecision(width) << Im;
	}
	else if (abs(this->Im) < 1e-6)
	{
		cout << setw(7) << fixed << setprecision(width) << Re << "*i";
	}
	else if (abs(this->Im) < 1e-6 && abs(this->Re) < 1e-6)
	{
		cout << setw(9) << fixed << '0';
	}
	else if (abs(this->Im) > 1e-6 && abs(this->Re) > 1e-6)
	{
		cout << setw(3) << fixed << setprecision(width) << Im << "+i*" << setw(3) << fixed << setprecision(width) << Re;
	}
}

