// no gurls.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

void filewrite(); //функция создаёт текстовый файл и записывает туда рандомные элементы формата int
void fileread(int* p_darr, int& t, int& c); //считывает элементы из созданного filewrite() документа и записывает в массив p_darr все нечётные
void checkif(int& c); //проверяет сколько всего элементов в текстовом файле
void sorte(int* p_darr, int left, int right); //сортирует массив p_darr по возрастанию
void checkif1(int& t, int& c); //проверяет количество нечётных чисел

int main()
{
	setlocale(LC_ALL, "Russian");
	int t = 0, c = 0; //c = return from checkif(), t = return from checkif1()
	filewrite(); //вызов функции для записи рандомных элементов в текстовый файл
	checkif(c);//вызов функции для подсчёта количества элементов в файле
	checkif1(t, c);
	int* p_darr = new int[t];
	fileread(p_darr, t, c);
	sorte(p_darr, 0, t - 1);
	for (int i = 0; i < t; i++)cout << "p_darr[" << i << "]= " << p_darr[i] << "\n";
	delete[] p_darr;
	return 0;
}

void filewrite()
{
	ofstream F;          // поток для записи
	F.open("D:\\hello.txt", ios::out); // окрываем файл для записи
	if (F.is_open())
	{
		srand((unsigned)time(0));
		for (int i = 0; i <= 10000; i++) {
			F << (rand() % 10000) + 1 << "\n";
		}
	}
	F.close();
}

void checkif(int& c)
{
	int value;
	ifstream F;          // поток для чтения
	F.open("D:\\hello.txt", ios::in); // окрываем файл для чтения
	if (F.is_open())
	{
		F >> value;
		while (!F.eof()) //проверяем, достигнут ли конец файла
		{
			F >> value; //считываем значение из файла просто чтобы !F.eof() работала правильно
			c++;
			//cout << "value=" << value;
		}
		cout << "c=" << c << "\n";
	}
	F.close();
}

void checkif1(int& t, int& c)
{
	int value;
	ifstream F;          // поток для чтения
	F.open("D:\\hello.txt", ios::in); // окрываем файл для чтения
	if (F.is_open())
	{
		for (int i = 0; i <= c; i++)
		{
			F >> value;
			if (value % 2 != 0 and value != 0)t++;
		}
		cout << "t=" << t << "\n";
	}
	F.close();
}

void fileread(int* p_darr, int& t, int& c)
{
	int value1;
	ifstream F;          // поток для чтения
	F.open("D:\\hello.txt", ios::in); // окрываем файл для чтения
	if (F.is_open())
	{
		ofstream F1;
		F1.open("D:\\hello1.txt", ios::out);
		if (F1.is_open())
		{
			for (int i = 0; i <= c; i++)
			{
				F >> value1;
				if (value1 % 2 != 0 and value1 != 0) F1 << value1 << "\n";
				//cout << "p_darr[" << i << "]=" << p_darr[i] << "\n";
			}
		}
		F1.close();
		ifstream F2;
		F2.open("D:\\hello1.txt", ios::in);
		if (F2.is_open())
		{
			for (int i = 0; i < t; i++)
			{
				F2 >> p_darr[i];
				//cout << "p_darr[" << i << "]= " << p_darr[i] << "\n";
			}
		}
		F2.close();
	}
	F.close();
}

void sorte(int* p_darr, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = p_darr[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((p_darr[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			p_darr[left] = p_darr[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо 
		}
		while ((p_darr[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			p_darr[right] = p_darr[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо 
		}
	}
	p_darr[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		sorte(p_darr, left, pivot - 1);
	if (right > pivot)
		sorte(p_darr, pivot + 1, right);
}