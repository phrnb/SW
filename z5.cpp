// z5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	long long howMuchTry = 0;
	char* password = new char[4];
	char* key = new char[4];
	short stage = 0;
	short number = 0;
	for (int i = 0; i < 4; i++)
	{
		number = rand() % (122 - 48 + 1) + 48;
		while (number >= 58 && number <= 62 || number >= 91 && number <= 96)
			number = rand() % (122 - 48 + 1) + 48;
		*(password + i) = (char)number;
	}
	*(password + 4) = '\0';
	*(key + 4) = '\0';
	system("cls");
	cout << "[выполняется подбор]" << endl;
	while (true)
	{
		number = rand() % (122 - 48 + 1) + 48;
		while (number >= 58 && number <= 62 || number >= 91 && number <= 96)
			number = rand() % (122 - 48 + 1) + 48;
		*(key + stage) = (char)number;
		if (*(password + stage) != *(key + stage))
		{
			howMuchTry++;
			continue;
		}
		else if (*(password + stage) == *(key + stage))
			stage++;
		if (stage == 4)
			break;
	}
	system("cls");
	cout << "Пароль угаданный программой: " << key << endl;
	cout << "Пароль созданный программой: " << password << endl;
	cout << "Количество попыток программы: " << howMuchTry << endl;
	return 0;
}
