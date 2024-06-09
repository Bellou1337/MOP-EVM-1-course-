/*
* ����� ���
* ��� ���
* ����������� ���������
* �����
* �������� ������� 1.2
* ������ E
* �����������: ������ �.�
* ������: ���� 1-7
* ����: 02.23.2024
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
* ��� ���������: Head(���: Item),Tail(���: Item),�������, ������� ����� ��������(���: int)
* ��� ������: ��������� � ����� ������������ ������ �������
* ��� ���������: ������, ������� ���� void
*/
void customPushBack(Item& , Item& , int );
/*
* ��� ���������: Head(���: Item),Tail(���: Item), ��������� �� ������� �������(���: Item)
* ��� ������: ������� ������� ������� � ����������� ������
* ��� ����������: ������, ������� ���� void
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

