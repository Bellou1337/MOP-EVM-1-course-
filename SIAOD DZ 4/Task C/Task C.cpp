/*
ЮФУ ИКТИБ
МОП ЭВМ
СиАОД
Домашнее задание 2.2
Задание F
Исполнитель: Иванов Артём Артурович(КТбо1-7)
04.03.2024
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double C;
	cin >> C;
	double left = 0,right = 100000;
	for (int i = 0; i < 1000; i++)
	{
		double middle = (left + right) / 2;
		if (pow(middle, 2) + sqrt(middle) < C)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}
	cout << fixed << setprecision(6) << right << endl;

	
}
