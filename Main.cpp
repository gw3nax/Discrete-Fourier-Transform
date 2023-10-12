#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;

void main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "RU-ru");
	string name;
	cout << "Input name: ";
	cin >> name;
	int n = 32;
	int* nameCode = new int[n];
	char alphabet[34] = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשüûת‎‏ÿ";

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] >= 'À' && name[i] <= '‗')
		{
			name[i] = name[i] - ('‗' - 'ÿ');
		}
		for (int j = 0; j < sizeof(alphabet)/sizeof(char); j++)
		{
			if (name[i] == alphabet[j])
			{
				nameCode[i] = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (*(nameCode+i) <= 0) nameCode[i] = 0;
	}
	Matrix z(nameCode, 1, n);
	cout << "Z = \n";
	z.print();
	cout << endl;
	cout << endl;
	cout << "Fn = \n";
	Matrix Fn(n);
	Fn.print();
	cout << endl;
	z.Transpose();
	cout << endl;
	z.print();
	Matrix W(n, 1);
	W= Fn * z;
	cout << "W = \n";
	W.print();
	cout << endl;
	Matrix Fn1 = Fn;
	Fn1.ÑonjugateNumber();
	Matrix res = Fn1 * W;
	res = res / n;
	cout << "RES: \n";
	res.print();
	cout << endl;
	char* result = new char[n];
	for (int i = 0; i < n; i++)
	{
		int index = (int)round(res.GetMatrixNum(i));
		result[i] = alphabet[index];
		cout << result[i];
	}
}