/*
ЮФУ ИКТИБ
МОП ЭВМ
СиАОД
Домашнее задание 2.2
Задание E
Исполнитель: Иванов Артём Артурович(КТбо1-7)
04.03.2024
*/

#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	int left = 0;
	int right = vec[n - 1];

	while (right - left > 1)
	{
		int middle = (left + right) / 2;
		int countCows = 1;
		int lastPosCow = vec[0];
		for (int search : vec)
		{
			if (search - lastPosCow >= middle)
			{
				countCows++;
				lastPosCow = search;
			}
		}
		if (countCows >= k)
		{
			left = middle;
		}
		else right = middle;
	}
	cout << left << endl;
}