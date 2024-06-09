/*
ЮФУ ИКТИБ
МОП ЭВМ
СиАОД
Домашнее задание 2.2
Задание D
Исполнитель: Иванов Артём Артурович(КТбо1-7)
04.03.2024
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];


	vector<int> vecSort(n);
	vecSort.assign(vec.begin(), vec.end());
	sort(vecSort.begin(), vecSort.end());

	for (int i = 0; i < n; i++)
	{
		int k = vec[i];
		int counter = 0;
		for (auto it = vecSort.begin(); it != vecSort.end(); it++)
		{
			int search = k - *it;
			auto itUp = upper_bound(it + 1, vecSort.end(), search);
			auto itLow = lower_bound(it + 1, itUp, search);
			while (itLow != itUp)
			{
				counter++;
				itLow++;
			}

		}
		cout << counter << endl;
	}

}