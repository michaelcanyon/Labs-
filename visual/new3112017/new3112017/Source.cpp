#include<iostream>

using namespace std;
int main()
{//massive titling
	setlocale(0, "RUSSIAN");
	const int NMAX = 9;//massive size
    int Avec[NMAX] = { 1,8,9,3,9,4,5,1,7 };
	int i;//cicle paramentr
	//massive entrance
	/*cout << "введите " << NMAX << " элементов массива" << endl;
	for (i = 0; i < NMAX; i++)
	{
		cout << " AVec[" << i << "]= ";//приглашение к вводу
		cin >> Avec[i];
		cout << Avec[i] << endl; //эхопечать
		//печать массива в одну строку
	}*/
	cout << "\tрезультат\n";
	for (i = 0; i < NMAX; i++)
		cout << Avec[i] << " ";
        cout << endl;//for i
	//в обратном порядке
	for (i = NMAX - 1; i >= 0; i--)
	cout << " " << Avec[i];
	//печать равноотстоящих от конца нечетного числа элементов
	for (i = 0; i < (NMAX-1) / 2; i++)
		cout << Avec[i] << "  " << Avec[(NMAX - 1) - i] << endl;
	cout << endl;
	//печать равноотстоящих от конца элементов для чентного числа элементов
	for (i = 0; i < (NMAX + 1) / 2; i++)
		cout << Avec[i] << "  " << Avec[(NMAX - 1) - i] << endl;
	cout << endl;
	//Найти минимальный элемент и его индекс
	//----------------------------------------------------------------------------------------------------------------------------
	int Min = 0;
	int iMin = -1;
	Min = Avec[0];
	iMin = 0;
	for (i = 1; i < NMAX; i++)
	{
		if (Avec[i] <= Min)
		{
			Min = Avec[i];
			iMin = i;
		}
	}
	cout << "min= " << Min << "\timin= " << iMin << endl;
	//вывод индексов всех минимальных элементов
	Min = Avec[0];
	iMin = 0;
	for (i = 1; i < NMAX; i++)
		if (Avec[i] < Min)
		{
			Min = Avec[i];
		}
	//печать индексов минимальных элементов
	for(i=0;i<NMAX;i++)
		if(Avec[i]==Min)
		{
			cout <<"minimal index is "<< i << endl;
		}
	//найти максимальный элемент и вывести индексы всех максимальных элементов
	int Max;
		int iMax;
	Max = Avec[0];
	iMax = 0;
	for(i=1;i<NMAX;i++)
		if(Avec[i]>Max)
		{
			Max = Avec[i];
		}//печать индексов максимальных элементов
	for(i=0;i<NMAX;i++)
		if(Avec[i]==Max)
		{
			cout <<"Largest number index is "<< i << endl;
		}
	//найти последний положительный элемент и его индекс, и если таковых элементов нет, вывести сообщение об ошибке
	int LastP = 0 ;
	int iLastP;
	for (i = 0; i<NMAX; i++)
		if(Avec[i]>LastP)
		{
			LastP = Avec[i];
			iLastP = i;

		}
	cout << "Maximal positive element is " << LastP << "\tindex is " << iLastP << endl;
	if(LastP=0)
	{
		cout << "there is no positive numbers";
	}
	//
	i = 0;
	while (i < NMAX-1)
	{
		swap(Avec[i], Avec[i + 1]);
			cout << " " << Avec[i]<<" "<<Avec[i+1];
		i+=2; }




	system("pause");
	return 0;
}