/*
	����� ���
	��� ���
	����������� ���������
	�����
	���� 1.1: ��������� ������
	������: B
	�����������: ������ �.�, ���� 1-7

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
* ��� ���������: �������, ������� ����� �������� � ������, � "������"(Head ��������� ���� List)
* ��� ������: �������� ������� � ������ ����������� ������ � �������� ������,��������� �
* ��� �� ����� ��������� �������
* ��� ���������: ������, ������� ���� void
*/
void customPushFront(int , List& );
/*
* ��� ���������: Head(��������� ���� List)
* ��� ������: ������� ������� � ������  ����������� ������ � �������� ������, ��������� �
* ��� �� ��������� �������
* ��� ���������: ������, ������� ���� void
*/
void customPopFront(List& );
/*
* ��� ���������: Tail(��������� ���� List)
* ��� ������: ������� ������� � ����� ����������� ������ � �������� �����, ��������� ���
* ��� �� ���������� �������
* ��� ���������: ������, ������� ���� void
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