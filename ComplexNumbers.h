#include <iostream>
using namespace std;

class ComplexNum
{
private:
	double Re;
	double Im;
public:
	ComplexNum();
	ComplexNum(double aIm, double aRe);
	void SetComplexNum(double aIm, double aRe);
	void SetComplexNum();
	ComplexNum СonjugateNumber();
	ComplexNum operator + (ComplexNum b);
	bool operator == (ComplexNum b);
	friend ostream& operator<<(ostream& os, const ComplexNum& complex);
	ComplexNum operator - (ComplexNum b);
	ComplexNum operator * (ComplexNum b);
	ComplexNum operator / (ComplexNum b);
	ComplexNum operator / (int num);
	ComplexNum operator = (ComplexNum b);
	ComplexNum operator * (int num);
	double GetRe();
	double GetIm();
	void print();
};