#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
	short int nodeIndex;
	short int data;
	Node *next;
};

Node * addNode(Node *p, short int index, short int data)
{
	p = new Node();
	p->nodeIndex = index;
	p->data = data;
	return p;
}

void removeNode()
{

}

Node * addList(Node *ptr, short int data)
{
	ptr = addNode(ptr, 1, data);
	return ptr;
}

void removeList()
{

}

void displayList(Node *ptr)
{
	if (ptr == NULL)
		cout << "List is empty" << "\n\n\n\n";
	else
	{
		Node *p = ptr;
		cout << "List:" << '\n' << "Index:  ";
		while (p->next != NULL)
		{
			cout << p->nodeIndex << '\t';
			p = p->next;
		}
		cout << p->nodeIndex << '\t';
		p = ptr;
		cout << endl << "Data:   ";
		while (p->next != NULL)
		{
			cout << p->data << '\t';
			p = p->next;
		}
		cout << p->data << '\t' << "\n\n";
	}
}

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == 224)
	{
		if (num2 == 72)
			if (arrow > 49)
				num1 = --arrow;
			else
				num1 = 52;
		else if (num2 == 80)
			if (arrow < 52)
				num1 = ++arrow;
			else
				num1 = 49;
		else
			num1 = arrow;
	}

	cout << '\n' << "Add element    ";
	if (num1 == 49)
		cout << "<--";
	cout << '\n' << "Delete element ";
	if (num1 == 50)
		cout << "<--";
	cout << '\n' << "Add list       ";
	if (num1 == 51)
		cout << "<--";
	cout << '\n' << "Delete list    ";
	if (num1 == 52)
		cout << "<--";
	cout << "\n\n" << "Press Esc to exit";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = 49;
	short int position = 0, newData = 0;
	bool wrongNumber = false;

	Node *head, *tmp, *p;
	head = NULL;
	tmp = NULL;


	displayList(head);

	cout << '\n' << "Add element    <--";
	cout << '\n' << "Delete element ";
	cout << '\n' << "Add list    ";
	cout << '\n' << "Delete list ";
	cout << "\n\n" << "Press Esc to exit";

	while (choose != 27)
	{
		p = head;
		do
		{
			choose = _getch();
			if (choose == 224)
				tempChoose = _getch();
		} while ((choose != 27) && (choose != 49) && (choose != 50) && (choose != 51)
			&& (choose != 52) && (choose != 224) && (choose != 13));

		if (choose == 13)
		{
			system("cls");
			switch (arrowControl)
			{
			case 49:
				if (head == NULL)
				{
					cout << "There is no list to add new element" << endl;
					break;
				}
				cout << "Number of new element: ";
				cin >> position;
				cout << "Value of new element: ";
				cin >> newData;
				if (position == 1)
				{
					tmp = head;
					head = new Node();
					head->nodeIndex = 1;
					head->data = newData;
					head->next = tmp;
					if (tmp != NULL)
					{
						short int i = 0;
						while (tmp != NULL)
						{
							tmp->nodeIndex = position + 1 + i++;
							tmp = tmp->next;
						}
					}
					break;
				}
				if (position < 1)
				{
					cout << "\nError: wrong number" << endl;
					break;
				}
				while (p->nodeIndex <= position - 2)
				{
					if (p->next == NULL)
					{
						cout << "\nError: wrong number" << endl;
						wrongNumber = true;
						break;
					}
					p = p->next;
				}
				if (wrongNumber)
				{
					wrongNumber = false;
					break;
				}
				tmp = p->next;
				p->next = addNode(p, position, newData);
				p = p->next;
				p->next = tmp;
				if (tmp != NULL)
				{
					short int i = 0;
					while (tmp != NULL)
					{
						tmp->nodeIndex = position + 1 + i++;
						tmp = tmp->next;
					}
				}
				position = 0;
				newData = 0;
				break;
			case 50:
				if (head != NULL)
				{
					cout << "Number of element to remove it: ";
					cin >> position;
					if (position < 1)
					{
						cout << "\nError: wrong number" << endl;
						break;
					}
					if (position == 1)
					{
						tmp = head->next;
						delete(head);
						head = tmp;
						if (tmp != NULL)
						{
							short int i = 0;
							while (tmp != NULL)
							{
								tmp->nodeIndex = position + i++;
								tmp = tmp->next;
							}
						}
						break;
					}
					while (p->nodeIndex <= position - 2)
					{
						if (p->next == NULL)
						{
							cout << "\nError: wrong number" << endl;
							wrongNumber = true;
							break;
						}
						p = p->next;
					}
					if (wrongNumber)
					{
						wrongNumber = false;
						break;
					}
					tmp = p->next->next;
					delete(p->next);
					p->next = tmp;
					if (tmp != NULL)
					{
						short int i = 0;
						while (tmp != NULL)
						{
							tmp->nodeIndex = position + i++;
							tmp = tmp->next;
						}
					}
					position = 0;
				}
				break;
			case 51:
				if (head == NULL)
				{
					cout << "Value of first element: ";
					cin >> newData;
					head = addList(head, newData);
					head->next = NULL;
				}
				else
					cout << "List already exist" << "\n\n";
				break;
			case 52:
				if (head != NULL)
				{
					while (head->next != NULL)
					{
						tmp = p = head;
						while (p->next != NULL)
						{
							tmp = p;
							p = p->next;
						}
						if (p->nodeIndex != 1)
							delete(p);
						tmp->next = NULL;
					}
					delete(head);
					head = NULL;
				}
				else
					cout << "There is no list to delete it" << "\n\n";
			}
			cout << "Press any key";
			_getch();
			choose = arrowControl;
		}
		system("cls");
		displayList(head);
		arrowControl = menu(choose, tempChoose, arrowControl);
	}
	
	return 0;
}