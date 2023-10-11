#include <iostream>
#include "ComplexNumbers.h"
using namespace std;
class Matrix
{
private:
	int sizeX, sizeY;
	Complex* matrix;
public:
	Matrix(int sX, int sY);
	Matrix();
	Matrix operator + (Matrix b);
	Matrix operator - (Matrix b);
	Matrix operator * (int num);
	void SetMatrixRand(int size);
	void SetMatrix();
	void Transpose();
	int* GetMatrix();
	Complex SumStr(int strNum);
	Complex SumStb(int stbNum);
	void print();
};