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

void addNode()
{

}

void deleteNode()
{

}

void addList()
{

}

void deleteList()
{

}

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == 224)
	{
		if (num2 == 72)
			if (arrow > 49)
				num1 = --arrow;
			else
				num1 = 52; //num1 = arrow;
		else if (num2 == 80)
			if (arrow < 52)
				num1 = ++arrow;
			else
				num1 = 49; //num1 = arrow;
		else
			num1 = arrow;
	}

	cout << '\n' << "Add node    ";
	if (num1 == 49)
		cout << "<--";
	cout << '\n' << "Delete node ";
	if (num1 == 50)
		cout << "<--";
	cout << '\n' << "Add list    ";
	if (num1 == 51)
		cout << "<--";
	cout << '\n' << "Delete list ";
	if (num1 == 52)
		cout << "<--";
	cout << '\n' << '\n' << "Press Esc to exit";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = 49;
	short int nodeCounter = 1;

	Node *p;
	Node Head;
	Head.nodeIndex = 1;
	Head.data = pow(Head.nodeIndex, 2);
	Head.next = NULL;
	p = &Head;
	cout << "Index:  ";
	for (int i = 0; i < nodeCounter; i++)
	{
		cout << p->nodeIndex << '\t';
		p = p->next;
	}
	cout << endl << "Data:   ";
	p = &Head;
	for (int i = 0; i < nodeCounter; i++)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl << endl;
	p = &Head;

	//-----------------------------DELETE IT-----------------------------
	Node a, b, c, d;
	Head.next = &a;
	nodeCounter = 5;
	a.nodeIndex = 2;
	a.data = pow(a.nodeIndex, 2);
	a.next = &b;
	b.nodeIndex = 3;
	b.data = pow(b.nodeIndex, 2);
	b.next = &c;
	c.nodeIndex = 4;
	c.data = pow(c.nodeIndex, 2);
	c.next = &d;
	d.nodeIndex = 5;
	d.data = pow(d.nodeIndex, 2);
	d.next = NULL;
	//-------------------------------------------------------------------


	cout << '\n' << "Add node    ";
	cout << "<--";
	cout << '\n' << "Delete node ";
	cout << '\n' << "Add list    ";
	cout << '\n' << "Delete list ";
	cout << '\n' << '\n' << "Press Esc to exit";

	while (choose != 27)
	{
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
				//clockwiseToTheCenter(M, N, matrix);
				break;
			case 50:
				//counterclockwiseToTheCenter(M, N, matrix);
				break;
			case 51:
				//clockwiseFromTheCenter(M, N, matrix);
				break;
			case 52:
				//counterclockwiseFromTheCenter(M, N, matrix);
			default:;
			}
			/*for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
					printf("%5d", matrix[i][j]);
				cout << '\n' << '\n';
			}*/
			cout << "Press any key";
			_getch();
			choose = arrowControl;
		}
		system("cls");
		cout << "Index:  ";
			for (int i = 0; i < nodeCounter; i++)
			{
				cout << p->nodeIndex << '\t';
				p = p->next;
			}
		cout << endl << "Data:   ";
		p = &Head;
		for (int i = 0; i < nodeCounter; i++)
		{
			cout << p->data << '\t';
			p = p->next;
		}
		cout << endl << endl;
		p = &Head;
		arrowControl = menu(choose, tempChoose, arrowControl);
	}

	return 0;
}

/*
#include "stdafx.h"
#include <iostream>
using namespace std;
struct DoubleList //описание узла списка
{
int data; //информационное поле
DoubleList *next; //указатель на следующий элемент
DoubleList *prev; //указатель на предыдущий элемент
};
DoubleList *head; //указатель на первый элемент списка
//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void AddList(int value, int position)
{
DoubleList *node=new DoubleList; //создание нового элемента
node->data=value; //присвоение элементу значения
if (head==NULL) //если список пуст
{
node->next=node; //установка указателя next
node->prev=node; //установка указателя prev
head=node; //определяется голова списка
}
else
{
DoubleList *p=head;
for(int i=position; i>1; i--) p=p->next;
p->prev->next=node;
node->prev=p->prev;
node->next=p;
p->prev=node;
}
cout<<"\nЭлемент добавлен...\n\n";
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
int DeleteList(int position)
{
if (head==NULL) { cout<<"\nСписок пуст\n\n"; return 0; }
if (head==head->next)
{
delete head;
head=NULL;
}
else
{
DoubleList *a=head;
for (int i=position; i>1; i--) a=a->next;
if (a==head) head=a->next;
a->prev->next=a->next;
a->next->prev=a->prev;
delete a;
}
cout<<"\nЭлемент удален...\n\n";
}
//*************************ВЫВОД СПИСКА*************************
void PrintList()
{
if (head==NULL) cout<<"\nСписок пуст\n\n";
else
{
DoubleList *a=head;
cout<<"\nЭлементы списка: ";
do
{
cout<<a->data<<" ";
a=a->next;
} while(a!=head); cout<<"\n\n";
}
}
//************************ГЛАВНАЯ ФУНКЦИЯ************************
void main()
{
setlocale(LC_ALL, "Rus");
int value, position, x;
do
{
cout<<"1. Добавить элемент"<<endl;
cout<<"2. Удалить элемент"<<endl;
cout<<"3. Вывести список"<<endl;
cout<<"0. Выйти"<<endl;
cout<<"\nНомер операции > "; cin>>x;
switch (x)
{
case 1:
cout<<"Значение > "; cin>>value;
cout<<"Позиция > "; cin>>position;
AddList(value, position); break;
case 2:
cout<<"Позиция > "; cin>>position;
DeleteList(position); break;
case 3: PrintList(); break;
}
} while (x!=0);
}
*/