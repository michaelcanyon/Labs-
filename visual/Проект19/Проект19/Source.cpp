/*****************************************************************************************
**Project Name : lab2                                                                   **
**Project Type : Win32 Console Application                                              **
**File Name    : lab2.cpp                                                               **
**Language     : CPP MSVS 2013                                                          **
**Programmers  : Chechuga Mihail, Kovalenko Bogdan,M30-124bk,5 brigade                  **
**Created      : 14/10/17                                                               **
**Last revision: 07/12/17                                                               **
**Comment      : tabulation function                                                    **
******************************************************************************************/

#include<iostream>
#include <fstream>
#include <conio.h>
using namespace std;
const char *FNAME = "Array1.h";//объявление файла
int main()
{
	int N;//объявление переменной, обозначающей число элементов в массиве
	int i = 0;//индекс элемента
	int firstP;//первый положительный элемент
	int ifirstP = -1;//его индекс
	int lastP;//последний положительный элемент 
	int ilastP = -1;//его индекс
	int const NMAX = 6;//размерность массива
	int Array[NMAX];//массив
	ifstream fin(FNAME);//открытие файла для чтения
	if (!fin)//проверка имени файла
	{
		cout << "File " << FNAME << " not found\n";//имя файла указано некорректно
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	fin >> N;//Ввод числа элементов в программу из файла
	if (fin.eof())//проверка на наличие данных в файле
	{
		cout << "File " << FNAME << " is empry\n";//сообщение о пустом файле
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	if (fin.fail())//Проверка не некорректные типы данных в файле
	{
		cout << "Error. Reading file " << FNAME << " failure\n";//в файле есть посторонние типы данных
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	//Эхо печать
	cout << "N= " << N << "\tfin.eof() = " << fin.eof() << endl;
	if (fin.good())//если препятствий не обнаружено 
	{
		cout << "Vector reading\n";//чтение данных
		for (i = 0; i < N; i++)
		{
			fin >> Array[i];//ввод данных в программу из файла
			cout << " i= " << i << "\tArray = " << Array[i] << endl;//печать элементов массива и его индекса

		}
	}
	fin.close();//закрытие файла
	cout << "File was succesfully read" << endl;//уведомлеение о том, что файл прочитан
												//печать массива
	for (i = 0; i < N; i++)
	{
		cout << " " << Array[i];
	}
	cout << endl;

	/*int const NMAX = 10;
	int Array[NMAX] = { -1, 4,-6,-8,-12,54,-6,-4,-49,-3 };//declared array
	int i;
	int firstP;
	int ifirstP = -1;
	int lastP;
	int ilastP = -1;*/
	/*for (i = 0; i < NMAX; i++)//declarin array elements on our own
	{
	cout << "enter array element ";
	cin >> Array[i];
	}*/
	//Поиск превого положительного элемента
	for (i = 0; i < NMAX; i++)
	{
		if (Array[i] > 0)
		{
			cout << "first positive element is " << Array[i] << endl;
			cout << "index is " << i << endl;
			firstP = Array[i];
			ifirstP = i;
			break;//прерывание цикла, т.к элемент найден
		}
	}

	if (ifirstP == -1)//индекс не изменился, положительных элементов нет
	{
		cout << "An error occured. Array has no positive elements" << endl;
	}
	else
	{
		//Поиск последнего положительного элемента
		for (i = NMAX-1; i >= 0; i--)
		{
			if (Array[i] > 0)
			{
				cout << "last positive element is " << Array[i] << endl;
				cout << "index is " << i << endl;
				lastP = Array[i];
				ilastP = i;
				break;//прерывание цикла, т.к элемент найден
			}
		}
		if (ilastP == ifirstP)//если в массиве только один положительный элемент
		{
			cout << "Error. There is only one positive element" << endl;
		}
		else
		{


			//Рассчёт суммы
			int Summ = 0;
			if (ilastP - ifirstP == 1)//случай - суммы не существует
			{
				cout << "Summ doesn't exist" << endl;
			}
			else
			{
				for (i = ifirstP + 1; i < ilastP; i++)
				{
					Summ += Array[i];

				}
				cout << "Summ equals " << Summ << endl;
			}
		}
	}
	//Поиск наибольшего элемента
	int Max = Array[0];
	int iMax;
	for (i = 0; i < NMAX; i++)
		if (Array[i] >= Max)
		{
			Max = Array[i];
			iMax = i;
		}
	cout << "Maximal element is equals " << Max << endl;
	cout << "index is " << iMax << endl;

	//Поиск наименьшего элемента
	int Min;
	int iMin;
	Min = Array[0];
	for (i = 0; i < NMAX; i++)
		if (Array[i] <= Min)
		{
			Min = Array[i];
			iMin = i;
		}
	cout << "Minimal element is equals " << Min << endl;
	cout << "index is " << iMin << endl;

	//Обмен элемнтов местами
	int temp;
	temp = Array[iMax];
	Array[iMax] = Array[iMin];
	Array[iMin] = temp;
	for (i = 0; i < NMAX; i++)
	{
		cout << Array[i] << "  ";
	}
	cout << endl;


	system("PAUSE");
	return 0;
}