#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
void FileDeclaring(char *FNAME, int &b, bool &flag);
void MatrixFillingIn(char *FNAME, double **amatr, int b);
void matrprint(int b, double **amatr);
void matrenter(int b, double **amatr);
void fileprint(int b, double **amatr);
void UpperTriangle(int b, double **amatr, double &max);
void fileprint1(int b, double **amatr, double max);
int main()
{
	double max = DBL_MIN;
	cout << "enter filename: ";
	char FNAME[30];
	cin >> FNAME;
	strcat_s(FNAME, ".txt");
	int b; bool flag = true;

	FileDeclaring(FNAME, b, flag);
	if (!flag)
	{
		cout << "enter array dimension: ";
		cin >> b;
		double **amatr = new double*[b];
		for (int i = 0; i < b; i++)
		{
			amatr[i] = new double[b];
		}
		matrenter(b, amatr);
		matrprint(b, amatr);
		fileprint(b, amatr);
		UpperTriangle(b, amatr, max);
		fileprint1(b, amatr, max);
	}
	else
	{
		double **amatr = new double*[b];
		for (int i = 0; i < b; i++)
		{
			amatr[i] = new double[b];
		}
		MatrixFillingIn(FNAME, amatr, b);
		matrprint(b, amatr);
		fileprint(b, amatr);
		UpperTriangle(b, amatr, max);
		fileprint1(b, amatr, max);
	}
	system("pause");
	return 0;
}
void FileDeclaring(char *FNAME, int &b, bool &flag)
{
	fstream fin;
	fin.open(FNAME, fstream::in);

	if (!fin)
	{
		cout << "File " << FNAME << " not found\n";
		fin.close();
		flag = false;
		return;
	}
	else
	{
		fin >> b;
		if (fin.fail())
		{
			cout << "Matrix dimension isn't declared.";
			fin.close();
			flag = false;
			return;
		}
		if (fin.eof())
		{
			cout << "File " << FNAME << " is empty or has not enough numbers\n";
			fin.close();
			flag = false;
			return;
		}
		else if (fin.fail())
		{
			cout << "Error. File " << FNAME << " contains incorrect data types\n";
			fin.close();
			flag = false;
			return;
		}
	}
}
void MatrixFillingIn(char *FNAME, double **amatr, int b)
{
	fstream fin;
	fin.open(FNAME, fstream::in);
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)
		{
			fin >> amatr[i][j];

		}
	}
}
void matrprint(int b, double **amatr)
{
	cout << "matrix: " << endl;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << amatr[i][j] << "  ";
		}
		cout << endl;
	}
}
void matrenter(int b, double **amatr)
{
	cout << "enter matrix [" << b << "]*[" << b << "]" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "enter " << i << " string" << endl;
		for (int j = 0; j < b; j++)
		{
			cin >> amatr[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
void fileprint(int b, double **amatr)
{
	ofstream save("C:\\Users\\hrani\\Desktop\\fileresult.txt", ios::app);
	save << "matix:" << endl;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)
		{
			save << amatr[i][j] << " ";

		}
		save << endl;
	}
	save.close();
}
void UpperTriangle(int b, double **amatr, double &max)
{
	int t=0;
	int k = b;
	int h = b;
	cout << "Upper triangle\n ";
	for (int i =k-1; i >=0; i--)
	{
		for (int j = t; j <h; j++)
		{
			cout << amatr[i][j] << " ";
			if (amatr[i][j] > max)
			{
				max = amatr[i][j];
			}
		}
		t++;
		cout << endl;
	}
	cout << "maximal element is: " << max;
}
void fileprint1(int b, double **amatr, double max)
{
	int k = b;
	int h = b;
	ofstream save("C:\\Users\\hrani\\Desktop\\fileresult.txt", ios::app);
	save << "Upper triangle\n ";
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < h; j++)
		{
			save << amatr[i][j] << " ";
		}
		h--;
		save << endl;
	}
	save << "maximal element is: " << max;
	save.close();
}