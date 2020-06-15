#include <iostream>
#include <ctime>
using namespace std;

void ifcheckd(int* p_darr, int t, int k, int& d);
int main()
{
	setlocale(LC_ALL, "Russian");
	int t, a, b;
	cout << "Введите количество элементов массива:"; cin >> t; cout << "\n";
	if (t <= 0)
	{
		cout << "wrong parameters"; return 1;
	}
	cout << "Введите значения границ интервала, по которому будут заданы элементы массива\n";
	cout << "Введите значение левой границы(включительно):"; cin >> a; cout << "\n";
	cout << "Введите значение правой границы(включительно):"; cin >> b; cout << "\n";
	int* p_darr = new int[t];
	if (a >= 0)
	{
		if (b >= 0)
		{
			if (b - a < 0)
			{
				cout << "wrong parameters";
				return 2;
			}
		}
		else
		{
			cout << "wrong parameters";
			return 3;
		}
	}
	else
	{
		if (b < 0)
		{
			if (b - a < 0)
			{
				cout << "wrong parameters"; return 4;
			}
		}
	}
	srand((unsigned)time(0));
	for (int i = 0; i < t; i++)
	{
		p_darr[i] = rand() % (b - a + 1) + a; //(double)rand() * (b-a) / RAND_MAX + a;
		cout << "p_darr[" << i << "]= " << p_darr[i] << "\n";
	}
	int k;
	cout << "Для удаления элементов массива с заданным значением, пожалуйста, введите его:"; cin >> k; cout << "\n";
	int s = 0, d = 0;
	ifcheckd(p_darr, t, k, d);
	int* new_p_darr = new int[t - d];
	for (int g = 0; g < t - d; g++)
	{
		new_p_darr[g] = p_darr[g];
		cout << "p_darr[" << g << "]= " << new_p_darr[g] << "\n";
	}
	delete[] new_p_darr;
	delete[] p_darr;
	return 0;
}

void ifcheckd(int* p_darr, int t, int k, int& d)
{
	for (int i = 0; i < t; i++)
	{
		if (p_darr[i] == k)
		{
			d++;
			int temp;
			for (int j = i; j < t - 1; j++)
			{
				temp = p_darr[j];
				p_darr[j] = p_darr[j + 1];
				p_darr[j + 1] = temp;
			}
			if (i != 0)i = i - 1;
		}
		if (t - 1 - d == i)break;

	}
}