/*
	ИКТИБ ЮФУ
	МОП ЭВМ
	Программная инженерия
	СИАОД
	Тема 1.1: Структуры данных
	Задача: B
	Исполнитель: Иванов А.А, КТбо 1-7

*/

#include <iostream>
using namespace std;

typedef struct Item
{
	//next
	Item* next = nullptr;
	//prev
	Item* prev = nullptr;
	//data
	int data;


} Item;

typedef Item* List;

/*
* Что принимает: элемент, который нужно добавить в начало, и "голову"(Head указатель типа List)
* Что делает: помещает элемент в начало двусвязного списка и изменяет голову,перемещая её
* уже на новый созданный элемент
* Что возращает: ничего, функция типа void
*/
void customPushFront(int , List& );
/*
* Что принимает: Head(указатель типа List)
* Что делает: удаляет элемент в начале  двусвязного списка и изменяет голову, перемещая её
* уже на следующий элемент
* Что возращает: ничего, функция типа void
*/
void customPopFront(List& );
/*
* Что принимает: Tail(указатель типа List)
* Что делает: удаляет элемент в конце двусвязного списка и изменяет хвост, перемещая его
* уже на предыдущий элемент
* Что возращает: ничего, функция типа void
*/
void customPopBack(List& );


int main()
{
	List Head = new Item;
	List Tail = Head;
	List PointerForList = Head;
	int n;
	cin >> n;
	int operation, numbers;
	int countElementsInList = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> operation;
		if (operation == 1 || operation == 2)
		{
			cin >> numbers;
			if (operation == 1)
			{
				if (countElementsInList == 0)
				{
					Head = new Item;
					Tail = Head;
					Head->data = numbers;
					PointerForList = Head;
					countElementsInList++;
				}
				else
				{
					customPushFront(numbers,Head);
					countElementsInList++;
				}
			}
			else if (operation == 2)
			{
				if (countElementsInList == 0)
				{
					Head = new Item;
					Head->data = numbers;
					Tail = Head;
					PointerForList = Head;
					countElementsInList++;
				}
				else
				{
					if (PointerForList != nullptr)
					{
						PointerForList->next = new Item;
						PointerForList->next->data = numbers;
						PointerForList->next->prev = PointerForList;
						PointerForList = PointerForList->next;
						Tail = PointerForList;
						countElementsInList++;
					}
					else if (PointerForList == nullptr)
					{
						Head = new Item;
						PointerForList = Head;
						Head->data = numbers;
						Tail = Head;
						countElementsInList++;
					}
					
					
				}
			}
		}
		else
		{
			if (operation == 3)
			{
				cout << Head->data << " ";
				customPopFront(Head);
				countElementsInList--;
			}
			else if (operation == 4)
			{
				cout << Tail->data << " ";
				customPopBack(Tail);
				countElementsInList--;
				PointerForList = Tail;
			}
		}
	}



	return 0;
}
void customPushFront(int element, List& Head)
{
	List tempPointer = new Item;
	tempPointer->data = element;
	tempPointer->next = Head;
	tempPointer->prev = nullptr;
	Head->prev = tempPointer;
	Head = tempPointer;
}
void customPopFront(List& Head)
{
	if (Head!=nullptr && Head->next != nullptr)
	{
		List tempPointer = Head;
		Head = Head->next;
		Head->prev = nullptr;
		delete tempPointer;
	}
	else if(Head!=nullptr && Head->next == nullptr) delete Head,Head = nullptr;
}
void customPopBack(List& Tail)
{
	if (Tail!=nullptr && Tail->prev != nullptr)
	{
		List tempPointer = Tail;
		Tail = Tail->prev;
		Tail->next = nullptr;
		delete tempPointer;
	}
	else if(Tail!=nullptr && Tail->prev == nullptr) delete Tail,Tail = nullptr;
}