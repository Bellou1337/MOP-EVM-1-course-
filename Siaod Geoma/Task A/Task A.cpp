/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* СИАОД
* Тема 7 Вычислительная геометрия
* Задача А
* дата: 25.05.2024
* исполнитель: Иванов А.А, КТбо 1-7
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
	ll n;
	cin >> n;
	vector<pair<double, double>> vec(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	ll answer = 0;
	for (ll i = 0; i < n - 2; ++i)
	{
		pair<double, double> firstCoord, secondCoord,lastCoord;
		firstCoord = vec[i], secondCoord = vec[i + 1],lastCoord = vec[i+2];
		// образуем векторы
		//первый вектор
		pair<double, double> firstVector = { secondCoord.first - firstCoord.first,secondCoord.second - firstCoord.second };
		//второй вектор
		pair<double, double> secondVector = {lastCoord.first - secondCoord.first,lastCoord.second - secondCoord.second};
		//считаем векторное произведение
		double result = firstVector.first * secondVector.second - secondVector.first * firstVector.second;
		if (result > 0) answer++;
	}
	cout << answer << endl;
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