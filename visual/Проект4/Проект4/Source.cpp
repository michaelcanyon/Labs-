/**Project Name : lastlab                                                               **
**Project Type : Win32 Console Application                                              **
**File Name : lab2.cpp                                                                  **
**Language : CPP MSVS 2017                                                              **
**Programmers : Ryisin Artem, M30 - 124bk                                               **
**Created : 20 / 12 / 17                                                                **
**Last revision : 24 / 12 / 17                                                          **
**Comment :одномерные массивы                                                           **
******************************************************************************************/
#include <iostream>

using namespace std;

int main() {

	setlocale(0, "");

	const int n = 100;

	int a[n];

	int k, i = 0;

	int per = i;

	cout << "k = ";

	cin >> k;

	for (i = 0; i < n; i++)

	{

		cout << "a[" << i << "] = ";

		cin >> per;

		if (per == 0)

			break;

		a[i] = per;

	}//end for

	for (i = 0; i<n; i++)

	{

		if (a[i] > k) {

			per = i;

			break;

		}//end if

	}//end for

	cout << per << endl;

	system("PAUSE");

	return 0;

}