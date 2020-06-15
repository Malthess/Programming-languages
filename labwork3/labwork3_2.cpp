#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

int main()

{

	setlocale(LC_ALL, "ru");
	srand(time(0));

	const int size = 255;

	char str[size];

	const char* article[] = { "the", "a", "one" }; // 3
	const char* noun[] = { "boy", "girl", "dog", "cat", "hamster" }; // 5
	const char* noun1[] = { "street", "house", "city", "village" }; // 4
	const char* verb[] = { "runs", "jumps", "eats", "walks", "sleeps" }; // 5
	const char* preposition[] = { "to", "from", "over", "under", "on", "at" }; // 6

	for (int i = 0; i < 5; i++)

	{

		sprintf(str, "%s %s %s %s %s %s%c", article[rand() % 3], noun[rand() % 5], verb[rand() % 5], preposition[rand() % 6], article[rand() % 3], noun1[rand() % 4], '.');
		str[0] = toupper(str[0]); //Заглавная буква
		cout << str << endl;

	}

	return 0;

}