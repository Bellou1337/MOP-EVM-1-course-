/*
����� ���
��� ���
����������� ���������
�����
�������� ������� 5.1 : ��������� �� ������
������ B
����: 20.04.2024
�����������: ������ �.�, ����1-7
*/
#include <iostream>
#include <vector>

using namespace std;

/*
* ��� ���������: ������ ��������� ������,������ ���������� ������,������� �������,���������� �������,
* ���������� ���� bool ��� ������ �� ������,� ����� �������, � ������� ������� ����� �����
* ��� ������: ��������� ����� ����� � �������
* ��� ����������: ������, ������� ���� void
*/
void Dfs(vector<vector<int>>&, vector<bool>&, int, int, bool&,int);

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int el;
			cin >> el;
			if (el)
			{
				graph[i].push_back(j);
			}
		}
	}
	bool flag = 1;
	for (int i = 0; i < graph.size(); ++i)
	{
		vector<bool> visited(n);
		Dfs(graph, visited, i, -1,flag,i);
		for (int j = 0; j < n; ++j)
		{
			if (!visited[j]) flag = 0;
		}
		if (flag)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}
void Dfs(vector<vector<int>>& graph, vector<bool>& visited, int pos,int prev,bool& flag,int start)
{
	visited[pos] = true;
	for (auto it = graph[pos].begin(); it != graph[pos].end(); ++it)
	{
		if (*it != prev)
		{
			if (!visited[*it])
			{
				prev = pos;
				Dfs(graph, visited, *it, prev, flag,start);
			}
			else
			{
				if (*it == start)
				{
					flag = 0;
					return;
				}
				
			}
			
		}
		
	}
}