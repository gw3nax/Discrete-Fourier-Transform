#include "ComplexNumbers.h"
#include <iostream>
#include "Matrix.h"
#include <string>

using namespace std;

void main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "RU-ru");
	Matrix b(4, 4);
	b.SetMatrixRand(10);
	b.print();
	cout << endl;
	b.Transpose();
	b.print();
	system("cls");
}