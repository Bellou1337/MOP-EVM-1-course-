#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <ctype.h>

using namespace std;

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
    cout << parse << endl;

    return 0;
}
