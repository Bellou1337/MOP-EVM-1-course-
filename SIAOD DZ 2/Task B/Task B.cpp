/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* Программная инженерия
* СИАОД
* Домашнее задание 1.2
* Задача E
* Исполнитель: Иванов А.А
* Группа: КТбо 1-7
* дата: 02.23.2024
*/
#include <iostream>

using namespace std;

typedef struct circleList
{
	circleList* next = nullptr;
	circleList* prev = nullptr;
	int data;

} circleList;

typedef circleList* Item;


/*
* Что принимает: Head(тип: Item),Tail(тип: Item),элемент, который нужно добавить(тип: int)
* Что делает: добавляет в конец циклического списка элемент
* Что возращает: ничего, функция типа void
*/
void customPushBack(Item& , Item& , int );
/*
* Что принимает: Head(тип: Item),Tail(тип: Item), указатель на текущий элемент(тип: Item)
* Что делает: удаляет текущий элемент в циклическом списке
* Что возвращает: ничего, функция типа void
*/
void customPop(Item& , Item& , Item& );

int main()
{
	Item Head = nullptr;
	Item Tail = Head;
	Item psearch = Head;
	int n, k;
	cin >> n >> k;
	int countElementsInList = n;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{

		customPushBack(Tail,Head,i+1);
	}
	bool flag = 1;
	psearch = Head;
	while (flag)
	{
		counter++;
		bool checker = 1;
		if (countElementsInList == 0) flag = 0;
		else if (counter == k)
		{
			counter = 0;
			countElementsInList--;
			cout << psearch->data << " ";
			customPop(psearch, Head, Tail);
			checker = 0;
		}
		if(checker) psearch = psearch->next;
		
		
	}

	return 0;
}

void customPushBack(Item& Tail,Item& Head, int element)
{
	if (Head == nullptr)
	{
		Head = new circleList;
		Head->data = element;
		Tail = Head;
		Tail->next = Head;
		Tail->prev = Head;
		Head->prev = Tail;
	}
	else
	{
		Item temp = new circleList;
		temp->data = element;
		Tail->next = temp;
		temp->next = Head;
		temp->prev = Tail;
		Tail = temp;
		Head->prev = Tail;

	}
}
void customPop(Item& psearch, Item& Head,Item& Tail)
{
	Item temp = psearch;
	psearch->prev->next = psearch->next;
	psearch->next->prev = psearch->prev;
	psearch = psearch->next;
	delete temp;
	temp = nullptr;
}

