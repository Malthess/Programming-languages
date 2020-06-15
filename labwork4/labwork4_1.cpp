#include <iostream>
#include <ctime>

using namespace std;


int maksimum(int* A, int n, int max)
{
	if (n == -1) return max;
	if (max < A[n]) max = A[n];

	return maksimum(A, --n, max);
}

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));

	int n;

	cout << "Введите количество элементов массива: ";
	cin >> n;
	int* A = new int[n]; // Создаём динамический массив размером n элементов

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;

		printf("A[%d] = %d\n", i, A[i]);
	}

	int max = 0;

	cout << endl << "Максимальное значение: " << maksimum(A, n - 1, max) << endl; // Передаём n - 1, потому что n - размерность массива и в дальнейшем используем n как индекс каждого элемента.

	return 0;
}
