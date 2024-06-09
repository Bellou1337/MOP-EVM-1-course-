/*
ЮФУ ИКТИБ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 3.1 Множества, отображения, деревья
Задача B: Девайсы
Исполнитель: Иванов А.А
Дата: 14.03.2024
*/


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>


using namespace std;


int main()
{
	map<string, pair<int, int>> mp;

	int n = 6;

	int minCurrent = INT_MAX;
	string minDevise;
	int maxCounter = 0;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		string devise;
		cin >> devise;
		int current;
		cin >> current;
		if (!mp.count(devise))
		{
			mp[devise] = { current,1 };
			if (mp[devise].second > maxCounter) maxCounter = mp[devise].second;
		}
		else
		{
			int minCurrent = min(current,mp[devise].first);
			mp[devise] = { minCurrent,++mp[devise].second};
			if (mp[devise].second > maxCounter) maxCounter = mp[devise].second;
		}
	}

	for (const auto& str : mp)
	{
		if (str.second.second == maxCounter)
		{
			if (str.second.first < minCurrent)
			{
				minCurrent = str.second.first;
				minDevise = str.first;
			}
		}
	}
	cout << minDevise << endl;
}