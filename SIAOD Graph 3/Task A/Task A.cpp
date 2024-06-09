/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 5.3 Алгоритмы на графах
Задача G
дата: 04.05.2024
исполнитель: Иванов А.А
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct edge
{
	ll u, v;
	ll weight;
};

/*
* Что принимает: два элемента структуры edge
* Что делает: сортирует вектор структур
* Что вовзращает: специальный параметр для сортировки
*/
bool compare(struct edge, struct edge);
/*
* Что принимает: вектор вершин,вектор глубины графа, две вершины для соединения
* Что делает: реализует часть алгоритма Краскала(пытается соединить две вершины минимального веса)
* Что возвращает: булевое значение, которое говорит удалось ли соединить две вершины
*/
bool get_cnm(vector<ll>&, vector<ll>&, ll, ll);
/*
* Что принимает: вектор вершин и вершину
* Что делает: реализует поиск вершины для соединения с другой
* Что возвращает: номер вершины
*/
ll search(vector<ll>&, ll);

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<struct edge> vec(m);
	for (ll i = 0; i < m; ++i)
	{
		ll u, v, weight;
		cin >> u >> v >> weight;
		vec[i].u = u;
		vec[i].v = v;
		vec[i].weight = weight;
	}
	sort(vec.begin(), vec.end(), compare);
	vector<ll> parent(n + 1);
	vector<ll> depth(n + 1);
	for (ll i = 1; i <= n; ++i) parent[i] = i;

	ll current = 0;

	for (ll i = 0; i < m; ++i)
	{
		bool checker = get_cnm(parent, depth, vec[i].u, vec[i].v);
		if (checker) current += vec[i].weight;
	}
	cout << current << endl;
	return 0;
}
bool compare(struct edge a, struct edge b)
{
	return a.weight < b.weight;
}
bool get_cnm(vector<ll>& parent, vector<ll>& depth, ll x, ll y)
{
	x = search(parent, x);
	y = search(parent, y);
	if (x == y) return false;
	if (depth[x] < depth[y]) swap(x, y);
	parent[y] = x;
	if (depth[x] == depth[y]) depth[x]++;
	return true;
}
ll search(vector<ll>& parent, ll v)
{
	if (v == parent[v]) return v;
	return parent[v] = search(parent, parent[v]);
}