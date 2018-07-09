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
#include<iostream>//��������� ���������
#include<cmath>
#include<iomanip>
using namespace std;//���������� ������������ ���
double const pi = 3.1415926535898;
int main()
{
	double A;//����� �
	double B;//����� �
	int N;//���������� ���������� N
	double h;//��� � ���������� ���������
	int i;//�����, � ������� ��������� �������� �������
	double x;//������� x 
	double F;//������� F
	double G;//�������  G

	cout << "Enter A: ";//����������� � ����� �
	cin >> A;//���� ����� � � ���������
	cout << "Enter B: ";//����������� � ����� �
	cin >> B;//���� ����� B � ���������
	cout << "A= " << A << endl << "B= " << B << endl;//���������
	if (A == B)//������� ���������
	{
		N = 1	;//�.� h=0, �������� ��������� x �������� �� ����� => �������� ��������� ������ �� ������ �������� ������ ����� ��� ������ �������

	}
	else
	{//������ ������
		cout << "Enter N: ";//����������� � ����� ����� N
		cin >> N;//���� N � ���������
		if (N <= 0)//������ ��������� N ����
		{
			cout << "ERROR" << endl;//��������� �� ������
			system("pause");//�������� ������
			return 0;//������� � 0 
		}
	}
	if (B < A)//������ ������������� �������
	{
		swap(A, B);//������ ���������� �������
		cout << "A= " << A << " " << "B= " << B << endl;
	}
	h = (B - A) / N;//������� h
	i = 0;//�������� �������� ��� ��������� �����
	cout << setw(1) << setfill(char(201)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(187)) << "" << endl;//�������� ����� �������
	cout << setw(1) << setfill(char(186)) << "" << "\tx\t" << setw(1) << setfill(char(186)) << "" << "\tF" << setw(1) << setfill(char(186)) << "" << "\tG\t\t" << setw(1) << setfill(char(186)) << "" << endl;//���������� ����� ���������� �������
	cout << setw(1) << setfill(char(204)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(185)) << "" << endl;//�������� ��������� �����
	while (i <= N)//���� ������� ����� � ��� ���������
	{
		if(A==B)
		{
			N = 0;
		}
		x = A + (i*h);//������� ������������ �������� x
		F = sin(x)*cos(x);//������� ������������ �������� F
		G = (2 * sin(2 * x)) + 1;//������� ������������ �������� G
        cout << setw(1) << setfill(char(186)) << "" << "\t" << setprecision(3) << x << "\t" << setw(1) << setfill(char(186)) << ""<<setfill(char(32)) <<""<< setw(8) << setprecision(3) << F  << setw(1) << setfill(char(186)) << "" << "\t" << setprecision(3) << G << "\t\t" << setw(1) << setfill(char(186)) << "" << endl;//����� ������
		cout << setw(1) << setfill(char(200)) << "" << setw(47) << setfill(char(205)) << "" << setw(1) << setfill(char(188)) << "" << endl;//�������� ��������� �����

		i++;//���������� �������� i �� 1

	}//����� �����


	system("pause");//�������� ������
	return 0;//������� � 0
}