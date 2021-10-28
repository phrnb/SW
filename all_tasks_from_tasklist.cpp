
#include <iomanip>
#include<iostream>
#include<math.h>
#include<string>
#include<conio.h>
#include <time.h>
using namespace std;
int InputArrayElements(int*, int);
void OutputArrayElements(int*, int);
int FirstElementNumber(int, int*, int);
void DifferenceOfTwoNumbers(int*, int );
void LongestSequenceLength(int* , int );
void InputMatrix(int*&, int , int );
void OutputMatrix(int*, int, int );
void TranspositionRelativeToTheMain(int* , int , int);
void TranspositionRelativeToTheCollateral(int*, int, int);
void FindMaximumBetweenTwoDots(int**, int);
void FindMyStringInMainString(string& mainString, string& key);

int main()
{
    system("chcp 1251");
    system("cls");
    int arrSize = 0;
    cout << "Введите размер массива: ";
    cin >> arrSize;
    int* arr = new int[arrSize];
    InputArrayElements(arr, arrSize);
    OutputArrayElements(arr, arrSize);
    //FirstTask
    cout << "Введите любой элемент массива : " << endl;
    int keyInt;
    cin >> keyInt;
    FirstElementNumber(keyInt, arr, arrSize);
    cout << endl << endl;
    //SecondTask
    DifferenceOfTwoNumbers(arr, arrSize);
    cout << endl << endl;
    //ThirdTask
    LongestSequenceLength(arr, arrSize);
    cout << endl << endl;
    //FourthTask
    int rowFirst = 0;
    int columnFirst = 0;
    int* matrixFirst = nullptr;
    cout << "Введите количество строк для первой матрицы: ";
    cin >> rowFirst;
    cout << "Введите количество солбцов для первой матрицы: ";
    cin >> columnFirst;
    InputMatrix(matrixFirst, rowFirst, columnFirst);
    OutputMatrix(matrixFirst, rowFirst, columnFirst);
    cout << endl;
    TranspositionRelativeToTheMain(matrixFirst, rowFirst, columnFirst);
    TranspositionRelativeToTheCollateral(matrixFirst, rowFirst, columnFirst);
    cout << endl << endl;
    //FifthTask
    srand(time_t(NULL));
    int** arrayInt = nullptr;
    int column = 0;
    arrayInt = new int* [2];
    cout << "Введите количество координат (генерируются рандомно): ";
    cin >> column;
    for (int i = 0; i < 2; i++) {
        arrayInt[i] = new int[column];
        for (int j = 0; j < column; j++) {
            arrayInt[i][j] = rand() % (20 + 20 + 1) - 20;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0)
                cout << "X[" << j + 1 << "]: {" << setw(3) << arrayInt[i][j] << "} ";
            else
                cout << "Y[" << j + 1 << "]: {" << setw(3) << arrayInt[i][j] << "} ";
        }
        cout << endl;
    }
    FindMaximumBetweenTwoDots(arrayInt, column);
    //AdditionalTask
    string mainString = "";
    string key = "";
    cout << "Введите основную строку: ";
    getline(cin, mainString,';');
    mainString.erase(0, 1);
    cout << "Введите подстроку: ";
    getline(cin, key, ';');
    key .erase(0, 1);
    FindMyStringInMainString(mainString, key);
    mainString.clear();
    key.clear();

    delete[]arr;
    delete[]matrixFirst;
    
    for (int i = 0; i < 2; i++)
    {
        delete[] arrayInt[i];
    }
    delete[]arrayInt;
    
    return 0;

}


int InputArrayElements(int* ourArray, int arraySize)
{
srand(time_t(NULL));
for (int i = 0; i < arraySize; i++) 
    {
        ourArray[i] = rand() % (20 - (-20) + 1) + (-20);
    }
return * ourArray;
}

