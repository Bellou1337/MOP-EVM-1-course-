/*
ИКТИБ ЮФУ
МОП ЭВМ
СИАОД
Тема 5.2 Алгоритмы на графах
задача E
дата: 27.04.2024
исполнитель: Иванов А.А
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int size = 1e9;
	vector<vector<pair<int,int>>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		u--,v--;
		graph[u].push_back({ v,weight });
		graph[v].push_back({ u,weight });
	}
	int answer = -size; 
	for (int every = 0; every < graph.size(); ++every)
	{
		vector<int> dist(n, size);
		vector<bool> visited(n, false);
		dist[every] = 0;
		int local_max = -size;
		for (int i = 0; i < graph.size(); ++i)
		{
			int near = -1;
			for (int v = 0; v < graph.size(); ++v)
			{
				if (!visited[v] && (near == -1
					|| dist[near] > dist[v]))
				{
					near = v;
				}
			}
			visited[near] = true;
			for (pair<int, int> search : graph[near])
			{
				if (dist[search.first] > dist[near] + search.second)
				{
					dist[search.first] = dist[near] + search.second;
				}
			}
			
		}
		for (int search = 0; search < dist.size(); ++search)
		{
			if (dist[search] > local_max && dist[search] != size)
			{
				local_max = dist[search];
			}
		}
		if (local_max > answer) answer = local_max;
	}
	if (answer == -size) cout << 0 << endl;
	else cout << answer << endl;
}
