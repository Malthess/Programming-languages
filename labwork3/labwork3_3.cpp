#include <iostream>
#include <stdio.h>
#include <cctype>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

void SpaceCleaner(char* str1) // Убираем все пробелы в строке
{
	int j = 0;
	for (int i = 0; true; i++, j++)
	{
		while (str1[j] == ' ' || str1[j] == '-' || str1[j] == '.' || str1[j] == '?' || str1[j] == '!') j++;

		str1[i] = str1[j];

		if (str1[j] == '\0') break;
	}
}

bool palindrom(char* str1, int f) // Проверка на палиндром
{
	bool t;

	for (int i = 0; true; i++, f--)
	{

		if (str1[i] != str1[f])
		{
			t = false;
			return t;
		}

		if (i == (strlen(str1) - 1) / 2)
		{
			t = true;
			return t;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	char* str1 = new char[100];

	cout << "Введите строку: "; fgets(str1, '100', stdin);
	cout << str1 << endl;

	for (int i = 0; true; i++) // Переводим в нижний регистр
	{
		if (str1[i] == '\0') break;
		str1[i] = tolower(str1[i]);
	}
	SpaceCleaner(str1); // Убираем все пробелы в строке

	int f = strlen(str1) - 2;
	bool t = palindrom(str1, f);

	if (t == true) cout << "Палиндром" << endl;
	else cout << "Не палиндром" << endl;

	//cout << str1 << endl;

	delete[] str1;

	return 0;
}
