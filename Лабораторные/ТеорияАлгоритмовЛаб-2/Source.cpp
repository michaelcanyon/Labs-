#include<iostream>
#include<fstream>
using namespace std;
struct element
{
	double *data;
	int *index;
	element *next;
};

struct ListDescriptor
{
	element *head=nullptr;
	element *current;


	void AddElement(double *argument, int *index)
	{

		if (head == nullptr)
		{
			head = new element;
			head->data= argument;
			head->index = index;
			head->next = nullptr;

		}
		else
		{
			current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new element;
			current = current->next;
			current->data = argument;
			current->index = index;
			current->next = nullptr;
		}
	}

	void DeleteList()
	{
		element *buffer=new element;
		current = head;
		while (current->next != nullptr)
		{
			buffer = current;
			current = current->next;
			delete buffer;
			
		}
		cout << "List has been deleted!" << endl;
	}

	void PrintList()
	{

		current = head;
		while (current->next != nullptr)
		{
			cout << "Element index: " << *(current->index) <<"\t\t";
			cout << "Data: " << *(current->data) << endl;
			current = current->next;
		}
	}

	void SearchMaximal()
	{
		int inputsCounter = 1;
		double *maximalElement=new double;
		int *ELIndex = new int;
		maximalElement = head->data;
		current = head;
		while (current->next != nullptr)
		{
			current = current->next;
			if (*(current->data) > *maximalElement)
			{
				maximalElement = current->data;
				ELIndex = current->index;
			}
			inputsCounter++;
		}
		cout << "Maximal element: " << *(maximalElement) << "\t\t" << "Index: " << *(ELIndex) << endl;
		cout << "Inputs quantity: " << inputsCounter << endl;
	}

	int InsertElement(double *data, int AfterTheIndex, int *newIndex)
	{
		int inputsCounter = 0;
		bool flag = false;
		current = head;
		while (current->next != nullptr&&*(current->index)!=AfterTheIndex)
		{
			current = current->next;
		}
		if (*(current->index) == AfterTheIndex)
			flag = true;
		if (!flag)
		{
			cout << ("Wrong index! Function is unable to insert element after it.") << endl;
			return -1;
		}

		//Вставка
		current = head;
		while (*(current->index)!=AfterTheIndex)
		{
			current = current->next;
			inputsCounter++;
		}

		element *buffEL = new element;
		buffEL->next = current->next;//только поменять адресс
		current->next = new element;
		current = current->next;
		current->data = data;
		current->index = newIndex;
		current->next = buffEL->next;
		cout << "Inputs quantity: " << inputsCounter << endl;
		return 0;
	}

	int DeleteElement(int ElementIndex)
	{
		int inputsCounter = 0;
		current = head;
		element *buffAdress = new element;
		while (current->next != nullptr&&*(current->index) != ElementIndex)
		{
			current = current->next;
		}
		if (*(current->index) == ElementIndex)
			buffAdress = current;
		else
		{
			cout<<"List doesn't contain such index."<<endl;
			return -1;
		}
		//Удаление
		current = head;
		if (buffAdress == head)
		{
			current = buffAdress->next;
			head = current;
			delete buffAdress;
			inputsCounter++;
			cout << "Inputs quantity: " << inputsCounter << endl;
			return 0;

		}
		while (current->next != buffAdress)
		{
			current = current->next;
			inputsCounter++;
		}
		
		current->next = buffAdress->next;
		delete buffAdress;
		cout << "Inputs quantity: " << inputsCounter << endl;
		return 0;
	}
	};
int main()
{
	int ErrorCatch;
	ifstream fin;
	fin.open("List.txt");
	int size;
	double elementBuffer;
	fin >> size;
	ListDescriptor list=*new ListDescriptor;
	for (int i = 0; i <= size; i++)
	{
		double *buff = new double;
		int *indexbuff = new int;
		fin >> *indexbuff;
		fin >> *buff;
		list.AddElement(buff, indexbuff);
	}
	fin.close();
	cout << "LIST:" << endl;
	list.PrintList();
	cout << "\n\n\n";
	cout << "enter the element index you want to delete:";
	int removableIND;
	cin >> removableIND;
	ErrorCatch=list.DeleteElement(removableIND);
	if (ErrorCatch <0 )
	{}
	else
	list.PrintList();
	cout << "\n\n\n";

	cout << "Looking for maximal:" << endl;
	list.SearchMaximal();
	cout << "\n\n\n";

	int indexAfter;
	cout << "Enters the index of the list, where you want to put new element: ";
	cin >> indexAfter;
	cout << endl;
	cout << "enter element meaning you want to add: ";
	double *insert = new double;
	cin >> *insert;
	cout << endl;
	cout << "enter index of the new element: ";
	int *newIndex = new int;
	cin >> *newIndex;
	cout << endl;
	ErrorCatch=list.InsertElement(insert ,indexAfter,newIndex);
	if (ErrorCatch < 0)
	{}
	else
	list.PrintList();
	list.DeleteList();
	
	system("PAUSE");
	return 0;
}