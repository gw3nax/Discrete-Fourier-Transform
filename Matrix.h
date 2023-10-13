#include <iostream>
#include "ComplexNumbers.h"
using namespace std;
class Matrix
{
private:
	int sizeX, sizeY;
	ComplexNum* matrix;
public:
	Matrix(int sX, int sY);
	Matrix();
	Matrix(int *nums, int sizeX, int sizeY);
	Matrix(int n);
	Matrix operator + (Matrix b);
	Matrix operator - (Matrix b);
	Matrix operator * (int num);
	Matrix operator * (Matrix b);
	Matrix operator / (int num);
	void ÑonjugateNumber();
	void SetMatrixRand(int size);
	void SetMatrix();
	void Transpose();
	int* GetMatrix();
	double GetMatrixNum(int num);
	ComplexNum SumStr(int strNum);
	ComplexNum SumStb(int stbNum);
	void print();
};