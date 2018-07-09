
#include <iostream> 
#include <math.h> 
using namespace std;
int main()
{
	double Eps;
	double Slag;
	double Sum;
	double Tsum;
	double Diff;
	double N;
	Sum = 0;
	setlocale(0, "Russian");
	cout << "Eps=";
	cin >> Eps;
	//входной контроль 
	if (Eps > 0)
	{
		//инициализация переменных 
		N = 1;
		Slag = 1 / ((4 * N - 1)*(4 * N + 1));
		Tsum = 0.5 - 3.1415 / 8;
		Sum = Sum + Slag;
		Diff = abs(Tsum - Sum);
		//расчет суммы ряда 
		while (Diff < 1000)
		{
			N = N + 1;
			Slag = 1 / ((4 * N - 1)*(4 * N + 1));
			Sum = Sum + Slag;
			Diff = abs(Tsum - Sum);
			cout << "N= " << N << endl << "Tsum=" << Tsum << endl << "Sum= " << Sum << endl << "Diff= " << Diff << endl;
		}//while 

		cout << "N= " << N << endl << "Tsum=" << Tsum << endl << "Sum= " << Sum << endl << "Diff= " << Diff << endl;


	}
	else
	{
		cout << "Error " << endl;
	}

	system("pause");
	return 0;
}//main