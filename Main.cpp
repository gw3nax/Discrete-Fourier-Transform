#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;

void main()
{
	cout << "Made By Larin Mikhail IKPI-25" << endl << endl;
	system("chcp 1251");
	setlocale(LC_ALL, "RU-ru");
	string name;
	cout << "Введите вашу строку: ";
	cin >> name;
	int n = 8;
	if (name.length() <= 9)
	{
		n = 8;
	}
	else if (name.length() > 9)
	{
		n = name.length() / 8 * 8 + 8;
	}
	int* nameCode = new int[n];
	char alphabet[35] = "абвгдеёжзийклмнопрстуфхцчшщьыъэюя_";

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] >= 'А' && name[i] <= 'Я')
		{
			name[i] = name[i] - ('Я' - 'я');
		}
		for (int j = 0; j < sizeof(alphabet)/sizeof(char); j++)
		{
			if (name[i] == alphabet[j])
			{
				nameCode[i] = j+1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (nameCode[i] < 0)
		{
			nameCode[i] = 34;
		}
	}
	Matrix z(nameCode, 1, n);
	cout << "Z = \n";
	z.SetName("Z");
	z.print();
	z.printFile();
	cout << endl;
	cout << endl;
	cout << "Fn = \n";
	Matrix Fn(n);
	Fn.SetName("Fn");
	Fn.print();
	Fn.printFile();
	cout << endl;
	z.Transpose();
	Matrix W(n, 1);
	W= Fn * z;
	cout << "W = \n";
	W.SetName("W");
	W.print();
	W.printFile();
	cout << endl;
	Matrix Fn1 = Fn;
	Fn1.СonjugateNumber();

	cout << "Fn* = " << endl;

	Fn1.print();

	Matrix res = Fn1 * W;
	res = res / n;
	cout << "RES: \n";
	res.SetName("RESULT");
	res.print();
	res.printFile();
	cout << endl;
	char* result = new char[n];
	for (int i = 0; i < n; i++)
	{
		int index = (int)round(res.GetMatrixNum(i));
		result[i] = alphabet[index-1];
		cout << result[i];
	}

	cout << endl<< endl<< "Made By Larin Mikhail IKPI-25" << endl << endl;
}