/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* Программная инженерия
* СИАОД
* Домашнее задание 1.2
* Задача F
* Исполнитель: Иванов А.А
* Группа: КТбо 1-7
* дата: 02.23.2024
*/
#include <iostream>

using namespace std;

typedef struct Item
{
	Item* next = nullptr;
	Item* prev = nullptr;
	int data;


} Item;

typedef Item* List;

/*
* Что принимает: Head(тип: Item),Tail(тип: Item),элемент, который нужно добавить(тип: int)
* Что делает: добавляет в конец циклического списка элемент
* Что возращает: ничего, функция типа void
*/
void customPushBack(List& , List& , int);
/*
* Что принимает: Head(тип: List)
* Что делает: удаляет элемент с начала списка
* Что возвращает: ничего, функция типа void
*/
void customPopFront(List&);
/*
* Что принимает: указатель на текущий элемент(тип: List),элемент, который нужно добавить(тип: int),Head(тип:List),Tail(тип:List)
* Что делает: добавляет элемент после текущего
* Что возвращает: ничего, функция типа void
*/
void customInsert(List&, int,List&,List&);

int main()
{
	List Head = nullptr;
	List Tail = Head;
	List psearch = Head;

	int n;
	cin >> n;
	char space;
	cin.get(space);
	int counter = 0;
	psearch = Head;
	for (int i = 0; i < n; i++)
	{
		char simvol;
		cin >> simvol;
		if (simvol == '+')
		{
			int element;
			cin >> element;
			counter++;
			customPushBack(Tail,Head,element);
			if (counter % 2 != 0 && Head->next != nullptr)
			{
				psearch = psearch->next;
			}
			else if(counter%2!=0 && Head->next==nullptr) psearch = Head;
			
		}
		else if (simvol == '-')
		{
			cout << Head->data << endl;
			customPopFront(Head);
			counter--;
			if (counter % 2 != 0 && Head->next != nullptr)
			{
				psearch = psearch->next;
			}
			else if (counter % 2 != 0 && Head->next == nullptr) psearch = Head;
		}
		else if (simvol == '*')
		{
			int element;
			cin >> element;
			customInsert(psearch,element,Head,Tail);
			counter++;
			if (counter % 2 != 0 && Head->next != nullptr)
			{
				psearch = psearch->next;
			}
			else if (counter % 2 != 0 && Head->next == nullptr) psearch = Head;
		}
	}



	return 0;
}

void customPushBack(List& Tail,List&Head,int element)
{
	if (Head == nullptr)
	{
		Head = new Item;
		Head->data = element;
		Head->prev = nullptr;
		Tail = Head;
		Tail->next = nullptr;
	}
	else
	{
		List temp = new Item;
		temp->data = element;
		temp->prev = Tail;
		Tail->next = temp;
		temp->next = nullptr;
		Tail = temp;
	}
}
void customPopFront(List& Head)
{
	if (Head->next == nullptr)
	{
		delete Head;
		Head = nullptr;
	}
	else
	{
		List temp = Head;
		Head = Head->next;
		Head->prev = nullptr;
		delete temp;
		temp = nullptr;
	}

}
void customInsert(List& psearch,int element,List& Head,List& Tail)
{
	if (Head == nullptr)
	{
		Head = new Item;
		Head->data = element;
		Tail = Head;
	}
	else if(Head!=nullptr && Head->next != nullptr)
	{
		List temp = new Item;
		temp->data = element;
		psearch->next->prev = temp;
		temp->next = psearch->next;
		psearch->next = temp;
	}
	else if(Head!=nullptr && Head->next == nullptr)
	{
		List temp = new Item;
		temp->data = element;
		temp->prev = Head;
		Head->next = temp;
		Tail = temp;
	}




}