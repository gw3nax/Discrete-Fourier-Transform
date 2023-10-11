#include <iostream>

using namespace std;
class Matrix
{
private:
	int sizeX, sizeY;
	int* matrix;
	int length;
	int capacity;
public:
	Matrix(int minX, int maxX, int minY, int maxY);
	int minXIndex() const;
	int maxXIndex() const;
	int minYIndex() const;
	int maxYIndex() const;
	Matrix();
	void AddElement(int el);
	Matrix operator + (Matrix b);
	Matrix operator - (Matrix b);
	void SetMatrixRand(int range);
	void SetMatrix();
	int* GetMatrix();
	int SumStr(int strNum);
	int SumStb(int stbNum);
	void print();
};