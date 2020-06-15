#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//Указываем структуру smth(в этот момент под неё ещё не выделяется память)
struct smth {
	//внутри неё будут все нужные нам данные из каждой строки

	float num = 0;

	string name = " ";

	string otch = " ";

	string lastname = " ";

	string nazvanie = " ";

	int stoimost = 0;

};

bool cmpByLastname(const smth& r1, const smth& r2) //Для сортировки по фамилии автора

{

	return r1.lastname < r2.lastname;

}

int main()

{

	setlocale(LC_ALL, "rus"); //Подключаем, чтобы не было иероглифов вместо кириллицы

	string x;

	smth s; /*указываем переменную s типа smth(структура, что создали ранее), в этот раз память выделяется, в неё мы будем
			записывать информацию о книгах, номерах билетов и авторах*/

	ifstream file;

	file.open("D://books.txt"); //путь к файлу

	int len(0); //здесь будет кол-во строк из файла

	//Проверяем, открыт ли файл
	if (file.is_open())
	{
		//Здесь проверяем длину файла в строках с помощью .eof(пока не дошли до конца файла)
		while (!file.eof())
		{

			string s;
			//верхняя и нижняя строчка нужны для нормальной работы .eof, каждую итерацию перезаписываем s
			getline(file, s);

			len++;

		}

	}
	else
	{
		cout << "Возникла проблема с открытием файла";
		return 1;
	}

	smth* arr = new smth[len]; //задаём массив типа smth(чтобы хранить всю информацию из каждой строки файла) с размером len

	file.seekg(0, ios_base::beg); //перемещаем указатель get pointer в начало файла с помощью функции seekg

	for (size_t i = 0; i < len; i++) //size_t - беззнаковое целое, так удобнее.

	{

		getline(file, x); //строку из файла запихиваем в переменную x

		istringstream iss(x); /*задаём переменную через класс istringstream(дочерний от istream), чтобы разбить строку x на
							  несколько переменных и поместить внутрь структуры s(через пробелы)*/

		iss >> s.num >> s.name >> s.otch >> s.lastname >> s.nazvanie >> s.stoimost;

		//выше мы распределили в переменную s типа smth все нужные значения из строки по необходимым местам
		arr[i] = s; //здесь мы запишем значения из s, чтобы сохранить их, так как s обновится на следующей итерации

	}

	cout << "Информация обо всех взятых книгах: \n" << endl;

	//Вывод информации обо всех книгах(первое задание)
	for (size_t n = 0; n < len; n++)

	{

		cout << "Номер билета : " << arr[n].num << "  "

			<< "Имя : " << arr[n].name << "  "

			<< "Отчество : " << arr[n].otch << "  "

			<< "Фамилия : " << arr[n].lastname << "  "

			<< "Название : " << arr[n].nazvanie << "  "

			<< "Стоимость : " << arr[n].stoimost << endl;

	}

	cout << "\nИнформация о книгах автора Набокова :\n" << endl;
	//из строки выше понятно, что тут выведутся только книги Набокова(второе задание)
	for (size_t n = 0; n < len; n++)

	{
		//пробежимся по массиву и найдём совпадение фамилии со строкой "Nabokov", если совпало, то выведем
		if (arr[n].lastname == "Nabokov")

		{

			cout << "Номер билета : " << arr[n].num << "  "

				<< "Имя : " << arr[n].name << "  "

				<< "Отчество : " << arr[n].otch << "  "

				<< "Фамилия : " << arr[n].lastname << "  "

				<< "Название : " << arr[n].nazvanie << "  "

				<< "Стоимость : " << arr[n].stoimost << endl;

		}

	}

	cout << "\nИнформация о книгах, стоимостью более 1500, но менее 3000: \n" << endl;
	//(третье задание, стоимость от 1500 до 3000)

	sort(arr, arr + len, cmpByLastname); //сортируем по фамилии автора

	for (size_t n = 0; n < len; n++)

	{

		if (arr[n].stoimost > 1500 and arr[n].stoimost < 3000)

		{

			cout << "Номер билета : " << arr[n].num << "  "

				<< "Имя : " << arr[n].name << "  "

				<< "Отчество : " << arr[n].otch << "  "

				<< "Фамилия : " << arr[n].lastname << "  "

				<< "Название : " << arr[n].nazvanie << "  "

				<< "Стоимость : " << arr[n].stoimost << endl;

		}

	}

	file.close(); //закрываем файл перед завершением работы
	delete[]arr; //очищаем память
	return 0;

}
