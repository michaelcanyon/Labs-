#include<iostream>
using namespace std;
int main()
{
	double eps = 1 / (10 ^ 5);
	double b, a, h, i, n, x, y, sum1, sum2,sumr;
	double diff;
	cout << "ener a: ";
	cin >> a;
	cout << "enter b: ";
	cin >> b;
	if (a > b)
	{
		double front;
		front = a;
		a = b;
		b = front;
	}
	if (a == b)
	{
		cout << "No interval. Integral doesn't exist" << endl;
	}
	diff = 1;
		for(n=1;diff>eps;n++)
		{
			h = (b - a) / n;
			sum1 = 0;
			for (i = 1; i <= n; i++)
			{
				x = a + i*h;
				sum1 = sum1 + x;

			}
			n=n*2;
			h = (b - a) / n;
			sum2 = 0;
			for (i = 1; i <= n; i++)
			{
				x = a + i*h;
				sum2 = sum2 + x;

			}
			if (sum2 == sum1)
			{
				cout << "An error occured. Sum2 can't be equal Sum1" << endl;
			}
			
				diff = sum2 - sum1;

		}
	cout << "n= " << n << endl;
    h = (b - a) / n;
	sumr = 0;
	for(i=1;i<n;i++)
	{
		x = a + i*h;
		sumr = sumr + x;
	}
	y = h*sumr;
	cout << "integral meaning y= " << y << endl;
	system("pause");
	return 0;
}

