/*
ИКТИБ ЮФУ
МОП ЭВМ
Программная инженерия
СИАОД
Домашнее задание 5.1 : Алгоритмы на графах
Задача А
дата: 20.04.2024
исполнитель: Иванов А.А, КТбо1-7
*/

#include <iostream>
#include <vector>

using namespace std;

/*
* Что принимает: вектор смежности вершин,переменную типа bool для ответа на задачу, текущую вершину
* Что делает: выполняет обход графа в глубину
* Что возвращает: ничего, функция типа void
*/
void Dfs(vector<vector<int>>&, vector<bool>&, int);

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n);
    bool flag = 1;
    while (flag)
    {
        int firstEl;
        cin >> firstEl;
        if (!firstEl) flag = 0;
        else
        {
            int secondEl;
            cin >> secondEl;
            graph[firstEl - 1].push_back(secondEl - 1);
        }
    }
    vector<bool> visited(n, false);
    Dfs(graph, visited, k - 1);
    bool flag_for_answer = 1;
    for (int i = 0; i < n && flag_for_answer; ++i)
    {
        if (!visited[i]) flag_for_answer = 0;
    }
    if (flag_for_answer) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
void Dfs(vector<vector<int>>& graph, vector<bool>& visited, int pos)
{
    visited[pos] = true;
    for (auto it = graph[pos].begin(); it != graph[pos].end(); ++it)
    {
        if (!visited[*it])
        {
            Dfs(graph, visited, *it);
        }
    }


}