/*
* ����� ���
* ��� ���
* �����
* ���� 7 �������������� ���������
* ������ �
* ����: 25.05.2024
* �����������: ������ �.�, ���� 1-7
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using ull = unsigned long long;
/*
* ��� ���������: ������
* ��� ������: ������ ������
* ��� ����������: ������
*/
void solve()
{
	ll n;
	cin >> n;
	vector<pair<double, double>> vec(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	ll answer = 0;
	for (ll i = 0; i < n - 2; ++i)
	{
		pair<double, double> firstCoord, secondCoord,lastCoord;
		firstCoord = vec[i], secondCoord = vec[i + 1],lastCoord = vec[i+2];
		// �������� �������
		//������ ������
		pair<double, double> firstVector = { secondCoord.first - firstCoord.first,secondCoord.second - firstCoord.second };
		//������ ������
		pair<double, double> secondVector = {lastCoord.first - secondCoord.first,lastCoord.second - secondCoord.second};
		//������� ��������� ������������
		double result = firstVector.first * secondVector.second - secondVector.first * firstVector.second;
		if (result > 0) answer++;
	}
	cout << answer << endl;
}

signed main()
{
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}