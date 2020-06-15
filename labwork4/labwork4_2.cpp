#include <iostream>
#include <ctime>

using namespace std;


int sum(int n, int i)
{
	if (n / 10 == 0) return ++i;

	return sum(n / 10, ++i);
}

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));

	int n, i;
	i = 0;

	cout << "Введите число: "; cin >> n;

	cout << "Количество цифр в заданном числе: " << sum(n, i) << endl;

	return 0;
}
