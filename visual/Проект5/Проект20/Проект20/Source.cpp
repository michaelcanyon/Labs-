#include<iostream>
using namespace std;
int main()
{
	int i;
	int const N = 10;
	int firstCh;
	int ifirstCh = -1;
	int firstNCh;
	int ifirstNCh=-1;
	int ArrCh[N] = { 1,2,3,4,5,6,7,8,9,10 };
	int ArrNch[N] = { 3,5,7,12,4,9,10,14,13,16 };
	//1 массив
	for (i = 0; i < N; i++)
	{
		if (ArrCh[i]%2==0)
		{
			firstCh = ArrCh[i];
			ifirstCh = i;
			break;
		}
	}
	if (ifirstCh==-1)
	{
		cout << "there is no n/2 elements" << endl;
		system("pause");
		return 0;
	}
	//2 массив
	for(i=0;i<N;i++)
	{
		if (ArrNch[i]%2==0)
		{
			firstNCh = ArrNch[i];
			ifirstNCh = i;
			break;
		}
		cout << " ArrNCH= " << 5;
	¬ывод: ѕолученные результаты совпадают с ожидаемыми.

	}
	if (ifirstNCh==-1)
	{
		cout << "there is no n/2 elements" << endl;
		system("pause");
		return 0;

	}
	//проверка на ближайшее расположение к началу
	if(ifirstCh>ifirstNCh)
	{
		cout << "in the second Array " << ifirstNCh << " closer to the start of the massive than " << ifirstCh << " in the first" << endl;
	}
	if (ifirstCh<ifirstNCh)
	{
		cout << "in the first Array " << ifirstCh << " closer to the start of the massive than " << ifirstNCh << " in the second" << endl;
	}
	if(ifirstCh==ifirstNCh)
	{
		cout << "n/2 elements have equal positions" << endl;
	}
	//формирование нового массива
	double NewArr[N];
	for(i=0;i<N;i++)
	{
		NewArr[i] = (ArrCh[i] + ArrNch[i]) / 2;
	}
	for(i=0;i<N;i++)
	{
		cout << " " << NewArr[i];
	}
	system("pause");
	return 0;
}