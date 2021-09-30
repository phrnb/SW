// z2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	short day = 0;
	cout << "Enter the day of the week: ";
	cin >> day;
	if (day > 7 || day < 1)
		cout << "enter the week number" << endl;
	if (day == 1)
		cout << "number " << day << " is  monday" << endl;
	if (day == 2)
		cout << "number " << day << " is tuesday" << endl;
	if (day == 3)
		cout << "number " << day << " is wednesday" << endl;
	if (day == 4)
		cout << "number " << day << " is thursday" << endl;
	if (day == 5)
		cout << "number " << day << " is friday" << endl;
	if (day == 6)
		cout << "number " << day << " is saturday" << endl;
	if (day == 7)
		cout << "number " << day << "is sunday" << endl;
	system("pause");
	return 0;
}