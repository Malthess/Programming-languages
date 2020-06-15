#include <iostream>

using namespace std;

int F(int n);
int G(int n);

int main()
{
	for (int i = 1; i <= 10; i++)// перебираем i от 1 до 10
	{
		cout << "F(" << i << ") = " << F(i) << "\t\t"; // выводим F(i)
		cout << "G(" << i << ") = " << G(i) << "\t\t" << endl; // выводим G(i)
	}
	return 0;
}

int F(int n)
{
	if (n >= 2) return F(n - 1) - 2 * G(n - 1);
	else return 4;
}

int G(int n)
{
	if (n >= 2) return F(n - 1) - G(n - 1);
	else return -2;
}
