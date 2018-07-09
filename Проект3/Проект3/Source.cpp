///***************************************************************************************
//**Project Name : 2slab1                                                               **
//**Project Type : Win32 Console Application                                            **
//**File Name    : 2slab1.cpp                                                           **
//**Language     : CPP MSVS 2013                                                        **
//**Programmers  : Chechuga Mihail, Kovalenko Bogdan,M30-124bk,5 brigade                ** 
//**Created      : 05/03/18                                                             **
//**Last revision: 05/03/18                                                             **
//**Comment      : character data                                                       **
//****************************************************************************************/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;
const char *FNAME = "file.h";//declay file
int main() {
	int NMAX = 5;
	int N;
	int i = 0;
	string Min = "a";
	string *str = new string[NMAX];
	/*str[0] = "mama";
	str[1] = "billy";
	str[2] = "forbid";
	str[3] = "bo";
	str[4] = "mo";*/

	ifstream fin(FNAME);//открытие файла дл€ чтени€
	if (!fin)//проверка имени файла
	{
		cout << "File " << FNAME << " not found\n";//им€ файла указано некорректно
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	fin >> N;//¬вод числа элементов в программу из файла
	if (fin.eof())//проверка на наличие данных в файле
	{
		cout << "File " << FNAME << " is empry\n";//сообщение о пустом файле
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	if (fin.fail())//ѕроверка не некорректные типы данных в файле
	{
		cout << "Error. Reading file " << FNAME << " failure\n";//в файле есть посторонние типы данных
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	//Ёхо печать
	cout << "N= " << N << "\tfin.eof() = " << fin.eof() << endl;
	if (fin.good())//если преп€тствий не обнаружено 
	{
		cout << "Vector reading\n";//чтение данных
		for (i = 0; i < N; i++)
		{
			fin >> str[i];//ввод данных в программу из файла
			cout << " i= " << i << "\tArray = " << str[i] << endl;//печать элементов массива и его индекса

		}
	}
	fin.close();//закрытие файла
	cout << "File was succesfully read" << endl;
	for (i = 0; i < NMAX; i++) {
		if (str[i].length()> Min.length())
		{
			Min = str[i];
		}
	}
	cout << "The longest word: " << Min << "  " << Min.length() << endl;//с ним мы будем сравнивать

	for (i = 0; i < NMAX; i++) {
		if (str[i].length()< Min.length())
		{
			Min = str[i];
		}
	}
	cout << "The shortest word: " << Min << "  " << Min.length() << endl;

	for (i = 0; i < NMAX; i++) {
		if (str[i].length() == Min.length()) {
			cout << str[i] << "   ";
		}
	}

	system("PAUSE");
	return 0;
}