void OutputArrayElements(int* ourArray, int arraySize)
{
    cout << "Массив с размером в " << arraySize << " элементов :" << endl << endl;
    for (int i = 0; i < arraySize; i++) 
    {
        cout << "[" << ourArray[i] << "]";
        
    }
    cout << endl << endl;
}
 int FirstElementNumber(int key, int* ourArray, int arraySize)
{
    cout << "Номер первого элемента ["<< key <<"]:";
    bool flag = true;
    for (int i = 0; i < arraySize; i++)
    {   
        if (ourArray[i] == key)
        {
            cout  << i + 1 << endl << endl;
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        cout << "такого элемента нет" << endl;
    }
    
    return key;
}
 void FindMyStringInMainString(string& mainString, string& key) 
 {
     int count = 0;
     bool findFirstLetter = false;
     for (int i = 0; i < mainString.length(); i++)
     {
         if (findFirstLetter && mainString[i] != key[count]) 
         {
             findFirstLetter = false;
             count = 0;
         }
         if (findFirstLetter && mainString[i] == key[count])
         {
             count++;
         }
         if (count == key.length()) 
         {
             cout << "Подстрока " << key << " была найдена на " << i - count + 1 << " позиции" << endl;
             return;
         }
         if (!findFirstLetter && mainString[i] == key[0]) 
         {
             findFirstLetter = true;
             count++;
         }
     }
     cout << "Подстрока " << key << " не была найдена" << endl;
 }

 void DifferenceOfTwoNumbers(int* ourArray, int arraySize)
 {
     cout << "Числа меньшие разности двух предыдущих :  ";
     for (int i = 2; i < arraySize; i++)
     {
         if (ourArray[i] < (ourArray[i - 2] - ourArray[i - 1]))
         {
             
             cout << ourArray[i]<< "\t";
         }
     }
     cout << endl << endl;
 }
 void LongestSequenceLength(int* ourArray, int arraySize)
 {

     int i = 0;
     int k = 0;
     int maxValue  = 0;
     int numberOfOrder; 
     int m ;
     while (i < arraySize)
     {
         int j = 0;
         m = ourArray[i];
         while (ourArray[i] == m && i < arraySize)
         {
             j++;
             i++;
         }
         if (j >= maxValue)
             if (j > maxValue)
             {
                 maxValue = j;
                 numberOfOrder = m;
             }
             else  k = j;
     }
     if (maxValue != k)
         cout << "\nКоличество чисел в наиболее длинной последовательности, состоящей из  "<< numberOfOrder<< " = " << maxValue;
     else
         cout << "\nНайдено несколько равных по длине последовательностей состоящих из "<< maxValue<<" одинаковых элементов";

     cout << endl;
 }
 void InputMatrix(int *& matrixFirst, int rowFirst, int columnFirst)
 {
     matrixFirst = new int[rowFirst * columnFirst];
     for (int i = 0; i < rowFirst; i++)
     {
         for (int j = 0; j < columnFirst; j++)
         {
             *(matrixFirst + i * columnFirst + j) = rand() % (20 - (-20) + 1) + (-20);
         }
     }
 }
 void OutputMatrix(int* matrixFirst, int rowFirst, int columnFirst)
 {
     cout << "Первая матрица с размерами " << rowFirst << "x" << columnFirst << endl << endl;
     for (int i = 0; i < rowFirst; i++) {
         for (int j = 0; j < columnFirst; j++) {
             cout << "[" << setw(6) << *(matrixFirst + i * columnFirst + j) << "] ";
         }
         cout << endl << endl;
     }
     cout << endl << endl;
 }
 void TranspositionRelativeToTheMain(int* matrixFirst, int rowFirst, int columnFirst)
 {
     cout << "Транспонированная относительно главной диагонали матрица :" << endl << endl;
     for (int j = 0; j < columnFirst; j++)
     {
         for (int i = 0; i < rowFirst; i++)
         {
             cout << "[" << setw(6)  <<*(matrixFirst+i*columnFirst+j) << "] ";
         }
         cout << endl;
     }
 }
 void TranspositionRelativeToTheCollateral(int* matrixFirst, int rowFirst, int columnFirst)
 {
     cout << "Транспонированная относительно побочной диагонали матрица :" << endl << endl;
     for (int i = 0; i < columnFirst; i++)
     {
         for (int j = 0; j < rowFirst; j++)
         {
             cout << "[" << setw(6) << *(matrixFirst+(rowFirst - 1 - j)* columnFirst+(columnFirst - 1 - i)) << "] ";
         }
         cout << endl;
     }
 }
 void FindMaximumBetweenTwoDots(int** coordinats, int column) {
     double tempResult = 0;
     double bestResult = sqrt(pow(coordinats[0][0] - coordinats[0][1], 2) + pow(coordinats[1][0] - coordinats[1][1], 2));
     int firstX = coordinats[0][0];
     int firstY = coordinats[0][1];
     int secondX = coordinats[1][0];
     int secondY = coordinats[1][1];
     for (int i = 0; i < column - 1; i++) {
         for (int j = i + 1; j < column; j++) {
             tempResult = sqrt(pow(coordinats[0][j] - coordinats[0][i], 2) + pow(coordinats[1][j] - coordinats[1][i], 2));
             if (tempResult > bestResult) {
                 bestResult = tempResult;
                 firstX = coordinats[0][j];
                 secondX = coordinats[0][i];
                 firstY = coordinats[1][j];
                 secondY = coordinats[1][i];
             }
         }
     }
     cout << "Наибольшее расстояние равно " << bestResult << " между точками (" << firstX << ", " << firstY << ") и (" << secondX << ", " << secondY << ")" << endl;
 }
 



      

