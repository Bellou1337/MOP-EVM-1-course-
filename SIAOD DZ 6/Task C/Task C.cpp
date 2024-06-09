/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Домашнее задание: 3.2 Множества, отображения, деревья
Задача F
Дата: 22.03.2024
Исполнитель: Иванов Артём Артурович, КТбо1-7
*/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, string> regist;
	map<string, pair<string, bool>> logOrLogout;
	for (int i = 0; i < n; ++i)
	{
		string option;
		cin >> option;
		if (option == "register")
		{
			string username, password;
			cin >> username >> password;
			if (regist.count(username)) cout << "fail: user already exists" << endl;
			else
			{
				regist[username] = password;
				cout << "success: new user added" << endl;
			}
		}
		else if (option == "login")
		{
			string username, password;
			cin >> username >> password;
			if (!regist.count(username)) cout << "fail: no such user" << endl;
			else if (regist.count(username) && regist[username] != password)
			{
				cout << "fail: incorrect password" << endl;
			}
			else
			{
				if (logOrLogout.count(username) && logOrLogout[username].second == true)
				{
					cout << "fail: already logged in" << endl;
				}
				else
				{
					cout << "success: user logged in" << endl;
					logOrLogout[username] = { password,true };

				}
			}
		}
		else if (option == "logout")
		{
			string username;
			cin >> username;
			if (!regist.count(username)) cout << "fail: no such user" << endl;
			else if (logOrLogout[username].second == false) cout << "fail: already logged out" << endl;
			else
			{
				cout << "success: user logged out" << endl;
				logOrLogout[username].second = false;
			}
		}
	}

}