#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char arr[500];
	ifstream fin("file.h");
	fin.getline(arr, 500);
	cout << arr;
	fin.close();
	cout << " string: ";
		int i = 0;
		int shword;
		int newshword = 499;
		int c, b;
		int bw = 0;
		int ew = 0;
		int lengthstr=sizeof(arr)-1;
		while(i!=0)
		{
			while ((arr[i] != ' ') && (i < lengthstr))
			{
				i--;
				cout << i<<"1" << endl;

			}
			bw = i;
			while((arr[i]==' ')&&(i<lengthstr))
			{
				i--;
				cout << i <<"2"<< endl;
			}
			ew = i+1;
			shword = bw-ew;
			cout << shword << endl;
			if(shword<newshword)
			{
				newshword = shword;
				c = bw;
				b = ew;
				cout << "!!!!!" << endl;

			}

		}
		cout << "word length " << shword << endl;
		cout << "word is  ";
		for (i = c; i <= b; i++)
		{
			cout << arr[i];
		}

		system("pause");
		return 0;




}