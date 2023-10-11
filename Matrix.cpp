#include <iostream>
#include "Matrix.h"
#include "ComplexNumbers.h"
#include <iomanip>

using namespace std;
	Matrix::Matrix(int sX, int sY)
	{
		sizeX = sX;
		sizeY = sY;
		matrix = new Complex[sizeX * sizeY];
	}
	Matrix::Matrix()
	{
		matrix = new Complex[20];
		sizeX = sizeY = 0;
	}
	Matrix Matrix::operator + (Matrix b)
	{
		Matrix Temp(sizeX, sizeY);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				*(Temp.matrix + j + i * sizeY) = *(matrix + j + i * sizeY) + *(b.matrix + j + i * b.sizeY);
			}
		}
		return Temp;
	}
	Matrix Matrix::operator - (Matrix b)
	{
		Matrix Temp(sizeX, sizeY);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				*(Temp.matrix + j + i * sizeY) = *(matrix + j + i * sizeY) - *(b.matrix + j + i * b.sizeY);
			}
		}
		return Temp;
	}
	Matrix Matrix::operator * (int num)
	{
		Matrix Temp(sizeX, sizeY);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				*(Temp.matrix + j + i * sizeY) = *(this->matrix + j + i * this->sizeY) * num;
			}
		}
		return Temp;
	}
	void Matrix::SetMatrixRand(int size)
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				if (i == 0 || j == 0)
				{
					*(matrix + j + i * sizeY) = Complex(1,0);
				}
				else
				{
					*(matrix + j + i * sizeY) = Complex(2,2);
				}
			}
		}
	}
	/*void Matrix::Transpose()
	{
		Complex t;
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				t = *(matrix + j + i * sizeY);
				*(matrix + j + i * sizeY) = *(matrix + i + j * sizeY);
				*(matrix + i + j * sizeY) = t;
			}
		}
	}*/
	void Matrix::SetMatrix()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << "Введите " << j+1 << "-й элемент для " << i+1 << "-й строки: ";
				*(matrix + j + i * sizeY)->print();
			}
		}
	}
	int* Matrix::GetMatrix()
	{
		int* temp = nullptr;
		memcpy(temp, matrix, sizeX * sizeY * sizeof(int));
		return temp;
	}
	Complex Matrix::SumStr(int strNum)
	{
		if (strNum > sizeX || strNum <= 0) return Complex(-1,0);
		Complex sum = Complex();
		for (int j = 0; j < sizeY; j++)
		{
			sum = sum +  *(matrix + strNum-1 + j*sizeX);
		}
		return sum;
	}
	Complex Matrix::SumStb(int stbNum)
	{
		if (stbNum <= 0 || stbNum > sizeY) return Complex(-1, 0);
		Complex sum = Complex();
		for (int i = 0; i < sizeX; i++)
		{
			sum = sum + *(matrix + i + (stbNum - 1) * sizeX);
			
		}
		return sum;
	}
	void Matrix::print()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << setw(4) << fixed;
				*(matrix + j + i * sizeY)->print();
				cout<< " | ";
			}
			cout << endl;
			for (int j = 0; j < sizeY-1; j++)
			{
				cout << setw(4) << fixed << "- - - - ";
			}
			cout << endl;
		}
	}