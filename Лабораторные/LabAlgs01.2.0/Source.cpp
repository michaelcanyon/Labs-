#include "iostream"
#include "fstream"

struct writing
{
	int key;
	int meaning;
};



using namespace std;
void S(int counter, writing str[], ofstream &fout);
void Q(int counter, writing str[], ofstream &fout);
void T(int counter, writing str[], ofstream &fout);
void B(int counter, writing str[], ofstream &fout);
int main()
{
	string inputFile = "file.txt";
	string outputFile = "OutFileALgs1.txt";
	int buffer;
	string buff;
	int counter;

	ifstream fin;
	fin.open(inputFile);
	fin >> counter;
	writing *str = new writing[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		fin >> str[i].key;
		fin >> str[i].meaning;
	}
	fin.close();
	ofstream fout;
	fout.open(outputFile, 'a');
	S(counter, str, fout);
	Q(counter, str, fout);
	T(counter, str, fout);
	B(counter, str, fout);
	fout.close();
	system("PAUSE");
	return 0;
}

void S(int counter, writing str[], ofstream &fout)
{
	cout << "S algoritm: " << endl;
	fout << "S algoritm: \n";
	int keyL;
	int outMeaning;
	bool nullCatch = false;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	fout << "Key is " << keyL << "\n";

	int i = 0;
	for (; i < counter; i++)
	{
		if (str[i].key == keyL)
		{
			outMeaning = str[i].meaning;
			cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1<< "\n";
			fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1<< "\n";
			nullCatch = true;
		}
	}
	if (!nullCatch)
	{
		cout << "No one key found." << endl;
		fout << "No one key found." << endl;
		fout << "Pathes quantity is " << i << endl;
	}
	fout << endl;
}

void Q(int counter, writing str[], ofstream &fout)
{
	cout << "Q algoritm: " << endl;
	fout << "Q algoritm: \n";
	int keyL;
	int outMeaning;
	int keyCounter = 0;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	fout << "Key is " << keyL << "\n";
	str[counter].key = keyL;
	int i = 0;
repeatSearch:
	for (; str[i].key != keyL; i++)
	{
	}
	if (i < counter)
	{
		keyCounter++;
		outMeaning = str[i].meaning;
		cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1<< "\n";
		fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1 << "\n";
		i++;
		goto repeatSearch;
	}
	else if (keyCounter == 0)
	{
		cout << "No one key found!" << endl;
		fout << "No one key found." << endl;
		fout << "Pathes quantity is " << i<< endl;
	}
	fout << endl;
}

void T(int counter, writing str[], ofstream &fout)
{
	cout << "T algoritm: " << endl;
	fout << "T algoritm: \n";
	int keyCounter = 0;
	int keyL;
	int outMeaning;
	//сортировка
	for (int i = 0; i < counter; i++)
	{
		for (int j = i; j < counter; j++)
		{
			if (str[i].key > str[j].key)
			{
				swap(str[i].key, str[j].key);
				swap(str[i].meaning, str[j].meaning);
			}
		}
	}
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	fout << "Key is " << keyL << "\n";
	str[counter].key = keyL;

	int i = 0;
	for (; str[i].key < keyL; i++)
	{
	}
	while (str[i].key == keyL&&i < counter)
	{
		keyCounter++;
		outMeaning = str[i].meaning;
		cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1 << "\n";
		fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i+1 << "\n";
		i++;
	}
	if (keyCounter == 0)
	{
		cout << "Key not found!" << endl;
		fout << "No one key found." << endl; 
		fout << "Pathes quantity is " << i << endl;
	}
	fout << endl;
}

void B(int counter, writing str[], ofstream &fout)
{
	cout << "B algoritm: " << endl;
	fout << "B algoritm: \n";
	int start = 0;
	int end = counter;
	bool nullCatch = true;
	int dupsCounter = 0;
	int keyL;
	int outMeaning;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	fout << "Key is " << keyL << "\n";

	//сортировка
	for (int i = 0; i < counter; i++)
	{
		for (int j = i; j < counter; j++)
		{
			if (str[i].key > str[j].key)
			{
				swap(str[i].key, str[j].key);
				swap(str[i].meaning, str[j].meaning);
			}
		}
	}
	int pathCounter = 1;
	for (int i = 0; start <= end; pathCounter++)
	{
		i = (start + end) / 2;
		if (keyL < str[i].key)
		{
			end = i - 1;
			continue;
		}
		else
		{
			if (str[i].key == keyL)
			{
				outMeaning = str[i].meaning;
				nullCatch = false;
				cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << pathCounter << "\n";
				fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << pathCounter << "\n";
				while (i > 0 && str[--i].key == keyL)
				{
					pathCounter++;
					dupsCounter++;
					outMeaning = str[i].meaning;
					cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << pathCounter << "\n";
					fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i << "\n";
				}
				dupsCounter++;
				i += dupsCounter;
				while (i < counter-1 && str[++i].key == keyL)
				{
					pathCounter++;
					outMeaning = str[i].meaning;
					cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << pathCounter << "\n";
					fout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i << "\n";
				}
				return;
			}
			else
			{
				start = i + 1;
				continue;
			}
		}
	}
	if (nullCatch)
	{
		cout << "No one key found!" << endl;
		fout << "No one key found." << endl;
		fout << "Pathes quantity is " << pathCounter << endl;
	}
	fout << endl;
	return;
}