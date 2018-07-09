#include<iostream>
using namespace std;
int main()
{
	double vec[10];//0...9
	int intArr[3];
	intArr[0] = 7;
	intArr[1] = 8;
	intArr[2] = 9;
	int i;
	//Titling and massive initialisation part1
	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cout << "uninitiolised massive" << endl;
	cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
	cout << "massive initialisation" << endl;
	cout << intArr[0] << " " << intArr[1] << " " << intArr[2] << endl;
	//part 2
	cout << "Data massive\n";
	for(i=0;i<12;i++)
	{
		cout << "month" << i + 1 << " has " << Days[i] << " days "<<endl;

}
	//part 3
	int DaysP[12] = { 31,28,31,30,31,30,31,31,30};
	for (i = 0; i < 12; i++)
	{
		cout << "month" << i + 1 << " has " << DaysP[i] << " days " << endl;
	}
	//part 4
	int DaysU[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cout << "Unknown size away DaysU" << endl;
	for(i=0;i<sizeof DaysU/sizeof(int);i++)
		cout << "month" << i + 1 << " has " << DaysU[i] << " days " << endl;
	//part 5
	int Daysk[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cout << "Data massive\n";
	for (i = 0; i < 22; i++)
	{
		cout << "month" << i + 1 << " has " << Daysk[i] << " days " << endl;
	}



    
	system("color F2");
	system("PAUSE");
	return 0;

	}


