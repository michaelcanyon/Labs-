#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int nNcelsius;
	int nNfactor;
	int nFahrenheit;
	cout << "nNcelsius=";
	cin >> nNcelsius;
	nNfactor = 212 - 32;
	nFahrenheit = nNfactor*nNcelsius / 100 + 32;
	cout << ("nFahrenheit=");
	cout << nFahrenheit << endl;
	system("pause");
	return 0;
}