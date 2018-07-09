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
const char *FNAME = "Array1.h";//���������� �����
int main()
{
	int N;//���������� ����������, ������������ ����� ��������� � �������
	int i = 0;//������ ��������
	int firstP;//������ ������������� �������
	int ifirstP = -1;//��� ������
	int lastP;//��������� ������������� ������� 
	int ilastP = -1;//��� ������
	int const NMAX = 6;//����������� �������
	int Array[NMAX];//������
	ifstream fin(FNAME);//�������� ����� ��� ������
	if (!fin)//�������� ����� �����
	{
		cout << "File " << FNAME << " not found\n";//��� ����� ������� �����������
		fin.close();//�������� �����
		system("pause");
		return 1;
	}
	fin >> N;//���� ����� ��������� � ��������� �� �����
	if (fin.eof())//�������� �� ������� ������ � �����
	{
		cout << "File " << FNAME << " is empry\n";//��������� � ������ �����
		fin.close();//�������� �����
		system("pause");
		return 1;
	}
	if (fin.fail())//�������� �� ������������ ���� ������ � �����
	{
		cout << "Error. Reading file " << FNAME << " failure\n";//� ����� ���� ����������� ���� ������
		fin.close();//�������� �����
		system("pause");
		return 1;
	}
	//��� ������
	cout << "N= " << N << "\tfin.eof() = " << fin.eof() << endl;
	if (fin.good())//���� ����������� �� ���������� 
	{
		cout << "Vector reading\n";//������ ������
		for (i = 0; i < N; i++)
		{
			fin >> Array[i];//���� ������ � ��������� �� �����
			cout << " i= " << i << "\tArray = " << Array[i] << endl;//������ ��������� ������� � ��� �������

		}
	}
	fin.close();//�������� �����
	cout << "File was succesfully read" << endl;//������������ � ���, ��� ���� ��������
												//������ �������
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
	//����� ������� �������������� ��������
	for (i = 0; i < NMAX; i++)
	{
		if (Array[i] > 0)
		{
			cout << "first positive element is " << Array[i] << endl;
			cout << "index is " << i << endl;
			firstP = Array[i];
			ifirstP = i;
			break;//���������� �����, �.� ������� ������
		}
	}

	if (ifirstP == -1)//������ �� ���������, ������������� ��������� ���
	{
		cout << "An error occured. Array has no positive elements" << endl;
	}
	else
	{
		//����� ���������� �������������� ��������
		for (i = NMAX-1; i >= 0; i--)
		{
			if (Array[i] > 0)
			{
				cout << "last positive element is " << Array[i] << endl;
				cout << "index is " << i << endl;
				lastP = Array[i];
				ilastP = i;
				break;//���������� �����, �.� ������� ������
			}
		}
		if (ilastP == ifirstP)//���� � ������� ������ ���� ������������� �������
		{
			cout << "Error. There is only one positive element" << endl;
		}
		else
		{


			//������� �����
			int Summ = 0;
			if (ilastP - ifirstP == 1)//������ - ����� �� ����������
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
	//����� ����������� ��������
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

	//����� ����������� ��������
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

	//����� �������� �������
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