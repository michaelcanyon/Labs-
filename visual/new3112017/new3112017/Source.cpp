#include<iostream>

using namespace std;
int main()
{//massive titling
	setlocale(0, "RUSSIAN");
	const int NMAX = 9;//massive size
    int Avec[NMAX] = { 1,8,9,3,9,4,5,1,7 };
	int i;//cicle paramentr
	//massive entrance
	/*cout << "������� " << NMAX << " ��������� �������" << endl;
	for (i = 0; i < NMAX; i++)
	{
		cout << " AVec[" << i << "]= ";//����������� � �����
		cin >> Avec[i];
		cout << Avec[i] << endl; //���������
		//������ ������� � ���� ������
	}*/
	cout << "\t���������\n";
	for (i = 0; i < NMAX; i++)
		cout << Avec[i] << " ";
        cout << endl;//for i
	//� �������� �������
	for (i = NMAX - 1; i >= 0; i--)
	cout << " " << Avec[i];
	//������ �������������� �� ����� ��������� ����� ���������
	for (i = 0; i < (NMAX-1) / 2; i++)
		cout << Avec[i] << "  " << Avec[(NMAX - 1) - i] << endl;
	cout << endl;
	//������ �������������� �� ����� ��������� ��� �������� ����� ���������
	for (i = 0; i < (NMAX + 1) / 2; i++)
		cout << Avec[i] << "  " << Avec[(NMAX - 1) - i] << endl;
	cout << endl;
	//����� ����������� ������� � ��� ������
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
	//����� �������� ���� ����������� ���������
	Min = Avec[0];
	iMin = 0;
	for (i = 1; i < NMAX; i++)
		if (Avec[i] < Min)
		{
			Min = Avec[i];
		}
	//������ �������� ����������� ���������
	for(i=0;i<NMAX;i++)
		if(Avec[i]==Min)
		{
			cout <<"minimal index is "<< i << endl;
		}
	//����� ������������ ������� � ������� ������� ���� ������������ ���������
	int Max;
		int iMax;
	Max = Avec[0];
	iMax = 0;
	for(i=1;i<NMAX;i++)
		if(Avec[i]>Max)
		{
			Max = Avec[i];
		}//������ �������� ������������ ���������
	for(i=0;i<NMAX;i++)
		if(Avec[i]==Max)
		{
			cout <<"Largest number index is "<< i << endl;
		}
	//����� ��������� ������������� ������� � ��� ������, � ���� ������� ��������� ���, ������� ��������� �� ������
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