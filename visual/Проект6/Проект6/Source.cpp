#include<iostream>
using namespace std;
int main()
{
	int number;
	int quantity=1;
	cout << "enter number ";
	cin >> number;
	cout << endl;
	for(;number>=10; number /= 10)
	
		quantity++;

	cout << "quantity equals " << quantity << endl;
	system("pause");
	return 0;
}