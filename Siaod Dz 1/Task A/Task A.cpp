#include <iostream>
#include <list>
using namespace std;

#define countCards 5

int main()
{

	list <int> firstPlayer;
	list <int> secondPlayer;



	for (int i = 0; i < countCards; i++)
	{
		int num;
		cin >> num;
		firstPlayer.push_back(num);
	}
	
	for (int i = 0; i < countCards; i++)
	{
		int num;
		cin >> num;
		secondPlayer.push_back(num);
	}

	list <int>::iterator pfirstPlayer = firstPlayer.begin();
	list <int>::iterator psecondPlayer = secondPlayer.begin();

	bool flag = 1;
	bool flagForbotva = 1;
	long long countSteps = 0;

	while (flag)
	{
		if (firstPlayer.empty() || secondPlayer.empty()) flag = 0;

		else if (countSteps >= 1000000) flagForbotva = 0, flag = 0;
		//реализация хода
		else if (*pfirstPlayer < *psecondPlayer)
		{
			if (*pfirstPlayer == 0 && *psecondPlayer == 9)
			{
				
				//добавляем

				firstPlayer.push_back(*pfirstPlayer);
				firstPlayer.push_back(*psecondPlayer);
				pfirstPlayer++;
				psecondPlayer++;

				//удаляем
				secondPlayer.pop_front();
				firstPlayer.pop_front();
				countSteps++;
			}
			else
			{
				//добавляем

				secondPlayer.push_back(*pfirstPlayer);
				secondPlayer.push_back(*psecondPlayer);
				pfirstPlayer++;
				psecondPlayer++;

				//удаляем
				firstPlayer.pop_front();
				secondPlayer.pop_front();
				countSteps++;
			}
			
		}
		else if (*pfirstPlayer > *psecondPlayer)
		{
			if(*psecondPlayer==0 && *pfirstPlayer==9)
			{
				//добавляем

				secondPlayer.push_back(*pfirstPlayer);
				secondPlayer.push_back(*psecondPlayer);
				pfirstPlayer++;
				psecondPlayer++;

				//удаляем
				firstPlayer.pop_front();
				secondPlayer.pop_front();
				countSteps++;
			}
			else
			{
				//добавляем

				firstPlayer.push_back(*pfirstPlayer);
				firstPlayer.push_back(*psecondPlayer);
				pfirstPlayer++;
				psecondPlayer++;

				//удаляем
				secondPlayer.pop_front();
				firstPlayer.pop_front();
				countSteps++;
			}
			
		}
		

	}
	if (!flagForbotva) cout << "botva" << endl;

	else if (firstPlayer.empty() || !secondPlayer.empty()) 
		cout << "second" << " " << countSteps << endl;

	else cout << "first" << " " << countSteps << endl;

	return 0;
}

