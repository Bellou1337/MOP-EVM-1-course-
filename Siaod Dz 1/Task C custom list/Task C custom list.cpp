/*
	ИКТИБ ЮФУ
	МОП ЭВМ
	Программная инженерия
	СИАОД
	Тема 1.1: Структуры данных
	Задача: C
	Исполнитель: Иванов А.А, КТбо 1-7

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#define arraySize 100009

typedef struct Item
{
	Item* next = nullptr;
	Item* prev = nullptr;
	char data;

} Item;

typedef Item* List;

/*
* Что принимает: элемент, который нужно добавить в конец, и "хвост"(Tail указатель типа List)
* Что делает: помещает элемент в конец двусвязного списка и изменяет хвост,перемещая его
* уже на новый созданный элемент
* Что возращает: ничего, функция типа void
*/
void customPushBack(char, List&);
/*
* Что принимает: Tail(указатель типа List)
* Что делает: удаляет элемент в конце двусвязного списка и изменяет хвост, перемещая его
* уже на предыдущий элемент
* Что возращает: ничего, функция типа void
*/
void customPopBack(List&);

int main()
{
	//объявление листа
	List Head = new Item;
	List Tail = Head;
	//ввод
	char arrayForWords[arraySize] = { '\n' };
	bool flag = 1;
	cin.getline(arrayForWords, arraySize);

	if (arrayForWords[0] == ')' || arrayForWords[0] == ']'
		|| arrayForWords[0] == '}') flag = 0;

	bool checker = 0;

	int countOpen = 0;
	int countClose = 0;
	int checkerForList = 0;
	for (int i = 0; i < strlen(arrayForWords) && flag; i++)
	{
		if (arrayForWords[i] == '(' || arrayForWords[i] == '['
			|| arrayForWords[i] == '{')
		{
			if (checkerForList == 0)
			{
				Head = new Item;
				Tail = Head;
				Head->data = arrayForWords[i];
				countOpen++;
				checkerForList++;
			}
			else
			{
				customPushBack(arrayForWords[i], Tail);
				countOpen++;
				checkerForList++;
			}
		}
		else if (arrayForWords[i] == ')' || arrayForWords[i] == ']'
			|| arrayForWords[i] == '}')
		{
			checker = 1;
			
			if (arrayForWords[i] == ')')
			{
				if (checkerForList > 0)
				{
					if (Tail->data == '(')
					{
						customPopBack(Tail);
						arrayForWords[i] = '+';
						countClose++;
						checkerForList--;
					}
					else flag = 0;
				}
				else flag = 0;
			}
			else if (arrayForWords[i] == ']' )
			{
				if(checkerForList > 0)
				{
					if (Tail->data == '[')
					{
						customPopBack(Tail);
						arrayForWords[i] = '+';
						countClose++;
						checkerForList--;
					}
					else flag = 0;
				}
				
				else flag = 0;
			}
			else if (arrayForWords[i] == '}' )
			{
				if (checkerForList > 0)
				{
					if (Tail->data == '{')
					{
						customPopBack(Tail);
						arrayForWords[i] = '+';
						countClose++;
						checkerForList--;
					}
					else flag = 0;
				}
				
				else flag = 0;
			}
		}
	}

	if (flag && checker && (countOpen == countClose)) cout << "yes";
	else cout << "no";
	return 0;
}

void customPushBack(char element, List& Tail)
{
	List tempPointer = new Item;
	tempPointer->data = element;
	tempPointer->next = nullptr;
	tempPointer->prev = Tail;
	Tail->next = tempPointer;
	Tail = tempPointer;
}
void customPopBack(List& Tail)
{
	if (Tail != nullptr && Tail->prev != nullptr)
	{
		List tempPointer = Tail;
		Tail = Tail->prev;
		Tail->next = nullptr;
		delete tempPointer;
	}
	else if (Tail != nullptr && Tail->prev == nullptr) delete Tail, Tail = nullptr;
}