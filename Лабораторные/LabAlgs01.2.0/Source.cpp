#include "iostream"
#include "fstream"

struct writing
{
	int key;
	int meaning;
};

void S(int counter, writing str[]);
void Q(int counter, writing str[]);
void T(int counter, writing str[]);
void B(int counter, writing str[], int start);

using namespace std;
int main()
{
	int buffer;
	string buff;
	int counter;

	ifstream fin;
	fin.open("file.txt");
	fin >> counter;
	writing *str = new writing[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		fin >> str[i].key;
		fin >> str[i].meaning;
	}

	fin.close();
	S(counter, str);
	Q(counter, str);
	T(counter, str);
	B(counter, str, 0);

	system("PAUSE");
	return 0;
}

void S(int counter, writing str[])
{
	int keyL;
	int outMeaning;
	bool nullCatch = false;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	int i = 0;
	for (; i < counter; i++)
	{
		if (str[i].key == keyL)
		{
			outMeaning = str[i].meaning;
			nullCatch = true;
			break;
		}
	}
	if (!nullCatch)
	{
		cout << "No matches found.";
	}
	else
	{
		cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i;
	}
}

void Q(int counter, writing str[])
{
	int keyL;
	int outMeaning;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	str[counter].key = keyL;
	int i = 0;
	for (; str[i].key != keyL; i++)
	{
	}
	if (i < counter - 1)
	{
		outMeaning = str[i].meaning;
		cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i;
	}
	else
	{
		cout << "Key not found!" << endl;;
	}

}

void T(int counter, writing str[])
{
	int keyL;
	int outMeaning;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;
	str[counter].key = keyL;

	//сортировка
	for (int i = 0; i < counter; i++)
	{
		for (int j = i; j < counter; j++)
		{
			if (str[i].key > str[j].key)
				swap(str[i].key, str[j].key);
		}
	}
	int i = 0;
	for (; str[i].key < keyL; i++)
	{
	}
	if (str[i].key == keyL&&i < counter)
	{
		outMeaning = str[i].meaning;
		cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << i;
	}
	else
	{
		cout << "Key not found!" << endl;;
	}
}

void B(int counter, writing str[], int start)
{
	int end = counter;
	bool nullCatch = true;
	int keyL;
	int outMeaning;
	cout << "Enter the key you want to look for: ";
	cin >> keyL;

	//сортировка
	for (int i = 0; i < counter; i++)
	{
		for (int j = i; j < counter; j++)
		{
			if (str[i].key > str[j].key)
				swap(str[i].key, str[j].key);
		}
	}

	for (int i = 0, pathCounter = 1; start <= end; pathCounter++)
	{
		i = (start + end) / 2;
		if (keyL < str[i].key)
		{
			end = i - 1;
			continue;
		}
		else
		{
			if (keyL == str[i].key)
			{
				outMeaning = str[i].meaning;
				nullCatch = false;
				cout << "Match found! Key is " << keyL << " meaning is " << outMeaning << "\n" << "Pathes quantity is " << pathCounter;
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
		cout << "key not found!" << endl;
		return;
	}
}