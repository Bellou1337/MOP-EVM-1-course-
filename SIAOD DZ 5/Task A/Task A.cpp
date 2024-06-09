/*
ЮФУ ИКТИБ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 3.1 Множества, отображения, деревья
Задача А: Буквы, которых нет
Исполнитель: Иванов А.А
Дата: 14.03.2024
*/



#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string firstWord;
	cin >> firstWord;
	for (char& simvol : firstWord)
	{
		simvol = toupper(simvol);
	}

	map<char, int> mp;
	for (int i = 0; i < firstWord.size(); ++i)
	{
		if (!mp.count(firstWord[i])) mp[firstWord[i]] = 1;
		else mp[firstWord[i]]++;
	}
	string secondWord;
	cin >> secondWord;

	for (char& simvol : secondWord)
	{
		simvol = toupper(simvol);
	}

	for (int i = 0; i < secondWord.size(); ++i)
	{
		if (!mp.count(secondWord[i])) mp[secondWord[i]] = 1;
		else mp[secondWord[i]]++;
	}

	vector<char> vec;

	for (char i = 'A'; i <= 'Z'; ++i)
	{
		if (!mp.count(i)) vec.push_back(i);
	}
	if (vec.size() == 0) cout << 0 << endl;
	else
	{
		for (char simvol : vec)
		{
			cout << simvol;
		}
	}
}