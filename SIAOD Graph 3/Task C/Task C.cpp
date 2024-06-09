/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Тема 5.3 Алгоритмы на графах
Задача I
дата: 04.05.2024
исполнитель: Иванов А.А
*/
#include <iostream>
#include <vector>

using namespace std;

/*
* Что принимает: вектор смежности, вектор посещённых вершин,вектор соединений двудольного графа, номер вершины из правой доли
* Что делает: По алгоритму Куна соединяет вершины в двудольном графе
* Что возвращает: тип bool удалось ли соединить две вершины
*/
bool dfs_kyn(vector<vector<int>>&, vector<bool>&, vector<int>&, int);

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> match(n, -1);
	vector<vector<int>> graph(s);
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int value;
			cin >> value;
			if (value != 0)
			{
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < s; ++i)
	{
		vector<bool> visited(s, false);
		dfs_kyn(graph, visited, match, i);
	}
	int answer = 0;
	for (int i = 0; i < match.size(); ++i)
	{
		if (match[i] != -1) answer++;
	}
	cout << answer << endl;
	return 0;
}
bool dfs_kyn(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& match, int v)
{
	if (visited[v]) return false;
	visited[v] = true;
	for (auto it = graph[v].begin(); it != graph[v].end(); ++it)
	{
		if (match[*it] == -1 || dfs_kyn(graph, visited, match, match[*it]))
		{
			match[*it] = v;
			return true;
		}
	}
	return false;

}