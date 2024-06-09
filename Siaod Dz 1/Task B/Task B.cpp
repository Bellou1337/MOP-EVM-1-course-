#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	cin >> n;

	list<int> shelf;

	int operation, numbers;

	for (int i = 0; i < n; i++)
	{
		cin >> operation;
		if (operation == 1 || operation == 2)
		{
			cin >> numbers;
			if (operation == 1) shelf.push_front(numbers);
			else if (operation == 2) shelf.push_back(numbers);
		}
		else
		{
			if (operation == 3)
			{
				cout << shelf.front()<<" ";
				shelf.pop_front();
			}
			else if (operation == 4)
			{
				cout << shelf.back()<<" ";
				shelf.pop_back();
			}
		}
	}
	
	return 0;
}
