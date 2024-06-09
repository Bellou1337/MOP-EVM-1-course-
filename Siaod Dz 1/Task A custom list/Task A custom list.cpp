/*
	����� ���
	��� ���
	����������� ���������
	�����
	���� 1.1: ��������� ������
	������: �
	�����������: ������ �.�, ���� 1-7

*/



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define countCards 5

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
* ��� ���������: �������, ������� ����� �������� � �����, � "�����"(Tail ��������� ���� List)
* ��� ������: �������� ������� � ����� ����������� ������ � �������� �����,��������� ���
* ��� �� ����� ��������� �������
* ��� ���������: ������, ������� ���� void
*/
void customPushBack(int, List&);

/*
* ��� ���������: Head(��������� ���� List)
* ��� ������: �������� ������� � ������ ����������� ������ � �������� ������, ��������� �
* ��� �� ����� ��������� �������
* ��� ���������: ������, ������� ���� void
*/
void customPopFront(List&);

int main()
{
	//Head
	List HeadFirst = new Item;
	List HeadSecond = new Item;
	//Tail
	List TailFirst = HeadFirst;
	List TailSecond = HeadSecond;
	//ptr
	List PointerFirstPlayer = HeadFirst;
	List PointerSecondPlayer = HeadSecond;

	//����� ������� ������
	for (int i = 0; i < countCards; i++)
	{
		int num;
		cin >> num;
		//��� ����,����� � head �������� �������
		if (!i) PointerFirstPlayer->data = num;
		//��� ��� ������ ����� �������
		else
		{
			PointerFirstPlayer->next = new Item;
			PointerFirstPlayer->next->prev = PointerFirstPlayer;
			PointerFirstPlayer->next->data = num;
			PointerFirstPlayer = PointerFirstPlayer->next;
			TailFirst = PointerFirstPlayer;
		}
	}
	//����� ������� ������
	for (int i = 0; i < countCards; i++)
	{
		int num;
		cin >> num;
		if (!i) PointerSecondPlayer->data = num;
		else
		{
			PointerSecondPlayer->next = new Item;
			PointerSecondPlayer->next->prev = PointerSecondPlayer;
			PointerSecondPlayer->next->data = num;
			PointerSecondPlayer = PointerSecondPlayer->next;
			TailSecond = PointerSecondPlayer;
		}
	}
	//������ ���������
	PointerFirstPlayer = HeadFirst;
	PointerSecondPlayer = HeadSecond;

	bool flag = 1;
	bool flagForbotva = 1;
	long long countSteps = 0;
	int countElementsInFirst = 5;
	int countElementsInSecond = 5;

	while (flag)
	{
		bool CheckFirstPlayer = (countElementsInFirst == 0);
		bool CheckSecondPlayer = (countElementsInSecond == 0);
		if (CheckFirstPlayer || CheckSecondPlayer) flag = 0;
		else if (countSteps >= 1000000) flagForbotva = 0, flag = 0;
		else if ((PointerFirstPlayer->data) < (PointerSecondPlayer->data))
		{
			if ((PointerFirstPlayer->data == 0) && (PointerSecondPlayer->data == 9))
			{
				//���������
				customPushBack(PointerFirstPlayer->data, TailFirst);
				customPushBack(PointerSecondPlayer->data, TailFirst);
				countElementsInFirst += 2;
				PointerFirstPlayer = PointerFirstPlayer->next;
				PointerSecondPlayer = PointerSecondPlayer->next;
				//�������
				customPopFront(HeadSecond);
				customPopFront(HeadFirst);
				countElementsInFirst -= 1;
				countElementsInSecond -= 1;
				countSteps++;
			}
			else
			{
				//���������
				customPushBack(PointerFirstPlayer->data, TailSecond);
				customPushBack(PointerSecondPlayer->data, TailSecond);
				countElementsInSecond += 2;
				PointerFirstPlayer = PointerFirstPlayer->next;
				PointerSecondPlayer = PointerSecondPlayer->next;
				//�������
				customPopFront(HeadFirst);
				customPopFront(HeadSecond);
				countElementsInFirst -= 1;
				countElementsInSecond -= 1;
				countSteps++;
			}
		}
		else if ((PointerFirstPlayer->data) > (PointerSecondPlayer->data))
		{
			if ((PointerSecondPlayer->data == 0) && (PointerFirstPlayer->data == 9))
			{
				//���������
				customPushBack(PointerFirstPlayer->data, TailSecond);
				customPushBack(PointerSecondPlayer->data, TailSecond);
				countElementsInSecond += 2;
				PointerFirstPlayer = PointerFirstPlayer->next;
				PointerSecondPlayer = PointerSecondPlayer->next;
				//�������
				customPopFront(HeadFirst);
				customPopFront(HeadSecond);
				countElementsInFirst -= 1;
				countElementsInSecond -= 1;
				countSteps++;
			}
			else
			{
				//���������
				customPushBack(PointerFirstPlayer->data, TailFirst);
				customPushBack(PointerSecondPlayer->data, TailFirst);
				countElementsInFirst += 2;
				PointerFirstPlayer = PointerFirstPlayer->next;
				PointerSecondPlayer = PointerSecondPlayer->next;
				//�������
				customPopFront(HeadSecond);
				customPopFront(HeadFirst);
				countElementsInFirst -= 1;
				countElementsInSecond -= 1;
				countSteps++;
			}

		}
	}
	bool checkForAnswerFirst = (countElementsInFirst == 0);
	bool checkForAnswerSecond = (countElementsInSecond == 0);
	if (!flagForbotva) cout << "botva" << endl;

	else if (checkForAnswerFirst || !checkForAnswerSecond)
		cout << "second" << " " << countSteps << endl;

	else cout << "first" << " " << countSteps << endl;

	return 0;
}

void customPushBack(int element, List& Tail)
{
	List tempPointer = new Item;
	tempPointer->data = element;
	tempPointer->next = nullptr;
	tempPointer->prev = Tail;
	Tail->next = tempPointer;
	Tail = tempPointer;
}
void customPopFront(List& Head)
{

	if (Head->next != nullptr)
	{
		List tempPointer = Head;
		Head = Head->next;
		Head->prev = nullptr;
		delete tempPointer;
	}
	else delete[] Head;

}