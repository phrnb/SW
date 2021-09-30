// z4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	bool f = false;
	short s = 0;
	int firstMatch = -1;
	int holeWidth = 0, holeHeigths = 0;
	int paralLength = 0, paralWidth = 0, paralHeigths = 0;
	while (true)
	{
		if (s == 0)
		{
			cout << "Введите высоту отверстия: ";
			cin >> holeWidth;
			if (cin.fail() || holeWidth < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка: повторите ввод";
				continue;
			}
			s = 1;
		}
		if (s== 1)
		{
			cout << "Введите ширину отверстия: ";
			cin >> holeHeigths;
			if (cin.fail() || holeHeigths < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка: повторите ввод";
				continue;
			}
		}
		break;
	}
	s = 0;
	while (true)
	{
		if (s == 0)
		{
			cout << "Введите длину параллелепипеда: ";
			cin >> paralLength;
			if (cin.fail() || paralLength < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка: повторите ввод";
				continue;
			}
			s = 1;
		}
		if (s == 1)
		{
			cout << "Введите ширину параллелепипеда: ";
			cin >> paralWidth;
			if (cin.fail() || paralWidth < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка: повторите ввод";
				continue;
			}
			s = 2;
		}
		if (s == 2)
		{
			cout << "Введите высоту параллелепипеда: ";
			cin >> paralHeigths;
			if (cin.fail() || paralHeigths < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка: повторите ввод";
				continue;
			}
		}
		break;
	}
	int mass[] = { paralHeigths, paralLength, paralWidth };
	for (int i = 0; i < 3; i++)
	{
		if (mass[i] <= holeHeigths && !f)
		{
			firstMatch = mass[i];
			i = -1;
			f = true;
			continue;
		}
		if (mass[i] <= holeWidth && mass[i] != firstMatch && f)
		{
			system("cls");
			cout << "Параллелепипед с габаритами (ДхВхШ) " << paralLength << "x" << paralHeigths << "x" << paralWidth << endl;
			cout << "может поместиться в отверстие с габаритами (ВхШ)" << holeHeigths << "x" << holeWidth << endl;;
			system("pause");
			return 0;
		}
	}
	cout << "Параллелепипед с габаритами (ДхВхШ) " << paralLength << "x" << paralHeigths << "x" << paralWidth << endl;
	cout << "не может поместиться в отверстие с габаритами (ВхШ)" << holeHeigths << "x" << holeWidth << endl;
	system("pause");
	return 0;
}

