///***************************************************************************************
//**Project Name : 2slab1                                                               **
//**Project Type : Win32 Console Application                                            **
//**File Name    : 2slab1.cpp                                                           **
//**Language     : CPP MSVS 2013                                                        **
//**Programmers  : Chechuga Mihail, Kovalenko Bogdan,M30-124bk,5 brigade                ** 
//**Created      : 05/03/18                                                             **
//**Last revision: 02/04/18                                                             **
//**Comment      : character data                                                       **
//****************************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
using namespace std;
void f1(int i, int b, char str[], int length, int &minlength, int bw, int &ew);
void f2(int i, int b, char str[], int length, int minlength, int bw, int ew);

int main()
{
	//чтение данных из файла
	char str[255];
	string filename;
	cout << "enter full filename ";
	cin >> filename;
	ifstream fin(filename);
	if (!fin)//проверка имени файла
	{
		cout << "Filename is incorrect\n";//им€ файла указано некорректно
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}
	if (fin.is_open())
	{
		if (fin.eof())
			cout << "file is empty";
	}
	if (fin.fail())//ѕроверка не некорректные типы данных в файле
	{
		cout << "Error. Reading file failure\n";//в файле есть посторонние типы данных
		fin.close();//закрытие файла
		system("pause");
		return 1;
	}


	fin.getline(str, 255); 
	fin.close(); 
	/*char str[] = "there is always sunny in Moscow...";*/
	cout << "string: " << str << endl;
	int i = 0;
	int minlength = 255;
	int k = 0, ew = 0, bw = 0, b = 0, length = 1;
	
	f1(i, b, str, length, minlength, bw, ew);
	i = ew;
	f2(i, b, str, length, minlength, bw, ew);

	system("pause");
	return 0;



}
//поиск самого короткого слова
void f1(int i, int b, char str[], int length, int& minlength, int bw, int& ew)
{
	while (str[i] != '\0')//инициализаци€ цикла, считающего символы до '\0'
	{
		b = i;//к - буферна€ переменна€ дл€ оценки длины слова
		while (str[i] != ' '&&i <= 255&& str[i] != '\0')//подсчЄт символов до ' ' или пока не закончитс€ массив данных(в случае, когда после последнего стоит '\0' или остаютс€ невыделенные под текст €чейки)
		{
			i++;
			length = i - b;
		}
		
		if (length < minlength)//обозначение минимального числа и маркировка нужных переменных дл€ печати слова
		{
			minlength = length;
			bw = b;
			ew = i;

		}
		if (str[i] == '\0')
		{
			break;
		}
		i++;
	}
	cout << "first shortest word: ";
	for (b = bw; b != ew; b++)
	{
		cout << str[b];
	}
	cout << endl;
}
//поиск повтор€ющихс€ слов, равных по длине кратчайшему
	void f2(int i, int b, char str[], int length, int minlength, int bw, int ew)
	{
		cout << "Words that have equal length to the shortest one:  " << endl;
		while (str[i] != '\0')//инициализаци€ цикла, считающего символы до '\0'
		{
			
			b = i;//к - буферна€ переменна€ дл€ оценки длины слова
			while (str[i] != ' '&&i <= 255&&str[i] != '\0')//подсчЄт символов до ' ' или пока не закончитс€ массив данных(в случае, когда после последнего стоит '\0' или остаютс€ невыделенные под текст €чейки)
			{
				i++;
				length = i - b;
			}
			
			if (length == minlength)//обозначение минимального числа и маркировка нужных переменных дл€ печати слова
			{
				minlength = length;
				bw = b;
				ew = i;
				for (b = bw; b != ew; b++)
				{
					cout << str[b];
				}
				cout << endl;

			}
			if (str[i] == '\0')
			{
				break;
			}
			i++;
			
		}
		
}