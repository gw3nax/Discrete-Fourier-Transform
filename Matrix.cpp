#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <math.h>
#include <fstream>


using namespace std;

double pi = atan(1.0)*4;

Matrix::Matrix(int sX, int sY)
{
	sizeX = sX;
	sizeY = sY;
	matrix = new ComplexNum[sizeX * sizeY]();
}
Matrix::Matrix()
{
	matrix = new ComplexNum[0]();
	sizeX = sizeY = 0;
}
Matrix::Matrix(int n)
{
	sizeX = sizeY = n;
	matrix = new ComplexNum[sizeX * sizeY]();
	//ComplexNum* bn = new ComplexNum[n]();
	//cout << "bn = ";
	//for (int i = 0; i < n; i++)
	//{
	//	bn[i].SetComplexNum(cos(-2 * pi / n * (i + 1)), sin(-2 * pi / n * (i + 1)));
	//	bn[i].print();
	//}
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{		
			double a = (-2.0) * pi * j * i / n;
			matrix[i * sizeY + j].SetComplexNum(cos(a), sin(a));
		}
	}
}
void Matrix::SetName(string name)
{
	this->name = name;
}
Matrix::Matrix(int* nums, int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	matrix = new ComplexNum[sizeX * sizeY]();
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			matrix[j + i * sizeY].SetComplexNum(*(nums+j), 0);
		}
	}
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
				Temp.matrix[j + i * sizeY] = matrix[j + i * sizeY] * num;
			}
		}
		return Temp;
	}
	Matrix Matrix::operator * (Matrix b)
	{
		if (sizeY != b.sizeX) {
			cout << "ERROR: Size of matrixs isnt equal" << endl;
			return Matrix();
		}
		Matrix result(sizeX, b.sizeY);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < b.sizeY; j++) 
			{
				ComplexNum sum = ComplexNum();
				for (int k = 0; k < sizeY; k++) 
				{
					sum = sum + matrix[k + i * sizeY] * b.matrix[j + k * b.sizeY];
				}
				result.matrix[j + i * b.sizeY] = sum;
			}
		}
		return result;
	}
	Matrix Matrix::operator / (int num)
	{
		Matrix Temp(sizeX, sizeY);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				Temp.matrix[j + i * sizeY] = matrix[j + i * sizeY] / num;
			}
		}
		return Temp;
	}
	void Matrix::ÑonjugateNumber()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				matrix[j + i * sizeY] = matrix[j + i * sizeY].ÑonjugateNumber();
			}
		}
	}
	double Matrix::GetMatrixNum(int num)
	{
		return matrix[num].GetIm();
	}
	void Matrix::SetMatrixRand(int size)
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				matrix[j + i * sizeY].SetComplexNum(rand()%10, rand()%10);
			}
		}
	}
	void Matrix::Transpose()
	{
		Matrix transposed(sizeY, sizeX);

		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				transposed.matrix[j + i * sizeY] = matrix[i + j * sizeY];
			}
		}
		int tempSize = sizeX;
		sizeX = sizeY;
		sizeY = tempSize;
		memcpy(matrix, transposed.matrix, sizeof(matrix));
	}
	void Matrix::SetMatrix()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << "Ââåäèòå " << j+1 << "-é ýëåìåíò äëÿ " << i+1 << "-é ñòðîêè: ";
				matrix[j + i * sizeY].SetComplexNum();
			}
		}
	}
	int* Matrix::GetMatrix()
	{
		int* temp = nullptr;
		memcpy(temp, matrix, sizeX * sizeY * sizeof(int));
		return temp;
	}
	void Matrix::print()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << "|";
				matrix[j + i * sizeY].print();
				cout<< "|";
			}
			cout << endl << setw(14) << fixed << "- - - - - - - " << endl;
		}
	}
	void Matrix::printFile()
	{
		string fileName = name + ".txt";
		ofstream file(fileName);
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				file << matrix[j + i * sizeY] << "|";
			}
			file << endl;
		}
	}
