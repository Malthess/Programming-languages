#include <iostream>

#include <stdio.h>

using namespace std;

int lenghtstr(char* str, int i)

{

	if (str[i] == '\0') return i;

	else

		return lenghtstr(str, ++i);

}

int main()

{

	setlocale(LC_ALL, "ru");

	char* str = new char[255];

	int i = 0;

	cout << "Введите строку: "; fgets(str, '\n', stdin);

	cout << str << endl << endl;

	cout << "\t" << lenghtstr(str, i) << endl;

	cout << "Проверка: " << strlen(str) << endl;

	delete[] str;

	return 0;

}