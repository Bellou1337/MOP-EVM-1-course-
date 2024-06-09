/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 6.1 Строки и последовательности
Задача B
дата: 12.05.2024
исполнитель: Иванов А.А, КТбо1-7
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <vector>

using namespace std;

bool compare(pair<char, int>, pair<char, int>);

int main()
{
    string word;
    getline(cin, word);
    string parse;
    map<char, int> mp;
    for (int i = 0; i < word.size(); ++i)
    {
        if (isalpha(word[i])) parse += toupper(word[i]);
    }
    sort(parse.begin(), parse.end(), greater<char>());
    for (int i = 0; i < parse.size(); ++i)
    {
        if (!mp.count(parse[i])) mp[parse[i]] = 1;
        else mp[parse[i]]++;
    }
    vector<pair<char, int>> vec_for_mp(mp.begin(), mp.end());
    sort(vec_for_mp.begin(), vec_for_mp.end(), compare);
    int len = 0;
    int counter_nechet = 0;
    for (auto search : vec_for_mp)
    {
        if (search.second % 2 == 0) len += search.second;
        else counter_nechet++;
    }
    if (counter_nechet > 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    char item;
    for (auto search : vec_for_mp)
    {
        if (search.second % 2 != 0)
        {
            item = search.first;
            len+=search.second; 
        }
    }
    vector<char> vec(len);
    int left = 0, right = len - 1;
    bool flag = 0;
    for (auto search : vec_for_mp)
    {
        if (search.second % 2 == 0)
        {
            while (mp[search.first] > 0)
            {
                vec[left++] = search.first;
                mp[search.first]--;
                vec[right--] = search.first;
                mp[search.first]--;
            }
        }
        else if (search.second % 2 != 0)
        {
            while (mp[search.first] > 1)
            {
                vec[left++] = search.first;
                mp[search.first]--;
                vec[right--] = search.first;
                mp[search.first]--;
            }
            flag = 1;
        }
    }
    if (flag)
    {
        vec[left] = item;
        mp[item]--;
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
    }
    return 0;
}
bool compare(pair<char,int> a,pair<char,int>b)
{
    return a.first > b.first;
}