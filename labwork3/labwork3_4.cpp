#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>

using namespace std;

int counterSen(char* str2)//Счёт предложений
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (; true; i++)
	{
		if (str2[i] == '\0')
		{
			break;
		}
		if (str2[i] == '.' || str2[i] == '?' || str2[i] == '!') count++;
	}

	return count;
}

int counterWor(char* str2)//Счёт слов 
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (; true; i++)
	{
		if (str2[i] == '\0')
		{
			count++;
			break;
		}
		if (str2[i] == ' ' && str2[i + 1] == ' ') continue; // Если идут два пробела подряд переходим к следующему элементу
		if (str2[i] == ' ' || str2[i] == '\n') count++;
	}

	return count;
}

void main()
{
	setlocale(LC_ALL, "ru");

	char symbol;
	char* str2 = new char[100];

	ifstream text("D:\\text.txt");//Чтение
	if (!text) cout << "Ошибка открытия файла text.txt." << endl;

	int i = 0;
	while (text.get(symbol))
	{
		str2[i] = symbol;
		i++;
	}
	str2[i] = '\0';
	text.close();


	cout << "Количество слов в текстовом файле: " << counterWor(str2) << endl;
	cout << "Количество предложений в текстовом файле: " << counterSen(str2) << endl;

}
