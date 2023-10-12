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
	ComplexNum ÑonjugateNumber();
	ComplexNum operator + (ComplexNum b);
	bool operator == (ComplexNum b);
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