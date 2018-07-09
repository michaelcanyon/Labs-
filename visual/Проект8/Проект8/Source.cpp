/*****************************************************************************************
**Project Name : lab2                                                                   **
**Project Type : Win32 Console Application                                              **
**File Name    : lab2.cpp                                                               **
**Language     : CPP MSVS 2013                                                          **
**Programmers  : Chechuga Mihail, Kovalenko Bogdan,M30-124bk,5 brigade                  **
**Created      : 14/10/17                                                               **
**Last revision: 26/10/17                                                               **
**Comment      : tabulation function                                                    **
******************************************************************************************/
#include<iostream>//включение библиотек
#include<cmath>
#include<iomanip>
using namespace std;//объявление пространства имён
double const pi = 3.1415926535898;
int main()
{
	double A;//точка А
	double B;//точка В
	int N;//количество интервалов N
	double h;//шаг к приращению аргумента
	int i;//точка, в которой считаются значения функции
	double x;//функция x 
	double F;//функция F
	double G;//функция  G

	cout << "Enter A: ";//приглашение к вводу А
	cin >> A;//Ввод числа А в программу
	cout << "Enter B: ";//приглашение к вводу В
	cin >> B;//Ввод числа B в программу
	cout << "A= " << A << endl << "B= " << B << endl;//эхопечать
	if (A == B)//Условие равенства
	{
		N = 1	;//т.к h=0, значение аргумента x меняться не будет => возможно высчитать только по одному значению данной точки для каждой функции

	}
	else
	{//другой случай
		cout << "Enter N: ";//приглашение к вводу числа N
		cin >> N;//ввод N в программу
		if (N <= 0)//случай равенства N нулю
		{
			cout << "ERROR" << endl;//сообщение об ошибке
			system("pause");//задержка потока
			return 0;//Возврат к 0 
		}
	}
	if (B < A)//Случай некорректного условия
	{
		swap(A, B);//замена переменных местами
		cout << "A= " << A << " " << "B= " << B << endl;
	}
	h = (B - A) / N;//Рассчёт h
	i = 0;//Исходное значения для инициации цикла
	cout << setw(1) << setfill(char(201)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(187)) << "" << endl;//разметка шапки таблицы
	cout << setw(1) << setfill(char(186)) << "" << "\tx\t" << setw(1) << setfill(char(186)) << "" << "\tF" << setw(1) << setfill(char(186)) << "" << "\tG\t\t" << setw(1) << setfill(char(186)) << "" << endl;//Заполнение ячеек названиями функций
	cout << setw(1) << setfill(char(204)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(185)) << "" << endl;//Разметка отделения ячеек
	while (i <= N)//Ввод условия цикла и его инициация
	{
		if(A==B)
		{
			N = 0;
		}
		x = A + (i*h);//Рассчёт необходимого значения x
		F = sin(x)*cos(x);//Рассчёт необходимого значения F
		G = (2 * sin(2 * x)) + 1;//Рассчёт необходимого значения G
        cout << setw(1) << setfill(char(186)) << "" << "\t" << setprecision(3) << x << "\t" << setw(1) << setfill(char(186)) << ""<<setfill(char(32)) <<""<< setw(8) << setprecision(3) << F  << setw(1) << setfill(char(186)) << "" << "\t" << setprecision(3) << G << "\t\t" << setw(1) << setfill(char(186)) << "" << endl;//Вывод данных
		cout << setw(1) << setfill(char(200)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(188)) << "" << endl;//Разметка отделения ячеек

		i++;//Увеличение значения i на 1

	}//конец цикла


	system("pause");//задержка потока
	return 0;//Возврат к 0
}