#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void structprint(struct planes num[], int b);
void sort(struct planes num[], int b, int i, int j, int t);
void fileout(struct planes num[], int b);
void enterstr(struct planes num[], char *FNAME, int b, int pln, char *string, char late, bool &flag, char *pass);
void filecheck(char *FNAME, bool &che);
struct planes {
	int racenumber;
	string shipnumber;
	string passengersq;
	char racelate[7];
};
int main()
{
	bool che = true;
	bool flag = true;
	int b = 0, i = 0, j = 0, t = 0;
	char FNAME[30];
	cout << "enter file name: ";
	cin >> FNAME;
	strcat_s(FNAME, ".txt");
	filecheck(FNAME, che);
	
		fstream file;
		file.open(FNAME, fstream::in);
		if (!file)
		{
			file.close();
			cout << "Error. File " << FNAME << " doesn't exist" << endl;
			system("pause");
			return 0;

		}
		char string[15];
		char pass[10];
		int pln = 0;
		char late = '0';
		for (b = 0; !file.eof(); b++)
		{
			file >> string;
			

		}
		file.close();
		if (che == true)
		{
			b /= 4;
		planes *num = new planes[b];

		enterstr(num, FNAME, b, pln, string, late, flag, pass);
		if (flag == true)
		{
			structprint(num, b);
			fileout(num, b);
			sort(num, b, i, j, t);
			cout << "sorted schedule: " << endl;
			structprint(num, b);
			fileout(num, b);
		}






	}
	else
	{
		cout << "Schedule file contains incorrect data type";
	}
	system("pause");
	return 0;
}
void structprint(struct planes num[], int b)
{
	cout << setw(1) << setfill(char(218)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(194)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(194)) << "" << setw(10) << setfill(char(196)) << "" << setw(1) << setfill(char(194)) << "" << setw(12) << setfill(char(196)) << "" << setw(1) << setfill(char(191)) << "" << endl;//разметка шапки таблицы
	cout << setw(1) << setfill(char(179)) << "" << setw(1) << setfill(char(179)) << "Race" << "\t" << setw(1) << setfill(char(179)) << "" << "Plane\t" << setw(1) << setfill(char(179)) << "" << "passengers" << setw(1) << setfill(char(179)) << "" << "Late\t" << setw(1) << setfill(char(179)) << "" << endl;//Заполнение ячеек названиями функций
	cout << setw(1) << setfill(char(195)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(10) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(12) << setfill(char(196)) << "" << setw(1) << setfill(char(180)) << "" << endl;//Разметка отделения ячеек
	for (int j = 0; j < b; j++)
	{

		cout << setw(1) << setfill(char(179)) << "" << num[j].racenumber << "\t";
		cout << setw(1) << setfill(char(179)) << "" << num[j].shipnumber << " " << setw(1) << setfill(char(179)) << "" << num[j].passengersq << " " << setw(6) << setfill(char(255)) << "" << setw(1) << setfill(char(179)) << "";
		for (int t = 0; t < 8; t++)
		{
			cout << num[j].racelate[t];
		}
		cout << setw(4) << setfill(char(255)) << "" << setw(1) << setfill(char(179)) << "" << endl;
		if (j < (b - 1))
		{
			cout << setw(1) << setfill(char(195)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(10) << setfill(char(196)) << "" << setw(1) << setfill(char(197)) << "" << setw(12) << setfill(char(196)) << "" << setw(1) << setfill(char(180)) << "" << endl;
		}
		else
		{
			cout << setw(1) << setfill(char(192)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(193)) << "" << setw(7) << setfill(char(196)) << "" << setw(1) << setfill(char(193)) << "" << setw(10) << setfill(char(196)) << "" << setw(1) << setfill(char(193)) << "" << setw(12) << setfill(char(196)) << "" << setw(1) << setfill(char(217)) << "" << endl;
		}
	}
}
void sort(struct planes num[], int b, int i, int j, int t)
{
	for (i = 0; i < b; i++)
	{
		for (j = i + 1; j < b; j++)
		{
			for (t = 0; t < 8; t++)
			{
				/*if ((num[j].racelate[t] == ':') || (num[i].racelate[t] == ':'))
				{
					continue;
				}*/
				/*else*/ if (num[j].passengersq < num[i].passengersq)
				{
					swap(num[j].passengersq, num[i].passengersq);
					break;
				}
			}

		}
	}
}
void fileout(struct planes num[], int b)
{
	fstream fileout;
	fileout.open("result.txt", fstream::app);
	fileout << "race\tship\tpassengers\t\ttime" << endl;
	for (int j = 0; j < b; j++)
	{

		fileout << num[j].racenumber << " " << num[j].shipnumber << " \t\t" << num[j].passengersq << "\t\t\t\t ";
		for (int t = 0; t < 8; t++)
		{
			fileout << num[j].racelate[t];
		}
		fileout << endl;
	}
	fileout.close();

}
void enterstr(struct planes num[], char *FNAME, int b, int pln, char *string, char late, bool &flag, char *pass)
{
	fstream structure;
	structure.open(FNAME, fstream::in);
	for (int j = 0; j < b; j++)//string
	{
		for (int i = 0; i < 4; i++)//word
		{
			switch (i)
			{
			case 0:
				structure >> pln;
				if (structure.fail())
				{
					cout << "Error reading int. Perhaps data is corrupted." << endl;
					flag = false;
					return;
				}
				num[j].racenumber = pln;
				break;
			case 1:
				structure >> string;
				num[j].shipnumber = string;
				if (strlen(string) != 6)
				{
					cout << "error. shipnumber has wrong format." << endl;
					flag = false;
					return;
				}

				break;
			case 2:
				structure >> pass;
				num[j].passengersq = pass;
				if (strlen(pass) != 3)
				{
					cout << "error. passengers quantity has wrong format." << endl;
					flag = false;
					return;
				}
				break;
			case 3:
				for (int y = 0; y <= 7; y++)
				{
					structure >> late;
					num[j].racelate[y] = late;
				}
				if (num[j].racelate[2] != ':' || num[j].racelate[5] != ':')
				{

					cout << "error. time data is corrupted or has wrong format." << endl;
					flag = false;
					return;
				}
				break;

			}
		}
	}
	structure.close();
}
void filecheck(char *FNAME, bool &che)
{
	char num;
	fstream check;
	check.open(FNAME, fstream::in);
	check >> num;
	if (check.eof())
	{
		check.close();
		cout << "file is empty" << endl;
		che = false;
		system("pause");
		return;
	}
	if ((num == '0') | (num == '1') | (num == '2') | (num == '3') | (num == '4') | (num == '5') | (num == '6') | (num == '7') | (num == '8') | (num == '9'))
	{
		return;
	}
	else
	{
		che = false;
	}
	check.close();
}