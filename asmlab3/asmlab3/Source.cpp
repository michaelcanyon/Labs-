#include<iostream>
using namespace std;
int main()
{
	mark:
	int a,b; 
	cout << "enter any number: ";
	cin >> a;
	cout << "enter any number: ";
	cin >> b;
	if (a == b)
	{
		cout << "GGD is" << a;
		return 0;
	}
	for (;a!=b;)
	{

		if (a > b)
		{
			a -= b;
		}
		else if(b>a)
		{
			b -= a;
		}

	}
	cout << "GGD is " << a<<endl;
	cout << "Continue?(Y/N)";
	char d;
	cin >> d;
	if (d == 'Y' || d == 'y')
	{
		goto mark;
	}

		system("pause");
		return 0;


}