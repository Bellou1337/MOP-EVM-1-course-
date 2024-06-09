/*
����� ���
��� ���
����������� ���������
�����
���� 5.3 ��������� �� ������
������ I
����: 04.05.2024
�����������: ������ �.�
*/
#include <iostream>
#include <vector>

using namespace std;

/*
* ��� ���������: ������ ���������, ������ ���������� ������,������ ���������� ����������� �����, ����� ������� �� ������ ����
* ��� ������: �� ��������� ���� ��������� ������� � ���������� �����
* ��� ����������: ��� bool ������� �� ��������� ��� �������
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