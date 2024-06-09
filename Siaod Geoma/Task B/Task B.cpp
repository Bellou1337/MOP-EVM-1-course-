/*
* ����� ���
* ��� ���
* �����
* ���� 7 �������������� ���������
* ������ B
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
	ll x1, y1, x2, y2, x3, y3,l;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> l;
	// ���������� ���� ��������
	// (x1,y1) = A,(x2,y2) = B,(x3,y3) = C
	double lenAB = sqrt((double)pow((x2 - x1), 2) + (double)pow((y2 - y1), 2));
	double lenAC = sqrt((double)pow((x3 - x1), 2) + (double)pow((y3 - y1), 2));
	double lenCB = sqrt((double)pow((x3-x2),2)+(double)pow((y3-y2),2));
	//���������� ������ ��������������
	//����� ������� �� ������� ������
	// ������������
	double semiPerimeter = (lenAB + lenAC + lenCB) / 2;
	// ������� �������
	double square = sqrt(semiPerimeter*(semiPerimeter-lenAB)*(semiPerimeter - lenAC)*(semiPerimeter - lenCB));
	//������� ������(�� ���� ��� � ���� ���������� ����������)
	double h = (square*2.0)/ lenAB;
	// ������ ��������� ������ ������
	// 1) ��� ���� ����� ���� ������������� �����������
	if (max(lenAC,lenCB)*max(lenAC,lenCB)>min(lenAC,lenCB)*min(lenAC,lenCB)+ (double)pow(lenAB,2))
	{
		//�������������� ���������� ���������
		//��� ������ ������� �� ���� AC � CB
		h = min(lenAC,lenCB);
	}
	// 2) ���� ������� ������ � ���� �����
	// ����� lenAB == 0
	if (lenAB == 0.0)
	{
		// ��� ����� ������ ����� ����� AC ��� BC, ���������� ����� ���������
		h = lenAC;
	}
	// ������� �����
	double firstAnswer = max(0.0,h-l);
	double secondAnswer = max(0.0,max(lenAC,lenCB)-l);
	cout << fixed << setprecision(2) << firstAnswer << endl;
	cout << fixed << setprecision(2) << secondAnswer << endl;
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