/*
ИКТИБ ЮФУ
МОП ЭВМ
СИАОД
Тема 5.2 Алгоритмы на графах
задача D
дата: 27.04.2024
исполнитель: Иванов А.А
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	const int size = 1e9;
	vector<vector<pair<int,int>>> graph(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int weight;
			cin >> weight;
			if (weight != 0)
			{
				graph[i].push_back({ j,weight });
			}
		}
	}
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	vector<int> dist(n, size);
	dist[a] = 0;
	vector<bool> visited(n, false);
	vector<int> prev(n, -1);
	for (int i = 0; i < graph.size(); ++i)
	{
		int near = -1;
		for (int v = 0; v < graph.size(); ++v)
		{
			if (!visited[v] && (near == -1
				|| dist[v] < dist[near]))
			{
				near = v;
			}
		}
		visited[near] = true;
		for (pair<int,int> search : graph[near])
		{
			if (dist[search.first] > dist[near] + search.second)
			{
				dist[search.first] = dist[near] + search.second;
				prev[search.first] = near;
			}
		}
	}
	if (dist[b] == size)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << dist[b] << endl;
	vector<int> path;
	int start = b;
	while (start != -1)
	{
		path.push_back(start+1);
		start = prev[start];
	}
	reverse(path.begin(), path.end());
	for (int search : path)
	{
		cout << search << " ";
	}
	return 0;
}
