#include<iostream>
#include<fstream>
using namespace std;
struct element
{
	int *data;
	int *index;
	int *priority;
	element *next;
	element *prev;
};

struct QueueDescriptor
{
	element *head = nullptr;
	element *tail = nullptr;
	element *current;
 	void Enqueue(int *argument, int *index, int *priority)
	{
		bool tailcatch = false;
		if (head == nullptr)
		{
			head = new element;
			head->data = argument;
			head->index = index;
			head->priority = priority;
			head->prev = nullptr;
			head->next = nullptr;
			tail = head;
		}
		else
		{
			for (current = head; current != tail ; current = current->next)
			{
				if (*(current->priority) == *(priority))
				{
					cout << "Queue already contains such priority. Addition is forbiden!" << endl;
					return;
				}
			}
			
			for (current = head; current != tail; current = current->next)
			{
				if (*(current->priority) < *(priority))//
				{
					if (current == head)
					{
						mark:
						head->prev = new element;
						current = head->prev;
						current->data = argument;
						current->index = index;
						current->priority = priority;
						current->next = head;
						head = current;
						current->prev = nullptr;
						return;
					}
					else
					{
					mark1:
						element *buffer = new element;
						element *buffer1 = new element;
						buffer = current;
						current = current->prev;
						buffer1 = current;
						current->next = new element;
						current = current->next;
						current->data = argument;
						current->index = index;
						current->priority = priority;
						current->next = buffer;
						current->prev = buffer1;
						buffer = current;
						current = current->next;
						current->prev = buffer;
						return;
					}
				}
			}
			if (current==tail)
			{
				if (*priority < *current->priority)
				{
					current->next = new element;
					current = current->next;
					current->data = argument;
					current->index = index;
					current->priority = priority;
					current->next = nullptr;
					current->prev = tail;
					tail = current;
				}
				else if (head == tail&&priority > current->priority)
					goto mark;
				else
					goto mark1;

			}
		}
	}
	void Deletequeue()
	{
		element *buffer = new element;
		current = head;
		if (!head)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		while (current->next != nullptr)
		{
			buffer = current;
			current = current->next;
			delete buffer;
		}
		cout << "Queue has been deleted!" << endl;
	}

	void PrintList()
	{

		current = head;
		if (!head)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		while (current->next != nullptr)
		{
			cout << "Priority: " << *(current->priority) << " \t\t" << "Element index: " << *(current->index) << "\t\t";
			cout << "Data: " << *(current->data) << endl;
			current = current->next;
		}
		cout << "Priority: " << *(current->priority) << " \t\t" << "Element index: " << *(current->index) << "\t\t";
		cout << "Data: " << *(current->data) << endl;
	}

	void DequeueMax()
	{
		if (!head)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		if (head->next == nullptr)
		{
			cout << "Chosen element: " << *head->data << " Index: " << *head->index << " Priority: " << *head->priority << endl;
			delete head;
			return;
		}
		element *Maximal = new element;
		Maximal = head;
		current = head;
		head = current->next;
		cout << "Chosen element: " << *Maximal->data << " Index: " << *Maximal->index << " Priority: " << *Maximal->priority << endl;
		delete Maximal;
	}
};

int main()
{
	char M = ' ';
	int size;
	QueueDescriptor list = *new QueueDescriptor;
	ifstream fin;
	fin.open("Queue.txt");
	while (M != 'B')
	{
		cout << "Press " " key for : F - creating queue with data from the file.\n P - print queue.\nD - dequeue maximal.\n E - enqueue element to queue.\n J - delete queue.\n";
		cin >> M;
		switch (M) {
		case 'F':

			fin >> size;
			for (int i = 0; i < size; i++)
			{
				int *buff = new int;
				int *indexbuff = new int;
				int *priority = new int;
				fin >> *indexbuff;
				fin >> *buff;
				fin >> *priority;
				list.Enqueue(buff, indexbuff, priority);
			}
			fin.close();
			break;
		case 'P':
			cout << "Queue:" << endl;
			list.PrintList();
			cout << "\n\n\n";
			break;
		case 'D':
			list.DequeueMax();
			break;
		case 'E':
		{
			int *pr = new int;
			int *ne = new int;
			int *ind = new int;
			cout << "Enter the element you want to enqueue: ";
			cin >> *ne;
			cout << endl;
			cout << "Index: ";
			cin >> *ind;
			cout << endl;
			cout << "Priority: ";
			cin >> *pr;
			list.Enqueue(ne, ind, pr);
		}
		break;
		case 'J':
			list.Deletequeue();
			goto end;
			break;
		}
	}
end:
	system("PAUSE");
	return 0;
}
