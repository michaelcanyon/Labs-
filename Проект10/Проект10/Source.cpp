#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
const int nmatr = 7;
const int mmatr = 5;
const int ari=5;

void max(double nmax, int nmatr, int mmatr, int &ima, int &jma, double amatr[][ari], int i, int j);
void min(double nmin, int nmatr, int mmatr, int &imi, int &jmi, double amatr[][ari], int i, int j);
void exchprint(double exch, int i, int j, double amatr[][ari], int jma, int jmi, int nmatr, int mmatr);
void matrprint(int i, int j, double amatr[][ari], int nmatr, int mmatr);
void fileprint(int i, int j, int nmatr, int mmatr, double amatr[][ari]);
int main()
{
	int i = 0, j = 0, ima = 0, jma = 0, imi = 0, jmi = 0;
	double exch = 0;
	double temp = 0, nmax = 0, nmin = 0;
	cout << "enter filename: ";
	char FNAME[30];
	cin >> FNAME;
	strcat_s(FNAME, ".txt");
	double amatr[nmatr][mmatr];
	ifstream fin(FNAME);
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{
			fin >> amatr[i][j];
			cout << amatr[i][j] << " ";
		}
		cout << endl;
	}
	min(nmin, nmatr, mmatr, imi, jmi, amatr, i, j);
	max(nmax, nmatr, mmatr, ima, jma, amatr, i, j);
	cout << endl;
	exchprint(exch, i, j, amatr, jma, jmi, nmatr, mmatr);
	fileprint(i, j, nmatr, mmatr, amatr);
	system("pause");
	return 0;










}

	void min(double nmin, int nmatr, int mmatr, int &imi, int &jmi, double amatr[][ari], int i, int j)
{
	nmin = 42949676;
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{

			if (amatr[i][j] < nmin)
			{
				imi = i;
				jmi = j;
				nmin = amatr[imi][jmi];
			}
		}
	}
	cout << "minimal element is " << nmin << endl;
}
void max(double nmax, int nmatr, int mmatr, int &ima, int &jma, double amatr[][ari], int i, int j)
{
	nmax = -4294967296;
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{
			if (amatr[i][j]>nmax)
			{
				ima = i;
				jma = j;
				nmax = amatr[ima][jma];
			}

		}
	}
	cout << "maximal element is " << nmax << endl;


}
void exchprint(double exch, int i, int j, double amatr[][ari], int jma, int jmi, int nmatr, int mmatr)
{
	for (i = 0; i < nmatr; i++)
	{
		exch = amatr[i][jma];
		amatr[i][jma] = amatr[i][jmi];
		amatr[i][jmi] = exch;
	}
	//changed matrix
	matrprint(i, j, amatr, nmatr, mmatr);
}
void matrprint(int i, int j, double amatr[][ari], int nmatr, int mmatr)
{
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{
			cout << amatr[i][j] << "  ";
		}
		cout << endl;
	}
}
void fileprint(int i, int j, int nmatr, int mmatr, double amatr[][ari])
{
	ofstream save("C:\\Users\\hrani\\Desktop\\fileresult.txt", ios::app);
	save << "matix:" << endl;
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{
			save << amatr[i][j] << " ";

		}
		save << endl;
	}
	save.close();
}










