#define _CRT_SECURE_NO_WARNINGS
#define M_PI            3.14159265358979323846
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <io.h>
#include<math.h>
double dividing(double Q, double a, double b,double &fx);
double integralCalc(double Q, double a, double b, int n, int *&iter);
double f(double x);
double fintegral(double x);
int main()
{
	int *itr = 0;
	double a = 1.2, b = 1.3, fx=0;
	double Q = FLT_EPSILON * 2;
	/*printf("Presision: ");
	printf("%10.20lf", Q);*/
	/*printf("\n");*/
	double root = dividing(Q, a, b, fx);
	if (root < 0)
	{
		printf("Math error detected!\n");
		return 0;
	}
	printf("Equation root:  ");
	printf("%10.20lf",root);
	printf("\n");
	printf("f(x) meaning: ");
	printf("%10.20lf", fx);
	printf("\n");
	a = 0, b =M_PI;
	Q = 0.0005;
	int n = 20;
	printf("\n\n\n\n");
	/*printf("\nPresigion: ");
	printf("%10.20lf", Q);*/
	double integrand;
	integrand = integralCalc(Q, a, b, n, *&itr);
	if (integrand  < 0)
	{
		printf("Math error detected!\n");
		return 0;
	}
	printf("\n");
	printf("Integrand:  ");
	printf("%10.20lf", integrand);
	printf("\n");
	printf("iterations quantity: ");
	printf("%d", itr);
	printf("\n");
	system("PAUSE");
	return 0;
}
double dividing(double Q,double a, double b,double &fx)
{
	begining:
	if (b < a)
	{
		double temp;
		temp = b;
		b = a;
		a = temp;
	}
	double x;
	double length = b - a;
	if (length < Q)
	{
		fx = f(b);
		return b;
	}
		
	x = (a + b) / 2;
	double fa = f(a);
	double fb = f(b);
	fx = f(x);
	double modul = fabs(fx);
	if (modul <= Q)
	{
		fx = f(x);
		return x;
	}
	if ((fa > 0 && fx > 0) || (fa < 0 && fx < 0))
	{
		if (fb > 0 && fx > 0 || fb < 0 && fx < 0)
		{
			printf("Math error detected!\n");
			return 0;
		}
		else
		{
			a = b;
			b = x;
			goto begining;
		}
	}
	if ((fb > 0 && fx > 0) || (fb < 0 && fx < 0))
	{
		if (fa > 0 && fx > 0 || fa < 0 && fx < 0)
		{
			printf("Math error detected!\n");
			return 0;
		}
		else
		{
			b = x;
			goto begining;
		}
	}
	printf("Math error detected!\n");
	return 0;
}
double f(double x)
{
	double fx;
	fx = (4 + pow(x, 2)) * (exp(x) - 1/exp(x)) - 18;
	return fx;
}
double integralCalc(double Q, double a, double b, int n, int *&iter)
{
	double S0 = 0;
	double h = (b - a) / n;
	for (int i = 0; i < n; i++)
		S0 += h*fintegral(a + h*i + h / 2);
repeat:
	iter++;
	n += 5;
	double S1 = 0;
	h = (b - a) / n;
	for (int i = 0; i < n; i++)
	{
		S1 += h*fintegral(a + h*i + h / 2);
	}
	double difference = abs(S0 - S1);
	if (difference < Q)
		return S1;
	else
	{
		S0 = S1;
		goto repeat;
	}
}
double fintegral(double x)
{
	double fx;
	fx = sqrt(1 + pow(cos(x), 2));
	return fx;
}