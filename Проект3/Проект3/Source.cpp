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
			fin >> str[i];//���� ������ � ��������� �� �����
			cout << " i= " << i << "\tArray = " << str[i] << endl;//������ ��������� ������� � ��� �������

		}
	}
	fin.close();//�������� �����
	cout << "File was succesfully read" << endl;
	for (i = 0; i < NMAX; i++) {
		if (str[i].length()> Min.length())
		{
			Min = str[i];
		}
	}
	cout << "The longest word: " << Min << "  " << Min.length() << endl;//� ��� �� ����� ����������

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