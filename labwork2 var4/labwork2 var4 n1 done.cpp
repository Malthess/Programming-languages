#include <iostream>
#include <ctime>


void upside(int n, int** arr, int ijforup[2], int& max, bool& f);
void maxnegativeshow(bool f, int max);
void rightside(int n, int** arr, int ijforright[2], int& min, bool& p);
void minpositiveshow(bool p, int min);
void endofprogram(int** arr, int ijforright[2], int ijforup[2], int max, int min, bool p, bool f);

int main() {
	srand(unsigned(time(0)));
	int n;
	double a, b;
	std::cout << "Please enter the size of square matrix "; std::cin >> n;
	if (n <= 0) {
		do {
			std::cout << "Please type n again: "; std::cin >> n;
		} while (n <= 0);
	}

	std::cout << "Please enter the a value of the left border: "; std::cin >> a;
	std::cout << "Please enter the b value of the right border: "; std::cin >> b;

	if (a >= 0)
	{
		if (b >= 0)
		{
			if (b - a < 0)
			{
				std::cout << "wrong parameters";
				return 2;
			}
		}
		else
		{
			std::cout << "wrong parameters";
			return 3;
		}
	}
	else
	{
		if (b < 0)
		{
			if (b - a < 0)
			{
				std::cout << "wrong parameters"; return 4;
			}
		}
	}


	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = (double)rand() * (b - a) / RAND_MAX + a;
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	bool f = 0;
	int max;
	int ijforup[2];
	//выше главной и побочной диагонали
	upside(n, arr, ijforup, max, f);

	bool p = 0;
	int min;
	int ijforright[2];
	//правее главной и побочной диагонали
	rightside(n, arr, ijforright, min, p);

	//|| (i<j && i>n - 1 - j) - левее правой и побочной диагонали


	if (p != 0 && f != 0) {
		arr[ijforright[0]][ijforright[1]] = max;
		arr[ijforup[0]][ijforup[1]] = min;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << arr[i][j] << "\t";
			}
			std::cout << "\n";
		}
	}


	  for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;


	

	return 0;
}

void upside(int n, int** arr, int ijforup[2], int& max, bool& f) {
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n - i - 1; j++) {

			if (i <= j && i + j <= n - 1) {

				if (f == 0 && arr[i][j] < 0) {

					max = arr[i][j];
					f = 1;
					ijforup[0] = i;
					ijforup[1] = j;
				}
				else {
					if (f == 0)continue;
					if (arr[i][j] > max&& arr[i][j] < 0) {

						max = arr[i][j];
						ijforup[0] = i;
						ijforup[1] = j;
					}

				}
			}
		}

	}
	maxnegativeshow(f, max);
}

void rightside(int n, int** arr, int ijforright[2], int& min, bool& p) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if ((i<j && i>n - 1 - j)) {

				if (p == 0 && arr[i][j] > 0) {

					min = arr[i][j];
					p = 1;
					ijforright[0] = i;
					ijforright[1] = j;
				}
				else {
					if (p == 0)continue;
					if (arr[i][j] < min && arr[i][j] > 0) {

						min = arr[i][j];
						ijforright[0] = i;
						ijforright[1] = j;
					}

				}
			}
		}

	}
	minpositiveshow(p, min);
}

void minpositiveshow(bool p, int min) {
	if (p == 0) {
		std::cout << "No positive elements in the hatched field\n";
	}
	else {
		std::cout << "Min positive element is the hatched field is " << min << "\n";
	}
}

void maxnegativeshow(bool f, int max) {
	if (f == 0) {
		std::cout << "No negative elements in the hatched field\n";
	}
	else {
		std::cout << "Max negative element in the hatched field is " << max << "\n";
	}

}

