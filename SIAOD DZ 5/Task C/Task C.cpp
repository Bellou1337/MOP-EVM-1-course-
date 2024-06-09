/*
ЮФУ ИКТИБ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 3.1 Множества, отображения, деревья
Задача С: Структура map
Исполнитель: Иванов А.А
Дата: 14.03.2024
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<string, int>> vec;

	for (int i = 0; i < n; ++i)
	{
		int operation;
		cin >> operation;
		if (operation == 1)
		{
			string name;
			cin >> name;
			int current;
			cin >> current;
			bool flag = 1;
			for (int j = 0; j < vec.size() && flag; ++j)
			{
				if (vec[j].first == name)
				{
					flag = 0;
					vec[j].second += current;
				}
			}
			if (flag)
			{
				vec.push_back({name,current});
			}			
		}
		else
		{
			string name;
			cin >> name;
			bool flag = 1;
			for (int j = 0; j < vec.size() && flag; ++j)
			{
				if (vec[j].first == name)
				{
					cout << vec[j].second << endl;
					flag = 0;
				}
			}
			if (flag) cout << "ERROR" << endl;
		}
	}
}