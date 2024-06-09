/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 6.1 Строки и последовательности
Задача А
дата: 12.05.2024
исполнитель: Иванов А.А, КТбо1-7
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string first_word, second_word;
	cin >> first_word >> second_word;
	string total = first_word + '#' + second_word;
	vector<int> pref(total.size(), 0);
	for (int i = 1; i < total.size(); ++i)
	{
		int j = pref[i - 1];
		while (j > 0 && total[i] != total[j])
		{
			j = pref[j - 1];
		}
		if (total[i] == total[j]) j++;
		pref[i] = j;
	}
	bool flag = 0;
	for (int i = 0; i < pref.size() && !flag; ++i)
	{
		if (pref[i] == first_word.size()) flag = 1;
	}
	if (flag) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
