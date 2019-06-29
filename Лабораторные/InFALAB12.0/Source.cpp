#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

int factorial(int n);
double rowCosh(double x, double Eps);

int main()
{
	double p;
	double Eps = 0.000001; //��������
	int A = 4;
	int M = 0;
	int strq = 5;
	//������ �:
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
	double tSum = cosh(x);			// ������ �����
	double ArgX;					// ��������� ����������
	int DNFact;					// ����������� ����������
	double Slag;					// ��������� ��������� �������������������
	double Sum = 1;					// ������� �����
	double Diff;					// �������� ����� ������ ������ � �������
	int N = 0;						// ���������� �������� N, Znak, ArgX, DN1Fact
	Diff = fabs(tSum - Sum);			// ���������� ������� ����� ������ ������ � �����������
	while (Diff > Eps)				// ���� ���� Diff > Eps
	{
		N = N + 1;						// ������� � ��������� ���������� ����������
		ArgX = pow(x, 2 * N);			// ���������� x � ������� 2N-1 (��������� ���������)
		DNFact = factorial(2 * N); 		// ���������� ����������� 2N!
		Slag = (ArgX) / DNFact;			// ���������� ����������
		Sum = Sum + Slag;				// ���������� ����� N-���������
		Diff = fabs(tSum - Sum);			// ���������� ������� ����� ������ ������ � �����������
	}//while	
	return Sum;
}

 int factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}

