#include<iostream>
#include<fstream>
const char *FNAME = "file.txt";
using namespace std;
int main()
{
	int i = 0; const int b = 20; double arr[b];
	ifstream fin(FNAME);
	cout << "array: " << endl;
	for (i = 0; i < b; i++)
	{
		fin >> arr[i];
		cout << arr[i] << " ";

	}
	cout << endl;
	fin.close();
	double imax = 0; double imin = 9000000; double tempfirst=0, templast=0;
	int indmax; int indmin;
	for (i = 0; i < b; i++)
	{
		if(arr[i]>imax)
	{
		imax = arr[i];
		indmax = i;
	}
	if(arr[i]<imin)
	{
		imin = arr[i];
		indmin = i;
	}

	}
	cout << "maximal element " << imax << endl;
	cout << "index is " << indmax << endl;
	cout << "minimal element " << imin << endl;
	cout << "index is " << indmin << endl;
	int lastind = i - 1;
	//замена наименьшего и первого
	tempfirst = arr[0];
	arr[0] = imin;
	imin = tempfirst;
	

	//замена наибольшего и последнего 
	templast = arr[lastind];
	arr[lastind] = imax;
	imax = templast;

	cout << "result array: "<<endl;
	for(i=0;i<b;i++)
	{
		if(i==indmin)
		{
			cout << tempfirst << " ";
		}
		else if (i==indmax)
		{
			cout << templast << " " ;
		}
		else {
			cout << arr[i]<<" " ;
		}
	}
	system("pause");
	return 0;
}