﻿#include <iostream>
#include "ComplexNumbers.h"
using namespace std;
class Matrix
{
private:
	int sizeX, sizeY;
	ComplexNum* matrix;
	string name;
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
	void СonjugateNumber();
	void SetMatrixRand(int size);
	void SetMatrix();
	void SetName(string name);
	void Transpose();
	int* GetMatrix();
	double GetMatrixNum(int num);
	ComplexNum SumStr(int strNum);
	ComplexNum SumStb(int stbNum);
	void print();
	void printFile();
};