/*
* ����� ���
* ��� ���
* ����������� ���������
* �����
* ���� 2.1 ���������� � �����
* ������ A
* �����������: ������ �.�, ���� 1-7
* ����: 28.02.2024
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr.begin(),arr.end());

	int counterForPlayer = 0,counterForShrek = 0,middle = n/2;

	for (int i = 0; i < middle; i++) counterForPlayer += arr[i];

	for (int i = middle; i < n; i++) counterForShrek += arr[i];

	cout << counterForShrek-counterForPlayer<< endl;

	return 0;
}