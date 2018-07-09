#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char *file = "file.h";
	char arr[500];
	ifstream fin("file");
	fin.getline(arr, 500);
	fin.close();//конец чтения файла
	cout << arr << endl;

	int i = 0;
	int lengthsw = 499;
	int a, lengthow, c;
	int lenstr = sizeof(arr) - 1;
	
		while((arr[i]!='\0')&&(i<lenstr))
		{
			while(arr[i]==' ')
		{
			i++;
		}
			while(arr[i]!=' ')
			{
				i++;
			}
			lengthow = lenstr - (lenstr - i);
			if (lengthow<lengthsw)
			{
				lengthsw = lengthow;
				c = i;
			}

	    }
		cout << "shortest word is ";
		int t = c + lengthsw;
		for(i=c;i<=t;i++)
		{
			cout << arr[i];
		}
		system("pause");
		return 0;

}
	