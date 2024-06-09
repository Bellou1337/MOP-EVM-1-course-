/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Домашнее задание: 3.2 Множества, отображения, деревья
Задача D
Дата: 22.03.2024
Исполнитель: Иванов Артём Артурович, КТбо1-7
*/


#include <iostream>
#include <vector>
#include <algorithm>


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
void customInsert(Item& , int );
/*
* Что принимает: адрес корня и вектор, в который добавляется ответ на задание
* Что делает: ищет вершины с одним сыном
* Что возвращает: ничего, функция типа void
*/
void semiDfs(Item& , vector<int>& );

int main()
{
	int node;
	Item customThree = nullptr;
	vector<int> answer;
	bool flag = 1;
	while (flag)
	{
		cin >> node;
		if (!node) flag = 0;
		else customInsert(customThree, node);
	}
	semiDfs(customThree, answer);
	sort(answer.begin(), answer.end());
	for (int search : answer) cout << search << endl;
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
void semiDfs(Item& customThree,vector<int>& vec)
{
	if (customThree == nullptr) return;

	else if (customThree->pleft == nullptr && customThree->pright != nullptr)
	{
		vec.push_back(customThree->data);
	}
	else if (customThree->pleft != nullptr && customThree->pright == nullptr)
	{
		vec.push_back(customThree->data);
	}
	semiDfs(customThree->pleft, vec);
	semiDfs(customThree->pright, vec);
}