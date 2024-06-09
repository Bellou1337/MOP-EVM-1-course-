/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 5.3 Алгоритмы на графах
Задача H
дата: 04.05.2024
исполнитель: Иванов А.А
*/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
* Что принимает: вектор посещённых вершин, вектор смежности, номер текущей вершины
* Что делает: поиск в глубину в графе
* Что возвращает: ничего, функция типа void
*/
void dfs(vector<bool>&, vector<vector<int>>&, int);

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> visited(n);
	dfs(visited, graph, 0);
	return 0;
}
void dfs(vector<bool>& visited, vector<vector<int>>& graph, int v)
{
	visited[v] = true;
	for (auto it = graph[v].begin(); it != graph[v].end(); ++it)
	{
		if (!visited[*it])
		{
			cout << v + 1 << " " << *it + 1 << endl;
			dfs(visited, graph, *it);
		}
	}

}