#include <iostream>
#include <string.h>
#include <list>
using namespace std;

#define arraySize 100009

int main()
{
	char arrayForWords[arraySize] = {'\n'};
	bool flag = 1;
	cin.getline(arrayForWords, arraySize);

	if (arrayForWords[0] == ')' || arrayForWords[0] == ']'
		|| arrayForWords[0] == '}') flag = 0;

	list <char> words;

	bool checker = 0;

	int countOpen = 0;
	int countClose = 0;

	for (int i = 0; i < strlen(arrayForWords) && flag; i++)
	{
		if (arrayForWords[i] == '(' || arrayForWords[i] == '['
			|| arrayForWords[i] == '{') words.push_back(arrayForWords[i]),countOpen++;

		else if(arrayForWords[i] == ')' || arrayForWords[i] == ']'
			|| arrayForWords[i] == '}')
		{
			checker = 1;

			if (arrayForWords[i] == ')')
			{

				if (words.back() == '(')
				{
					words.pop_back();
					arrayForWords[i] = '+';
					countClose++;
				}
				else flag = 0;
			}

			else if (arrayForWords[i] == ']')
			{

				if (words.back() == '[')
				{
					words.pop_back();
					arrayForWords[i] = '+';
					countClose++;
				}
				else flag = 0;
			}

			else if (arrayForWords[i] == '}')
			{

				if (words.back() == '{')
				{
					words.pop_back();
					arrayForWords[i] = '+';
					countClose++;
				}
				else flag = 0;
			}

		}
	}

	if (flag && checker && (countOpen == countClose)) cout << "yes";
	else cout << "no";

	return 0;
}

