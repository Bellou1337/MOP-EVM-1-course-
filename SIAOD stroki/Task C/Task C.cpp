/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 6.1 Строки и последовательности
Задача C
дата: 12.05.2024
исполнитель: Иванов А.А, КТбо1-7
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string word;
	cin >> word;

	int search = word.find("R"),counter = 0;
	for (int i = search; i < word.size(); ++i)
	{
		if (word[i] == 'B')
		{
			counter++;
			word.erase(i,1);
			--i;
		}
	}
	cout << word << endl;
	cout << counter;
	return 0;
}