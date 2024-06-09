/*
* ����� ���
* ��� ���
* �����
* ���� 7 �������������� ���������
* ������ C
* ����: 25.05.2024
* �����������: ������ �.�, ���� 1-7
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
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
	ll R, X, Y;
	cin >> R >> X >> Y;
	if (X < 0) X = -X;
	double result = (double)(R * X) / (double)(2 * R - Y);
	cout << fixed << setprecision(2) << result << endl;
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