// z3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



   


#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	char n[100];
	int k = 0;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter k: ";
	cin >> k;
	cout << k << " first digits of the number " << n << " : ";
	for (int i = 0; i < k; i++)
	{
		if (n[i] != '\0')
			cout << n[i];
		if (n[i] == '\0' && i != k - 1)
			cout << endl << "All numbers are displayed as k exceeds the number of digits n";
		if (n[i] == '\0')
			break;
	}
	cout << endl;
	system("pause");
	return 0;
}
