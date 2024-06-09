/*
����� ���
��� ���
����������� ���������
�����
�������� �������: 3.2 ���������, �����������, �������
������ D
����: 22.03.2024
�����������: ������ ���� ���������, ����1-7
*/


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
* ��� ��������: ��������� �� ������ � ������� ����, ����� �������
*/
typedef struct Three
{
	Three* pleft = nullptr;
	Three* pright = nullptr;
	int data;


}Three;

typedef Three* Item;

/*
* ��� ���������: ����� ����� � ����� �������(������� �� ����� ��������)
* ��� ������: ��������� ����� ������� � ������
* ��� ����������: ������, ������� ���� void
*/
void customInsert(Item& , int );
/*
* ��� ���������: ����� ����� � ������, � ������� ����������� ����� �� �������
* ��� ������: ���� ������� � ����� �����
* ��� ����������: ������, ������� ���� void
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
		//������ �� ��������� �����
		if (customThree->data > value)
		{
			customInsert(customThree->pleft, value);
		}
		// ����� ��������� ������
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