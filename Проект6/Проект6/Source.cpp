#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
const int nmatr = 4;
const int mmatr = 4;
const int ari= 4;
const int arj= 4;
void transpos(int i, int j, int nmatr, int mmatr, double amatr[ari][arj], double temp);
void max(double nmax, int nmatr, int mmatr, int &ima, int &jma, double amatr[ari][arj], int i, int j);
void min(double nmin, int nmatr, int mmatr, int &imi, int &jmi, double amatr[ari][arj], int i, int j);
void exchprint(double exch, int i, int j, double amatr[ari][arj], int ima, int jma, int imi, int jmi);
void matrprint(int i, int j, double amatr[ari][arj], int nmatr, int mmatr);
void matrenter(int i, int j, double amatr[ari][arj], int nmatr, int mmatr);
void fileprint(int i, int j, int nmatr, int mmatr, double amatr[ari][arj]);

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
	if (!fin)
		{
			cout << "File " << FNAME << " not found\n";
			fin.close();
			matrenter(i, j, amatr, nmatr, mmatr);
			system("pause");
		}
	else
	{
		for (i = 0; i < nmatr; i++)
		{
			for (j = 0; j < mmatr; j++)
			{
				fin >> amatr[i][j];

			}
		}
		fin.close();
		if (fin.eof())
		{
			cout << "File " << FNAME << " is empty or has not enough numbers\n";
			fin.close();
			matrenter(i, j, amatr, nmatr, mmatr);
			system("pause");
		}
		else if (fin.fail())
		{
			cout << "Error. File " << FNAME << " contains incorrect data types\n";
			fin.close();
			matrenter(i, j, amatr, nmatr, mmatr);
			system("pause");
		}
		
	}
	cout << "matrix: " << endl;
	matrprint(i, j, amatr, nmatr, mmatr);
	cout << endl;
	fileprint(i, j, nmatr, mmatr, amatr);
	cout << "transposed matrix: " << endl;
	transpos(i, j, nmatr, mmatr, amatr, temp);
	max(nmax, nmatr, mmatr, ima, jma, amatr, i, j);
	min(nmin, nmatr, mmatr, imi, jmi, amatr, i, j);
	cout << "changed matrix: " << endl;
	exchprint(exch, i, j, amatr, ima, jma, imi, jmi);
	fileprint(i, j, nmatr, mmatr, amatr);
	system("pause");
	return 0;



}
void transpos(int i, int j, int nmatr, int mmatr, double amatr[ari][arj], double temp)
{
	for (i=0;i < nmatr; i++)
	{
		for (j = i + 1; j < mmatr; j++)
		{
			temp = amatr[i][j];
			amatr[i][j] = amatr[j][i];
			amatr[j][i] = temp;
		}
	}
	//printmatr
	matrprint(i, j, amatr, nmatr, mmatr);
}
void max(double nmax, int nmatr, int mmatr, int &ima, int &jma, double amatr[ari][arj], int i, int j)
{
	nmax = -4294967296;
	for (i = 0; i < nmatr; i++)
	{
		for (j = 0; j < mmatr; j++)
		{
			if(amatr[i][j]>nmax)
			{
				ima = i;
				jma = j;
				nmax = amatr[ima][jma];
			}
			
		}
	}
	cout << "maximal element is " << nmax << endl;
	

}
void min(double nmin, int nmatr, int mmatr, int &imi, int &jmi, double amatr[ari][arj],int i,int j)
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
void exchprint(double exch, int i, int j, double amatr[ari][arj], int ima, int jma, int imi, int jmi)
{
	exch = amatr[ima][jma];
	amatr[ima][jma] = amatr[imi][jmi];
	amatr[imi][jmi] = exch;
	//changed matrix
	matrprint(i, j, amatr, nmatr, mmatr);
}

void matrprint( int i, int j, double amatr[ari][arj], int nmatr, int mmatr)
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
void matrenter(int i, int j, double amatr[ari][arj], int nmatr, int mmatr)
{
	cout << "enter matrix [" << nmatr << "]*[" << mmatr << "]" << endl;
	for (i = 0; i < nmatr; i++)
	{
		cout << "enter " << i << " string" << endl;
		for (j = 0; j < mmatr; j++)
		{
			cin >> amatr[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
void fileprint(int i, int j, int nmatr, int mmatr,double amatr[ari][arj])
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