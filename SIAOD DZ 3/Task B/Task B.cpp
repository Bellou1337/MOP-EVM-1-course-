/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* Программная инженерия
* СИАОД
* Тема 2.1 Сортировка и поиск
* Задача B
* Исполнитель: Иванов А.А, КТбо 1-7
* Дата: 28.02.2024
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(),arr.end());

	vector<int> answer(n);

	int left = 0,right = n - 1;


	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) answer[left++] = arr[i];
		else answer[right--] = arr[i];
	}

	for (auto it = answer.begin(); it != answer.end(); ++it) cout << *it << " ";

	return 0;
}