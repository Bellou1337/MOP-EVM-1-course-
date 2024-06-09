/*
ИКТИБ ЮФУ
МОП ЭВМ
СИАОД
Тема 5.2 Алгоритмы на графах
задача F
дата: 27.04.2024
исполнитель: Иванов А.А
*/
#include <iostream>
#include <vector>


using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	vector<vector<pair<ll, ll>>> graph(n);
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			ll weight;
			cin >> weight;
			if (weight != 0)
			{
				graph[i].push_back({ j,weight });
			}
		}
	}
	vector<ll> children(n);
	const int size = 10000;
	ll answer = 1e9;
	ll place = 0;
	for (ll i = 0; i < n; ++i) cin >> children[i];

	for (ll every = 0; every < graph.size(); ++every)
	{
		vector<ll> dist(n, size);
		vector<ll> visited(n,false);
		dist[every] = 0;
		for (ll i = 0; i < graph.size(); ++i)
		{
			ll near = -1;
			for (ll v = 0; v < graph.size(); ++v)
			{
				if (!visited[v] && (near == -1
					|| dist[near] > dist[v]))
				{
					near = v;
				}
			}
			visited[near] = true;
			for (pair<ll, ll> search : graph[near])
			{
				if(dist[search.first] > dist[near] + search.second)
				{
					dist[search.first] = dist[near] + search.second;
				}
			}
		}
		ll current = 0;
		for (ll search = 0; search < dist.size(); ++search)
		{
			current += (dist[search] * children[search]);
		}
		if (current < answer)
		{
			answer = current;
			place = every + 1;
		}
	}
	cout <<place<<" "<< answer << endl;
	return 0;
}