/*
����� ���
��� ���
����������� ���������
�����
�������� ������� 5.1 : ��������� �� ������
������ C
����: 20.04.2024
�����������: ������ �.�, ����1-7
*/
#include <iostream>
#include <vector>


using namespace std;

/*
* ��� ���������: ������ ���������, ������ ���������� ������,������� ���� �������,������� ����� �������,
* ���������� ���� bool ��� ������ �� ������
* ��� ������: ��������� ����� ����� � ������� � ������� ������ � 2 �����
* ��� ����������: ������, ������� ���� void
*/
void dfs(vector<vector<int>>&, vector<int>&, int, int, bool&);

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> visited(n, 0);
	for (int i = 0; i < m; ++i)
	{
		int left, right;
		cin >> left >> right;
		graph[left - 1].push_back(right - 1);
		graph[right - 1].push_back(left - 1);
	}
	bool flag = 1;
	for (int i = 0; i < graph.size(); ++i)
	{
		if (!visited[i])
		{
			dfs(graph, visited, 1, i, flag);
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

}
void dfs(vector<vector<int>>& graph, vector<int>& visited, int color, int pos, bool& flag)
{
	visited[pos] = color;
	for (auto it = graph[pos].begin(); it != graph[pos].end(); ++it)
	{
		if (!visited[*it])
		{
			dfs(graph, visited, 3 - color, *it, flag);
		}
		else if (visited[pos] == visited[*it])
		{
			flag = 0;
			return;
		}
	}

}