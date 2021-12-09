#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct fileStruct
{
	string word;
	int num = 0;
	double average = 0;
	int index = 0;
};

fileStruct* readFile(string Name, int& size);

void numberOflines();
void printTaskInNewFile(string Name, fileStruct* files, int size, int openMode);
fileStruct* resizeArray(int& firstFileSize, int newFileSize, fileStruct* files);
void sort(string Name, fileStruct* files, int size, int openMode);

int main()
{

	int size = 1;
	setlocale(LC_ALL, "rus");
	fileStruct* files = readFile("txtDocument.txt", size);
	printTaskInNewFile("txtDocument2.txt", files, size, ios_base::app);

	fstream file("txtDocument.txt");
	int size_of_file = 0;
	file.seekg(0, ios::end);
	size_of_file = file.tellg();
	cout << "New file is " << size_of_file << " bytes" << endl;
	file.close();
	numberOflines();
	sort("txtDocument2.txt", files, size, ios_base::app);
	printTaskInNewFile("txtDocument2.txt", files, size, ios_base::app);
	cout << "The end..." << endl;
	system("pause");

	return 0;
}

void numberOflines()
{
	char* str = new char[1024];
	int i = 0;
	ifstream exam("txtDocument.txt");
	while (!exam.eof())
	{
		exam.getline(str, 1024, '\n');
		i++;
	}
	exam.close();
	delete str;
}

fileStruct* readFile(string Name, int& size)
{
	ifstream file(Name);
	if (!file.is_open())
	{
		return nullptr;
	}
	size <= 0 ? size = 10 : size = size;
	fileStruct* files = new fileStruct[size];
	int numberOfLines = 0;
	while (!file.eof())
	{
		if (numberOfLines == size)
		{
			files = resizeArray(size, size + 1, files);
		}
		file >> files[numberOfLines].word;
		file >> files[numberOfLines].num;
		file >> files[numberOfLines].average;
		file >> files[numberOfLines].index;
		numberOfLines++;
	}
	files = resizeArray(size, numberOfLines - 1, files);
	file.close();
	return files;
}

fileStruct* resizeArray(int& firstFileSize, int newFileSize, fileStruct* files)
{
	if (firstFileSize == newFileSize)
	{
		return files;
	}
	fileStruct* newArray = new fileStruct[newFileSize];
	firstFileSize = newFileSize < firstFileSize ? newFileSize : firstFileSize;
	for (int i = 0; i < firstFileSize; i++)
	{
		newArray[i] = files[i];
	}
	firstFileSize = newFileSize;
	delete[] files;
	return newArray;
}

void printTaskInNewFile(string Name, fileStruct* files, int size, int openMode)
{
	ofstream file(Name, openMode);
	if (!file.is_open()) {
		return;
	}
	else {
		cout << "file is open  " << endl;
		for (int i = size - 1; i >= 0; i--) {
			file
				<< files[i].word << " "
				<< files[i].num << " "
				<< files[i].average << " "
				<< files[i].index << endl;
		}
		file.close();
		cout << "task is done " << endl;
	}
}

void sort(string Name, fileStruct* files, int size, int openMode)
{
	ofstream file(Name, openMode);
	if (!file.is_open()) {
		return;
	}
	else
	{
		cout << "File is open  " << endl;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (files[j].num > files[j + 1].num)
			{
				fileStruct temp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = temp;

			}
		}
	}
	file << "Sorted array" << endl;
	file.close();
}























