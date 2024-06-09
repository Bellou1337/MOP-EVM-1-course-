/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* Программная инженерия
* СИАОД
* Тема 2.1 Сортировка и поиск
* Задача C
* Исполнитель: Иванов А.А, КТбо 1-7
* Дата: 28.02.2024
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int main()
{
	string Alphabet;
	cin >> Alphabet;

	vector<pair<char, int>> arr;

	for (int i = 0; i < Alphabet.size(); ++i) arr.push_back({ Alphabet[i], i+1 });
	
	sort(arr.begin(), arr.end());

	bool flag = 1;

	int pos = 0;

	vector<int> answer;

	for (int i = 'A'; i <= 'Z' && flag; i++)
	{
		pair<char, int> temp = arr[pos];
		if (temp.first >= char(i)) answer.push_back(temp.second);
		else flag = 0;
		pos++;

	}
	if (!flag) cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		for (auto it = answer.begin(); it != answer.end(); it++) cout << *it << " ";

	}

	return 0;
}
