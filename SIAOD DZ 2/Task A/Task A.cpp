/*
* ����� ���
* ��� ���
* ����������� ���������
* �����
* �������� ������� 1.2 
* ������ D
* �����������: ������ �.�
* ������: ���� 1-7
* ����: 02.23.2024
*/

#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <string>

using namespace std;


typedef struct Stack
{
	Stack* prev = nullptr;
	int data;

}Stack;

typedef Stack* Item;


/*
��� ������: ��������� � ���� �������(� �����)
��� ��������� �� ����: ����� ���������(���: Item)(����� �����) � �����, ������� ����� ��������(���: int)
��� ����������: ������, ������� ���� void
*/
void customPush(Item& , int );
/*
* ��� ������: ������� ������� � �������� �����
* ��� ��������� �� ����: �����(���: Item)
* ��� ����������: ������, ������� ���� void
*/
void customPop(Item& );

int main()
{
	string strForStack;
	getline(cin, strForStack);
	//������������� �����
	Item Tail = nullptr;
	string createNums;
	int countElementsInString = 0;
	for (int i = 0; i < strForStack.size(); i++)
	{
		if (strForStack[i] != '+' && strForStack[i] != '-' && strForStack[i] != '*'
			&& strForStack[i]!=' ')
		{
			createNums += strForStack[i];
			countElementsInString++;
		}
		else if (strForStack[i] == ' ')
		{
			if(countElementsInString>0)
			{
				int element = stoi(createNums);
				createNums.clear();
				customPush(Tail,element);
				countElementsInString = 0;
			}
		}
		else if (strForStack[i] == '+' || strForStack[i] == '-'
			|| strForStack[i] == '*')
		{
			int result = Tail->data;
			customPop(Tail);
			if (strForStack[i] == '+')
			{
				result += Tail->data;
			}
			else if (strForStack[i] == '-')
			{
				result = Tail->data - result;
			}
			else if (strForStack[i] == '*')
			{
				result *= Tail->data;
			}
			
			customPop(Tail);
			customPush(Tail,result);
		}


	}
	cout << Tail->data;

	return 0;
}

void customPush(Item& Tail,int element)
{
	if (Tail == nullptr)
	{
		Tail = new Stack;
		Tail->data = element;
	}
	else
	{
		Item temp = new Stack;
		temp->prev = Tail;
		temp->data = element;
		Tail = temp;

	}
}

void customPop(Item& Tail)
{
	if (Tail->prev == nullptr)
	{
		delete Tail;
		Tail = nullptr;
	}
	else
	{
		Item temp = Tail;
		Tail = Tail->prev;
		delete temp;
		temp = nullptr;
	}
}
