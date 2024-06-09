/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* СИАОД
* Тема 7 Вычислительная геометрия
* Задача D
* дата: 25.05.2024
* исполнитель: Иванов А.А, КТбо 1-7
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

using ll = long long;
using ull = unsigned long long;

/*
* Что принимает: ничего
* Что делает: решает задачу
* Что возвращает: ничего
*/
void solve()
{
	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// если точка два образует прямой угол
	// находим векторы
	pair<ll, ll> vector21 = {x2-x1,y2-y1};
	pair<ll, ll> vector32 = {x3-x2,y3-y2};
	pair<ll, ll> vector31 = {x3 - x1,y3 - y1};
	pair<ll, ll> vector12 = { x1 - x2,y1 - y2 };
	pair<ll, ll> vector13 = { x1 - x3,y1 - y3 };
	pair<ll, ll> vector23 = { x2 - x3,y2 - y3 };
	if ((vector21.first * vector31.first + vector21.second * vector31.second) == 0)
	{
		ll x = x1 + x2 - x1 + x3 - x1;
		ll y = y1 + y2 - y1 + y3 - y1;
		cout << x << " " << y << endl;
		return;
	}
	// ессли точка один образует прямой угол
	if ((vector12.first * vector32.first + vector12.second * vector32.second) == 0)
	{
		ll x = x2 + x1 - x2 + x3 - x2;
		ll y = y2 + y1 - y2 + y3 - y2;
		cout << x << " " << y << endl;
		return;
	}
	if ((vector13.first * vector23.first + vector13.second * vector23.second) == 0)
	{
		ll x = x3 + x1 - x3 + x2 - x3;
		ll y = y3 + y1 - y3 + y2 - y3;
		cout << x << " " << y << endl;
		return;
	}
}

signed main()
{
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}