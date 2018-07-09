#include<iostream>
using namespace std;
int main()
{
	const int NMAX = 10;
	int Avec[NMAX] = { -3,-6,111,7,-8,2,9,-99,1,0 };
	int FirstP = -1;
	int iFirstP = 1;
	int LastN = 1;
	int iLastN = -1;
	int iBeg = iFirstP;
	int iEnd = iLastN;
	int sum = 0;
	int i;
	bool FlagEx = true;

	//vvod ishodnogo massiva
	cout << "enter massive composed from " << NMAX << " numbers";
	for (i = 0; i < NMAX; i++)
	{
		cout << Avec[i] << " ";
	}
	cout << endl;
	//looking for element and it's index
	i = -1;
	do
	{
		i++;
		if (Avec[i] > 0)
		{
			FirstP = Avec[i];
			iFirstP = i;
		}
	} while ((i < NMAX) && (Avec[i] <= 0));
	cout << "/1 FirstP= " << FirstP << "\tiFirstp= " << iFirstP << endl;//vivod pervogo + elementa
	if (i == NMAX)
	{
		cout << "There is no positive numbers" << endl;
		FlagEx = false;
	}
	else {
		cout << "first positive meaning " << FirstP << endl;
		cout << "index is " << iFirstP << endl;
	}
	//looking for last negative number
	i = NMAX;
	do
	{
		i--;
		if (Avec[i] < 0)
		{
			LastN = Avec[i];
			iLastN = i;

		}
	}
		while ((i >= 0) && (Avec[i] >= 0));
	if (LastN = 1)
	{
		cout << "There is no negative numbers";
		FlagEx = false;
	}
	else
	{
		cout << "the lowest negative number is " << LastN << endl << "Index is " << iLastN << endl;
	}


		if (!FlagEx)
		{
			cout << "Summ is not possible to find/ Can't change numbers" << endl;
			system("pause");
			return 1;

		}
	}
	//looking for sum
	double Sum_PN = 0;
	for(i = iBeg + 1; i < iEnd; i++ )
	Sum_PN = Sum_PN + Avec[i];
	cout << "Sum_PN= " << Sum_PN << endl;


	system("pause");
	return 0;
}
