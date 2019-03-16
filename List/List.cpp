#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

const short SPEC_KEY = 224;
const short UP_ARROW_KEY = 72;
const short DOWN_ARROW_KEY = 80;
const short LEFT_ARROW_KEY = 75;
const short RIGHT_ARROW_KEY = 77;
const short ENTER_KEY = 13;
const short ESC_KEY = 27;
const short SPACE_KEY = 32;
const short BACKSPACE_KEY = 8;
const short NUM_0_KEY = 48;
const short NUM_1_KEY = 49;
const short NUM_2_KEY = 50;
const short NUM_3_KEY = 51;
const short NUM_4_KEY = 52;
const short NUM_5_KEY = 53;
const short NUM_6_KEY = 54;
const short NUM_7_KEY = 55;
const short NUM_8_KEY = 56;
const short NUM_9_KEY = 57;

struct Node
{
	short int nodeIndex;
	short int data;
	Node *next;
};

Node * addNode(Node *ptr, short int index, short int data)
{
	ptr = new Node();
	ptr->nodeIndex = index;
	ptr->data = data;
	return ptr;
}

Node * addElement(Node *ptr)
{
	Node *tmp, *p;
	short int position = 0, newData = 0;

	p = ptr;
	cout << "Number of new element: ";
	cin >> position;
	cout << "Value of new element: ";
	cin >> newData;
	if (position == 1)
	{
		tmp = ptr;
		ptr = new Node();
		ptr->nodeIndex = 1;
		ptr->data = newData;
		ptr->next = tmp;
		if (tmp != NULL)
		{
			short int i = 0;
			while (tmp != NULL)
			{
				tmp->nodeIndex = position + 1 + i++;
				tmp = tmp->next;
			}
		}
		return ptr;
	}
	if (position < 1)
	{
		cout << "\nError: wrong number" << endl;
		return ptr;
	}
	while (p->nodeIndex <= position - 2)
	{
		if (p->next == NULL)
		{
			cout << "\nError: wrong number" << endl;
			return ptr;
		}
		p = p->next;
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
	return ptr;
}

Node * removeNode(Node *ptr)
{
	Node *tmp, *p;
	short int position = 0;
	bool wrongNumber = false;

	p = ptr;
	cout << "Number of element to remove it: ";
	cin >> position;
	if (position < 1)
	{
		cout << "\nError: wrong number" << endl;
		return ptr;
	}
	if (position == 1)
	{
		tmp = ptr->next;
		delete(ptr);
		ptr = tmp;
		if (tmp != NULL)
		{
			short int i = 0;
			while (tmp != NULL)
			{
				tmp->nodeIndex = position + i++;
				tmp = tmp->next;
			}
		}
		return ptr;
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
	if (wrongNumber || (p->next == NULL))
	{
		if (!wrongNumber)
			cout << "\nError: wrong number" << endl;
		wrongNumber = false;
		return ptr;
	}
	if (p->next != NULL)
		tmp = p->next->next;
	else
		tmp = NULL;
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
	return ptr;
}

Node * addList(Node *ptr, short int data)
{
	ptr = addNode(ptr, 1, data);
	return ptr;
}

Node * removeList(Node *ptr)
{
	Node *tmp, *p;
	while (ptr->next != NULL)
	{
		tmp = p = ptr;
		while (p->next != NULL)
		{
			tmp = p;
			p = p->next;
		}
		if (p->nodeIndex != 1)
			delete(p);
		tmp->next = NULL;
	}
	delete(ptr);
	return NULL;
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
	if (num1 == SPEC_KEY)
	{
		if (num2 == UP_ARROW_KEY)
			if (arrow > NUM_1_KEY)
				num1 = --arrow;
			else
				num1 = NUM_4_KEY;
		else if (num2 == DOWN_ARROW_KEY)
			if (arrow < NUM_4_KEY)
				num1 = ++arrow;
			else
				num1 = NUM_1_KEY;
		else
			num1 = arrow;
	}

	cout << '\n' << "Add element    ";
	if (num1 == NUM_1_KEY)
		cout << "<--";
	cout << '\n' << "Remove element ";
	if (num1 == NUM_2_KEY)
		cout << "<--";
	cout << '\n' << "Add list       ";
	if (num1 == NUM_3_KEY)
		cout << "<--";
	cout << '\n' << "Remove list    ";
	if (num1 == NUM_4_KEY)
		cout << "<--";
	cout << "\n\n" << "Press Esc to exit";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = NUM_1_KEY;
	short int newData = 0;
	Node *head;
	head = NULL;

	displayList(head);
	cout << '\n' << "Add element    <--";
	cout << '\n' << "Remove element ";
	cout << '\n' << "Add list       ";
	cout << '\n' << "Remove list    ";
	cout << "\n\n" << "Press Esc to exit";

	while (choose != ESC_KEY)
	{
		do
		{
			choose = _getch();
			if (choose == SPEC_KEY)
				tempChoose = _getch();
		} while ((choose != ESC_KEY) && (choose != NUM_1_KEY) && (choose != NUM_2_KEY) && (choose != NUM_3_KEY)
			&& (choose != NUM_4_KEY) && (choose != SPEC_KEY) && (choose != ENTER_KEY));

		if (choose == ENTER_KEY)
		{
			system("cls");
			switch (arrowControl)
			{
			case NUM_1_KEY:
				if (head == NULL)
				{
					cout << "There is no list to add new element" << endl;
					break;
				}
				head = addElement(head);
				break;
			case NUM_2_KEY:
				if (head != NULL)
					head = removeNode(head);
				break;
			case NUM_3_KEY:
				if (head == NULL)
				{
					cout << "Value of first element: ";
					cin >> newData;
					head = addList(head, newData);
					head->next = NULL;
				}
				else
					cout << "List already exists" << "\n\n";
				break;
			case NUM_4_KEY:
				if (head != NULL)
					head = removeList(head);
				else
					cout << "There is no list to remove it" << "\n\n";
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