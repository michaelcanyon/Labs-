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
	//������ ������ �� �����
	char str[255];
	string filename;
	cout << "enter full filename ";
	cin >> filename;
	ifstream fin(filename);
	if (!fin)//�������� ����� �����
	{
		cout << "Filename is incorrect\n";//��� ����� ������� �����������
		fin.close();//�������� �����
		system("pause");
		return 1;
	}
	if (fin.is_open())
	{
		if (fin.eof())
			cout << "file is empty";
	}
	if (fin.fail())//�������� �� ������������ ���� ������ � �����
	{
		cout << "Error. Reading file failure\n";//� ����� ���� ����������� ���� ������
		fin.close();//�������� �����
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
//����� ������ ��������� �����
void f1(int i, int b, char str[], int length, int& minlength, int bw, int& ew)
{
	while (str[i] != '\0')//������������� �����, ���������� ������� �� '\0'
	{
		b = i;//� - �������� ���������� ��� ������ ����� �����
		while (str[i] != ' '&&i <= 255&& str[i] != '\0')//������� �������� �� ' ' ��� ���� �� ���������� ������ ������(� ������, ����� ����� ���������� ����� '\0' ��� �������� ������������ ��� ����� ������)
		{
			i++;
			length = i - b;
		}
		
		if (length < minlength)//����������� ������������ ����� � ���������� ������ ���������� ��� ������ �����
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
//����� ������������� ����, ������ �� ����� �����������
	void f2(int i, int b, char str[], int length, int minlength, int bw, int ew)
	{
		cout << "Words that have equal length to the shortest one:  " << endl;
		while (str[i] != '\0')//������������� �����, ���������� ������� �� '\0'
		{
			
			b = i;//� - �������� ���������� ��� ������ ����� �����
			while (str[i] != ' '&&i <= 255&&str[i] != '\0')//������� �������� �� ' ' ��� ���� �� ���������� ������ ������(� ������, ����� ����� ���������� ����� '\0' ��� �������� ������������ ��� ����� ������)
			{
				i++;
				length = i - b;
			}
			
			if (length == minlength)//����������� ������������ ����� � ���������� ������ ���������� ��� ������ �����
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