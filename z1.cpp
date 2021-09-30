
#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251");
	system("cls");
	int i = 0;
	char number[100];
	cout << "Enter the number: ";
	cin >> number;
	while (number[i] != '\0')
	{
		cout << number[i] << endl;
		i++;
	}
	system("pause");
	return 0;
}










