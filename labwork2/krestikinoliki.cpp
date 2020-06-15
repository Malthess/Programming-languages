#include <ctime>
#include <iostream>
#include <windows.h>
#include <string>
#include "stdio.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int** m;
	char** a, ** c;
	int* z, * f;
	int rows, cols;//строки, столбцы

	rows = cols = 3;//строки = столбцы
	printf("Игра в %dx%d:", rows, cols);
	HANDLE line = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(line, FOREGROUND_RED);
	cout << "\n-----------------------------------------------------------------------\n";
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

	m = new int* [rows];//Создаём динамический массив указателей размером количества СТРОК
	a = new char* [rows];
	c = new char* [rows];
	z = new int[9];
	f = new int[9];


	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[cols];//Присваиваем элементам указателей новые динамические массивы размером количества СТОЛБЦОВ
	}

	int n = 0;//Позиция
	for (int i = 0; i < rows; i++)//Заполняем двумерный динамический массив числами
	{
		for (int j = 0; j < cols; j++)
		{
			m[i][j] = ++n;//Ограничиваем значение до 10
		}
	}

	/////////////////////////////// CHAR a /////////////////////////////
	for (int i = 0; i < rows; i++)
	{
		a[i] = new char[cols];//Присваиваем элементам указателей новые динамические массивы размером количества СТОЛБЦОВ
	}

	for (int i = 0; i < rows; i++)//Заполняем двумерный динамический массив
	{
		for (int j = 0; j < cols; j++)
		{
			a[i][j] = '*';
		}
	}
	//////////////////////////////// CHAR c ////////////////////////////
	for (int i = 0; i < rows; i++)
	{
		c[i] = new char[cols];//Присваиваем элементам указателей новые динамические массивы размером количества СТОЛБЦОВ
	}

	for (int i = 0; i < rows; i++)//Заполняем двумерный динамический массив
	{
		for (int j = 0; j < cols; j++)
		{
			c[i][j] = '*';
		}
	}

	////////////////////////// INT z ///////////////////////////////////

	////////////////////////////////////////////////////////////////////

	for (int i = 0; i < rows; i++)//Выводим на экран двумерный динамический массив
	{
		for (int j = 0; j < cols; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl << endl << endl;
	}

	//////////////////////////// ИНТЕРАКТИВ /////////////////////////////////
	string name;
	cout << "Введите имя[можно использовать только буквы латинского алфавита и символы]: ";
	cin >> name;
	cout << "Ваше имя: " << name;
	name = "[" + name + "]";

	bool game;
	int h;//Номер хода
	string p2;
	p2 = "[КОМПЬЮТЕР]: ";
	game = true;
	h = 2;
	int position;
	int there2;
	int countPL1 = 0;
	int countPL2 = 0;

	Sleep(2000);
	system("CLS");
	SetConsoleTextAttribute(line, FOREGROUND_RED);
	cout << "-----------------------------------------------------------------------\n";
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "Ход: " << 1 << endl;
	SetConsoleTextAttribute(line, FOREGROUND_GREEN);
	cout << name << endl << endl;
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "Выберите позицию[1 - 9]: ";
	cin >> position;

	if (position < 1 || position > 9)//Проверка не выходит ли введённое число за границы [1, 9]
	{
		while (position < 1 || position > 9)
		{
			cout << "Выберите позицию от 1 до 9: ";
			cin >> position;
			cout << endl;
		}
	}

	int there;
	for (int i = 0; i < rows; i++)//1 ход игрока
	{
		for (int j = 0; j < cols; j++)
		{
			if (position == m[i][j])
			{
				a[i][j] = 'X';
				there = position;//Запоминаем позицию крестика
				countPL1++;//Считаем количество ходов игрока
				SetConsoleTextAttribute(line, FOREGROUND_GREEN);
				cout << a[i][j] << "\t";
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else cout << c[i][j] << "\t";
			c[i][j] = a[i][j];

		}
		cout << endl << endl << endl;
	}
	SetConsoleTextAttribute(line, FOREGROUND_RED);
	cout << "-----------------------------------------------------------------------\n";
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

	for (int i = 0; i < 9; i++)//Запоминаем позиции крестика
	{
		if ((i + 1) == there) z[i] = there;
	}

	///////////////////////////////// ИГРОВАЯ ЛОГИКА /////////////////////////////////////////
	while (game == true)
	{
		SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		cout << "\nХод: " << h << endl;

		if (h % 2 != 0)//Ход игрока
		{
			SetConsoleTextAttribute(line, FOREGROUND_GREEN);
			cout << name << endl << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "Выберите позицию[1 - 9]: ";
			cin >> position;

			for (int i = 0; i < 9; i++)//Проверяем введённую позицию на наличие свободного места и на границы
			{
				if (position < 1 || position > 9 || position == z[i] || position == f[i])
				{
					while (position < 1 || position > 9 || position == z[i] || position == f[i])
					{
						SetConsoleTextAttribute(line, FOREGROUND_RED);
						cout << "Это место занято или находится за пределами отрезка [1, 9]." << endl;
						cout << "Выберите новое место: ";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
						cin >> position;
						i = position - 1;//Приравниваем индекс к значению элемента массива. Например, i = 3, то m[i-1] = 3. Т.к. 1й элемент = 0.  
					}
				}
			}

			for (int i = 0; i < rows; i++)//Размещаем крестик
			{
				for (int j = 0; j < cols; j++)
				{
					if (position == m[i][j])
					{
						a[i][j] = 'X';
						there = position;//Запоминаем позицию крестика
						countPL1++;
						SetConsoleTextAttribute(line, FOREGROUND_GREEN);
						cout << a[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					}
					else if (c[i][j] == 'X')
					{
						SetConsoleTextAttribute(line, FOREGROUND_GREEN);
						cout << c[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					}
					else if (c[i][j] == 'O')
					{
						SetConsoleTextAttribute(line, FOREGROUND_BLUE);
						cout << c[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					}
					else cout << c[i][j] << "\t";
					c[i][j] = a[i][j];
				}
				cout << endl << endl << endl;
			}

			SetConsoleTextAttribute(line, FOREGROUND_RED);
			cout << "-----------------------------------------------------------------------\n";
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

			for (int i = 0; i < 9; i++)//Запоминаем позиции крестика
			{
				if ((i + 1) == there) z[i] = there;
			}

			SetConsoleTextAttribute(line, FOREGROUND_GREEN);
			if (a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X')//Левая граница поля
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X')//Верхняя граница поля
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X')//Правая граница поля
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X')//Нижняя граница поля
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X')//Вертикаль
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X')//Горизонталь
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')//Нисходящая диагональ
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			else if (a[2][0] == 'X' && a[1][1] == 'X' && a[0][2] == 'X')//Восходящая диагональ
			{
				cout << "ПОБЕДА " << name << "!" << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}


			int star = 0;
			for (int i = 0; i < rows; i++)//Проверка на наличие свободного места
			{
				for (int j = 0; j < cols; j++)
				{
					if (a[i][j] != '*') star++;
				}
			}

			if (star == 9)
			{
				SetConsoleTextAttribute(line, FOREGROUND_RED);
				cout << "Не осталось свободного места! " << endl;
				SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}

		}

		////////////////////////////// ИИ //////////////////////////////////////////////////   

		bool flag = false;
		if (h % 2 == 0)//Ход ИИ
		{
			SetConsoleTextAttribute(line, FOREGROUND_BLUE);
			cout << p2 << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (a[i][j] != 'X' && a[i][j] != 'O' && flag == false)
					{
						a[i][j] = 'O';
						there2 = m[i][j];//Запоминаем позицию нолика
						countPL2++;//Считаем количество ходов ИИ
						SetConsoleTextAttribute(line, FOREGROUND_BLUE);
						cout << a[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
						flag = true;//Оператор if выполняется один раз
					}
					else if (c[i][j] == 'X')
					{
						SetConsoleTextAttribute(line, FOREGROUND_GREEN);
						cout << c[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					}
					else if (c[i][j] == 'O')
					{
						SetConsoleTextAttribute(line, FOREGROUND_BLUE);
						cout << c[i][j] << "\t";
						SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					}
					else cout << c[i][j] << "\t";
					c[i][j] = a[i][j];
				}
				cout << endl << endl << endl;
			}

			SetConsoleTextAttribute(line, FOREGROUND_RED);
			cout << "-----------------------------------------------------------------------\n";
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

			for (int i = 0; i < 9; i++)//Запоминаем позиции нолика
			{
				if ((i + 1) == there2) f[i] = there2;
			}
		}

		SetConsoleTextAttribute(line, FOREGROUND_BLUE);
		if (a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O')//Левая граница поля
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O')//Верхняя граница поля
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O')//Правая граница поля
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O')//Нижняя граница поля
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O')//Вертикаль
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O')//Горизонталь
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O')//Нисходящая диагональ
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		else if (a[2][0] == 'O' && a[1][1] == 'O' && a[0][2] == 'O')//Восходящая диагональ
		{
			cout << "ПОБЕДА КОМПЬЮТЕРА!" << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}

		int star = 0;
		for (int i = 0; i < rows; i++)//Проверка на наличие свободного места
		{
			for (int j = 0; j < cols; j++)
			{
				if (a[i][j] != '*') star++;
			}
		}

		if (star == 9)
		{
			SetConsoleTextAttribute(line, FOREGROUND_RED);
			cout << "Не осталось свободного места! " << endl;
			SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			break;
		}
		h++;//Ход + 1
	}

	cout << "Количество ходов: " << h << endl;
	cout << endl;
	SetConsoleTextAttribute(line, FOREGROUND_BLUE);
	cout << "[ИИ]: ";
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << countPL2;
	cout << " | ";
	SetConsoleTextAttribute(line, FOREGROUND_GREEN);
	cout << name;
	SetConsoleTextAttribute(line, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << ": ";
	cout << countPL1 << endl;

	for (int i = 0; i < rows; i++)//Удаление динамических массивов
	{
		delete[] m[i];
	}
	for (int i = 0; i < rows; i++)//Удаление динамических массивов
	{
		delete[] a[i];
	}
	for (int i = 0; i < rows; i++)//Удаление динамических массивов
	{
		delete[] c[i];
	}
	delete[] m;//Удаление *динамического массива с указателями* на *динамические массивы*
	delete[] a;//Удаление *динамического массива с указателями* на *динамические массивы*
	delete[] c;//Удаление *динамического массива с указателями* на *динамические массивы*
	delete[] z;
	delete[] f;
}