#include <iostream>
#include "Matrix.h"

using namespace std;
	Matrix::Matrix(int minX, int maxX, int minY, int maxY)
	{
		sizeX = maxX-minX+1;
		sizeY = maxY-minY+1;
		matrix = new int[sizeX * sizeY];
		length = sizeX * sizeY;
		capacity = sizeX * sizeY;
	}
	int Matrix::minXIndex() const { return 0; }
	int Matrix::maxXIndex() const { return sizeX - 1; }
	int Matrix::minYIndex() const { return 0; }
	int Matrix::maxYIndex() const { return sizeY - 1; }
	Matrix::Matrix()
	{
		matrix = new int[20];
		sizeX = sizeY = 0;
		length = 0;
		capacity = 20;
	}
	void Matrix::AddElement(int el)
	{
		if (this->length >= this->capacity)
		{
			cout << length << endl;
			int* temp = new int[sizeX * sizeY + 20];
			memcpy(temp, matrix, length * sizeof(int));
			delete[] matrix;
			matrix = temp;
			capacity += 20;
			length += 1;
			sizeX += 1;
		}
		*(matrix+length-1) = el;
		cout << *(matrix + length) << endl << endl;
	}
	Matrix Matrix::operator + (Matrix b)
	{
		Matrix Temp(minXIndex(), maxXIndex(), minYIndex(), maxYIndex());
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
		Matrix Temp(minXIndex(), maxXIndex(), minYIndex(), maxYIndex());
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				*(Temp.matrix + j + i * sizeY) = *(matrix + j + i * sizeY) - *(b.matrix + j + i * b.sizeY);
			}
		}
		return Temp;
	}
	void Matrix::SetMatrixRand(int range)
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				*(matrix + j + i * sizeY) = rand()%range;
			}
		}
	}
	void Matrix::SetMatrix()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << "Введите " << j+1 << "-й элемент для " << i+1 << "-й строки: ";
				cin >> *(matrix + j + i * sizeY);
			}
		}
	}
	int* Matrix::GetMatrix()
	{
		int* temp;
		temp = matrix;
		return temp;
	}
	int Matrix::SumStr(int strNum)
	{
		if (strNum > sizeX || strNum <= 0) return -1;
		int sum = 0;
		for (int j = 0; j < sizeY; j++)
		{
			sum += *(matrix + strNum-1 + j*sizeX);
		}
		return sum;
	}
	int Matrix::SumStb(int stbNum)
	{
		if (stbNum <= 0 || stbNum > sizeY) return -1;
		int sum = 0;
		for (int i = 0; i < sizeX; i++)
		{
			sum += *(matrix + i + (stbNum - 1) * sizeX);
		}
		return sum;
	}
	void Matrix::print()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				cout << *(matrix + j + i * sizeY) << ' ';
			}
			cout << endl;
		}
	}