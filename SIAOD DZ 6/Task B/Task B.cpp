/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Домашнее задание: 3.2 Множества, отображения, деревья
Задача E
Дата: 22.03.2024
Исполнитель: Иванов Артём Артурович, КТбо1-7
*/

?#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/*
* Что содержит: указатели на левого и правого сына, номер вершины
*/
typedef struct Three
{
	Three* pleft = nullptr;
	Three* pright = nullptr;
	int data;


}Three;

typedef Three* Item;

/*
* Что принимает: адрес корня и новую вершину(которую мы хотим добавить)
* Что делает: добавляет новый элемент в дерево
* Что возвращает: ничего, функция типа void
*/
void customInsert(Item&, int);
/*
* Что принимает: адрес корня , первый максимум, второй максимум
* Что делает: ищет самых два максимальных элемента
* Что возвращает: ничего, функция типа void
*/
void searchMax(Item&, int&, int&);

int main()
{
	int node;
	Item customThree = nullptr;
	bool flag = 1;
	while (flag)
	{
		cin >> node;
		if (!node) flag = 0;
		else customInsert(customThree, node);
	}
	int firstMax = INT_MIN;
	int secondMax = INT_MIN;
	searchMax(customThree, firstMax, secondMax);
	cout << secondMax << endl;

}

void customInsert(Item& customThree, int value)
{
	if (customThree == nullptr)
	{
		customThree = new Three;
		customThree->data = value;
	}
	else if (customThree != nullptr)
	{
		//значит мы двигаемся влево
		if (customThree->data > value)
		{
			customInsert(customThree->pleft, value);
		}
		// иначе двигаемся вправо
		else if (customThree->data < value)
		{
			customInsert(customThree->pright, value);
		}
	}

}
void searchMax(Item& customThree, int& firstMax, int& secondMax)
{
	if (customThree == nullptr) return;

	else if (customThree->data > firstMax)
	{
		secondMax = firstMax;
		firstMax = customThree->data;
	}
	else if (customThree->data < firstMax && customThree->data > secondMax)
	{
		secondMax = customThree->data;
	}
	searchMax(customThree->pleft, firstMax, secondMax);
	searchMax(customThree->pright, firstMax, secondMax);
}