#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

int factorial(int n);
double rowCosh(double x, double Eps);

int main()
{
	double p;
	double Eps = 0.000001; //точность
	int A = 4;
	int M = 0;
	int strq = 5;
	//Задаем х:
	double x= rand() % 4;
	printf("%-10s %-15s %-10s", "x", "cosh(x)", "rowCosh(x)\n");
	while (M < strq)
	{
		printf("%-10.1f %-15f %-10f\n\n", x, cosh(x), rowCosh(x, Eps));
		x += 0.1;
		M++;
	}
	system("pause");
	return 0;
}
double rowCosh(double x, double Eps)
{
	double tSum = cosh(x);			// точная сумма
	double ArgX;					// числитель слагаемого
	int DNFact;					// знаменатель слагаемого
	double Slag;					// очередное слагаемое последовательсности
	double Sum = 1;					// текущая сумма
	double Diff;					// разность между точной суммой и текущей
	int N = 0;						// присвоение значений N, Znak, ArgX, DN1Fact
	Diff = fabs(tSum - Sum);			// нахождение разницы между точной суммой и вычисленной
	while (Diff > Eps)				// цикл пока Diff > Eps
	{
		N = N + 1;						// переход к обработке следующего слагаемого
		ArgX = pow(x, 2 * N);			// возведение x в степень 2N-1 (получение числителя)
		DNFact = factorial(2 * N); 		// вычисление знаменателя 2N!
		Slag = (ArgX) / DNFact;			// вычисление слагаемого
		Sum = Sum + Slag;				// нахождение суммы N-слагаемых
		Diff = fabs(tSum - Sum);			// нахождение разницы между точной суммой и вычисленной
	}//while	
	return Sum;
}

 int factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}

